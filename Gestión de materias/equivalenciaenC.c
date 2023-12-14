#include <stdio.h>
#include <string.h>

struct Materia {
    char nombre[50];
};

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    struct Materia materias[10];
    int numMaterias;
};

void agregarMateria(struct Estudiante* estudiante, const char* nombreMateria) {
    if (estudiante->numMaterias < 10) {
        strcpy(estudiante->materias[estudiante->numMaterias].nombre, nombreMateria);
        estudiante->numMaterias++;
    } else {
        printf("No se pueden agregar más materias. Límite alcanzado.\n");
    }
}

void eliminarMateria(struct Estudiante* estudiante, const char* nombreMateria) {
    int i;
    for (i = 0; i < estudiante->numMaterias; ++i) {
        if (strcmp(estudiante->materias[i].nombre, nombreMateria) == 0) {
            for (int j = i; j < estudiante->numMaterias - 1; ++j) {
                estudiante->materias[j] = estudiante->materias[j + 1];
            }
            estudiante->numMaterias--;
            return;
        }
    }

    printf("Materia no encontrada: %s\n", nombreMateria);
}

void mostrarEstudiante(const struct Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);

    printf("Materias:\n");
    for (int i = 0; i < estudiante->numMaterias; ++i) {
        printf("  - %s\n", estudiante->materias[i].nombre);
    }
}

int main() {
    struct Estudiante estudiante1 = {"Juan", 20, 8.5, {}, 0};

    agregarMateria(&estudiante1, "Matemáticas");
    agregarMateria(&estudiante1, "Ciencias");
    agregarMateria(&estudiante1, "Historia");

    mostrarEstudiante(&estudiante1);

    eliminarMateria(&estudiante1, "Ciencias");

    mostrarEstudiante(&estudiante1);

    return 0;
}
