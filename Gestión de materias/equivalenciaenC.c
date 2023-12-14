#include <stdio.h>
#include <string.h>

// Definición de la estructura Materia
struct Materia {
    char nombre[50];  // Usamos un array de caracteres para el nombre
    // Puedes agregar más información sobre la materia según sea necesario
};

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    struct Materia materias[10];  // Array de materias
    int numMaterias;  // Número actual de materias
};

// Función para agregar una materia a un estudiante
void agregarMateria(struct Estudiante* estudiante, const char* nombreMateria) {
    if (estudiante->numMaterias < 10) {
        strcpy(estudiante->materias[estudiante->numMaterias].nombre, nombreMateria);
        estudiante->numMaterias++;
    } else {
        printf("No se pueden agregar más materias. Límite alcanzado.\n");
    }
}

// Función para eliminar una materia de un estudiante
void eliminarMateria(struct Estudiante* estudiante, const char* nombreMateria) {
    int i;
    for (i = 0; i < estudiante->numMaterias; ++i) {
        if (strcmp(estudiante->materias[i].nombre, nombreMateria) == 0) {
            // Eliminar la materia moviendo las materias restantes
            for (int j = i; j < estudiante->numMaterias - 1; ++j) {
                estudiante->materias[j] = estudiante->materias[j + 1];
            }
            estudiante->numMaterias--;
            return;
        }
    }

    printf("Materia no encontrada: %s\n", nombreMateria);
}

// Función para mostrar la información de un estudiante, incluyendo las materias
void mostrarEstudiante(const struct Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);

    // Mostrar las materias
    printf("Materias:\n");
    for (int i = 0; i < estudiante->numMaterias; ++i) {
        printf("  - %s\n", estudiante->materias[i].nombre);
    }
}

int main() {
    // Crear una instancia de la estructura Estudiante
    struct Estudiante estudiante1 = {"Juan", 20, 8.5, {}, 0};

    // Agregar materias
    agregarMateria(&estudiante1, "Matemáticas");
    agregarMateria(&estudiante1, "Ciencias");
    agregarMateria(&estudiante1, "Historia");

    // Mostrar la información del estudiante, incluyendo las materias
    mostrarEstudiante(&estudiante1);

    // Eliminar una materia
    eliminarMateria(&estudiante1, "Ciencias");

    // Mostrar la información actualizada del estudiante
    mostrarEstudiante(&estudiante1);

    return 0;
}
