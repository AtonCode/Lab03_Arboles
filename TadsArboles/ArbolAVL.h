#ifndef ARBOLAVL_H_INCLUDED
#define ARBOLAVL_H_INCLUDED

#include "NodoAVL.h"

template < class T >
class ArbolAVL
{
    protected:
        NodoAVL<T>* raiz;
    public:
        ArbolAVL();
        ArbolAVL(T val);
        ~ArbolAVL();
        bool buscar(T& n);
        bool esVacio();
        bool insertar(T _dato);
        bool eliminar(T n);
        bool necesitaRotar(T _dato);
        int altura();
        int alturaM(NodoAVL<T>* inicio);
        int tamano(NodoAVL<T>* inicio);
        NodoAVL<T>* obtenerRaiz();
        NodoAVL<T>* rotacionDer();
        NodoAVL<T>* rotacionDerIzq();
        NodoAVL<T>* rotacionIzq();
        NodoAVL<T>* rotacionIzqDer();
        T obtenerDatoRaiz();
        void Ajustar_Balance(NodoAVL<T>* nodo);
        void fijarRaiz(NodoAVL<T>* nraiz);
        void inOrden(NodoAVL<T>* inicio);
        void nivelOrden(NodoAVL<T>* inicio);
        void posOrden(NodoAVL<T>* inicio);
        void preOrden(NodoAVL<T>* inicio);
        void Rotacion_Derecha(NodoAVL<T>* nodo);
        void Rotacion_Izquierda(NodoAVL<T>* nodo);
};

#include "ArbolAVL.hxx"

#endif // ARBOLBINARIO_H_INCLUDED
