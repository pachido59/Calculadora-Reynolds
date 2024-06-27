#ifndef CALCULOS_H
#define CALCULOS_H

void calcularDensidad(float* P, float sg);
void calcularArea(float* A, float D);
void calcularVelocidad(float* Vel, float NR, float P, float D, float n);
void calcularDiametro(float* D, float A);
void calcularReynolds(float* NR, float P, float Vel, float D, float n);
void calcularFlujoVolumetrico(float* Q, float Vel, float A);

#endif // CALCULOS_H
