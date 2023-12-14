#include <iostream>
#include <string>
#include <vector>

class Asistencia {
public:
    Asistencia(const std::string& fecha, const std::string& materia, const std::string& estado)
            : fecha(fecha), materia(materia), estado(estado) {}

    void mostrar() const {
        std::cout << "Fecha: " << fecha << "\nMateria: " << materia << "\nEstado: " << estado << '\n';
    }

private:
    std::string fecha, materia, estado;
};

struct Materia { std::string nombre; };

struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<Materia> materias;
    std::vector<Asistencia> asistencias;

    Estudiante(const std::string& n, int e, float p) : nombre(n), edad(e), promedio(p) {}

    void agregarMateria(const std::string& nombreMateria) {
        materias.push_back({nombreMateria});
    }

    void registrarAsistencia(const std::string& fecha, const std::string& materia, const std::string& estado) {
        asistencias.push_back({fecha, materia, estado});
    }

    void mostrar() const {
        std::cout << "Nombre: " << nombre << "\nEdad: " << edad << "\nPromedio: " << promedio << "\n\nMaterias:\n";
        for (const Materia& m : materias) std::cout << "  - " << m.nombre << '\n';

        std::cout << "\nAsistencias:\n";
        for (const Asistencia& a : asistencias) { a.mostrar(); std::cout << '\n'; }
    }
};

int main() {
    Estudiante estudiante1("Juan", 20, 8.5);
    estudiante1.agregarMateria("Matemáticas");
    estudiante1.agregarMateria("Ciencias");
    estudiante1.agregarMateria("Historia");
    estudiante1.registrarAsistencia("2023-01-01", "Matemáticas", "Asistió");
    estudiante1.registrarAsistencia("2023-01-02", "Ciencias", "Falta");
    estudiante1.mostrar();

    return 0;
}
