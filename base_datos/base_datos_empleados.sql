-- ============================================================
-- BASE DE DATOS: control_empleados
-- Esta base de datos guarda info de empleados y departamentos
-- La hice para el proyecto de Programacion 1
-- ============================================================

CREATE DATABASE IF NOT EXISTS control_empleados;

USE control_empleados;

-- Tabla de departamentos de la empresa
CREATE TABLE IF NOT EXISTS departamentos (
    id          INT AUTO_INCREMENT PRIMARY KEY,
    nombre      VARCHAR(100) NOT NULL,
    descripcion VARCHAR(255)
);

-- Tabla principal de empleados
-- Guarda nombre, horario y a que depto pertenece
CREATE TABLE IF NOT EXISTS empleados (
    id            INT AUTO_INCREMENT PRIMARY KEY,
    nombre        VARCHAR(100) NOT NULL,
    apellido      VARCHAR(100) NOT NULL,
    correo        VARCHAR(150),
    telefono      VARCHAR(20),
    id_depto      INT,
    hora_entrada  TIME,
    hora_salida   TIME,
    fecha_ingreso DATE,
    FOREIGN KEY (id_depto) REFERENCES departamentos(id)
);

-- Datos de ejemplo para departamentos
INSERT INTO departamentos (nombre, descripcion) VALUES
('Recursos Humanos', 'Manejo del personal'),
('Contabilidad',     'Control de pagos y finanzas'),
('Sistemas',         'Soporte tecnico y desarrollo'),
('Ventas',           'Atencion al cliente');

-- Datos de ejemplo para empleados
INSERT INTO empleados (nombre, apellido, correo, telefono, id_depto, hora_entrada, hora_salida, fecha_ingreso) VALUES
('Carlos',  'Mendoza',  'carlos@empresa.com',  '5512-3456', 3, '08:00:00', '17:00:00', '2022-03-15'),
('Maria',   'Lopez',    'maria@empresa.com',   '5598-7654', 1, '08:30:00', '17:30:00', '2021-07-01'),
('Juan',    'Perez',    'juan@empresa.com',    '5567-8901', 2, '09:00:00', '18:00:00', '2023-01-10'),
('Ana',     'Garcia',   'ana@empresa.com',     '5534-2109', 4, '08:00:00', '17:00:00', '2020-11-20'),
('Roberto', 'Martinez', 'roberto@empresa.com', '5578-4321', 3, '07:30:00', '16:30:00', '2019-05-05');