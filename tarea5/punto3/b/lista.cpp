#include "lista.h"

Nodo::~Nodo(){ //Destructor de la clase nodo
  cout << "Borrando nodo " << dato << endl;
  sig = NULL;
  ant = NULL;
  delete sig;
  delete ant;
}

Lista::Lista(){ //Constructor de la clase lista
  act = NULL;
}


void Lista::elimLista(int pos){
  Nodo *tmp, *borrar;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
      if(act != act->sig){
        tmp = act->ant;
        borrar = tmp->sig;
        act = act->sig;
        act->ant = tmp;
        tmp->sig = act;
      }
      else{
        borrar = act;
        act = NULL;
      }
    }
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
          tmp = tmp->sig;
      borrar = tmp->sig;
      Nodo* sig = tmp->sig->sig;
      tmp->sig = sig;
      sig->ant = tmp;
    }

    delete borrar;
  }
}

Elemento Lista::infoLista(int pos){ //Nos dice que hay en un elemento de la lista
   Nodo* tmp = act; //Hago que tmp sea la cabeza

   for(int i = 1; i < pos; i++)
      tmp = tmp->sig; //recorro hasta la posicion donde quiero saber que valor hay

   return tmp->dato; //retorno el valor que hay
}

int Lista::longLista(){
  int ans; //Creo la var de longitud
  if(vaciaLista())
    ans = 0; //Si esta vacia, pues longitud 0
  else{
    Nodo* tmp, *primero;
    int cont = 1;
    tmp = act; //Empiezo en la cabeza
    primero = act; //Hago que primero sea la cabeza

    while(tmp->sig != primero){
      tmp = tmp->sig; //Recorro hasta que el siguiente de temporal, sea la cabeza
      cont++; //Sumo al contador
    }

    ans = cont; //Retorno el largo de la lista
  }

  return ans;
}

bool Lista::vaciaLista(){ //Verifica si la cabeza apunta a NULL, de ser asi, esta vacia
   return act == NULL;
}




/*COMPLEJIDAD DE ESTA OPERACION:
La complejidad de esta operacion depende directamente del caso que se este considerando, dividamos esos casos en 3 posibilidades
1. El elemento debe ser insertado al principio de la lista
2. El elemento debe ser insertado al final de la lista
3. El elemento debe ser insertado entre el principio y el final de la lista

En el caso 1 es el mas simple de todos, pues puede ser debido a que la lista este vacia, caso tal tendria una complejidad O(1).
O puede ser que simplemente la lista tenga n elementos pero el dato sea menor a todos, en tal caso el ciclo while nunca se cumple
y solo se inserta el nodo, haciendolo al final la nueva cabeza, por lo que seria una complejidad de O(1)

En el caso numero 2 y numero 3 la complejidad es similar, pues en ambos casos se debe recorrer la lista hasta hallar
la posicion donde almacenar el nuevo nodo, naturalmente el peor caso es cuando debe insertarse al final del todo
pues nos obliga a recorrer toda la lista hasta descubrir que el elemento debe ir al final de la lista, luego de esto simplemente
se mete el nuevo nodo. Dandonos una complejidad de O(n), siendo n el tamaño de la lista

PEOR CASO: O(n)
MEJOR CASO: O(1)

*/

void Lista::insListaOrdenada(Elemento elem){
    Nodo* nuevo = new Nodo;
    nuevo->dato = elem;
    if(vaciaLista()){
        nuevo->sig = nuevo->ant = nuevo;
        act = nuevo;
    }
    else{
        Nodo *tmp = act;
        while(tmp->sig != act && tmp->dato < elem)
            tmp = tmp->sig;

        if(tmp->dato >= elem){
            nuevo->sig = tmp;
            nuevo->ant = tmp->ant;
            tmp->ant->sig = nuevo; //El siguiente del anterior de tmp
            tmp->ant = nuevo;
            if(tmp == act){ //El ciclo no se cumple si el dato debe ser colocado antes, por lo tanto solo lo meto como nueva cabeza
                act = nuevo;
            }
        }   else{ //Esto es por si el elemento debe insertarse al final de la lista, hago que tmp sea el ultimo y con eso inserto el nuevo nodo
            nuevo->sig = act;
            nuevo->ant = tmp;
            tmp->sig = nuevo;
            act->ant = nuevo;
        }
    }
}
/* Lo que hago es que Tengo la lista ordenada,y creo el nuevo Nodo
luego creo el nodo temporal para ir hasta el que tengo que meter la posicion, ubicandome despues del que voy a meter
luego igualo el temporal a ese nodo que esta despues de donde voy a introducir y hago que nuevo apunte a ese tmp
apunte al anterior del tmp, y hago que tmp apunte antes a nuevo y que el anterior a nuevo, apunte a nuevo, relativo a tmp
que es lo que conozco.
*/
