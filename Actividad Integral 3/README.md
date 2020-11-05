# Actividad Integral 2 - A01706212
## Datos preliminares:

### Consideraciones

- Estrictamente debe seguirse el formato en «prueba.txt» para la correcta lectura de archivos, ya que se lee separado por _:_ y _,_
- Siguiendo el formato anterior, el archivo **UNICAMENTE puede llevar 28 dígitos separados por comas**, de preferencia separado por semanas
- **Los datos numéricos deben de ser enteros**
- Si el archivo de prueba se encuentra en la misma carpeta del proyecto se puede ingresar el nombre sin la ruta de acceso
- **El proyecto fue hecho en Xcode, por lo que es posible que exista conflicto con la generación de archivos, se recomienda discreción (ya fue probado y funciona en repl.it)**

### ¿En qué consiste?

_Se tomaron en cuenta los comentarios de la entrega pasada y se decidió añadir un archivo extra de prueba, mil disculpas por tener que hacerlo forzozamente
iterativo pero Xcode es una espada de doble filo, en todo caso también se intentó comentar mejor el código._

El proyecto es una simulación de una bitacora de temperaturas de un mes separado en cuatro semanas, este archivo se puede leer en el programa y se pueden ordenar
las temperaturas de menor a mayor al igual que buscar rangos de las existentes.

Lo nuevo de la entrega 3 es que ahora los datos leídos del archivo (ya sea prueba.txt, prueba2.txt o cualquier archivo de texto siguiendo el formato) son ingresados a un árbol
Splay que los acomoda de manera automática, pues gracias a que los datos son primero guardados como un arreglo y convertidos a enteros con la función _stoi_ esto pudo ser,
entonces con una de las opciones del menú ahora se puede manipular nuestro árbol, permitiendo que los climatologos de nuestra solución puedan encontrar si en un mes existió
una lectura de temperatura o que puedan insertar/eliminar lecturas de igual forma, ciertamente facilidandoles el trabajo que deben de hacer.

### ¿Cómo funciona?

Igualmente debe seguirse el formato que se es dado en «prueba.txt» y «prueba2.txt», al ser leído el archivo, los datos numericos son insertados a un array
cuyo nombre es nLine[], éste sólo recibe 27 digitos (contando el 0) pues es una bitácora de un mes, seguido de esto, la variable num almacena los datos del array
convertidos a enteros con la propiedad _stoi_, para nuestro caso, insertamos num a la lista, y de esa forma todos y cada uno de los enteros de temperaturas son
almacenados en un árbol Splay que se puede manipular con las funciones _add(), remove() y find()_ al igual que se pueden desplegar los datos con _print_tree()_.

## Análisis de complejidad temporal

_Las complejidades de las funciones pasadas se encuentran en su respectiva entrega_

### main.cpp
El main comienza desplegando un menú switch con 7 cases, los cuales son utilizados para poder leer el archivo, ordenarlo, buscar por rango, generar el archivo 
ordenado, modificar la lista ligada y modificar el árbol Splay, en este caso realmente sólo se utilizaron las funciones _add(), remove(), find()_ y _print_tree()_, 
pues a diferencia de la entrega pasada, en este caso a pesar de aún estar presentes las cosas de la entrega anterior, la manera en la que se añadieron los datos fue 
mucho más sencillo, recordemos que desde la entrega pasada los datos leídos del archivo eran primeramente almacenados en un array y después comvertidos a enteros mediante el uso 
de _stoi_, pues en este caso lo único que se tuvo que hacer fue ingresar esos datos ya convertidos a la función _add_ del árbol, y así se generaba el Splay de temperaturas
listo para ser modificado y/o impreso, esto se hace mediante la opción del menú de modificar el árbol, dentro de ese menú podemos añadir valores haciendo
uso de la función _add_, eliminar valores con la función _remove_ y encontrar la existencia de un valor con la función _find_.
