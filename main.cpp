// alias push="git add . && git commit -m ".gitignore" && git push"
//alias pull="git pull"
// alias run="g++ -std=c++11 main.cpp && ./a.out"

#include<iostream>
#include <stdio.h>
#include <iterator>
#include "TadsArboles/ArbolBinario.h"
#include "TadsArboles/ArbolBinarioOrd.h"
#include "TadsArboles/ArbolAVL.h"


using namespace std;

void creadorArbolBinario(ArbolBinario<int> arbolBinario, int padre, int hijo);
void arbolOrdenado(ArbolBinarioOrd<int> arbolBinarioOrdenado);
void arbolAVL(ArbolAVL<int> arbolAVL);
ArbolAVL<int> convertirArbolBinarioToArbolAVL(ArbolBinario<int> arbolBinario);

/**
 1.	Cree un Programa que convierta 5 árboles binarios básicos en arboles AVL 
    (El programa tiene que CONVERTIR el árbol, no balancear un árbol)

 */

int main(){

  system("clear");

// Crenado Arboles Binarios
  ArbolBinario<int> arbolBinarioUNO(1);
  ArbolBinario<int> arbolBinarioDOS(6);
  ArbolBinario<int> arbolBinarioTRES(10);
  ArbolBinario<int> arbolBinarioCUATRO(15);
  ArbolBinario<int> arbolBinarioCINCO(20);

  creadorArbolBinario(arbolBinarioUNO, 1, 2);
  creadorArbolBinario(arbolBinarioDOS, 6, 7);
  creadorArbolBinario(arbolBinarioTRES, 10, 11);
  creadorArbolBinario(arbolBinarioCUATRO, 15, 16);
  creadorArbolBinario(arbolBinarioCINCO, 20, 21);

//Convietiendo arboleBinarios a AVL
  ArbolAVL<int> arbolAVLuno = convertirArbolBinarioToArbolAVL(arbolBinarioUNO);
  ArbolAVL<int> arbolAVLdos = convertirArbolBinarioToArbolAVL(arbolBinarioDOS);
  ArbolAVL<int> arbolAVLtres = convertirArbolBinarioToArbolAVL(arbolBinarioTRES);
  ArbolAVL<int> arbolAVcuatro = convertirArbolBinarioToArbolAVL(arbolBinarioCUATRO);
  ArbolAVL<int> arbolAVcinco = convertirArbolBinarioToArbolAVL(arbolBinarioCINCO);
  

//iMPRIMIR binario y avl
  arbolBinario(arbolBinarioUNO);
  cout << endl;
  arbolAVL(arbolAVLuno);
  cout << endl;
  cout << endl;
    
    return 0;
}


void creadorArbolBinario(ArbolBinario<int> arbolBinario, int padre, int hijo){

  if(arbolBinario.insertar(padre,hijo)){
      cout << "Se inserto el nodo correctamente" << endl;
    }
    else{
      cout << "No se inserto el nodo" << endl;
    }
    if(arbolBinario.insertar(hijo,hijo+1)){
      cout << "Se inserto el nodo correctamente" << endl;
    }
    else{
      cout << "No se inserto el nodo" << endl;
    }
        
    cout << "Raiz del arbolBinario: " << arbolBinario.obtenerDatoRaiz() << endl;
    cout << "La altura del arbolBinario es: " << arbolBinario.altura() << endl;
    cout << "El tamanio del arbolBinario es: " << arbolBinario.tamano(arbolBinario.obtenerRaiz()) << endl;
  
    cout << "El arbolBinario por pre-orden es el siguiente: ";
    arbolBinario.preOrden(arbolBinario.obtenerRaiz());
    cout << endl;
    cout << "El arbolBinario por in-orden es el siguiente: ";
    arbolBinario.inOrden(arbolBinario.obtenerRaiz());
    cout << endl;
    cout << "El arbolBinario por pos-orden es el siguiente: ";
    arbolBinario.posOrden(arbolBinario.obtenerRaiz());
    cout << endl;
    cout << "El arbolBinario por nivel-orden es el siguiente: ";
    arbolBinario.nivelOrden(arbolBinario.obtenerRaiz());
    cout << endl;
}

void arbolOrdenado( ArbolBinarioOrd<int> arbolBinarioOrdenado){
  
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


ArbolAVL<int> convertirArbolBinarioToArbolAVL(ArbolBinario<int> arbolBinario){
  list<int> inOrdenListBInaryTree;
  
  if(!arbolBinario.esVacio()){

    int counter = 0;
    int raiz = arbolBinario.obtenerDatoRaiz();
    int tamanoArbol = arbolBinario.tamano(arbolBinario.obtenerRaiz());
    ArbolAVL<int> arbolAVL(raiz);

    //Recorrer el arbolBinarion inOrden e ingresar los datos al AVL
    inOrdenListBInaryTree =  arbolBinario.inOrden(arbolBinario.obtenerRaiz());
    //Incertar por izquierada hasta llegar a la raiz, luego por derecha
    for (auto it = inOrdenListBInaryTree.begin(); it != inOrdenListBInaryTree.end(); ++it){
       //Por Izquierda
        if(inOrdenListBInaryTree.pop_front() != raiz){
            if(arbolAVL.insertar(inOrdenListBInaryTree.pop_front()))
              counter++;
        } 
        //Por derecha
        else{
          if(arbolAVL.insertar(inOrdenListBInaryTree.pop_front()))
              counter++;//Ignorar Raiz
          if(arbolAVL.insertar(inOrdenListBInaryTree.pop_front()))
              counter++;
        }
        
    }

    
  }
  if(counter == tamanoArbol){
    cout << "Se incertaron todos los datos" << endl;
  }
  return arbolAVL;
}