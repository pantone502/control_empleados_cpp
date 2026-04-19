#ifndef ELOQUENTORM_H
#define ELOQUENTORM_H

// EloquentORM.h
// Axel Dardon - Programacion 1
// Esta clase me permite hacer consultas a MySQL sin escribir
// tanto SQL a mano, solo le paso la tabla y las columnas
// y el se encarga de armar el SELECT

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <mysql.h>
#include "MySQLConexion.h"

using namespace std;

class EloquentORM {
private:
    MySQLConexion& conn;      // la conexion que ya hice en main
    string tabla;             // nombre de la tabla que voy a consultar
    vector<string> columnas;  // las columnas que quiero ver

public:
    // constructor, recibe todo lo que necesita para trabajar
    EloquentORM(MySQLConexion& conn, string tabla, vector<string> columnas)
        : conn(conn), tabla(tabla), columnas(columnas) {
    }