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
            int cantidadCalificaciones = 0;
            int aprobadas = 0;
            int reprobadas = 0;
            float calificacion = 0.0f;
            float sumaCalificaciones = 0.0f;
            float promedio = 0.0f;
            float calificacionMasAlta = 0.0f;
            float calificacionMasBaja = 0.0f;

            cout << "\nIngresa el nombre del alumno: ";
            getline(cin, nombreAlumno);

            cout << "Ingresa la edad del alumno: ";
            cin >> edad;

            if (edad < 0 || edad > 120) {
                cout << "Edad invalida" << endl;
                return 1;
            }

            cout << "Cuantas calificaciones deseas registrar? ";
            cin >> cantidadCalificaciones;

            if (cantidadCalificaciones <= 0) {
                cout << "Error: la cantidad de calificaciones debe ser mayor que cero." << endl;
                return 1;
            }

            for (int i = 1; i <= cantidadCalificaciones; i++) {
                cout << "Ingresa la calificacion " << i << ": ";
                cin >> calificacion;

                if (calificacion < 0 || calificacion > 10) {
                    cout << "Error: la calificacion debe estar entre 0 y 10." << endl;
                    return 1;
                }

                sumaCalificaciones += calificacion;

                if (calificacion >= 6) {
                    aprobadas++;
                } else {
                    reprobadas++;
                }

                if (i == 1) {
                    calificacionMasAlta = calificacion;
                    calificacionMasBaja = calificacion;
                } else {
                    if (calificacion > calificacionMasAlta) {
                        calificacionMasAlta = calificacion;
                    }

                    if (calificacion < calificacionMasBaja) {
                        calificacionMasBaja = calificacion;
                    }
                }
            }

            promedio = sumaCalificaciones / cantidadCalificaciones;

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
            cout << "Cantidad de calificaciones: " << cantidadCalificaciones << endl;
            cout << "Promedio: " << promedio << endl;
            cout << "Estado: " << estado << endl;
            cout << "Calificaciones aprobatorias: " << aprobadas << endl;
            cout << "Calificaciones reprobatorias: " << reprobadas << endl;
            cout << "Calificacion mas alta: " << calificacionMasAlta << endl;
            cout << "Calificacion mas baja: " << calificacionMasBaja << endl;
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
