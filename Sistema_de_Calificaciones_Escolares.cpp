#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombreAlumno;
    int edad = 0;
    float calificacion1 = 0.0f;
    float calificacion2 = 0.0f;
    float calificacion3 = 0.0f;
    float promedio = 0.0f;

    cout << "Sistema de Calificaciones Escolares" << endl;
    cout << "Ingresa el nombre del alumno: ";
    getline(cin, nombreAlumno);

    cout << "Ingresa la edad del alumno: ";
    cin >> edad;

    cout << "Ingresa la primera calificacion: ";
    cin >> calificacion1;

    cout << "Ingresa la segunda calificacion: ";
    cin >> calificacion2;

    cout << "Ingresa la tercera calificacion: ";
    cin >> calificacion3;

    promedio = (calificacion1 + calificacion2 + calificacion3) / 3.0f;

    cout << "\nAlumno: " << nombreAlumno << endl;
    cout << "Edad: " << edad << endl;
    cout << "Promedio: " << promedio << endl;

    return 0;
}
