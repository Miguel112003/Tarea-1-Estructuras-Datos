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

void Lista::anxLista(Elemento elem){ //Anexa un elemento a la lista
  Nodo *tmp, *primero; //Creo dos nodos, uno temporal y uno llamado primero (Que hace primero?)
  Nodo* nuevo = new Nodo; //Se crea un nodo con la funcion new (Cuestiones de memoria dinamica)
  nuevo->dato = elem; //Se hace el nodo "nuevo" en su dato tenga el elemento a insertar en la lista
  nuevo->sig = nuevo; //Se hace el que nodo "nuevo" apunte a si mismo en su apuntador siguiente
  nuevo->ant = nuevo; //Se hace que el nodo "nuevo" apunte a si mismo en su apuntador anterior

  if(act == NULL) //Si la lista esta vacia
    act = nuevo; //Digo que la cabeza sea el nuevo nodo creado (Ya quedaria insertado)
  else{ //Sino
    tmp = act->ant; //se hace que temporal sea el nodo anterior a la cabeza
    tmp->sig = nuevo; //se hace que tmp en siguiente apunte al nuevo nodo
    nuevo->ant = tmp; //se hace que el nuevo nodo en anterior sea "temporal"
    nuevo->sig = act; //se hace que el nuevo nodo en siguiente sea la cabeza
    act->ant = nuevo; //Hago que la cabeza en anterior sea el nuevo nodo
  }
}
/*Se crea un nuevo nodo que se mete en la ultima pos de la lista
el nodo tmp era el ultimo nodo de la lista antes de meter nuevo
se hace que tmp apunte al nuevo, y que nuevo apunte a tmp y a la cabeza
y se manteiene la circularidad*/


void Lista::insLista(Elemento elem, int pos){ //Insertar elemento en una pos de la lista
  Nodo *nuevo, *tmp; //
  nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;
  nuevo->ant = NULL;

  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
      tmp = act->ant;
      tmp->sig = nuevo;
      nuevo->ant = tmp;
      nuevo->sig = act;
      act->ant = nuevo;
      act = nuevo;
    }
/*Si lo voy a insertar en la pos 1 hago que tmp sea el ultimo dato
 que nuevo sea el dato que voy a introducir, y apunte al ultimo (tmp)
y apunte a la cabeza de la lista, luego de eso hago que nuevo sea la nueva cabeza
haciendo que lo que era la cabeza vieja, solo sea un nodo mas
y el nuevo que introducimos sea la cabeza, apunte al ultimo y a la cabeza anterior
y se mantiene la circularidad
*/
    else{
      tmp = act;
      for(int i = 0; i < pos - 2; i++) //justo hasta la posicion donde quiero cambiar
        tmp = tmp->sig;   //Avanzo hasta la pos donde quiero cambiar (Hago que temporal sea el nodo antes de donde voy a insertar)
      nuevo->sig = tmp->sig; //Que el siguiente de nuevo, sea el siguiente de temporal
      nuevo->ant = tmp;    //Que el anterior de nuevo sea el temporal
      tmp->sig->ant = nuevo;  //El anterior del siguiente de tpm es nuevo
      tmp->sig = nuevo;   //Y que el siguiente de tmp sea nuevo
    }
  }
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

/*RESPECTO A LA COMPLEJIDAD DE LA SOBRECARGA DEL OPERADOR
se recorre cada lista una vez para copiar todos sus elementos en la nueva lista. Por lo tanto, la complejidad de la operación es lineal en la suma de las longitudes de las dos listas.
Además, en la última línea de la implementación, se actualizan los punteros anterior y siguiente del último nodo de la nueva lista para que apunten a sí mismo, cerrando así el ciclo.
Esta operación tiene una complejidad constante O(1) y no afecta la complejidad total de la operación.
Por lo tanto, la complejidad de la operación de concatenación de dos listas circulares dobles mediante la sobrecarga del operador '+' es O(n),
donde n es la suma de las longitudes de las dos listas.

*/

Lista Lista::operator+(Lista &l){
    Nodo* tmp = act;
    Lista nuevaLista;
    do{
        nuevaLista.anxLista(tmp->dato);
        tmp = tmp->sig;
    } while(tmp != act);

    tmp = l.act;
    do{
        nuevaLista.anxLista(tmp->dato);
        tmp = tmp->sig;
    } while(tmp != l.act);

    nuevaLista.act->ant = nuevaLista.act->ant->sig = nuevaLista.act;
    return nuevaLista;
}

