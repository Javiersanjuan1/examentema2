#include <iostream>
#include <string>

// Definición de la
struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
};

int main() {
    // Crear una instancia de la estructura Estudiante
    Estudiante estudiante1;

    // Asignar valores a los campos
    estudiante1.nombre = "Juan";
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;

    // Imprimir la información del estudiante
    std::cout << "Nombre: " << estudiante1.nombre << std::endl;
    std::cout << "Edad: " << estudiante1.edad << std::endl;
    std::cout << "Promedio: " << estudiante1.promedio << std::endl;

    return 0;
}
