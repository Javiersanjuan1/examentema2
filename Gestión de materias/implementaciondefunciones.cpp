#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Definición de la estructura Materia
struct Materia {
    std::string nombre;
    // Puedes agregar más información sobre la materia según sea necesario
};

// Definición de la estructura Estudiante
struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<Materia> materias;  // Lista de materias
};

// Función para agregar una materia a un estudiante
void agregarMateria(Estudiante& estudiante, const std::string& nombreMateria) {
    estudiante.materias.push_back({nombreMateria});
}

// Función para eliminar una materia de un estudiante
void eliminarMateria(Estudiante& estudiante, const std::string& nombreMateria) {
    auto it = std::remove_if(estudiante.materias.begin(), estudiante.materias.end(),
                             [&](const Materia& materia) {
                                 return materia.nombre == nombreMateria;
                             });

    estudiante.materias.erase(it, estudiante.materias.end());
}

// Función para mostrar la información de un estudiante, incluyendo las materias
void mostrarEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Edad: " << estudiante.edad << std::endl;
    std::cout << "Promedio: " << estudiante.promedio << std::endl;

    // Mostrar las materias
    std::cout << "Materias:" << std::endl;
    for (const Materia& materia : estudiante.materias) {
        std::cout << "  - " << materia.nombre << std::endl;
    }
}

int main() {
    // Crear una instancia de la estructura Estudiante
    Estudiante estudiante1;

    // Asignar valores a los campos
    estudiante1.nombre = "Juan";
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;

    // Agregar materias
    agregarMateria(estudiante1, "Matemáticas");
    agregarMateria(estudiante1, "Ciencias");
    agregarMateria(estudiante1, "Historia");

    // Mostrar la información del estudiante, incluyendo las materias
    mostrarEstudiante(estudiante1);

    // Eliminar una materia
    eliminarMateria(estudiante1, "Ciencias");

    // Mostrar la información actualizada del estudiante
    mostrarEstudiante(estudiante1);

    return 0;
}
