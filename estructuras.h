#ifndef ADA_EVAL_02_STRUCTS_H
#define ADA_EVAL_02_STRUCTS_H

struct Carrera {
  const char *Nombre;
  int Codigo;
  float Ponderaciones[5];
  int Vacantes;
  double Primero;
  double Ultimo;
  int **Mechones;
  bool Disponibilidad;
};

struct OfertaUniversitaria {
  const char *Name;
  Carrera *Oferta;
  int CantidadCarreras;
  bool DisponibilidadCupos;
};

#endif /* ADA_EVAL_02_STRUCTS_H */
