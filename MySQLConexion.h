#ifndef MYSQLCONEXION_H
#define MYSQLCONEXION_H

// MySQLConexion.h
// Axel Dardon - Programacion 1
// Esta clase sirve para conectarse a la base de datos MySQL
// la uso en main.cpp para no tener que escribir todo ahi

#include <iostream>
#include <string>
#include <mysql.h>

using namespace std;

class MySQLConexion {
private:
    MYSQL* conexion;
    string host;
    string usuario;
    string contrasena;
    string baseDatos;

public:
    // aqui recibo los datos para conectarme
    MySQLConexion(string host, string usuario, string contrasena, string baseDatos) {
        this->host       = host;
        this->usuario    = usuario;
        this->contrasena = contrasena;
        this->baseDatos  = baseDatos;
        this->conexion   = nullptr;
    }

    // este metodo intenta conectarse
    // si logra conectar retorna true, si no retorna false
    bool conectar() {
        conexion = mysql_init(nullptr);

        if (conexion == nullptr) {
            cerr << "Error: no se pudo inicializar MySQL" << endl;
            return false;
        }

        // intento conectarme con los datos que me pasaron
        if (!mysql_real_connect(conexion,
                                host.c_str(),
                                usuario.c_str(),
                                contrasena.c_str(),
                                baseDatos.c_str(),
                                0, nullptr, 0)) {
            cerr << "Error al conectar: " << mysql_error(conexion) << endl;
            return false;
        }

        cout << "Me conecte a la base de datos: " << baseDatos << endl;
        return true;
    }

    // esto lo necesita EloquentORM para hacer las consultas
    MYSQL* getConexion() {
        return conexion;
    }

    // cuando el programa termina se cierra la conexion sola
    ~MySQLConexion() {
        if (conexion != nullptr) {
            mysql_close(conexion);
        }
    }
};

#endif