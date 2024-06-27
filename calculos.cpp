#include "calculos.h"
#include <cmath>

void calcularDensidad(float* P, float sg) {
    if (*P == 0 && sg != 0) {
        *P = sg * 1000; // Densidad del agua en kg/m^3 es aproximadamente 1000
    }
}

void calcularArea(float* A, float D) {
    if (*A == 0 && D != 0) {
        *A = M_PI * std::pow(D / 2, 2); // Área a partir del diámetro
    }
}

void calcularVelocidad(float* Vel, float NR, float P, float D, float n) {
    if (*Vel == 0 && NR != 0 && P != 0 && D != 0 && n != 0) {
        *Vel = NR * n / (P * D); // Velocidad a partir del Número de Reynolds
    }
}

void calcularDiametro(float* D, float A) {
    if (*D == 0 && A != 0) {
        *D = 2 * std::sqrt(A / M_PI); // Diámetro a partir del área
    }
}

void calcularReynolds(float* NR, float P, float Vel, float D, float n) {
    if (*NR == 0 && P != 0 && Vel != 0 && D != 0 && n != 0) {
        *NR = P * Vel * D / n; // Calcular NR
    }
}

void calcularFlujoVolumetrico(float* Q, float Vel, float A) {
    if (*Q == 0 && Vel != 0 && A != 0) {
        *Q = Vel * A; // Calcular flujo volumétrico
    }
}
