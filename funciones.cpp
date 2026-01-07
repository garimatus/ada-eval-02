#include <iostream>
#include <sstream>
#include <fstream>
#include "estructuras.h"
// #include <omp.h>

void displaySubjectInfo() {
    std::cout << std::endl << "=== Análisis de Algoritmos: Evaluación 02 ===" << std::endl;
    std::cout << std::endl << "Profesor: Sebastián Salazar M.\n";
    std::cout << std::endl << "Integrantes: ";
    std::cout << std::endl << "Edgar Matus";
    std::cout << std::endl << "Óscar Peñaloza";
    std::cout << std::endl << "Daniela Galleguillos" << std::endl;
}

int countFileNewLines(std::istream &file) {
    int LinesCount = 0;
    for (std::string l; getline(file, l); LinesCount++) {
    }
    return LinesCount;
}

int *getScores(const std::string& line) {
    int *scores = new int[8], i = 0;
    std::stringstream ss(line);
    std::string item;
    while (getline(ss, item, ';')) {
        int Valor = atoi(item.c_str());
        scores[i] = Valor;
        i++;
    }
    scores[6] = 0; // historia -> mejor ponderacion
    scores[7] = 0; // <- código carrera
    return scores;
}

double weighScoresByCareer(const int *scores, Carrera opcion) {
    return static_cast<float>(scores[1]) * opcion.Ponderaciones[0] +
           static_cast<float>(scores[2]) * opcion.Ponderaciones[1] +
           static_cast<float>(scores[3]) * opcion.Ponderaciones[3] +
           static_cast<float>(scores[4]) * opcion.Ponderaciones[2] +
           static_cast<float>(scores[5]) * opcion.Ponderaciones[4];
}

OfertaUniversitaria getAcademicOffer(int **ponderados, std::istream &archivo) {
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
    const int n = AcademicOffer.CantidadCarreras;

    for (std::string linea; std::getline(archivo, linea); i++) {
        double mejor = 0.0;

        int *puntajes = getScores(linea);

        ponderados[i] = puntajes;

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

        for (int j = 0; j < n; j++) {
            if ((puntajes[3] + puntajes[4]) / (double) 2.0 >= 450.0) {
                double ponderacion = weighScoresByCareer(puntajes, AcademicOffer.Oferta[j]);

                if (ponderados[i][0] == 17672369)
                    std::cout << ponderacion << ";" << AcademicOffer.Oferta[j].Nombre << std::endl;

                if (ponderacion > AcademicOffer.Oferta[j].Ultimo && ponderacion > mejor) {
                    mejor = ponderacion;
                    ponderados[i][6] = static_cast<int>(round(ponderacion));
                    ponderados[i][7] = AcademicOffer.Oferta[j].Codigo;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < AcademicOffer.Oferta[i].Vacantes; j++) {
            AcademicOffer.Oferta[i].Mechones[j] = new int[2];
            AcademicOffer.Oferta[i].Mechones[j][0] = 0;
            AcademicOffer.Oferta[i].Mechones[j][1] = 0;
        }
    }
    return AcademicOffer;
}

void heapify(int **arr, int n, int i, int index) {
    int smallest = i; // Initialize smallest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    // If left child is smaller than root
    if (l < n && arr[l][index] < arr[smallest][index])
        smallest = l;
    // If right child is smaller than smallest so far
    if (r < n && arr[r][index] < arr[smallest][index])
        smallest = r;
    // If smallest is not root
    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, smallest, index);
    }
}

void heapSort(int **arr, int n, int index) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, index);
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0, index);
    }
}

bool getGlobalAvailability(Carrera *opciones) {
    return !(opciones[0].Disponibilidad == false &&
             opciones[1].Disponibilidad == false &&
             opciones[2].Disponibilidad == false &&
             opciones[3].Disponibilidad == false &&
             opciones[4].Disponibilidad == false &&
             opciones[5].Disponibilidad == false &&
             opciones[6].Disponibilidad == false &&
             opciones[7].Disponibilidad == false &&
             opciones[8].Disponibilidad == false &&
             opciones[9].Disponibilidad == false &&
             opciones[10].Disponibilidad == false &&
             opciones[11].Disponibilidad == false &&
             opciones[12].Disponibilidad == false &&
             opciones[13].Disponibilidad == false &&
             opciones[14].Disponibilidad == false &&
             opciones[15].Disponibilidad == false &&
             opciones[16].Disponibilidad == false &&
             opciones[17].Disponibilidad == false &&
             opciones[18].Disponibilidad == false &&
             opciones[19].Disponibilidad == false &&
             opciones[20].Disponibilidad == false &&
             opciones[21].Disponibilidad == false &&
             opciones[22].Disponibilidad == false &&
             opciones[23].Disponibilidad == false &&
             opciones[24].Disponibilidad == false &&
             opciones[25].Disponibilidad == false &&
             opciones[26].Disponibilidad == false &&
             opciones[27].Disponibilidad == false);
}

void store(int *postulante, Carrera *opciones, int index) {
    for (int i = 0; i < opciones[index].Vacantes; i++) {
        if (opciones[index].Mechones[i][0] == 0) {
            opciones[index].Mechones[i][0] = postulante[0]; // <- rut
            opciones[index].Mechones[i][1] = postulante[6]; // <- ponderacion

            if (i == opciones[index].Vacantes - 1) {
                opciones[index].Disponibilidad = false;
                heapSort(opciones[index].Mechones, opciones[index].Vacantes, 1);
            }
            break;
        }
    }
}

void postulate(OfertaUniversitaria U, int **ponderados, const int students) {
    const int n = U.CantidadCarreras;

    for (int i = 0; i < students; i++) {
        U.DisponibilidadCupos = getGlobalAvailability(U.Oferta);

        if (U.DisponibilidadCupos == true) {
            int *postulante = ponderados[i];

            for (int j = 0; j < n; j++) {
                if (postulante[7] == U.Oferta[j].Codigo) {
                    if (U.Oferta[j].Disponibilidad == true) {
                        store(postulante, U.Oferta, j);
                    } else {
                        double mejor2 = 0;
                        int posicion = 0;

                        for (int k = 0; k < n; k++) {
                            if (U.Oferta[k].Disponibilidad == true) {
                                double ponderacion2 = weighScoresByCareer(postulante, U.Oferta[k]);

                                if (ponderacion2 >= mejor2) {
                                    posicion = k;
                                    mejor2 = ponderacion2;
                                }
                            }
                        }

                        postulante[6] = static_cast<int>(round(mejor2));
                        store(postulante, U.Oferta, posicion);
                    }
                }
            }
        } else {
            break;
        }
    }
}

void write(OfertaUniversitaria U, std::string ruta) {
    std::ofstream escritura;

    for (int i = 0; i < U.CantidadCarreras; i++) {
        std::string archivo = std::to_string(U.Oferta[i].Codigo);

        escritura.open(ruta + "/" + archivo + ".txt");

        if (escritura.is_open()) {
            for (int j = 0; j < U.Oferta[i].Vacantes; j++) {
                std::string salida = std::to_string(U.Oferta[i].Mechones[j][0]) + ";" + std::to_string(
                                         U.Oferta[i].Mechones[j][1]);
                escritura << salida << std::endl;
            }

            escritura.close();
        }
    }
}

std::string search(std::string ruta, std::string rut) {
    std::ifstream lectura;

    std::string busqueda = "\nNo se ha encontrado el estudiante del rut ingresado.";

    bool existen = false;

    const char *files[28] = {
        "21073.txt", "21049.txt", "21041.txt", "21047.txt", "21089.txt", "21043.txt", "21030.txt",
        "21096.txt", "21046.txt", "21076.txt", "21075.txt", "21048.txt", "21071.txt", "21031.txt",
        "21032.txt", "21045.txt", "21074.txt", "21083.txt", "21039.txt", "21087.txt", "21015.txt",
        "21081.txt", "21002.txt", "21012.txt", "21080.txt", "21082.txt", "21024.txt", "21023.txt"
    };

    int n = sizeof(files) / sizeof(files[0]);

    for (int i = 0; i < n; i++) {
        lectura.open(ruta + "/" + files[i]);

        if (lectura.is_open()) {
            if (existen == false) {
                existen = true;
            }

            int j = 0;

            for (std::string linea; std::getline(lectura, linea); j++) {
                int k = 0;
                std::string aux[2], item;
                std::stringstream ss(linea);

                while (getline(ss, item, ';')) {
                    aux[k] = item.c_str();
                    k++;
                }

                if (rut == aux[0]) {
                    busqueda = "\nEstudiante encontrado en la linea " + std::to_string(j + 1) + " del archivo " +
                               files[i];

                    lectura.close();

                    break;
                }
            }
        }

        lectura.close();
    }

    if (existen == false) {
        busqueda = "\nNo se ha encontrado ningun archivo en la ruta especificada.";
    }

    return busqueda;
}
