#ifndef ADA_EVAL_02_FUNCIONES_H
#define ADA_EVAL_02_FUNCIONES_H

#include "AdaEval02Structs.h"
#include "iostream"

void displaySubjectInfo();

int countFileLines(std::istream &);

int *getScores(std::string);

OfertaUniversitaria getAcademicOffer(int **, std::istream &);

void postulate(OfertaUniversitaria, int **, int);

void write(OfertaUniversitaria, const std::string&);

std::string search(const std::string&, const std::string&);

void heapify(int **arr, const int n, const int i, const int index);

void heapSort(int **arr, int n, int index);

#endif /* ADA_EVAL_02_FUNCIONES_H */

