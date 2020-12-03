#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include "graph.h"

using namespace std;

int main() {
  Graph g;
  Graph test;

  string gtest_ans;

  ifstream inFile;
  ofstream output;
  bool fileCheck = false;
  string cOrigen;
  string cDestino;
  int precioO;
  int precioD;
  int precioR;

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
    
    
    cout << "(1) Leer archivo de RUTAS: " << endl;
    cout << "(2) Imprimir lista adyacente: " << endl;
    cout << "(3) Imprimir matriz adyacente: " << endl;
    cout << "(4) Desplegar Rutas: " << endl;
    cout << "(5) Buscar Ruta Rápida: " << endl;
    cout << "(6) Buscar Ruta Económica: " << endl;
    cout << "(7) Casos de Prueba: " << endl;
    cout << "(8) Generar archivo con lista y matriz adyacente: " << endl;
    cout << "(9) Salir" << endl;
    cin >> option;
    if (option == 1){
      fileCheck = true;
    }
    switch(option){
      
      case 1:
      cout << "Leyendo archivo de grafos..." << endl;
      fileGraph = "rutas.txt";
      cout << "Leyendo número de vertices: " << endl;
      vNum = 8;
      cout << "Leyendo número de edges: " << endl;
      aNum = 8;
      g.loadGraphList(fileGraph, vNum, aNum); // Método para cargar grafo
      g.loadGraphMat(fileGraph, vNum, aNum);
      cout << '\n';
      
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
      cout << "RUTAS:" << endl;
      cout << "  QRO:      0" << endl;
      cout << "  SLP:      2" << endl;
      cout << "  ZAC:      4" << endl;
      cout << "  VER:      1" << endl;
      cout << "  TMP:      6" << endl;
      cout << "  MTY:      7" << endl;
      cout << '\n';
      break;

      case 5:
      if (fileCheck == false){
        cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
        cout << '\n';
        break;
      }
      cout << "Ingrese ciudad de origen"<< endl;
      cin >> cOrigen;
      if (cOrigen == "QRO" || cOrigen == "qro"){
        initV = 0;
        precioO = 250;
      }
      else if(cOrigen == "SLP" || cOrigen == "slp"){
        initV = 2;
        precioO = 210;
      }
      else if(cOrigen == "ZAC" || cOrigen == "zac"){
        initV = 4;
        precioO = 200;
      }
      else if(cOrigen == "VER" || cOrigen == "ver"){
        initV = 1;
        precioO = 220;
      }
      else if (cDestino == "TMP" || cDestino == "tmp"){
        targetV = 6;
        precioD = 220;
      }
      else if(cOrigen == "MTY" || cOrigen == "mty"){
        initV = 7;
        precioO = 330;
      }
      else{
        cout << "Ingrese orígen válido de la tabla de rutas..." << endl;
        break;
      }

      cout << "Ingrese ciudad de destino"<< endl;
      cin >> cDestino;

      if (cDestino == "QRO" || cDestino == "qro"){
        targetV = 0;
        precioD = 250;
      }
      else if (cDestino == "SLP" || cDestino == "slp"){
        targetV = 2;
        precioD = 210;
      }
      else if (cDestino == "ZAC" || cDestino == "zac"){
        targetV = 4;
        precioD = 200;
      }
      else if (cDestino == "VER" || cDestino == "ver"){
        targetV = 1;
        precioD = 220;
      }
      else if (cDestino == "TMP" || cDestino == "tmp"){
        targetV = 6;
        precioD = 220;
      }
      else if (cDestino == "MTY" || cDestino == "mty"){
        targetV = 7;
        precioD = 330;
      }
      else{
        cout << "Ingrese destino válido de la tabla de rutas..." << endl;
        break;
      }

      if(precioD == precioO){
        precioR = 0;
        cout << "No puedes viajar a donde ya estás"<< endl;
        break;
      }
      else{
        precioR = precioO + precioD;
      }
      
      cout << "Precio por esta ruta: $" << precioR << endl;
      cout << g.DFS(initV, targetV) << endl;
      cout << '\n';
      break;

      case 6:
      if (fileCheck == false){
        cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
        cout << '\n';
        break;
      }
      cout << "Ingrese ciudad de origen"<< endl;
      cin >> cOrigen;
      if (cOrigen == "QRO" || cOrigen == "qro"){
        initV = 0;
        precioO = 100;
      }
      else if(cOrigen == "SLP" || cOrigen == "slp"){
        initV = 2;
        precioO = 110;
      }
      else if(cOrigen == "ZAC" || cOrigen == "zac"){
        initV = 4;
        precioO = 120;
      }
      else if(cOrigen == "VER" || cOrigen == "ver"){
        initV = 1;
        precioO = 130;
      }
      else if (cDestino == "TMP" || cDestino == "tmp"){
        targetV = 6;
        precioD = 140;
      }
      else if(cOrigen == "MTY" || cOrigen == "mty"){
        initV = 7;
        precioO = 150;
      }
      else{
        cout << "Ingrese orígen válido de la tabla de rutas..." << endl;
        break;
      }
      
      cout << "Ingrese ciudad de destino"<< endl;
      cin >> cDestino;

      if (cDestino == "QRO" || cDestino == "qro"){
        targetV = 0;
        precioD = 100;
      }
      else if (cDestino == "SLP" || cDestino == "slp"){
        targetV = 2;
        precioD = 110;
      }
      else if (cDestino == "ZAC" || cDestino == "zac"){
        targetV = 4;
        precioD = 120;
      }
      else if (cDestino == "VER" || cDestino == "ver"){
        targetV = 1;
        precioD = 130;
      }
      else if (cDestino == "TMP" || cDestino == "tmp"){
        targetV = 6;
        precioD = 140;
      }
      else if (cDestino == "MTY" || cDestino == "mty"){
        targetV = 7;
        precioD = 150;
      }
      else{
        cout << "Ingrese destino válido de la tabla de rutas..." << endl;
        break;
      }

      if(precioD == precioO){
        precioR = 0;
        cout << "No puedes viajar a donde ya estás"<< endl;
        break;
      }
      else{
        precioR = precioO + precioD;
      }
      
      cout << "Precio por esta ruta: $" << precioR << endl;
      cout << g.BFS(initV, targetV) << endl;
      cout << '\n';
      break;

      case 7:

      if (fileCheck == false){
        cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
        cout << '\n';
        break;
      }

      gtest_ans = "vertex 0 : 2 7 vertex 1 : 5 6 vertex 2 : 0 4 vertex 3 : vertex 4 : 2 5 vertex 5 : 1 4 vertex 6 : 1 7 vertex 7 : 0 6 ";

      cout << " 1 " <<	(!gtest_ans.compare(g.printAdjList()) ? "success\n" : "fail\n");

      gtest_ans = "0 0 1 0 0 0 0 1 0 0 0 0 0 1 1 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 1 0 0 1 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 ";

      cout << " 2 " <<	(!gtest_ans.compare(g.printAdjMat()) ? "success\n" : "fail\n");

      gtest_ans = "visited: 0 7 path: 0 7";

      cout << " 3 " <<	( (!gtest_ans.compare(g.DFS(0,7))) ? "success\n" : "fail\n");

      gtest_ans = "visited: 0 2 7 path: 0 7";

      cout << " 4 " <<	( (!gtest_ans.compare(g.BFS(0,7))) ? "success\n" : "fail\n");
      
      break;

      case 8:
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

      case 9:
      cout << "FIN DE SESIÓN" << endl;
      exit = true;
    }
      
  }
}
