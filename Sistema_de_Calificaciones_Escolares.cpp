#include <iostream>
#include <string>

using namespace std;

int main() {
    int opcion = 0;

    cout << "=== SISTEMA DE CALIFICACIONES ===" << endl;
    cout << "1. Registrar estudiante" << endl;
    cout << "2. Ver informacion del programa" << endl;
    cout << "3. Salir" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
        case 1: {
            string nombreAlumno;
            string estado;
            int edad = 0;
            float calificacion1 = 0.0f;
            float calificacion2 = 0.0f;
            float calificacion3 = 0.0f;
            float promedio = 0.0f;

            cout << "\nIngresa el nombre del alumno: ";
            getline(cin, nombreAlumno);

            cout << "Ingresa la edad del alumno: ";
            cin >> edad;

            if (edad < 0 || edad > 120) {
                cout << "Edad invalida" << endl;
                return 1;
            }

            cout << "Ingresa la primera calificacion: ";
            cin >> calificacion1;

            cout << "Ingresa la segunda calificacion: ";
            cin >> calificacion2;

            cout << "Ingresa la tercera calificacion: ";
            cin >> calificacion3;

            if (calificacion1 < 0 || calificacion1 > 10 ||
                calificacion2 < 0 || calificacion2 > 10 ||
                calificacion3 < 0 || calificacion3 > 10) {
                cout << "Error: las calificaciones deben estar entre 0 y 10." << endl;
                return 1;
            }

            promedio = (calificacion1 + calificacion2 + calificacion3) / 3.0f;

            if (promedio >= 9) {
                estado = "EXCELENTE";
            } else if (promedio >= 7) {
                estado = "APROBADO";
            } else if (promedio >= 6) {
                estado = "REGULAR (aprobado con lo minimo)";
            } else {
                estado = "REPROBADO";
            }

            cout << "\nResumen del estudiante" << endl;
            cout << "Nombre: " << nombreAlumno << endl;
            cout << "Edad: " << edad << endl;
            cout << "Calificacion 1: " << calificacion1 << endl;
            cout << "Calificacion 2: " << calificacion2 << endl;
            cout << "Calificacion 3: " << calificacion3 << endl;
            cout << "Promedio: " << promedio << endl;
            cout << "Estado: " << estado << endl;
            break;
        }

        case 2:
            cout << "\nEste programa permite registrar los datos y calificaciones de un estudiante," << endl;
            cout << "calcular su promedio y determinar su estado academico." << endl;
            break;

        case 3:
            cout << "\nSaliendo del programa..." << endl;
            break;

        default:
            cout << "\nOpcion invalida." << endl;
    }

    return 0;
}
