#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Materia {
    std::string nombre;
};

struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<Materia> materias;
};

void agregarMateria(Estudiante& estudiante, const std::string& nombreMateria) {
    estudiante.materias.push_back({nombreMateria});
}

void eliminarMateria(Estudiante& estudiante, const std::string& nombreMateria) {
    auto it = std::remove_if(estudiante.materias.begin(), estudiante.materias.end(),
                             [&](const Materia& materia) {
                                 return materia.nombre == nombreMateria;
                             });

    estudiante.materias.erase(it, estudiante.materias.end());
}

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

    agregarMateria(estudiante1, "Matemáticas");
    agregarMateria(estudiante1, "Ciencias");
    agregarMateria(estudiante1, "Historia");

    mostrarEstudiante(estudiante1);

    eliminarMateria(estudiante1, "Ciencias");

    mostrarEstudiante(estudiante1);

    return 0;
}
