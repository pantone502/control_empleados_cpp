// main.cpp
// Axel Dardon - Programacion 1
// Este es el archivo principal del proyecto
// Aqui me conecto a la base de datos y muestro los empleados
// use la clase MySQLConexion para conectarme y EloquentORM
// para traer los datos sin escribir SQL a mano

#include "MySQLConexion.h"
#include "EloquentORM.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    // primero creo la conexion con los datos de mi MySQL
    // el usuario es root y la contrasena es 1234 que fue la que puse
    MySQLConexion conn("localhost", "root", "1234", "control_empleados");

    // intento conectarme, si falla el programa para
    if (!conn.conectar()) {
        cerr << "No se pudo conectar a la base de datos" << endl;
        return 1;
    }

    // aqui le digo que columnas quiero ver de la tabla empleados
    vector<string> columnas = {"id", "nombre", "apellido", "hora_entrada", "hora_salida"};

    // creo el objeto que va a manejar la tabla empleados
    EloquentORM empleados(conn, "empleados", columnas);

    // traigo todos los registros con getAll()
    auto lista = empleados.getAll();

    // muestro los resultados en pantalla
    cout << "==========================================" << endl;
    cout << "       LISTA DE EMPLEADOS                 " << endl;
    cout << "==========================================" << endl;

    // si no hay empleados aviso, si hay los muestro uno por uno
    if (lista.empty()) {
        cout << "No hay empleados registrados" << endl;
    } else {
        for (auto& reg : lista) {
            cout << "ID: "         << reg["id"]
                 << " | Nombre: "  << reg["nombre"]
                 << " "            << reg["apellido"]
                 << " | Entrada: " << reg["hora_entrada"]
                 << " | Salida: "  << reg["hora_salida"]
                 << endl;
        }
    }

    cout << "==========================================" << endl;
    cout << "Total de empleados: " << lista.size() << endl;

    return 0;
}