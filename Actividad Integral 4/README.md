# Actividad Integral 4 - A01706212
## Datos preliminares:

### Consideraciones

- Estrictamente debe seguirse el formato en «t1.txt» para la correcta lectura de archivos de grafos, se debe de contar los vertices y edges como n+1 a la cantidad de 
coordenadas.
- El avance es diferente a todos los demás avances, no tiene nada que ver con los pasados pues no tenía sentido utilizar grafos en los demás.
- **Los datos numéricos deben de ser enteros**
- **Xcode no puede correr estos archivos por falta de la biblioteca <bits/stdc++.h>. sin embargo funciona sin problema en Repl.it**

### ¿En qué consiste?

_Se tomaron en cuenta los comentarios de la entrega pasada y se hizo un case entero para demostrar el uso de grafos de manera de caso de prueba._

Esta entrega es únicamente para demostrar el uso de grafos, el usuario puede leer su propio archivo para utilizar búsquedas de profundidad y de anchura con ellos y puede 
desplegar las matrices y listas adyacentes, sin embargo, el uso real del programa se observa en el caso 6, pues en este se da un ejemplo de cómo pueden utilizarse los grafos de 
manera práctica con una simulación de cálculo de rutas de autobus, en este caso desde Querétaro a Monterrey, desplegando así que la rutas más rápida es más cara que la que pasa 
por más ciudades (nodos).

Igualmente el programa cumple con los requisitos de lectura  y generación de archivos.

### ¿Cómo funciona?

El programa trae consigo un archivo de ejemplo, se debe de leer un archivo que contenga las coordenadas de los grafos y se deben de ingresar los vertices y edges, haciendo uso 
de la entrega de grafos se puede así jugar con nuestro archivo, pudiendo hacer búsquedas e imprimir las matrices y listas adyacentes, las cuales pueden ser guardadas en un 
archivo generado.

### ¿Qué son los grafos y cúando se usan?

En resumidas cuentas, un grafo se puede definir como:
_«Un grafo es un conjunto de puntos y un conjunto de líneas, cada una de las cuales une un punto con otro, los puntos se llaman nodos o vértices de un grafo y las líneas se 
llaman aristas o arcos.»_

Sus usos son muchos en el espectro matemático, algunos de ellos son:

- Análisis de circuitos eléctricos.
- Determinación del camino más corto.
- Análisis de planificación de proyectos.
- Identificación de compuestos químicos.

En este proyecto estamos haciendo uso del segundo punto.

## Análisis de complejidad temporal

_Las complejidades de las funciones pasadas se encuentran en su respectiva entrega_

### main.cpp
El main comienza desplegando un menú switch con 9 cases, los cuales son utilizados para poder leer el archivo, imprimir lista adyacente, imprimir matriz adyacente, realizar búsqueda por profundidad, realizar búsuqeda por anchura, generar archivo con lista y matriz adyacente y salir, esto se hace en su mayoría gracias a las funciones _loadGraphList()_, _loadGraphMat()_, _printAdjList(), printAdjMat(), BFS(), DFS()_

## loadGraphMat
El algoritmo toma V + A pasos para cargar los arcos de un grafo para después almacenarlo en una matríz de adyacencia puesto que recibe como parametro V igual al número de vertices 
y A siendo el número de arcos, dicho lo anterior podemos decir que su complejidad temporal es O(V + A) para el peor de los casos.

## loadGraphList
El algoritmo toma V + A pasos para cargar los arcos de un grafo para después almacenarlo en una matríz de adyacencia puesto que recibe como parametro V igual al número de vertices 
y A siendo el número de arcos, dicho lo anterior podemos decir que su complejidad temporal es O(V + A) para el peor de los casos.

## DFS
El algoritmo toma V + A de pasos para almacenar en una lista de nodos visitados y el camino recorrido DFS de profundiad de un grafo comenzando por el nodo inicial y teniendo un 
nodo meta, estos son pasados como parametros en la función, V es igual al número de vertices y A es igual al número de arcos existentes en el grafo, dicho esto podemos decir que 
su complejidad temporal es O(V + A) para el peor de los casos.

## BFS
El algoritmo toma V + A de pasos para almacenar en una lista de nodos visitados y el camino recorrido BFS de anchura de un grafo comenzando por el nodo inicial y teniendo un 
nodo meta, estos son pasados como parametros en la función, V es igual al número de vertices y A es igual al número de arcos existentes en el grafo, dicho esto podemos decir que 
su complejidad temporal es O(V + A) para el peor de los casos.
