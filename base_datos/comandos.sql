-- ============================================================
-- ARCHIVO: comandos.sql
-- Aqui estan los 3 registros nuevos que agregue a la BD
-- Los ejecute desde HeidiSQL
-- ============================================================

USE control_empleados;

-- Empleado nuevo 1 - departamento de Ventas
INSERT INTO `empleados` (`nombre`, `apellido`, `correo`, `telefono`, `id_depto`, `hora_entrada`, `hora_salida`, `fecha_ingreso`)
VALUES ('Luis', 'Herrera', 'luis@empresa.com', '5545-6789', 4, '08:00:00', '17:00:00', '2024-01-15');

-- Empleado nuevo 2 - departamento de Sistemas
INSERT INTO `empleados` (`nombre`, `apellido`, `correo`, `telefono`, `id_depto`, `hora_entrada`, `hora_salida`, `fecha_ingreso`)
VALUES ('Sofia', 'Castillo', 'sofia@empresa.com', '5523-9876', 3, '09:00:00', '18:00:00', '2024-02-20');

-- Empleado nuevo 3 - departamento de Contabilidad
INSERT INTO `empleados` (`nombre`, `apellido`, `correo`, `telefono`, `id_depto`, `hora_entrada`, `hora_salida`, `fecha_ingreso`)
VALUES ('Diego', 'Ramirez', 'diego@empresa.com', '5511-2345', 2, '08:30:00', '17:30:00', '2024-03-05');

-- Para verificar que se insertaron bien
SELECT * FROM empleados;