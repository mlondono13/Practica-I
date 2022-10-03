#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <bits/stdc++.h>
#include "colors.h"
#include "Node.h"
#include <string.h>
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
Color::Modifier cyan(Color::FG_CYAN);
Color::Modifier blue(Color::FG_BLUE);
Color::Modifier red(Color::FG_RED);

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
void comparar2(Node* LLPhead, Node* LLIhead){
  Node* llp2 = LLPhead;
  Node* lli2 = LLIhead;
  int i = 0;
  int j = 0;
  while(lli2){
    i = 0;
    llp2 = llp2;
    while(llp2){
      if(lli2->value == llp2->value){
        if (i!=j){
          lli2->color = "yellow";
          }
        }
      llp2 = llp2->next;
      i++;
    }
    lli2 = lli2->next;
    j++;
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
        if (i!=j){
          comparar2(llp, lli);
        }else{
          lli->color = "green";
        }
       
      }
      llp = llp->next;
      i++;
      lli = lli->next;
      j++;
    }
    
    
  }
}

bool imprimirColor(Node* LLI, Node* LLP){
  Node* lli = LLI;
  while(lli != NULL){
    if(lli->color == "yellow"){
      cout<<yellow<<lli->value<<def;
    }else if (lli->color == "green"){
      cout<<green<<lli->value<<def;
    }else{
      cout<<lli->value;
    }
    lli = lli->next;
  }
  if(LLI == LLP){
    cout << red << " ¡Ganaste! " << def << endl;
    return true;
  }else{
    return false;
  }
}


int main(){
  string solucion = palabraAleatoria(diccionario);
  Node* LLP = convertirLista(solucion);  
  cout << cyan << "  ¡Bienvenido a Wordle!" << def << endl;
  cout << blue << "Inserta 1 para jugar o 0 para salir" << def<< endl;
  int opcion;
  cin >> opcion;
  Node* LLI;
  bool verificar;
  if(opcion == 1){ //se ejecuta el programa
    cout << blue << "La palabra a adivinar tiene " << red << solucion.length()<< blue << " letras..." << def << endl;
    cout << blue << "  Tienes 6 intentos para adivinarla" << def <<endl;
    string palabra;
    int intentos;
    for(intentos=0; intentos<6 ; intentos++){//intentos del usuario
      cout<<"\nIntento "<<intentos+1<<": ";
      cin >> palabra;
      palabra = aMayuscula(palabra);
      LLI = convertirLista(palabra);
      if(palabra.length() == solucion.length()){
        if (palabra==solucion){
          intentos = 6;
          break;
        }else{
          comparar(LLP, LLI);
          verificar = imprimirColor(LLI, LLP);
          reset(LLI);
          if(verificar == true){
            break;
          }
        }
      }else{
        cout << "¡Ingresa una palabra con " << solucion.length() << " letras!" << endl;
        intentos--;
      }
       
    } if(intentos <= 6 && palabra != solucion){
       cout<<"\nUps...sigue intentando"<<endl;
       cout<<"La palabra correcta es:"<<green<<solucion<<endl;
      } else {
      cout<< red << "  ¡Ganaste!" << def;
      } 
    }
    
  else if(opcion == 0){
    cout << cyan << "Hasta pronto!" << def;
    exit(opcion);  
  }
} 
