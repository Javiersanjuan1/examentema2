#include <stdio.h>
#include <string.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];  // Usamos un arreglo de caracteres para el nombre
    int edad;
    float promedio;
};

// Función para mostrar la información de un estudiante
void mostrarEstudiante(const struct Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);
}

int main() {
    // Crear una instancia de la estructura Estudiante
    struct Estudiante estudiante1;

    // Asignar valores a los campos
    strcpy(estudiante1.nombre, "Juan");
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;

    // Mostrar la información del estudiante
    mostrarEstudiante(&estudiante1);

    return 0;
}
