#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
                    int dato;
                    pnodo sig;
                    pnodo ant;
                    };
typedef struct tlista{
                    pnodo inicio;
                    pnodo fin;
                    };

void IniciarLista(tlista &lista)
{
    lista.inicio = NULL;
    lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor)
{
    nuevo = new tnodo;
    if(nuevo != NULL)
    {
        nuevo -> dato = valor;
        nuevo -> sig = NULL;
        nuevo -> ant = NULL;
    }
}

void AgregarInicio(tlista &lista, pnodo nuevo)
{
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        nuevo->sig = lista.inicio;
        lista.inicio->ant = nuevo;
        lista.inicio = nuevo;
    }
}

void AgregarFinal(tlista &lista, pnodo nuevo){
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        lista.fin->sig = nuevo;
        nuevo->ant = lista.fin;
        lista.fin = nuevo;
    }
}

void QuitarInicio(tlista &lista){
    if (lista.inicio != NULL) {
        pnodo borrado = lista.inicio;

        if (lista.inicio == lista.fin) {
            lista.inicio = NULL;
            lista.fin = NULL;
        } else {
            lista.inicio = lista.inicio->sig;
            lista.inicio->ant = NULL;
        }

        delete borrado;
    } else {
        cout << "Lista vacia" << endl;
    }
}


void QuitarFinal(tlista &lista){
    if(lista.fin != NULL){
        pnodo borrado = lista.fin;

        if(lista.inicio == lista.fin){ 
            lista.inicio = NULL;
            lista.fin = NULL;
        }
        else{
            lista.fin = lista.fin->ant;     
            lista.fin->sig = NULL;          
        }

        delete borrado; 
    }
    else{
        cout << "Lista vacia" << endl;
    }
}
string binarios(int n){
    if(n==0)
    return "0";
    if(n==1)
    return "1";
    return binarios(n/2) + to_string(n%2);
}
void maxmin(tlista lista)
{
    if(lista.inicio!=NULL){
        int max=lista.inicio->dato;
        int min=lista.inicio->dato;
        pnodo aux = lista.inicio;
        while(aux != NULL){
            if(aux->dato > max)
                max = aux->dato;
            if(aux->dato < min)
                min = aux->dato;
            aux = aux->sig;
        }
        cout << "Maximo: " << max << endl;
        cout << "Minimo: " << min << endl;
    }
    else{
        cout << "Lista vacia" << endl;
    }
}

int main(){

    return 0;
}