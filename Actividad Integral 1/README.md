# Actividad Integral 1
## Datos preliminares:

### Consideraciones

- Estrictamente debe seguirse el formato en «prueba.txt» para la correcta lectura de archivos, ya que se lee separado por _:_ y _,_
- Si el archivo de prueba se encuentra en la misma carpeta del proyecto se puede ingresar el nombre sin la ruta de acceso
- El proyecto fue hecho en Xcode, por lo que es posible que exista conflicto con la generación de archivos, se recomienda discreción

### ¿En qué consiste?

El proyecto es una simulación de una bitacora de temperaturas de un mes separado en cuatro semanas, este archivo se puede leer en el programa y se pueden ordenar
las temperaturas de menor a mayor al igual que buscar rangos de las existentes.

### ¿Cómo funciona?

Siguiendo el formato de ejemplo en el archivo «prueba.txt», el programa es capaz de hacer busquedas por rangos de temperaturas existentes y ordenar las temperaturas del mes registrado generando un archivo nuevo con las ordenadas.

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

### displayV
El algoritmo tiene como objetivo desplegar los datos almacenados en el vector tmpVec, para lo que hace uso de un ciclo _for_ que va de i = 0 hasta el tamaño del vector, sumando i cada vez que recorra una poscición hasta que deje de ser menor al tamaño del vector imprimiendo cada poscición con el uso de _at(i)_, a su vez el ciclo _for_ hace uso de un chequeo con un ciclo _if_, pero sólo es para la correcta visualización de los datos; por lo tanto podemos concluir que que la complejidad temporal es: O(n), ya que se comporta de manera lineal considerando el peor de los casos.

