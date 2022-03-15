// alias push="git add . && git commit -m ".gitignore" && git push"
//alias pull="git pull"
// alias run="g++ -std=c++11 main.cpp && ./a.out"

#include<iostream>
#include "TadsArboles/ArbolBinario.h"
#include "TadsArboles/ArbolBinarioOrd.h"
#include "TadsArboles/ArbolAVL.h"
using namespace std;

void arbolBinario(ArbolBinario<int> ArbolBinario);
void arbolOrdenado(ArbolBinarioOrd<int> arbolBinarioOrdenado);
void arbolAVL(ArbolAVL<int> arbolAVL);

int main(){

  ArbolBinario<int> ArbolBinario(33);
  arbolBinario(ArbolBinario);
  cout << endl;

  ArbolBinarioOrd<int> arbolBinarioOrdenado(12);
  arbolOrdenado(arbolBinarioOrdenado);
  cout << endl;

  ArbolAVL<int> arbolAVLp(55);
  arbolAVL(arbolAVLp);
    
    return 0;
}

void arbolBinario(ArbolBinario<int> ArbolBinario){

}

void arbolOrdenado( ArbolBinarioOrd<int> arbolBinarioOrdenado){
  system("clear");

    if(arbolBinarioOrdenado.insertar(7)){
      cout << "Se inserto el nodo correctamente" << endl;
    }
    else{
      cout << "No se inserto el nodo" << endl;
    }
    if(arbolBinarioOrdenado.insertar(6)){
      cout << "Se inserto el nodo correctamente" << endl;
    }
    else{
      cout << "No se inserto el nodo" << endl;
    }
        
    cout << "Raiz del arbol Ordenado: " << arbolBinarioOrdenado.obtenerDatoRaiz() << endl;
    cout << "La altura del arbol Ordenado es: " << arbolBinarioOrdenado.altura() << endl;
    cout << "El tamanio del arbol Ordenado es: " << arbolBinarioOrdenado.tamano(arbolBinarioOrdenado.obtenerRaiz()) << endl;
  
    cout << "El arbol ordenado por pre-orden es el siguiente: ";
    arbolBinarioOrdenado.preOrden(arbolBinarioOrdenado.obtenerRaiz());
    cout << endl;
    cout << "El arbol ordenado por in-orden es el siguiente: ";
    arbolBinarioOrdenado.inOrden(arbolBinarioOrdenado.obtenerRaiz());
    cout << endl;
    cout << "El arbol ordenado por pos-orden es el siguiente: ";
    arbolBinarioOrdenado.posOrden(arbolBinarioOrdenado.obtenerRaiz());
    cout << endl;
    cout << "El arbol ordenado por nivel-orden es el siguiente: ";
    arbolBinarioOrdenado.nivelOrden(arbolBinarioOrdenado.obtenerRaiz());
    cout << endl;
}

void arbolAVL(ArbolAVL<int> arbolAVL){

  if(arbolAVL.insertar(9)){
      cout << "Se inserto el nodo correctamente" << endl;
    }
    else{
      cout << "No se inserto el nodo" << endl;
    }
    if(arbolAVL.insertar(5)){
      cout << "Se inserto el nodo correctamente" << endl;
    }
    else{
      cout << "No se inserto el nodo" << endl;
    }
        
    cout << "Raiz del ArbolAVL: " << arbolAVL.obtenerDatoRaiz() << endl;
    cout << "La altura del ArbolAVL es: " << arbolAVL.altura() << endl;
    cout << "El tamanio del ArbolAVL es: " << arbolAVL.tamano(arbolAVL.obtenerRaiz()) << endl;
  
    cout << "El ArbolAVL por pre-orden es el siguiente: ";
    arbolAVL.preOrden(arbolAVL.obtenerRaiz());
    cout << endl;
    cout << "El ArbolAVL por in-orden es el siguiente: ";
    arbolAVL.inOrden(arbolAVL.obtenerRaiz());
    cout << endl;
    cout << "El ArbolAVL por pos-orden es el siguiente: ";
    arbolAVL.posOrden(arbolAVL.obtenerRaiz());
    cout << endl;
    cout << "El ArbolAVL por nivel-orden es el siguiente: ";
    arbolAVL.nivelOrden(arbolAVL.obtenerRaiz());
    cout << endl;
}

