/*Utilizando listas simples implemente:
a. TDA Pila y sus operaciones fundamentales.
b. TDA Cola y sus operaciones fundamentales (incluya un contador de
elementos para la cola).
*/
#include <iostream>
using namespace std;
typedef struct tnodo *punt;
struct tnodo{
    int dato;
    punt sig;
};
void menu(int &n);
void init_queue(punt &cola, int &contador);
void push_queue(punt &cola, int &contador);
punt pop_queue(punt &cola, int &contador);
bool is_empty_queue(punt cola);
punt top(punt cola);
punt bottom(punt cola);

int main(){
    punt cola;
    int contador,n;


    do{

        menu(n);
        switch (n)
        {
        case 1:
            init_queue(cola, contador);
            cout << "Cola inicializada." << endl;
            break;
        case 2:
            push_queue(cola, contador);
            cout << "Elemento agregado a la cola." << endl;
            break;
        case 3:
            if (!is_empty_queue(cola)) {
                punt eliminado = pop_queue(cola, contador);
                cout << "Elemento eliminado: " << eliminado->dato << endl;
                delete eliminado; // Liberar memoria del nodo eliminado
            } else {
                cout << "Error: Cola vacia." << endl;
            }
            break;
        case 4:
            if (!is_empty_queue(cola)) {
                punt frente = top(cola);
                cout << "Elemento en el frente de la cola: " << frente->dato << endl;
            } else {
                cout << "Error: Cola vacia." << endl;
            }
            break;
        case 5:
            if (!is_empty_queue(cola)) {
                punt final = bottom(cola);
                cout << "Elemento al final de la cola: " << final->dato << endl;
            } else {
                cout << "Error: Cola vacia." << endl;
            }
            break;
            case 0:
            cout << "Saliendo del programa." << endl;
            break;
        case 6:
        if(is_empty_queue(cola))
            cout<<"Cola vacia."<<endl;
        else
            cout<<"Cola no vacia."<<endl;
            break;
        default:
            cout << "Opcion no valida, por favor intente de nuevo." << endl;
            break;
        }
    
    }while(n=!0);
    return 0;
};

void menu(int &n){
    cout << "Menu de opciones:" << endl;
    cout << "1. Inicializar cola" << endl;
    cout << "2. Agregar elemento a la cola" << endl;
    cout << "3. Eliminar elemento de la cola" << endl;
    cout << "4. Ver elemento en el frente de la cola" << endl;
    cout << "5. Ver elemento al final de la cola" << endl;
    cout << "6. Verificar si la cola esta vacia" << endl;
    cout << "0. Salir" << endl;
    cin >> n;
};
void init_queue(punt &cola, int &contador) {
    cola = NULL; 
    contador = 0; 
};
void push_queue(punt &cola, int &contador){
    int nuevo_dato;
    punt aux=cola;
    punt nuevo=new tnodo;
    cout<<"Ingrese un dato para agregar a la cola: ";
    cin >> nuevo_dato;
    nuevo->dato = nuevo_dato;
    nuevo->sig = NULL;
    if(is_empty_queue(cola))
    {
        cola=nuevo;
    }
    else{
        while(aux->sig !=NULL){
            aux = aux->sig; // Buscar el último nodo
        };
        aux->sig=nuevo;
    }
    contador++;
};
punt pop_queue(punt &cola, int &contador){
    punt eliminado=cola,aux;
    if (is_empty_queue(cola))
        return NULL;
    else{
        cola=cola->sig;
        return eliminado;

    }
};
bool is_empty_queue(punt cola){
    return cola == NULL;
};
punt top(punt cola){
    if (is_empty_queue(cola)) {
        return NULL;
    }
    else{
        return cola;
    }
    
};
punt bottom(punt cola){
    if(is_empty_queue(cola))
    return NULL;
    punt aux = cola;
    while(aux->sig != NULL){
        aux = aux->sig;
    };
    return aux;
};