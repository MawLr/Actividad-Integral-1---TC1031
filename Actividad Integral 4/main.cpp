//
//  main.cpp
//  proyecto 1 tc1031
//
//  AVANCE 4:
//  A01706212
//  Created by Manolo Medina on 9/16/20. A0170212
//  Copyright © 2020 Manolo Medina. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "graph.h"

using namespace std;

int main() {
  Graph g;
  ifstream inFile;
  ofstream output;
  bool fileCheck = false;
  cout << "Bienvenido a este avance de grafos, por favor selecciona una opción" << endl;

  bool exit = false;
  while (exit == false){
    int option;
    string fileGraph;
    int opt;
    int vNum;
    int aNum;
    int initV;
    int targetV;
    
    cout << "(1) Leer archivo de grafos..." << endl;
    cout << "(2) Imprimir lista adyacente..." << endl;
    cout << "(3) Imprimir matriz adyacente..." << endl;
    cout << "(4) Realizar búsqueda en profundidad..." << endl;
    cout << "(5) Realizar búsqueda en anchura..." << endl;
    cout << "(6) Realizar ejemplo de uso de grafos..." << endl;
    cout << "(7) Generar archivo con lista y matriz adyacente..." << endl;
    cout << "(8) Salir..." << endl;
    cin >> option;
    if (option == 1){
      fileCheck = true;
    }
    switch(option){
      
      case 1:
      cout << "Ingrese nombre de archivo de grafos: " << endl;
      cin >> fileGraph;
      cout << "Ingrese número de vertices: " << endl;
      cin >> vNum;
      cout << "Ingrese número de edges: " << endl;
      cin >> aNum;
      g.loadGraphList(fileGraph, vNum, aNum); // Método para cargar grafo
      g.loadGraphMat(fileGraph, vNum, aNum);
      
      break;

      case 2:
      if (fileCheck == false){
        cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
        cout << '\n';
        break;
      }
      cout << g.printAdjList() << endl;
      break;

      case 3:
      if (fileCheck == false){
        cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
        cout << '\n';
        break;
      }
      cout << g.printAdjMat() << endl;
      break;

      case 4:
      if (fileCheck == false){
        cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
        cout << '\n';
        break;
      }
      cout << "Ingrese vertice de inicio"<< endl;
      cin >> initV;
      cout << "Ingrese vertice objetivo"<< endl;
      cin >> targetV;
      cout << g.DFS(initV, targetV) << endl;
      break;

      case 5:
      if (fileCheck == false){
        cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
        cout << '\n';
        break;
      }
      cout << "Ingrese vertice de inicio"<< endl;
      cin >> initV;
      cout << "Ingrese vertice objetivo"<< endl;
      cin >> targetV;
      cout << g.BFS(initV, targetV) << endl;
      break;

      case 6:

      if (fileCheck == false){
        cout << "Para este ejemplo se requiere el archivo «t1.txt», favor de leerlo antes de correr esta opción" << endl;
        cout << '\n';
        break;
      }
      cout << "Vamos a realizar un ejemplo de uso de grafos, en este caso nos vamos a imaginar rutas de autobus... \n" << endl;
      cout << "En este ejemplo, los grafos nos van a ayudar a poder llegar en la rutas más rápida y la menos costosa, haciendo uso de las búsquedas por anchura y por profundidad... \n" << endl;

      cout << "Suponiendo que el vertice de inicio es Querétaro y el objetivo es Monterrey, hagamos la prueba: \n" << endl;

      cout << "QUERÉTARO:      0" << endl;
      cout << "SLP:            2" << endl;
      cout << "ZACATECAS:      4" << endl;
      cout << "MATEHUALA:      1" << endl;
      cout << "PIEDRAS NEGRAS: 6" << endl;
      cout << "MONTERREY:      7" << endl;
      cout << '\n';
      cout << "Precio por esta ruta: 450$" << endl;
      cout << g.BFS(0, 7) << endl;
      cout << '\n';
      cout << "Precio por esta ruta: 575$" << endl;
      cout << g.DFS(0, 7) << endl;
      cout << '\n';
      cout << "Como podemos ver, la búsqueda de profundidad nos arrojó la ruta más rápida con nuestros nodos entre las ciudades hipotéticas, pero esto depende de las rutas conectadas, de esta forma podemos crear rutas y cobrar diferentes precios por rapidez, etc." << endl;;
      cout << '\n';
      cout << "Igualmente este es un caso de prueba, demostrando que el programa funciona" << endl;
      cout << '\n';
      break;

      case 7:
      if (fileCheck == false){
        cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
        cout << '\n';
        break;
      }
      cout << "Generando bitacora de grafos: " << endl;
      cout << '\n';
      output.open("grafos.txt");
      if (output.is_open()){
        output << g.printAdjList();
        cout << g.printAdjList()<<endl;
        output << g.printAdjMat();
        cout << g.printAdjMat()<<endl;
      }
      output.close();
      break;

      case 8:
      cout << "FIN DE SESIÓN" << endl;
      exit = true;
    }
      
  }
}
