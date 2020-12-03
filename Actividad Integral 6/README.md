# Actividad Integral 6 - A01706212

### Bucket Sort

## ¿En qué consiste?

El Bucket Sort, también conocido como Bin Sort o ordenamiento por casilleros es un algorítmo de ordenamiento que distribuye todos sus elementos entre un número de casilleros
(buckets), para poder hacer esto tiene condicionales para evitar meter un dato en dos casilleros, los casilleros después se ordenan individualmente, este algoritmo es útil cuando 
se está trabajando con una cantidad uniforme de números, recibe como parametro un arreglo y el tamaño del arreglo, despues de que se ordenan los baldes, estos se unen a un sólo 
arreglo, arrojando así el resultado de los datos ordenados.

## ¿Para qué se usa?

Se utiliza como algoritmo de ordenamiento, así que en casi cualquier situación donde se tengan que ordenar datos de manera rápida, pues el ordenamiento por baldes es mucho más 
rápido que otros algoritmos de ordenamiento, aunque este asume que los datos son uniformes, en este caso como ejemplo se tiene un programa que recibe 5 datos de miligrajes de 
medicina y se desea ponerlos en orden pero de igual manera el algoritmo puede ser utilizado para ordenar las diferencias entre medidas de temperatura, los errores de márgen en 
medición de piezas, las edades de diferentes personas, etc.

![](bucket.png)

## ¿Qué se hizo?

### Análisis de complejidad temporal

_Las complejidades de las funciones pasadas se encuentran en su respectiva entrega_

## main.cpp
El main comienza desplegando un menú switch con 6 cases, los cuales son utilizados para poder leer el archivo, leer la tabla hash, modificar los datos hash, generar el archivo y 
los casos de prueba (case 6 es salir), en este caso realmente sólo se utilizaron las funciones _put() y toString()_ del _chain.h_, 
recordemos que desde la entrega 1 los datos leídos del archivo eran primeramente almacenados en un array y después comvertidos a enteros mediante el uso 
de _stoi_, pues en este caso lo único que se tuvo que hacer fue ingresar esos datos ya convertidos a la función _put_ del hash junto con _mes_ (mes, num), y así se generaba el 
chain hash de temperaturas con meses listo para ser modificado y/o impreso, esto se hace mediante la opción del menú de leer la tabla hash o modificarla, dentro de ese menú 
podemos modificar valores haciendo uso de la función _put_ nuevamente, pero sólo nos permite modificar meses existentes en la tabla, o sea, alguno de los 12 del año.
Con todo esto podemos decir que la complejidad temporal del main es O(1), es decir, lineal para el peor de los casos, pues solamente recibe entradas para hacer funciones de 
manera lineal.
