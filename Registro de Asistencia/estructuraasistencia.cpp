#include <iostream>
#include <string>

// Definición de la clase Asistencia
class Asistencia {
public:
    // Constructor
    Asistencia(const std::string& fecha, const std::string& materia, const std::string& estado)
            : fecha(fecha), materia(materia), estado(estado) {}

    // Función para mostrar la información de la asistencia
    void mostrarAsistencia() const {
        std::cout << "Fecha: " << fecha << std::endl;
        std::cout << "Materia: " << materia << std::endl;
        std::cout << "Estado: " << estado << std::endl;
    }

private:
    std::string fecha;
    std::string materia;
    std::string estado;
};

int main() {
    // Crear una instancia de la clase Asistencia
    Asistencia asistencia1("2023-01-01", "Matemáticas", "Asistió");

    // Mostrar la información de la asistencia
    asistencia1.mostrarAsistencia();

    return 0;
}
