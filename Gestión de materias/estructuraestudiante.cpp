#include <iostream>
#include <vector>
#include <string>

struct Materia {
    std::string nombre;
};

struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<Materia> materias;
};

void mostrarEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Edad: " << estudiante.edad << std::endl;
    std::cout << "Promedio: " << estudiante.promedio << std::endl;

    std::cout << "Materias:" << std::endl;
    for (const Materia& materia : estudiante.materias) {
        std::cout << "  - " << materia.nombre << std::endl;
    }
}

int main() {
    Estudiante estudiante1;

    estudiante1.nombre = "Juan";
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;

    estudiante1.materias.push_back({"Matemáticas"});
    estudiante1.materias.push_back({"Ciencias"});
    estudiante1.materias.push_back({"Historia"});

    mostrarEstudiante(estudiante1);

    return 0;
}
