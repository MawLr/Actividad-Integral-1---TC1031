# Actividad Integral 2 - A01706212
## Datos preliminares:

### Consideraciones

- Estrictamente debe seguirse el formato en «prueba.txt» para la correcta lectura de archivos, ya que se lee separado por _:_ y _,_
- Siguiendo el formato anterior, el archivo **UNICAMENTE puede llevar 28 dígitos separados por comas**, de preferencia separado por semanas
- Los datos numéricos deben de ser enteros
- Si el archivo de prueba se encuentra en la misma carpeta del proyecto se puede ingresar el nombre sin la ruta de acceso
- El proyecto fue hecho en Xcode, por lo que es posible que exista conflicto con la generación de archivos, se recomienda discreción (ya fue probado y funciona en repl.it)

### ¿En qué consiste?

_Se tomaron en cuenta los comentarios de la entrega pasada y se decidió añadir un archivo extra de prueba, mil disculpas por tener que hacerlo forzozamente
iterativo pero Xcode es una espada de doble filo, en todo caso también se intentó comentar mejor el código._

El proyecto es una simulación de una bitacora de temperaturas de un mes separado en cuatro semanas, este archivo se puede leer en el programa y se pueden ordenar
las temperaturas de menor a mayor al igual que buscar rangos de las existentes.

La novedad en este avance es que se implemento una lista ligada en las temperaturas, por lo que ya es posible modificar los datos una vez son recibidos del archivo
mediante un pequeño menú en la pantalla (modificar lista), de esta forma es posible añadir, remover y actualizar datos de la lista ligada y además es posible
guardar dichos datos en un archivo separado del que es generado por lo requerido en la entrega pasada, nuevamente dentro del menú de modificación de la lista.

### ¿Cómo funciona?

Igualmente debe seguirse el formato que se es dado en «prueba.txt» y «prueba2.txt», al ser leído el archivo, los datos numericos son insertados a un array
cuyo nombre es nLine[], éste sólo recibe 27 digitos (contando el 0) pues es una bitácora de un mes, seguido de esto, la variable num almacena los datos del array
convertidos a enteros con la propiedad _stoi_, para nuestro caso, insertamos num a la lista, y de esa forma todos y cada uno de los enteros de temperaturas son
almacenados en una lista ligada la cual ya puede ser modificiada a nuestro gusto con las funciones _add, update, remove, toString y find_, igualmente se puede generar
un archivo que contiene la lista con sus modificaciones, en caso de ser alterada por el usuario.

## Análisis de complejidad temporal

_Las complejidades de las funciones pasadas se encuentran en su respectiva entrega_

### main.cpp
El main comienza desplegando un menú switch con 6 cases, los cuales son utilizados para poder leer el archivo, ordenarlo, buscar por rango, generar el archivo ordenado
y modificar la lista ligada, para poder leer los datos numericos del archivo se hizo uso de un ciclo _for_ que se encarga de obtener los datos numericos separados por coma e ingresarlos a un array, 
la complejidad temporal de éste es de O(n), es decir, lineal, pues to tienen mayor complejidad; una vez los datos son almacenados en el array se usa la propiedad _stoi_ para 
convertir los caracteres a enteros y poder meterlos al vector tmpVec haciendo uso de la propiedad _push_back_, también se almacena el mes y la semana en distintas variables pero 
no se hace uso contundente e ellas; con los datos ya en el vector se hace uso de la función _ordenaBurbuja_ cuya complejidad se ve analizada en otra sección de éste README,
una vez ordenados los datos es posible hacer uso de la función _busqBinaria_ para buscar por un rango definido todas las instancias de temperaturas, la complejidad temporal de ésta 
igualmente está detallada seguido de éste encabezado; por último se genera el archivo nuevamente con un sencillo cilo _for_ lineal que imprime los datos haciendo usode la propiedad _.at(i)_.

### Find
El algoritmo busca encontrar un número en un índice especificado haciendo uso de un ciclo _while_ que recorre toda la lista hasta encontrar el que contiene
la poscición del que se busca, devolviendola o en caso de no existir, devolviendo la poscición -1, dicho lo anterior, su complejidad temporal es O(n), es decir,
lineal para el peor de los casos, ya que sólo recorre n número de elementos en la lista.

### Update
El algoritmo en esta función tiene como objetivo actualizar un número en un índice, ambos especificados en los parámetros de la función, para hacer esto el índice
se busca haciendo uso de un ciclo _while_ que recorre la lista hasta encontrarlo, al encontrar dicho índice se actualiza el valor contenido, dicho lo anterior
su complejidad temporal es O(n) para el peor de los casos, pues al igual que otras funciones, sólo recorre n número de elementos de la lista.

### Add
El algoritmo busca encontrar y remover lo contenido en un índice que es dado como parámetro de la función, este se busca haciendo uso de un ciclo _while_ que
recorre la lista hasta encontrar el índice deseado, una vez que se encuentra, su contenido es removido y la lista se ajusta para poder seguir siendo utilizada,
cabe mencionar que se hace uso de la funcion _removeFirst_ en caso de que se desee remover el primer elemento, esto es para que se ajuste el _head_ de la lista
y pueda leerse sin problemas, dicho lo anterior, su complejidad temporal es O(n), es decir, lineal para el peor de los casos pues el ciclo sólo recorre n numero
de veces la lista, igualmente la complejidad de la función _removeFirst_ es O(1).

### Remove
El algoritmo busca añadir elementos nuevos a la lista, para hacer esto se hace uso de un ciclo _while_ que recorren toda la lista hasta llegar a la última poscición
para añadir el nuevo elemento, el cual se da como parámetro de la función, cabe mencionar que en caso de ser el primer elemento se llama a la función _addFirst_, 
para de esta forma asegurarse de la asignación del head, dicho lo anterior podemos decir que la complejidad temporal es de O(n), es decir, lineal para el peor de los casos 
pues el ciclo sólo está recorriendo la lista, mientras que la complejidad de _addFirst_ es de O(1).
