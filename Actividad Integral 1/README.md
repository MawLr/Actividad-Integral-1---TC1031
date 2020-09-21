# Actividad Integral 1
## Datos preliminares:
¿En qué consiste?
-----
El proyecto es una simulación de lo que ocurren cuando un sistema de meteorología tiene mediciones por cada día de la semana en 1 mes,
es decir, una bitcora de 4 semanas siguiendo un esctricto formato, pues de no seguir el formato el programa no va a funcionar.

¿Cómo funciona?
-----
Siguiendo el formato de ejemplo en el archivo «prueba.txt», el programa es capaz de hacer busquedas por rangos de temperaturas existentes y ordenar las temperaturas del mes registrado.

## Análisis de complejidad temporal

### busqBinaria
El algorítmo en ésta función busca ordenar de manera ascendiente la posición del vector en la que se deberia
de encontrar por lo que se situa en el medio del vector y comienza a comparar desde ahí con los números; de ser menor
pasa a buscar entre down (o bottom) y mid -1, caso opuesto para números mayores, buscando en top y sumando a mid.
La complejidad para el peor de los casos es O(log(n)), es decir, logaritmico para el peor de los casos.

### ordenaBurbuja
El algoritmo busca ordenar los valores de un vector de manera ascendente mediante el uso de dos ciclos _for_ que se encuentran _sujetos_
entre si mismos, los que se encargan de buscar el valor más grande y haciendo uso de la función swap intercambiando con esta el valor encontrado
por el que se encuentra en la última posición (j + 1), el proceso se repite con los valores restantes omitiendo los que ya están ordenados.
Dado el número de pasos que le toma a cada ciclo _for_, su complejidad es n(n+1/2) y su complejidad temporal para el peor de los casos es O(n^2), es decir, cuadrático.

