#include <iostream>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <filesystem>
#include "funciones.h"

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cerr << "\nNo hay argumentos suficientes para la ejecución." << std::endl;
        displaySubjectInfo();
        return EXIT_FAILURE;
    }

    std::string ArgvOption = argv[1];

    if (ArgvOption != "1" && ArgvOption != "2") {
        std::cerr << "\nNo se reconoce la opción '" << ArgvOption << "'." << std::endl;
        displaySubjectInfo();
        return EXIT_FAILURE;
    }

    if (ArgvOption == "1") {
        if (!argv[3]) {
            argv[3] = const_cast<char *>("./");
        }

        int **WeightedScores;

        std::string InputFilePath(argv[2]);
        std::string OutputFilePath(argv[3]);
        std::error_code PathStatusErrorCode;
        std::filesystem::file_status PathStatus = std::filesystem::status(
            std::filesystem::path(OutputFilePath), PathStatusErrorCode);

        if (PathStatusErrorCode) {
            std::cerr << "Error checking path status: " << PathStatusErrorCode.message() << std::endl;
            return EXIT_FAILURE;
        }

        if (!std::filesystem::exists(PathStatus)) {
            std::cerr << "\nDirectorio de escritura no existe." << std::endl;
            return EXIT_FAILURE;
        }

        if (InputFilePath.length() < 4) {
            std::cerr << "\nArchivo de lectura inválido." << std::endl;
            return EXIT_FAILURE;
        }

        std::string FileExtension = InputFilePath.substr(InputFilePath.length() - 4, InputFilePath.length());

        if (FileExtension != ".csv") {
            std::cerr << "\nExtensión de archivo incorrecto." << std::endl;
            return EXIT_FAILURE;
        }

        std::ifstream InputStream;
        InputStream.open(InputFilePath, std::ios_base::in);

        if (!InputStream.is_open()) {
            std::cerr << "\nArchivo no encontrado." << std::endl;
            return EXIT_FAILURE;
        }

        std::cout << "\nArchivo encontrado." << std::endl;

        const int FileLinesCounter = countFileLines(InputStream);
        InputStream.close();

        if (!FileLinesCounter) {
            std::cerr << "\nEl archivo está vacío." << std::endl;
            return EXIT_FAILURE;
        }

        WeightedScores = new int *[FileLinesCounter];
        InputStream.open(InputFilePath, std::ios_base::in);
        OfertaUniversitaria UtemOffer = getAcademicOffer(WeightedScores, InputStream);
        InputStream.close();
        auto StartHeapSortTime = std::chrono::steady_clock::now();
        heapSort(WeightedScores, FileLinesCounter, 6);
        auto FinishHeapSortTime = std::chrono::steady_clock::now();
        postulate(UtemOffer, WeightedScores, FileLinesCounter);
        write(UtemOffer, OutputFilePath);

        std::cout << "\nArchivos de texto creados en " + OutputFilePath
                << std::endl;

        auto HeapSortTime =
                std::chrono::duration_cast<std::chrono::nanoseconds>(FinishHeapSortTime - StartHeapSortTime)
                .count();

        std::cout << "\nSe demoró " << static_cast<double>(HeapSortTime) * (0.000000001)
                << "segundos ordenar y postular a los " << FileLinesCounter
                << " estudiantes." << std::endl;
    }

    if (ArgvOption == "2") {
        std::string FilePath(argv[3]);
        std::string Rut(argv[2]);
        auto StartTime = std::chrono::steady_clock::now();
        std::string SearchResultMessage = search(FilePath, Rut);
        auto FinishTime = std::chrono::steady_clock::now();
        auto SearchTime =
                std::chrono::duration_cast<std::chrono::nanoseconds>(FinishTime - StartTime).count();
        std::cout << SearchResultMessage << std::endl;
        std::cout << "La búsqueda demoró " << static_cast<double>(SearchTime) * (0.000000001)
                << "[segundos]." << std::endl;
    }
    return EXIT_SUCCESS;
}
