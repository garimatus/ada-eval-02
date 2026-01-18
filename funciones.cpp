#include <iostream>
#include <sstream>
#include <fstream>
#include "AdaEval02Structs.h"
// #include <omp.h>
#include "heapSort.cpp"

void displaySubjectInfo() {
    std::cout << std::endl << "=== Análisis de Algoritmos: Evaluación 02 ===" << std::endl;
    std::cout << std::endl << "Profesor: Sebastián Salazar M.\n";
    std::cout << std::endl << "Integrantes: ";
    std::cout << std::endl << "Edgar Matus";
    std::cout << std::endl << "Óscar Peñaloza";
    std::cout << std::endl << "Daniela Galleguillos" << std::endl;
}

int countFileLines(std::istream &File) {
    int LinesCounter = 0;
    for (std::string l; getline(File, l); LinesCounter++) {
    }
    return LinesCounter;
}

int *getScores(const std::string& Line) {
    int *Scores = new int[8], i = 0;
    std::stringstream SS(Line);
    std::string Item;
    while (getline(SS, Item, ';')) {
        const int Numeric = atoi(Item.c_str());
        Scores[i] = Numeric;
        i++;
    }
    Scores[6] = 0; // historia -> mejor ponderacion
    Scores[7] = 0; // <- código carrera
    return Scores;
}

double weighScoresByCareer(const int *Scores, const Carrera &Option) {
    return static_cast<float>(Scores[1]) * Option.Ponderaciones[0] +
           static_cast<float>(Scores[2]) * Option.Ponderaciones[1] +
           static_cast<float>(Scores[3]) * Option.Ponderaciones[3] +
           static_cast<float>(Scores[4]) * Option.Ponderaciones[2] +
           static_cast<float>(Scores[5]) * Option.Ponderaciones[4];
}

OfertaUniversitaria getAcademicOffer(int **Scores, std::istream &File) {
    OfertaUniversitaria AcademicOffer = {"Universidad Tecnológica Metropolitana (UTEM)", new Carrera[28], 28, true};
    AcademicOffer.Oferta[0] = {
        "Ing. en Biotecnologia", 21073, {0.15, 0.25, 0.20, 0.30, 0.10}, 60, 675.8, 540.9, new int *[60], true
    };
    AcademicOffer.Oferta[1] = {
        "Ing. Civil en Ciencia de Datos", 21049, {0.10, 0.25, 0.20, 0.35, 0.10}, 60, 673.65, 539.35, new int *[60], true
    };
    AcademicOffer.Oferta[2] = {
        "Ing. Civil en Computacion", 21041, {0.10, 0.25, 0.20, 0.35, 0.10}, 130, 673.65, 539.35, new int *[130], true
    };
    AcademicOffer.Oferta[3] = {"Arquitectura", 21047, {0.15, 0.25, 0.20, 0.20, 0.20}, 100, 640.2, 527.4, new int *[100], true};
    AcademicOffer.Oferta[4] = {
        "Administracion Publica", 21089, {0.15, 0.20, 0.30, 0.25, 0.10}, 35, 625.8, 513, new int *[35], true
    };
    AcademicOffer.Oferta[5] = {"Trabajo Social", 21043, {0.20, 0.30, 0.20, 0.10, 0.20}, 95, 705.9, 510.5, new int *[95], true};
    AcademicOffer.Oferta[6] = {
        "Ing. Informatica", 21030, {0.10, 0.25, 0.20, 0.35, 0.10}, 105, 705.15, 507.75, new int *[105], true
    };
    AcademicOffer.Oferta[7] = {
        "Ing. Civil Mecanica", 21096, {0.10, 0.25, 0.20, 0.35, 0.10}, 90, 697.65, 506.8, new int *[90], true
    };
    AcademicOffer.Oferta[8] = {"Ing. Bachillerato", 21046, {0.10, 0.25, 0.20, 0.35, 0.10}, 25, 586.45, 504.25, new int *[25], true};
    AcademicOffer.Oferta[9] = {
        "Ing. Civil Industrial", 21076, {0.10, 0.25, 0.20, 0.35, 0.10}, 200, 671.25, 500.85, new int *[200], true
    };
    AcademicOffer.Oferta[10] = {
        "Ing. Civil Electronica", 21075, {0.10, 0.25, 0.20, 0.35, 0.10}, 80, 657.35, 500.65, new int *[80], true
    };
    AcademicOffer.Oferta[11] = {"Ing. Comercial", 21048, {0.10, 0.20, 0.30, 0.30, 0.10}, 125, 652.9, 496.9, new int *[125], true};
    AcademicOffer.Oferta[12] = {
        "Dibujante Proyectista", 21071, {0.10, 0.25, 0.20, 0.35, 0.10}, 25, 689.85, 496.45, new int *[25], true
    };
    AcademicOffer.Oferta[13] = {"Ing. Geomensura", 21031, {0.10, 0.25, 0.20, 0.35, 0.10}, 60, 614.3, 487.85, new int *[60], true};
    AcademicOffer.Oferta[14] = {
        "Ing. Construccion", 21032, {0.20, 0.20, 0.15, 0.35, 0.10}, 100, 716.3, 476.95, new int *[100], true
    };
    AcademicOffer.Oferta[15] = {"Ing. Industrial", 21045, {0.10, 0.25, 0.20, 0.35, 0.10}, 60, 584.75, 476.25, new int *[60], true};
    AcademicOffer.Oferta[16] = {
        "Ing. Civil Obras Civiles", 21074, {0.20, 0.20, 0.15, 0.35, 0.10}, 100, 625, 476.1, new int *[100], true
    };
    AcademicOffer.Oferta[17] = {"Quimica Industrial", 21083, {0.10, 0.25, 0.15, 0.30, 0.20}, 40, 596.05, 472, new int *[40], true};
    AcademicOffer.Oferta[18] = {
        "Ing. Industria Alimentaria", 21039, {0.15, 0.25, 0.20, 0.30, 0.10}, 30, 680.2, 464.9, new int *[30], true
    };
    AcademicOffer.Oferta[19] = {
        "Ing. Civil Prevencion de Riesgos Y Medioambiente", 21087, {0.15, 0.35, 0.20, 0.20, 0.10}, 30, 615.2, 462.85,
        new int *[30], true
    };
    AcademicOffer.Oferta[20] = {
        "Ing. Administracion Agroindustrial", 21015, {0.10, 0.20, 0.30, 0.30, 0.10}, 30, 628.8, 461.8, new int *[30],
        true
    };
    AcademicOffer.Oferta[21] = {
        "Ing. Comercio Internacional", 21081, {0.10, 0.20, 0.30, 0.30, 0.10}, 90, 637.2, 458.8, new int *[90], true
    };
    AcademicOffer.Oferta[22] = {
        "Biotecnologia y Documentacion", 21002, {0.20, 0.20, 0.40, 0.10, 0.10}, 35, 675.3, 453.6, new int *[35], true
    };
    AcademicOffer.Oferta[23] = {
        "Contador Publico Auditor", 21012, {0.20, 0.20, 0.30, 0.15, 0.15}, 80, 635.55, 452.2, new int *[80], true
    };
    AcademicOffer.Oferta[24] = {"Ing. Quimica", 21080, {0.10, 0.25, 0.15, 0.30, 0.20}, 80, 606.55, 451.7, new int *[80], true};
    AcademicOffer.Oferta[25] = {
        "Ing. Gestion Turistica", 21082, {0.10, 0.20, 0.30, 0.30, 0.10}, 25, 659.4, 448.1, new int *[25], true
    };
    AcademicOffer.Oferta[26] = {
        "Diseno Comunicacion Audiovisual", 21024, {0.10, 0.40, 0.30, 0.10, 0.10}, 100, 706.3, 440.2, new int *[100],
        true
    };
    AcademicOffer.Oferta[27] = {"Diseno Industrial", 21023, {0.10, 0.40, 0.30, 0.10, 0.10}, 65, 642.2, 439.9, new int *[65], true};

    int i = 0;
    const int CareerCount = AcademicOffer.CantidadCarreras;

    for (std::string Line; std::getline(File, Line); i++) {
        double BestCaseWeighted = 0.0;

        int *Score = getScores(Line);

        Scores[i] = Score;

        /*
         ***************** Def. Valores *****************
            ponderados[i] = new int[8];
            ponderados[i][0] = puntajes[0]; <-> rut
            ponderados[i][1] = puntajes[1]; <-> NEM
            ponderados[i][2] = puntajes[2]; <-> ranking
            ponderados[i][3] = puntajes[3]; <-> matematica
            ponderados[i][4] = puntajes[4]; <-> lenguaje
            ponderados[i][5] = puntajes[5]; <-> ciencias
            ponderados[i][6] = 0; <-> mejor ponderación
            ponderados[i][7] = 0; <-> código carrera
        */

        for (int j = 0; j < CareerCount; j++) {
            if ((Score[3] + Score[4]) / (double) 2.0 >= 450.0) {
                const double Weighted = weighScoresByCareer(Score, AcademicOffer.Oferta[j]);

                // ¿
                //  if (Scores[i][0] == 17672369)
                //  std::cout << ponderacion << ";" << AcademicOffer.Oferta[j].Nombre << std::endl;
                // ?

                if (Weighted > AcademicOffer.Oferta[j].Ultimo && Weighted > BestCaseWeighted) {
                    BestCaseWeighted = Weighted;
                    Scores[i][6] = static_cast<int>(round(Weighted));
                    Scores[i][7] = AcademicOffer.Oferta[j].Codigo;
                }
            }
        }
    }

    for (int i = 0; i < CareerCount; i++) {
        for (int j = 0; j < AcademicOffer.Oferta[i].Vacantes; j++) {
            AcademicOffer.Oferta[i].Mechones[j] = new int[2];
            AcademicOffer.Oferta[i].Mechones[j][0] = 0;
            AcademicOffer.Oferta[i].Mechones[j][1] = 0;
        }
    }
    return AcademicOffer;
}


bool getGlobalAvailability(const Carrera *Options) {
    return !(Options[0].Disponibilidad == false &&
             Options[1].Disponibilidad == false &&
             Options[2].Disponibilidad == false &&
             Options[3].Disponibilidad == false &&
             Options[4].Disponibilidad == false &&
             Options[5].Disponibilidad == false &&
             Options[6].Disponibilidad == false &&
             Options[7].Disponibilidad == false &&
             Options[8].Disponibilidad == false &&
             Options[9].Disponibilidad == false &&
             Options[10].Disponibilidad == false &&
             Options[11].Disponibilidad == false &&
             Options[12].Disponibilidad == false &&
             Options[13].Disponibilidad == false &&
             Options[14].Disponibilidad == false &&
             Options[15].Disponibilidad == false &&
             Options[16].Disponibilidad == false &&
             Options[17].Disponibilidad == false &&
             Options[18].Disponibilidad == false &&
             Options[19].Disponibilidad == false &&
             Options[20].Disponibilidad == false &&
             Options[21].Disponibilidad == false &&
             Options[22].Disponibilidad == false &&
             Options[23].Disponibilidad == false &&
             Options[24].Disponibilidad == false &&
             Options[25].Disponibilidad == false &&
             Options[26].Disponibilidad == false &&
             Options[27].Disponibilidad == false);
}

void store(const int *Postulants, Carrera *Options, const int Index) {
    for (int i = 0; i < Options[Index].Vacantes; i++) {
        if (Options[Index].Mechones[i][0] == 0) {
            Options[Index].Mechones[i][0] = Postulants[0]; // <- rut
            Options[Index].Mechones[i][1] = Postulants[6]; // <- ponderacion

            if (i == Options[Index].Vacantes - 1) {
                Options[Index].Disponibilidad = false;
                heapSort(Options[Index].Mechones, Options[Index].Vacantes, 1);
            }
            break;
        }
    }
}

void postulate(OfertaUniversitaria U, int **WeightedScores, const int StudentsCount) {
    const int CareerCount = U.CantidadCarreras;

    for (int i = 0; i < StudentsCount; i++) {
        U.DisponibilidadCupos = getGlobalAvailability(U.Oferta);

        if (U.DisponibilidadCupos == true) {
            int *Postulant = WeightedScores[i];

            for (int j = 0; j < CareerCount; j++) {
                if (Postulant[7] == U.Oferta[j].Codigo) {
                    if (U.Oferta[j].Disponibilidad == true) {
                        store(Postulant, U.Oferta, j);
                    } else {
                        double SecondBestWeightedScore = 0;
                        int Position = 0;

                        for (int k = 0; k < CareerCount; k++) {
                            if (U.Oferta[k].Disponibilidad == true) {
                                double SecondWeighted = weighScoresByCareer(Postulant, U.Oferta[k]);

                                if (SecondWeighted >= SecondBestWeightedScore) {
                                    Position = k;
                                    SecondBestWeightedScore = SecondWeighted;
                                }
                            }
                        }

                        Postulant[6] = static_cast<int>(round(SecondBestWeightedScore));
                        store(Postulant, U.Oferta, Position);
                    }
                }
            }
        } else break;
    }
}

void write(OfertaUniversitaria U, const std::string &Path) {
    std::ofstream OutputStream;

    for (int i = 0; i < U.CantidadCarreras; i++) {
        std::string CareerCode = std::to_string(U.Oferta[i].Codigo);

        OutputStream.open((Path + "/").append(CareerCode) + ".txt");

        if (OutputStream.is_open()) {
            for (int j = 0; j < U.Oferta[i].Vacantes; j++) {
                OutputStream << std::to_string(U.Oferta[i].Mechones[j][0]) + ";" +
                        std::to_string(U.Oferta[i].Mechones[j][1]) << std::endl;
            }

            OutputStream.close();
        }
    }
}

std::string search(const std::string& Path, const std::string& Rut) {
    std::ifstream InputStream;

    std::string SearchMessage = "\nNo se ha encontrado el estudiante del rut ingresado.";

    bool ResultExists = false;

    const char *FileNames[28] = {
        "21073.txt", "21049.txt", "21041.txt", "21047.txt", "21089.txt", "21043.txt", "21030.txt",
        "21096.txt", "21046.txt", "21076.txt", "21075.txt", "21048.txt", "21071.txt", "21031.txt",
        "21032.txt", "21045.txt", "21074.txt", "21083.txt", "21039.txt", "21087.txt", "21015.txt",
        "21081.txt", "21002.txt", "21012.txt", "21080.txt", "21082.txt", "21024.txt", "21023.txt"
    };

    // const int FilesCount = sizeof(FileNames) / sizeof(FileNames[0]);

    for (auto & FileName : FileNames) {
        InputStream.open(Path + "/" + FileName);

        if (InputStream.is_open()) {
            if (ResultExists == false) {
                ResultExists = true;
            }

            int j = 0;

            for (std::string Line; std::getline(InputStream, Line); j++) {
                int k = 0;
                std::string aux[2], item;
                std::stringstream ss(Line);

                while (getline(ss, item, ';')) {
                    aux[k] = item.c_str();
                    k++;
                }

                if (Rut == aux[0]) {
                    SearchMessage = "\nEstudiante encontrado en la linea " + std::to_string(j + 1) + " del archivo " +
                               FileName;

                    InputStream.close();

                    break;
                }
            }
        }

        InputStream.close();
    }

    if (ResultExists == false) {
        SearchMessage = "\nNo se ha encontrado ningun archivo en la ruta especificada.";
    }

    return SearchMessage;
}
