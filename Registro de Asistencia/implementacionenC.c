#include <stdio.h>
#include <string.h>

// Definición de la estructura Asistencia
struct Asistencia {
    char fecha[11];  // formato YYYY-MM-DD
    char materia[50];
    char estado[20];
};

// Definición de la estructura Materia
struct Materia {
    char nombre[50];
};

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    struct Materia materias[10];
    struct Asistencia asistencias[50];
    int numMaterias;
    int numAsistencias;
};

// Función para agregar una materia al estudiante
void agregarMateria(struct Estudiante* estudiante, const char* nombreMateria) {
    if (estudiante->numMaterias < 10) {
        strcpy(estudiante->materias[estudiante->numMaterias].nombre, nombreMateria);
        estudiante->numMaterias++;
    } else {
        printf("No se pueden agregar más materias. Límite alcanzado.\n");
    }
}

// Función para registrar la asistencia
void registrarAsistencia(struct Estudiante* estudiante, const char* fecha, const char* materia, const char* estado) {
    if (estudiante->numAsistencias < 50) {
        strcpy(estudiante->asistencias[estudiante->numAsistencias].fecha, fecha);
        strcpy(estudiante->asistencias[estudiante->numAsistencias].materia, materia);
        strcpy(estudiante->asistencias[estudiante->numAsistencias].estado, estado);
        estudiante->numAsistencias++;
    } else {
        printf("No se pueden registrar más asistencias. Límite alcanzado.\n");
    }
}

// Función para mostrar la información del estudiante, incluyendo asistencias
void mostrarInformacion(const struct Estudiante* estudiante) {
    printf("Nombre: %s\nEdad: %d\nPromedio: %.2f\n\nMaterias:\n", estudiante->nombre, estudiante->edad, estudiante->promedio);
    for (int i = 0; i < estudiante->numMaterias; ++i) {
        printf("  - %s\n", estudiante->materias[i].nombre);
    }

    printf("\nAsistencias:\n");
    for (int i = 0; i < estudiante->numAsistencias; ++i) {
        printf("Fecha: %s\nMateria: %s\nEstado: %s\n\n",
               estudiante->asistencias[i].fecha,
               estudiante->asistencias[i].materia,
               estudiante->asistencias[i].estado);
    }
}

int main() {
    // Crear una instancia de la estructura Estudiante
    struct Estudiante estudiante1;
    strcpy(estudiante1.nombre, "Juan");
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;
    estudiante1.numMaterias = 0;
    estudiante1.numAsistencias = 0;

    // Agregar materias
    agregarMateria(&estudiante1, "Matemáticas");
    agregarMateria(&estudiante1, "Ciencias");
    agregarMateria(&estudiante1, "Historia");

    // Registrar asistencias
    registrarAsistencia(&estudiante1, "2023-01-01", "Matemáticas", "Asistió");
    registrarAsistencia(&estudiante1, "2023-01-02", "Ciencias", "Falta");

    // Mostrar la información del estudiante, incluyendo asistencias
    mostrarInformacion(&estudiante1);

    return 0;
}
