//Arbol AVL.hxx

#include <queue>
using namespace std;

template <class T>
ArbolAVL<T>::ArbolAVL()
{

}
template <class T>
ArbolAVL<T>::ArbolAVL(T val)
{
    raiz = new NodoAVL<T>(val);
}
template <class T>
ArbolAVL<T>::~ArbolAVL()
{

}
template <class T>
bool ArbolAVL<T>::esVacio()
{
    if(raiz == NULL)
        return true;
    return false;
}
template <class T>
NodoAVL<T>* ArbolAVL<T>::obtenerRaiz()
{
    return raiz;
}
template <class T>
void ArbolAVL<T>::fijarRaiz(NodoAVL<T>* nraiz)
{
    raiz = nraiz;
}

template <class T>
T ArbolAVL<T>::obtenerDatoRaiz()
{
    return raiz->getDato();
}

template<class T>
bool ArbolAVL<T>::insertar(T _dato)
{
    if(raiz->insertarNodo(_dato))
        return true;
    else
        return false;
}

template <class T>
bool ArbolAVL<T>::eliminar(T n)
{
    if(raiz == NULL)
        return false;
    else
    {
        raiz->eliminar(n);
    }
}


template <class T>
bool ArbolAVL<T>::buscar(T& n)
{
    if(raiz == NULL)
        return false;
    else
        return raiz->buscar(n);

}

template <class T>
int ArbolAVL<T>::altura()
{
    return alturaM(raiz) - 1;
}

template <class T>
int ArbolAVL<T>::alturaM(NodoAVL<T>* nodo)
{
    if (nodo == NULL)
    {
        return 0;
    }

    int izq = alturaM(nodo->getIzquierda());
    int der = alturaM(nodo->getDerecha());

    if (izq > der)
        return 1 + izq;
    else
        return 1 + der;
}

template <class T>
int ArbolAVL<T>::tamano(NodoAVL<T>* inicio)
{
    int cont = 0;
    if(inicio == NULL)
    {
        return 0;
    }
    else
    {
        cont++;
        
    }
    return cont + tamano(inicio->getIzquierda()) + tamano(inicio->getDerecha());
}

template <class T>
void ArbolAVL<T>::inOrden(NodoAVL<T>* inicio)
{
    if(inicio == NULL)
        return;
    else
    {
        inOrden(inicio->getIzquierda());
        cout << inicio->getDato() << " ";
        inOrden(inicio->getDerecha());
    }
}

template <class T>
void ArbolAVL<T>::preOrden(NodoAVL<T>* inicio)
{
    if(inicio != NULL)
    {
        cout << inicio->getDato() << " ";
        preOrden(inicio->getIzquierda());
        preOrden(inicio->getDerecha());
    }
}
template <class T>
void ArbolAVL<T>::posOrden(NodoAVL<T>* inicio)
{
    if(inicio == NULL)
        return;
    else
    {
        posOrden(inicio->getIzquierda());
        posOrden(inicio->getDerecha());
        cout << inicio->getDato() << " ";
    }
}

template <class T>
void ArbolAVL<T>::nivelOrden(NodoAVL<T>* inicio)
{
    queue< NodoAVL<T>* > cola;
    cola.push(inicio);
    while(!cola.empty())
    {
        cout << cola.front()->getDato() << " ";
        if(cola.front()->getIzquierda() != NULL)
            cola.push(cola.front()->getIzquierda());
        if(cola.front()->getDerecha() != NULL)
            cola.push(cola.front()->getDerecha());

        cola.pop();
    }
}
template <class T>
int Factor_Equilibrio(NodoAVL<T>* nodo) {
    int Valor;
    if ((nodo -> getAltura()) == 0) {
        Valor = 0;
    }
    else {
        if (((nodo -> getIzquierda()) != nullptr) && ((nodo -> getDerecha()) == nullptr)) {
        Valor = (nodo -> getIzquierda() -> getAltura()) + 1;
        }
        else if (((nodo -> getIzquierda()) == nullptr) && ((nodo -> getDerecha()) != nullptr)) {
        Valor = -(nodo -> getDerecha() -> getAltura()) - 1;
        }
        else if (((nodo -> getIzquierda()) != nullptr) && ((nodo -> getDerecha()) != nullptr)) {
        Valor = (nodo -> getIzquierda() -> getAltura()) - (nodo -> getDerecha() -> getAltura());
        }
    }
    return Valor;
}

template <class T>
void Ajustar_Balance(NodoAVL<T>* nodo) {
    if ((Factor_Equilibrio(nodo)) >= 2) {
        Rotacion_Derecha(nodo);
    }
    else if ((Factor_Equilibrio(nodo)) <= -2) {
        Rotacion_Izquierda(nodo);
    }
    else {
        if (nodo -> Padre != nullptr) {
        Ajustar_Balance(nodo -> Padre);
        }
    }
}
template <class T>
void Ajustar_altura(NodoAVL<T>* nodo) {
    if ((nodo -> getDerecha() == nullptr) && (nodo -> getIzquierda() == nullptr)) {
        nodo -> getAltura() = 0;
    }
    else if (nodo -> getDerecha() == nullptr) {
        if (nodo -> getIzquierda() != nullptr) {
            nodo -> getAltura() = (nodo -> getIzquierda() -> getAltura()) + 1;
        }
    }
    else if (nodo -> getIzquierda() == nullptr) {
        if (nodo -> getDerecha() != nullptr) {
            nodo -> getAltura() = (nodo -> getDerecha() -> getAltura()) + 1;
        }
    }
    else if ((nodo -> getDerecha() != nullptr) && (nodo -> getIzquierda() != nullptr)) {
        if ((nodo -> getDerecha() -> getAltura()) > (nodo -> getIzquierda() -> getAltura())) {
            nodo -> getAltura() = (nodo -> getDerecha() -> getAltura()) + 1;
        }
        else {
            nodo -> getAltura() = (nodo -> getIzquierda() -> getAltura()) + 1;
        }
    }

    if (nodo -> Padre != nullptr) {
        Ajustar_altura(nodo -> Padre);
    }
}

template <class T>
void Rotacion_Derecha(NodoAVL<T>* nodo) {
    if (nodo == Raiz) {
        Raiz = nodo -> getIzquierda();
        nodo -> getIzquierda() -> Padre = nullptr;
    }
    else if ((nodo -> Padre -> Dato) < (nodo -> Dato)) {
        nodo -> Padre -> getDerecha() = nodo -> getIzquierda();
        nodo -> getIzquierda() -> Padre = nodo -> Padre;
        }
    else if ((nodo -> Padre -> Dato) > (nodo -> Dato)) {
        nodo -> Padre -> getIzquierda() = nodo -> getIzquierda();
        nodo -> getIzquierda() -> Padre = nodo -> Padre;
    }
    if (nodo -> getIzquierda() -> getDerecha() == nullptr) {
        nodo -> Padre = nodo -> getIzquierda();
        nodo -> Padre -> getDerecha() = nodo;
        nodo -> getIzquierda() = nullptr;
    }
    else {
        nodo -> Padre = nodo -> getIzquierda();
        nodo -> getIzquierda() = nodo -> getIzquierda() -> getDerecha();
        nodo -> getIzquierda() -> Padre = nodo;
        nodo -> Padre -> getDerecha() = nodo;
    }
    Ajustar_altura(nodo);
    Ajustar_Balance(nodo);
}
template <class T>
void Rotacion_Izquierda(NodoAVL<T>* nodo){
    if (nodo == Raiz) {
        Raiz = nodo -> getDerecha();
        nodo -> getDerecha() -> Padre = nullptr;
    }
    else if ((nodo -> Padre -> Dato) < (nodo -> Dato)) {
        nodo -> Padre -> getDerecha() = nodo -> getDerecha();
        nodo -> getDerecha() -> Padre = nodo -> Padre;
    }
    else if ((nodo -> Padre -> Dato) > (nodo -> Dato)) {
        nodo -> Padre -> getIzquierda() = nodo -> getDerecha();
        nodo -> getDerecha() -> Padre = nodo -> Padre;
    }
    if (nodo -> getDerecha() -> getIzquierda() == nullptr) {
        nodo -> Padre = nodo -> getDerecha();
        nodo -> Padre -> getIzquierda() = nodo;
        nodo -> getDerecha() = nullptr;
    }
    else {
        nodo -> Padre = nodo -> getDerecha();
        nodo -> getDerecha() = nodo -> getDerecha() -> getIzquierda();
        nodo -> getDerecha() -> Padre = nodo;
        nodo -> Padre -> getIzquierda() = nodo;      
        }
    Ajustar_altura(nodo);
    Ajustar_Balance(nodo);
}




