# Práctico 1

Ha sido contratado para trabajar con las empresas que se han registrado durante este año en Chile ([página desde donde se sacó la info](https://datos.gob.cl/dataset/registro-de-empresas-y-sociedades)).

El programa recibirá un csv con la información de las empresas tal como se muestra a continuación:

ID;RUT;Razon Social;Fecha de actuacion (1era firma);Fecha de registro (ultima firma);Fecha de aprobacion x SII;Anio;Mes;Comuna Tributaria;Region Tributaria;Codigo de sociedad;Tipo de actuacion;Capital;Comuna Social;Region Social

3627391;77503124-7;Sherbim SpA;01-01-2022;01-01-2022;01-01-2022;2022;Enero;CURICO;7;SpA;CONSTITUCIÓN;500000;CURICO;7

3627560;77503123-9;Constructora Jaime Sebastián Cortes  Olivarez E.I.R.L.;01-01-2022;01-01-2022;01-01-2022;2022;Enero;CURICO;7;EIRL;CONSTITUCIÓN;1000000;CURICO;7


Esta información será guardada en el programa dentro de una estructura como se muestra a continuación.

```c
typedef struct n {
  int id;
  char rut[11];
  char razon_social[200];
  char fecha_actuacion[11];
  char fecha_registro[11];
  char fecha_aprobacion[11];
  int anio;
  char mes[20];
  char comuna[80];
  int region;
  char codigo[40];
  char tipo[80];
  int capital;
  char comuna_social[80];
  int region_social;  
} empresa;
```

## Funciones

Las funciones son las siguientes

| función                    | descripción                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| -------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| ```swap```                 | Función que recibe como argumento dos estructuras de tipo empresa. La función no retorna nada e intercambia el contenido de ambas estructuras.                                                                                                                                                                                                                                                                                                                                                                                      |
| ```leer_archivo```         | Función que recibe como argumento el nombre de un archivo y un puntero a entero, y retorna un arreglo con todas las empresas del archivo guardadas en él. Además guarda en el puntero a entero la cantidad de empresas leídas del archivo.                                                                                                                                                                                                                                                                                          |
| ```ordenar_pokemones```    | Recibe como argumento un arreglo de empresas, y un entero que indica la cantidad de empresas que tiene el arreglo. La función retornará UN NUEVO ARREGLO con las empresas ordenadas de mayor a menor (número más alto primero) según la columna capital. En caso de empate, ordenar por razón social.                                                                                                                                                                                                                               |
| ```N_mejores```            | Recibe como argumento un arreglo de empresas,  un entero que indica la cantidad de empresas que tiene el arreglo, y otro entero que indica la cantidad de empresas que serán ordenadas. La función retornará UN NUEVO ARREGLO con las empresas ordenadas de mayor a menor (número más alto primero) según la columna capital. En caso de empate, ordenar por razon social.                                                                                                                                                          |
| ```N_mejores_generacion``` | Recibe como argumento un arreglo de empresas, un entero que indica la cantidad de empresas que tiene el arreglo, otro entero que indica la cantidad de empresas que serán ordenados, y un último entero que indica la region social que será usada para obtener las mejores empresas. La función retornará UN NUEVO ARREGLO con las empresas ordenadas de mayor a menor (número más alto primero) según la columna capital, conteniendo sólo las empresas de la región social listada. En caso de empate, ordenar por razón social. |

## Consideraciones especiales

1. Sólo puede modificar los archivos **pregunta_X.c**. No puede modificar NADA MÁS.
2. Para facilitar su codificación se le entrega un Makefile que automatiza la compilación y ejecución de su código. Para ocuparlo debe hacer dos cosas:
   1. Modificar la línea 8 del archivo *utilities.h*, cambiando el número que aparece ahí por el número de la pregunta que desea compilar
   2. Escribir en la shell(consola-terminal) lo siguiente:

       ```bash
        make p1
       ```

       Este ejemplo es para compilar la pregunta 1. Si desea compilar la pregunta dos, en *utilities.h* edite el número mencionado anteriormente por un 2 y el make lo hace con p2
3. Sólo debe subir los archivos pregunta_X.c. SIN COMPRIMIR. No suba un zip, ni suba el main.c. Todo archivo extra subido a Webcursos será ignorado.
4. Nunca está demás decir que todos los códigos serán analizados con un detector de plagio. Esta evaluación se rige por la normas de conducta propias de un alumno UAI.
5. Para usar funciones creadas en otros archivos (por ejemplo quiere usar la función que creó en la pregunta_1 en la respuesta de la pregunta_2) debe copiar la implementación completa de la función en la pregunta que corresponde.