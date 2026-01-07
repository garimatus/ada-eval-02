#ifndef ADA_EVAL_02_FUNCIONES_H
#define ADA_EVAL_02_FUNCIONES_H

#include "estructuras.h"
#include "iostream"

void displaySubjectInfo();

int countFileNewLines(std::istream &);

int *getScores(std::string);

OfertaUniversitaria getAcademicOffer(int **, std::istream &);

void heapSort(int **, int, int);

void postulate(OfertaUniversitaria, int **, int);

void write(OfertaUniversitaria, std::string);

std::string search(std::string, std::string);

#endif /* ADA_EVAL_02_FUNCIONES_H */

