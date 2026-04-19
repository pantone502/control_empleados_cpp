// main.cpp
// Axel Dardon - Programacion 1
// Este es el archivo principal del proyecto
// Lo que hace este programa es conectarse a mi base de datos
// de MySQL y mostrar todos los empleados que estan registrados
//
// Para que funcione necesita dos archivos que yo hice:
//   - MySQLConexion.h : se encarga de hacer la conexion a MySQL
//   - EloquentORM.h   : se encarga de traer los datos de la tabla
//
// La base de datos se llama control_empleados y tiene
// dos tablas: empleados y departamentos

#include "MySQLConexion.h"  // mi clase para conectarme a MySQL
#include "EloquentORM.h"    // mi clase para hacer consultas facil
#include <iostream>         // para usar cout y cerr
#include <vector>           // para usar vector
#include <string>           // para usar string

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
    // solo pongo las que me interesan mostrar, no todas
    vector<string> columnas = {"id", "nombre", "apellido", "hora_entrada", "hora_salida"};

    // creo el objeto que va a manejar la tabla empleados
    // le paso la conexion, el nombre de la tabla y las columnas
    EloquentORM empleados(conn, "empleados", columnas);

    // traigo todos los registros con getAll()
    // getAll() me devuelve una lista con todos los empleados
    auto lista = empleados.getAll();

    // muestro los resultados en pantalla
    cout << "==========================================" << endl;
    cout << "       LISTA DE EMPLEADOS                 " << endl;
    cout << "==========================================" << endl;

    // si no hay empleados aviso, si hay los muestro uno por uno
    if (lista.empty()) {
        cout << "No hay empleados registrados" << endl;
    } else {
        // recorro cada empleado y muestro sus datos
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

    // la conexion se cierra sola cuando termina el programa
    // eso lo maneja el destructor de MySQLConexion
    return 0;
}