#include <iostream>
#include <string>

class Asistencia {
public:
    Asistencia(const std::string& fecha, const std::string& materia, const std::string& estado)
            : fecha(fecha), materia(materia), estado(estado) {}

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
    Asistencia asistencia1("2023-01-01", "Matemáticas", "Asistió");

    asistencia1.mostrarAsistencia();

    return 0;
}
