#include <iostream>
#include <vector>
#include <string>

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

    // Añadir materias
    estudiante1.materias.push_back({"Matemáticas"});
    estudiante1.materias.push_back({"Ciencias"});
    estudiante1.materias.push_back({"Historia"});

    // Mostrar la información del estudiante, incluyendo las materias
    mostrarEstudiante(estudiante1);

    return 0;
}
