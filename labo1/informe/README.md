Laboratorio 1
==========
--------------------
Estudiante:
--------------------
+ Roger Daniel Piovet García - C15990

En este repositorio se encuentra el trabajo realizado para el Laboratorio 1 del curso IE-0624 Laboratorio de Microcontroladores. 

En el directorio src se hallan el código fuente y los archivos de simulación necesarios para la simulación del diseño en SimulIDE. El archivo dado.simu contiene el circuito implementado en SimulIDE y el archivo dado.c el código implementado en C que se debe compilar, y luego cargar en el PIC12F675 para visualizar el simulador de dado.

# Simulación 

    1. Primero, compila el código `dado.c` en el directorio src
    ```sh
    make
    ```
    2. Abre el archivo `dado.simu` en SimulIDE y carga el archivo `dado.hex` al PIC12F675
    3. Presione el botón pulsador para *lanzar* el dado electrónicamente

# Reporte 
    1. Primero, genera el PDF por medio del siguiente comando en el directorio informe
    ```sh
    make
    ```
    2. Abre el PDF
    ```sh
    open main.pdf
    ```

