#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <bits/stdc++.h>
#include "colors.h"
#include "Node.h"
#include <string.h>
#include <list>
#include <iterator>
using namespace std;

string aMayuscula(string cadena) {
  for(int i = 0; i < cadena.length(); i++){
    cadena[i] = toupper(cadena[i]);
  }
  return cadena;
}

Color::Modifier green(Color::FG_GREEN);
Color::Modifier yellow(Color::FG_YELLOW);
Color::Modifier def(Color::FG_DEFAULT);

Node* convertirLista(string palabra){
  Node* head = new Node(palabra[0]);
  Node* temp = head;
  for(int i = 1; i<palabra.size(); i++){
    temp->next = new Node(palabra[i]);
    temp = temp->next;
  }
  return head;
}

string diccionario[] = {"COSTA", "GORRA", "BOLSA", "BALON", "LISTA", "PERRO", "ARROZ", "PALMA", "ARBOL", "PLAYA", "GATO"};

int obtenerNumeroRandom(){
  srand(time(NULL));
  int numRandom = rand()%11;
  return numRandom;
}

string palabraAleatoria(string diccionario[]){//arroja una palabra aleatoria
  int numeroAleatorio = obtenerNumeroRandom();
  string palabraAleatoria = diccionario[numeroAleatorio];
  return palabraAleatoria ;
}

void reset(Node* LLI){
  while(LLI != NULL){
    LLI->color = "default";
    LLI = LLI->next;
  }
}

void comparar(Node* LLPhead, Node* LLIhead){
  Node* llp = LLPhead;
  Node* lli = LLIhead;
  int i = 0;
  int j = 0;
  while(lli != NULL){
    i = 0;
    llp = llp;
    while(llp != NULL){
      if(lli->value == llp->value){
        if (j==i){
          lli->color = "green";
          break;
        }else{
          lli->color = "yellow";
        }
      }
      llp = llp->next;
      i++;
    }
    lli = lli->next;
    j++;
  }
}

bool imprimirColor(Node* LLI, Node* LLP){
  Node* lli = LLI;
  while(lli != NULL){
    if(lli->color == "green"){
      cout<<green<<lli->value<<def;
    }else if (lli->color == "yellow"){
      cout<<yellow<<lli->value<<def;
    }else{
      cout<<lli->value;
    }
    lli = lli->next;
  }
  if(LLI == LLP){
    cout << "Ganaste!" << endl;
    return true;
  }else{
    return false;
  }
}
/*bool verificarGanar(Node* LLP, Node* LLI){
  Node* llp = LLP;
  Node* lli = LLI;
  
}*/


int main(){
  string solucion = palabraAleatoria(diccionario);
  Node* LLP = convertirLista(solucion);  
  cout << "Bienvenido a Wordle" << endl;
  cout << "Inserta 1 para jugar o 0 para salir" << endl;
  int opcion;
  cin >> opcion;
  Node* LLI;
  bool verificar;
  if(opcion == 1){ //se ejecuta el programa
    cout << "La palabra a adivinar tiene " << solucion.length()<< " letras..." << endl;
    cout << "Tienes 6 intentos para adivinarla" << endl;
    string palabra;
    int intentos;
    for(intentos=0; intentos<6 ; intentos++){//intentos del usuario
      cout<<"\nIntento "<<intentos+1<<": ";
      cin >> palabra;
      palabra = aMayuscula(palabra);
      LLI = convertirLista(palabra);
      if(palabra.length() == solucion.length()){
        comparar(LLP, LLI);
        verificar = imprimirColor(LLI, LLP);
        reset(LLI);
        if(verificar == true){
          break;
        }
      }else{
        cout << "¡Ingresa una palabra con " << solucion.length() << " letras!" << endl;
        intentos--;
      }
       
    } if(intentos == 6){
       cout<<"\nUps...sigue intentando"<<endl;
       cout<<"La palabra correcta es: "<<green<<solucion<<endl;
      } 
    }
    
  else if(opcion == 0){
    cout<<"Hasta pronto!";
    exit(opcion);  
  }
} 
