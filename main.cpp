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

    std::string option = argv[1];

    if (option != "1" && option != "2") {
        std::cerr << "\nNo se reconoce la opción '" << option << "'." << std::endl;
        displaySubjectInfo();
        return EXIT_FAILURE;
    }

    if (option == "1") {
        if (!argv[3]) {
            argv[3] = const_cast<char*>("./");
        }

        int **ponderados;

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

        std::ifstream read;
        read.open(InputFilePath, std::ios_base::in);

        if (!read.is_open()) {
            std::cerr << "\nArchivo no encontrado." << std::endl;
            return EXIT_FAILURE;
        }

        std::cout << "\nArchivo encontrado." << std::endl;
        const int newLinesCount = countFileNewLines(read);

        if (!newLinesCount) {
            std::cerr << "\nEl archivo está vacío." << std::endl;
            return EXIT_FAILURE;
        }

        read.open(FileExtension, std::ios_base::in);
        ponderados = new int *[newLinesCount];
        OfertaUniversitaria OfertaUtem = getAcademicOffer(ponderados, read);
        read.close();
        auto StartTime = std::chrono::steady_clock::now();
        heapSort(ponderados, newLinesCount, 6);
        auto FinishTime = std::chrono::steady_clock::now();
        postulate(OfertaUtem, ponderados, newLinesCount);
        write(OfertaUtem, OutputFilePath);

        std::cout << "\nArchivos de texto creados en " + OutputFilePath
                << std::endl;

        auto HeapSortTime =
                std::chrono::duration_cast<std::chrono::nanoseconds>(FinishTime - StartTime)
                .count();

        std::cout << "\nSe demoró " << static_cast<double>(HeapSortTime) * (0.000000001)
                << "[segs] ordenar y postular a los " << newLinesCount
                << " estudiantes." << std::endl;
    }

    if (option == "2") {
        std::string ruta(argv[3]);
        std::string rut(argv[2]);
        auto StartTime = std::chrono::steady_clock::now();
        std::string SearchResultMessage = search(ruta, rut);
        auto FinishTime = std::chrono::steady_clock::now();
        auto SearchTime =
                std::chrono::duration_cast<std::chrono::nanoseconds>(FinishTime - StartTime).count();
        std::cout << SearchResultMessage << std::endl;
        std::cout << "La búsqueda demoró " << static_cast<double>(SearchTime) * (0.000000001)
                << "[segundos]." << std::endl;
    }
    return EXIT_SUCCESS;
}
