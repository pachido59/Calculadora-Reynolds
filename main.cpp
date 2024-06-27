#include <iostream>
#include <iomanip>
#include "calculos.h"

int main() {
    int opcionSIS;
    int opcionFormato = 1; // 1 - Decimal, 2 - Cientifica

    // Variables dinamicas
    float* P = new float(0);
    float* sg = new float(0);
    float* Q = new float(0);
    float* A = new float(0);
    float* D = new float(0);
    float* n = new float(0);
    float* v = new float(0);
    float* NR = new float(0);
    float* Vel = new float(0);

    do {
        // Menu de sistema de unidades
        std::cout << "Seleccione su sistema de unidades\n";
        std::cout << "1- SI\n";
        std::cout << "2- Sistema ingles\n";
        std::cout << "3- Salir\n";
        std::cin >> opcionSIS;

        if (opcionSIS == 1) {
            int calculo;
            do {
                // Menu de nuestro programa
                int opcion = 0;
                std::cout << "Calculadora Reynolds\n";
                std::cout << "Seleccione una opcion\n";
                std::cout << "1 - Ingresar Valores\n";
                std::cout << "2 - Calcular\n";
                std::cout << "3 - Seleccionar formato de salida\n";
                std::cout << "4 - Volver al menu principal\n";
                std::cin >> opcion;

                switch(opcion) {
                    case 1:
                        std::cout << "Ingrese valor de Densidad (kg/m^3) (Ingrese 0 si desea calcularlo): ";
                        std::cin >> *P;
                        std::cout << "Ingrese valor de Gravedad especifica (Ingrese 0 si ya tiene Densidad): ";
                        std::cin >> *sg;
                        std::cout << "Ingrese valor de Flujo volumetrico (m^3/s) (Ingrese 0 si desea calcularlo): ";
                        std::cin >> *Q;
                        std::cout << "Ingrese valor de Area (m^2) (Ingrese 0 si desea calcularlo): ";
                        std::cin >> *A;
                        std::cout << "Ingrese valor de Diametro (m) (Ingrese 0 si desea calcularlo): ";
                        std::cin >> *D;
                        std::cout << "Ingrese valor de Viscosidad Dinamica (Pa·s): ";
                        std::cin >> *n;
                        std::cout << "Ingrese valor de Viscosidad Cinetica (m^2/s): ";
                        std::cin >> *v;
                        std::cout << "Ingrese valor de Velocidad de flujo (m/s) (Ingrese 0 si desea calcularlo): ";
                        std::cin >> *Vel;
                        std::cout << "Ingrese valor de Numero de Reynolds (Ingrese 0 si desea calcularlo): ";
                        std::cin >> *NR;

                        // Calcular variables si son 0
                        calcularDensidad(P, *sg);
                        calcularArea(A, *D);
                        calcularReynolds(NR, *P, *Vel, *D, *n);
                        calcularVelocidad(Vel, *NR, *P, *D, *n);
                        calcularFlujoVolumetrico(Q, *Vel, *A);
                        break;

                    case 2:
                        int opcionOP2;
                        std::cout << "Seleccione Variable a calcular\n";
                        std::cout << "1- NR\n2 - D\n3 - A\n4 - Q\n5 - Densidad a partir de Gravedad especifica\n";
                        std::cin >> opcionOP2;

                        switch(opcionOP2) {
                            case 1:
                                // Calcular NR
                                calcularReynolds(NR, *P, *Vel, *D, *n);
                                std::cout << std::fixed << std::setprecision(4);
                                if (opcionFormato == 1)
                                    std::cout << "El Numero de Reynolds es: " << *NR << "\n";
                                else
                                    std::cout << "El Numero de Reynolds es: " << std::scientific << *NR << "\n";
                                break;

                            case 2:
                                // Calcular D
                                *D = (*NR) * (*n) / ((*P) * (*Vel));
                                std::cout << std::fixed << std::setprecision(4);
                                if (opcionFormato == 1)
                                    std::cout << "El Diametro es: " << *D << "\n";
                                else
                                    std::cout << "El Diametro es: " << std::scientific << *D << "\n";
                                break;

                            case 3:
                                // Calcular A
                                calcularArea(A, *D);
                                std::cout << std::fixed << std::setprecision(4);
                                if (opcionFormato == 1)
                                    std::cout << "El Area es: " << *A << "\n";
                                else
                                    std::cout << "El Area es: " << std::scientific << *A << "\n";
                                break;

                            case 4:
                                // Calcular Q
                                calcularFlujoVolumetrico(Q, *Vel, *A);
                                std::cout << std::fixed << std::setprecision(4);
                                if (opcionFormato == 1)
                                    std::cout << "El Flujo volumetrico es: " << *Q << "\n";
                                else
                                    std::cout << "El Flujo volumetrico es: " << std::scientific << *Q << "\n";
                                break;

                            case 5:
                                // Calcular Densidad a partir de Gravedad especifica
                                calcularDensidad(P, *sg);
                                std::cout << std::fixed << std::setprecision(4);
                                if (opcionFormato == 1)
                                    std::cout << "La Densidad es: " << *P << " kg/m^3\n";
                                else
                                    std::cout << "La Densidad es: " << std::scientific << *P << " kg/m^3\n";
                                break;

                            default:
                                std::cout << "Seleccion invalida, intente de nuevo\n";
                                break;
                        }
                        break;

                    case 3:
                        // Seleccionar formato de salida
                        std::cout << "Seleccione el formato de salida\n";
                        std::cout << "1- Decimal\n";
                        std::cout << "2- Notacion cientifica\n";
                        std::cin >> opcionFormato;
                        break;

                    case 4:
                        // Volver al menu principal
                        break;

                    default:
                        std::cout << "Seleccion invalida, intente de nuevo\n";
                        break;
                }
                std::cout << "Desea hacer otro calculo?\n";
                std::cout << "1 - Si\n";
                std::cout << "2 - No\n";
                std::cin >> calculo;
            } while(calculo == 1);

        } else if (opcionSIS == 2) {
            // Sistema ingles (pendiente de implementacion)
            std::cout << "Funcionalidad para el sistema ingles no esta implementada aun.\n";
        } else if (opcionSIS != 3) {
            std::cout << "Seleccion invalida, intente de nuevo\n";
        }

    } while (opcionSIS != 3);

    // Liberar memoria dinamica
    delete P;
    delete sg;
    delete Q;
    delete A;
    delete D;
    delete n;
    delete v;
    delete NR;
    delete Vel;

    return 0;
}
