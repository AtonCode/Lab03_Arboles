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
void ArbolAVL<T>::Ajustar_Balance(NodoAVL<T>* nodo) {
    
    if ((Factor_Equilibrio(nodo)) >= 2) {
        Rotacion_Derecha(nodo);
    }
    else if ((Factor_Equilibrio(nodo)) <= -2) {
        Rotacion_Izquierda(nodo);
    }
    else {
        if (nodo ->getPadre() != nullptr) {
        Ajustar_Balance(nodo ->getPadre());
        }
    }
}
template <class T>
void Ajustar_altura(NodoAVL<T>* nodo) {
    if ((nodo -> getDerecha() == nullptr) && (nodo -> getIzquierda() == nullptr)) {
        nodo -> setAltura(0);
    }
    else if (nodo -> getDerecha() == nullptr) {
        if (nodo -> getIzquierda() != nullptr) {
            nodo -> setAltura(nodo -> getIzquierda() -> getAltura() + 1);
        }
    }
    else if (nodo -> getIzquierda() == nullptr) {
        if (nodo -> getDerecha() != nullptr) {
            nodo -> setAltura(nodo -> getDerecha() -> getAltura() + 1);
        }
    }
    else if ((nodo -> getDerecha() != nullptr) && (nodo -> getIzquierda() != nullptr)) {
        if ((nodo -> getDerecha() -> getAltura()) > (nodo -> getIzquierda() -> getAltura())) {
            nodo -> setAltura(nodo -> getDerecha() -> getAltura() + 1);
        }
        else {
            nodo -> setAltura(nodo -> getIzquierda() -> getAltura() + 1);
        }
    }

    if (nodo -> getPadre() != nullptr) {
        Ajustar_altura(nodo -> getPadre());
    }
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
bool ArbolAVL<T>::insertar(T Valor)
{
    if (raiz == nullptr) {
        raiz = new NodoAVL<T>(Valor);
        raiz->setDato(Valor);
        raiz->setPadre(nullptr);
        raiz->setAltura(0);
      }
      else {
        NodoAVL<T>* Nodo_Padre = raiz;
        NodoAVL<T>* Nuevo_Nodo = new NodoAVL<T>(Valor);
        Nuevo_Nodo -> setDato(Valor);
        while (Nodo_Padre != nullptr) {
          if (Valor > Nodo_Padre -> getDato()) {
            if (Nodo_Padre -> getDerecha() == nullptr) {
                Nuevo_Nodo -> setAltura(0);
                Nuevo_Nodo -> setPadre(Nodo_Padre);     
                Nodo_Padre -> setDerecha(Nuevo_Nodo);
                Ajustar_altura(Nodo_Padre);
                Ajustar_Balance(Nodo_Padre);
                break;
            }
            else {
              Nodo_Padre = Nodo_Padre -> getDerecha();
            }
          }
          else {
            if (Nodo_Padre -> getIzquierda() == nullptr) {
              Nuevo_Nodo -> setAltura(0);
              Nuevo_Nodo -> setPadre(Nodo_Padre);
              Nodo_Padre -> setIzquierda(Nuevo_Nodo) ;
              Ajustar_altura(Nodo_Padre);
              Ajustar_Balance(Nodo_Padre);
              break;
            }
            else {
              Nodo_Padre = Nodo_Padre -> getIzquierda();
            }
          }
        }
      }
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
void ArbolAVL<T>::Rotacion_Derecha(NodoAVL<T>* nodo) {
    
    if (raiz == nodo) {
        raiz = nodo -> getIzquierda();
        nodo -> getIzquierda() -> setPadre (nullptr);
    }
    else if ((nodo ->getPadre() ->getDato()) < (nodo ->getDato())) {
        nodo ->getPadre() -> setDerecha(nodo -> getIzquierda());
        nodo -> getIzquierda() -> setPadre(nodo ->getPadre());
        }
    else if ((nodo ->getPadre() ->getDato()) > (nodo ->getDato())) {
        nodo ->getPadre() -> setIzquierda(nodo -> getIzquierda());
        nodo -> getIzquierda() ->setPadre(nodo ->getPadre());
    }
    if (nodo -> getIzquierda() -> getDerecha() == nullptr) {
        nodo ->setPadre(nodo -> getIzquierda());
        nodo ->getPadre() -> setDerecha(nodo);
        nodo -> setIzquierda(nullptr);
    }
    else {
        nodo ->setPadre(nodo -> getIzquierda());
        nodo -> setIzquierda(nodo -> getIzquierda() -> getDerecha());
        nodo -> getIzquierda() ->setPadre( nodo);
        nodo ->getPadre() -> setDerecha( nodo);
    }
    Ajustar_altura(nodo);
    Ajustar_Balance(nodo);
}

template <class T>
void ArbolAVL<T>::Rotacion_Izquierda(NodoAVL<T>* nodo){
    if (nodo == raiz) {
        raiz = nodo -> getDerecha();
        nodo -> getDerecha() ->setPadre(nullptr);
    }
    else if ((nodo ->getPadre() ->getDato()) < (nodo ->getDato())) {
        nodo ->getPadre() -> setDerecha(nodo -> getDerecha());
        nodo -> getDerecha() ->setPadre( nodo ->getPadre());
    }
    else if ((nodo ->getPadre() ->getDato()) > (nodo ->getDato())) {
        nodo ->getPadre() -> setIzquierda(nodo -> getDerecha());
        nodo -> getDerecha() ->setPadre(nodo ->getPadre());
    }
    if (nodo -> getDerecha() -> getIzquierda() == nullptr) {
        nodo ->setPadre(nodo -> getDerecha());
        nodo ->getPadre() -> setIzquierda(nodo);
        nodo -> setDerecha(nullptr);
    }
    else {
        nodo -> setPadre(nodo -> getDerecha());
        nodo -> setDerecha(nodo -> getDerecha() -> getIzquierda());
        nodo -> getDerecha() ->setPadre(nodo);
        nodo -> getPadre() -> setIzquierda(nodo);      
        }
    Ajustar_altura(nodo);
    Ajustar_Balance(nodo);
}




