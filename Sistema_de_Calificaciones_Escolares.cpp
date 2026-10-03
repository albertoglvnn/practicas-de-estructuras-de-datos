#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Prototipos de funciones
void mostrarMenu();
int leerEntero(string mensaje, int min, int max);
float leerCalificacion(int numero);
float calcularPromedio(float suma, int n);
string obtenerEstado(float promedio);
void registrarEstudiante();

int main() {
    int opcion = 0;

    do {
        mostrarMenu();
        opcion = leerEntero("Opcion: ", 1, 3);

        switch (opcion) {
            case 1:
                registrarEstudiante();
                break;

            case 2:
                cout << "\nEste programa permite registrar los datos y calificaciones de un estudiante," << endl;
                cout << "calcular su promedio y determinar su estado academico." << endl;
                break;

            case 3:
                cout << "\nSaliendo del programa..." << endl;
                break;
        }

    } while (opcion != 3);

    return 0;
}

// Definicion de funciones

void mostrarMenu() {
    cout << "\n=== SISTEMA DE CALIFICACIONES ===" << endl;
    cout << "1. Registrar estudiante" << endl;
    cout << "2. Ver informacion del programa" << endl;
    cout << "3. Salir" << endl;
}

int leerEntero(string mensaje, int min, int max) {
    int numero;

    cout << mensaje;
    cin >> numero;

    while (cin.fail() || numero < min || numero > max) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Valor invalido. Ingresa un numero entre "
             << min << " y " << max << ": ";
        cin >> numero;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return numero;
}

float leerCalificacion(int numero) {
    float calificacion;

    cout << "Ingresa la calificacion " << numero << ": ";
    cin >> calificacion;

    while (cin.fail() || calificacion < 0 || calificacion > 10) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Calificacion invalida. Ingresa una calificacion entre 0 y 10: ";
        cin >> calificacion;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return calificacion;
}

float calcularPromedio(float suma, int n) {
    return suma / n;
}

string obtenerEstado(float promedio) {
    if (promedio >= 9) {
        return "EXCELENTE";
    } else if (promedio >= 7) {
        return "APROBADO";
    } else if (promedio >= 6) {
        return "REGULAR (aprobado con lo minimo)";
    } else {
        return "REPROBADO";
    }
}

void registrarEstudiante() {
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

    edad = leerEntero("Ingresa la edad del alumno: ", 0, 120);

    cantidadCalificaciones = leerEntero(
        "Cuantas calificaciones deseas registrar? ", 1, 100
    );

    for (int i = 1; i <= cantidadCalificaciones; i++) {
        calificacion = leerCalificacion(i);

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

    promedio = calcularPromedio(sumaCalificaciones, cantidadCalificaciones);
    estado = obtenerEstado(promedio);

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
}
