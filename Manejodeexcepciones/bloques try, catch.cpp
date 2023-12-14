#include <iostream>
#include <string>

enum ErrorCode {
    NO_ERROR,
    LIMITE_MATERIAS_ALCANZADO,
    LIMITE_ASISTENCIAS_ALCANZADO
};

struct Result {
    ErrorCode error;

    // Constructor para el caso de éxito (sin error)
    Result() : error(NO_ERROR) {}

    // Constructor para el caso de error
    Result(ErrorCode err) : error(err) {}
};

// Resto del código...

int main() {
    Estudiante estudiante1;
    estudiante1.nombre = "Juan";
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;

    try {
        // Agregar materias y manejar errores
        Result resultadoMateria = estudiante1.agregarMateria("Matemáticas");
        if (resultadoMateria.error == LIMITE_MATERIAS_ALCANZADO) {
            throw std::runtime_error("Error: Límite de materias alcanzado.");
        }

        // Registrar asistencias y manejar errores
        Result resultadoAsistencia1 = estudiante1.registrarAsistencia("2023-01-01", "Matemáticas", "Asistió");
        Result resultadoAsistencia2 = estudiante1.registrarAsistencia("2023-01-02", "Ciencias", "Falta");

        if (resultadoAsistencia1.error == LIMITE_ASISTENCIAS_ALCANZADO) {
            throw std::runtime_error("Error: Límite de asistencias alcanzado.");
        }

        // Resto del código...

        // Mostrar la información del estudiante
        estudiante1.mostrarInformacion();
    } catch (const std::exception& e) {
        std::cerr << "Excepción atrapada: " << e.what() << std::endl;
    }

    return 0;
}


