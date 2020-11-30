// A01706212 Manolo Medina
// Integradora 5 Hashes

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include "chain.h"

using namespace std;

unsigned int myHash(const string s) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}

int main() {

    bool fileCheck = false;
    bool check = false;
    ifstream inFile;
    ofstream output;
    string fileName, line;
    string nLine [84] = { };
    string meses [12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
    string mes;

    string c_ans;

    Chain <string, int> chain_hash(20, myHash); //Se crea tabla chain hash para las temperaturas de los meses
    Chain <string, int> test_chain(10, myHash); //Se crea tabla chain hash para casos de prueba

    bool exit = false;
    while(exit == false){
        int option;
        string addMes;
        int addLtemp;
        cout << "Selecciona una opción: "<< endl;
        cout << "Los valores con los que se trabaje deben de ser ENTEROS: "<< endl;
        cout << "(1) Leer archivo de Temperaturas"<< endl;
        cout << "(2) Leer Tabla Hash"<< endl;
        cout << "(3) Modificar datos Hash"<<endl;
        cout << "(4) Generar Archivo con tabla Hash" << endl;
        cout << "(5) Casos de Prueba" << endl;
        cout << "(6) Salir" << endl;
        cin>> option;
        if (option == 1){
          fileCheck = true;
        }
        switch(option){
            case 1:
                cout << "Introduzca ruta o nombre del archivo: "<< endl;
                cin >> fileName;
                inFile.open(fileName);
                while(getline(inFile, line)){
                    stringstream ss(line);
                    getline(ss, mes, ':');
                    for(int i = 0; i <= 6; i++){
                        int num = 0;
                        getline(ss, nLine[i], ',');
                        
                        num = stoi(nLine[i]);

                        chain_hash.put(mes, num); //Se añade el mes y la última temperatura registrada de dicho mes en el hash, se utilizó chain para evitar colisiones.
                    }
                    
                }
                inFile.close();
                cout << '\n';
                cout << "Success... "<<endl;
                cout << '\n';

                break;
                
            case 2:
            if (fileCheck == false){
              cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
              cout << '\n';
              break;
            }
                cout << chain_hash.toString() << endl; //Se imprime tabla hash
                break;
            
            case 3:
            // Este caso nos permite modificar las últimas temperaturas registradas, siempre y cuando se ingrese el mes con el formato de nombre completo y con la primera letra mayúscula, en caso de no ser así no se permite modificar la tabla hash, esto es así porque en caso de ser diferente, la tabla permitiría añadir el valor nuevo y eso no es de utilidad para este caso.

            if (fileCheck == false){
              cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
              cout << '\n';
              break;
            }
            cout << "Ingrese mes que desee modificar: " << endl;
            cin >> addMes;
            if(addMes == "Enero" || addMes == "Febrero" || addMes == "Marzo" || addMes == "Abril" || addMes == "Mayo" || addMes == "Junio" || addMes == "Julio" || addMes == "Agosto" || addMes == "Septiembre" || addMes == "Octubre" || addMes == "Noviembre" || addMes == "Diciembre"){
              cout << "Ingrese última temperatura registrada de dicho mes que desee modificar: " << endl;
              cin >> addLtemp;
              chain_hash.put(addMes, addLtemp);
              cout << chain_hash.toString() << endl;
              cout << '\n';
              break;
            }
            else{
              cout << "Por favor ingrese dato válido..." << endl;
              break;
            }
                
            case 4:
            //Generación de archivos
            if (fileCheck == false){
              cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
              cout << '\n';
              break;
            }
                cout << "Generando bitacora de hash: " << endl;
                cout << '\n';
                output.open("hash.txt");
                if (output.is_open()){
                  output << chain_hash.toString();
                  cout << chain_hash.toString()<<endl;
                  
                }
                output.close();
                break;
            
            case 5:
            //Casos de prueba con el hash de testing, se utilizó un hash de testing para validar que funciona correctamente el hash chain.

              test_chain.put(string("mes"), 11);
			        test_chain.put(string("semana"), 4);
              test_chain.put(string("día"), 30);
              test_chain.put(string("hora"), 7);
              test_chain.put(string("minuto"), 21);
              test_chain.put(string("segundo"), 35);
              test_chain.put(string("milésima"), 10);
              

              c_ans = "(0 [milésima : 10]) (3 [día : 30]) (5 [mes : 11]) (6 [hora : 7]) (7 [segundo : 35]) (8 [minuto : 21]) (9 [semana : 4]) ";

              cout << " 1 " <<	( (!c_ans.compare(test_chain.toString().c_str())) ? "success\n" : "fail\n");

              test_chain.put(string("juan"), 21);

              c_ans = "(0 [milésima : 10] [juan : 21]) (3 [día : 30]) (5 [mes : 11]) (6 [hora : 7]) (7 [segundo : 35]) (8 [minuto : 21]) (9 [semana : 4]) ";

              cout << " 2 " <<	( (!c_ans.compare(test_chain.toString().c_str())) ? "success\n" : "fail\n");

              test_chain.put(string("luna"), 10);

              c_ans = "(0 [milésima : 10] [juan : 21]) (2 [luna : 10]) (3 [día : 30]) (5 [mes : 11]) (6 [hora : 7]) (7 [segundo : 35]) (8 [minuto : 21]) (9 [semana : 4]) ";

              cout << " 3 " <<	( (!c_ans.compare(test_chain.toString().c_str())) ? "success\n" : "fail\n");

              test_chain.put(string("vostok"), 68);

              c_ans = "(0 [milésima : 10] [juan : 21]) (2 [luna : 10]) (3 [día : 30]) (5 [mes : 11]) (6 [hora : 7]) (7 [segundo : 35]) (8 [minuto : 21] [vostok : 68]) (9 [semana : 4]) ";

              cout << " 4 " <<	( (!c_ans.compare(test_chain.toString().c_str())) ? "success\n" : "fail\n");

              cout << '\n';
              break;

            case 6:
                cout << "FIN DE SESIÓN\n";
                exit = true;
            
        }
    }
    
}
