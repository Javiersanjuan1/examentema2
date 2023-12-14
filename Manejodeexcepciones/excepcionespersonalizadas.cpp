#include <iostream>
#include <string>

// Enumeración para códigos de error personalizados
enum ErrorCode {
    NO_ERROR,
    LIMITE_MATERIAS_ALCANZADO,
    LIMITE_ASISTENCIAS_ALCANZADO
};

// Estructura para representar un resultado que puede contener un código de error
struct Result {
    ErrorCode error;

    // Constructor para el caso de éxito (sin error)
    Result() : error(NO_ERROR) {}

    // Constructor para el caso de error
    Result(ErrorCode err) : error(err) {}
};

// Definición de la estructura Asistencia
struct Asistencia {
    std::string fecha;
    std::string materia;
    std::string estado;
};

// Definición de la estructura Materia
struct Materia {
    std::string nombre;
};

// Definición de la estructura Estudiante
struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    Materia materias[10];
    Asistencia asistencias[50];
    int numMaterias;
    int numAsistencias;

    // Función para agregar una materia al estudiante
    Result agregarMateria(const std::string& nombreMateria) {
        if (numMaterias < 10) {
            materias[numMaterias].nombre = nombreMateria;
            numMaterias++;
            return Result(NO_ERROR);
        } else {
            return Result(LIMITE_MATERIAS_ALCANZADO);
        }
    }

    // Función para registrar la asistencia
    Result registrarAsistencia(const std::string& fecha, const std::string& materia, const std::string& estado) {
        if (numAsistencias < 50) {
            asistencias[numAsistencias].fecha = fecha;
            asistencias[numAsistencias].materia = materia;
            asistencias[numAsistencias].estado = estado;
            numAsistencias++;
            return Result(NO_ERROR);
        } else {
            return Result(LIMITE_ASISTENCIAS_ALCANZADO);
        }
    }

    // Función para mostrar la información del estudiante, incluyendo asistencias
    void mostrarInformacion() const {
        std::cout << "Nombre: " << nombre << "\nEdad: " << edad << "\nPromedio: " << promedio << "\n\nMaterias:\n";
        for (int i = 0; i < numMaterias; ++i) {
            std::cout << "  - " << materias[i].nombre << '\n';
        }

        std::cout << "\nAsistencias:\n";
        for (int i = 0; i < numAsistencias; ++i) {
            std::cout << "Fecha: " << asistencias[i].fecha
                      << "\nMateria: " << asistencias[i].materia
                      << "\nEstado: " << asistencias[i].estado << "\n\n";
        }
    }
};

int main() {
    Estudiante estudiante1;
    estudiante1.nombre = "Juan";
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;

    // Agregar materias y manejar errores
    Result resultadoMateria = estudiante1.agregarMateria("Matemáticas");
    if (resultadoMateria.error == LIMITE_MATERIAS_ALCANZADO) {
        std::cout << "Error: Límite de materias alcanzado.\n";
    }

    // Registrar asistencias y manejar errores
    Result resultadoAsistencia1 = estudiante1.registrarAsistencia("2023-01-01", "Matemáticas", "Asistió");
    Result resultadoAsistencia2 = estudiante1.registrarAsistencia("2023-01-02", "Ciencias", "Falta");

    if (resultadoAsistencia1.error == LIMITE_ASISTENCIAS_ALCANZADO) {
        std::cout << "Error: Límite de asistencias alcanzado.\n";
    }

    // ...

    return 0;
}
