#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <bits/stdc++.h>
#include "colors.h"
#include "Node.h"
#include "LinkedList.cpp"
#include <string.h>
using namespace std;

string aMayuscula(string cadena) {
  for (int i = 0; i < cadena.length(); i++)
    cadena[i] = toupper(cadena[i]);
    return cadena;
}

Color::Modifier green(Color::FG_GREEN);
Color::Modifier yellow(Color::FG_YELLOW);
Color::Modifier def(Color::FG_DEFAULT);

LinkedList* convertirLista(string palabra){
  LinkedList* l1;
  for(int i = palabra.length()-1; i>=0; i--){
    l1->add_at_head(palabra[i]);
  }
  return l1;
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

void compararListas(LinkedList* lista1, LinkedList* lista2){
  Node* n1 = lista1->head;
  Node* n2 = lista2->head;
  Node* equal_node;
  Node* node_in_llp;
  Node* not_in_llp;
  int i=0;
  int j=0;
  while(n2 != NULL){
      while(n1 != NULL){
        if(n1->value == n2->value){
          if(i==j){
            equal_node = n2;
            cout<<green<<equal_node->value<<endl;
          }else{
            node_in_llp = n2;
            cout<<yellow<<n2->value<<endl;
          }
        }else{
          n1 = n1->next;
          i++;
        }
      }
      n1 = lista1->head;
      i = 0;
      n2 = n2->next;
      j++;
    }
  not_in_llp = n2;
  cout<<def<<n2->value<<endl;
}

int main(){
string solucion = palabraAleatoria(diccionario);
LinkedList *LLP = convertirLista(solucion);  
cout << "Bienvenido a Wordle" << endl;
cout << "Inserta 1 para jugar o 0 para salir" << endl;
int opcion;
cin >> opcion;
LinkedList *LLI;
  if(opcion == 1){ //se ejecuta el programa
    cout << "La palabra a adivinar tiene " << solucion.length()<< " letras..." << endl;
    cout << "Tienes 6 intentos para adivinarla" << endl;
    string palabra;
    for(int i=0; i<6 ; i++){//intentos del usuario
      cin >> palabra;
      palabra = aMayuscula(palabra);
      if(palabra.length() == solucion.length()){
        LLI = convertirLista(palabra);
        if(solucion == palabra){
          cout << green << palabra << endl;
          cout << "Ganaste" << endl;
        }else{
          compararListas(LLP, LLI);
        }
      }else{
        cout << "¡Ingresa una palabra con " << solucion.length() << " letras!" << endl;
      }
    }
  }else if(opcion == 0){
    exit(opcion);
  }
}
