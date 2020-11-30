# Actividad Integral 5 - A01706212
## Datos preliminares:

### Consideraciones

- Estrictamente debe seguirse el formato en «prueba.txt» para la correcta lectura de archivos, ya que se lee separado por _:_ y _,_
- **Los datos numéricos deben de ser enteros**
- Si el archivo de prueba se encuentra en la misma carpeta del proyecto se puede ingresar el nombre sin la ruta de acceso
- **El proyecto fue hecho en Xcode, por lo que es posible que exista conflicto con la generación de archivos, se recomienda discreción (ya fue probado y funciona en repl.it)**

### ¿En qué consiste?

_Se tomaron en cuenta los comentarios de la entrega pasada y se comentó de nuevo el código al igual que se añadieron ahora sí casos de prueba, igualmente el programa es 
diferente a las entregas anteriores pero sigue el esquema de la entrega 1, 2 y 3 de trabajar con temperaturas._

El proyecto es una simulación de una bitacora de temperaturas de un año, donde se almacenan los datos en una tabla chain hash en formato _mes : última temperatura registrada_, 
de esta forma para los meteorologos que quieren comparar entre las últimas temperaturas registradas de cada mes les es más fácil visualizarlo así.

Lo nuevo de la entrega 3 es que ahora los datos leídos del archivo (ya sea prueba.txt, prueba2.txt o cualquier archivo de texto siguiendo el formato) son ingresados a una tabla 
chain hash que los acomoda con su mes y última temperatura registrada, se utilizó chain como método de evitar colisiones de datos, fue gracias a la función _stoi()_ que las 
temperaturas se pudieron convertir a enteros y se pudieron ingresar con su respectivo mes, igualmente el chain permite que se modifiquen valores existentes, gracias a un chequeo 
sólo se permite ingresar meses válidos, facilitando así el trabajo de los climatólogos.

### ¿Cómo funciona?

Igualmente debe seguirse el formato que se es dado en «prueba.txt», al ser leído el archivo, los datos numericos son insertados a un array
cuyo nombre es nLine[], seguido de esto, la variable num almacena los datos del array convertidos a enteros con la propiedad _stoi_, para nuestro caso, insertamos num a la tabla 
chain hash junto con _mes_, variable que se lee directamente del archivo, esto es gracias a la función _put()_ del chain hash, igualmente gracias a la función _toString()_ es 
que se puede visualizar la tabla chain hash.

## Análisis de complejidad temporal

_Las complejidades de las funciones pasadas se encuentran en su respectiva entrega_

### main.cpp
El main comienza desplegando un menú switch con 6 cases, los cuales son utilizados para poder leer el archivo, leer la tabla hash, modificar los datos hash, generar el archivo y 
los casos de prueba (case 6 es salir), en este caso realmente sólo se utilizaron las funciones _put() y toString()_ del _chain.h_, 
recordemos que desde la entrega 1 los datos leídos del archivo eran primeramente almacenados en un array y después comvertidos a enteros mediante el uso 
de _stoi_, pues en este caso lo único que se tuvo que hacer fue ingresar esos datos ya convertidos a la función _put_ del hash junto con _mes_ (mes, num), y así se generaba el 
chain hash de temperaturas con meses listo para ser modificado y/o impreso, esto se hace mediante la opción del menú de leer la tabla hash o modificarla, dentro de ese menú 
podemos modificar valores haciendo uso de la función _put_ nuevamente, pero sólo nos permite modificar meses existentes en la tabla, o sea, alguno de los 12 del año.
Con todo esto podemos decir que la complejidad temporal del main es O(1), es decir, lineal para el peor de los casos, pues solamente recibe entradas para hacer funciones de 
manera lineal.

### chain.h
## put
Por medio de la función _indexOf()_ es posible conocer el índice de la llave, con esto lo que hace es agregar la llave y el valor que fueron ingresados como parámetros de la 
función, en este caso al ser _chain_ no importa si el espacio está ocupado, pues va a encadenar los datos gracias al uso de vectores, dicho esto podemos decir que su complejidad 
temporal es O(1), es decir, constante pues sólo se están agregando valores y llaves a los vectores, a menos de que la tabla hash se encuentre atareada, en ese caso sería O(n), 
es decir, lineal para el peor de los casos

## toString
El algoritmo busca convertir a string los meses de cada llave (temperatura), haciendo uso de un ciclo _while_ que recorre los arreglos hasta llegar a _size_, cada iteración va 
almacenando los datos en strings, dicho esto podemos decir que su coomplejidad temporal es O(n), es decir, lineal para el peor de los casos.

## contains
En este caso si la función _indexOf()_ arroja un valor de -1 quiere decir que la llave que fue ingresada como parámetro no se encuentra en la tabla, por lo que sólo le toma un 
paso, dicho esto podemos decir que su complejidad temporal es O(1), es decir, constante para el peor de los casos.

## get
Únicamente devuelve el valor de una llave de la tabla por medio de la función _indexOf()_, pues esta devuelve el índice de esa llave, lo único que hace _get_ es obtener el 
valor, por lo que podemos decir que su complejidad temporal es O(1), es decir, constante para el peor de los casos.
