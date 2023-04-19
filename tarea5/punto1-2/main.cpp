#include "lista.h"
#include <iostream>


/*La complejidad de esta operacion "contarOcurrencias":
Esta operacion tiene una complejidad que depende de si la
lista esta vacia o no, en caso de estarlo la complejidad
es O(1), es decir constante, ya que solo analiza la funcion
de "vaciaLista()" la cual tiene una complejidad de O(1).

En el peor caso, la complejidad de esta operacion depende del tamaño
de la lista que denominaremos como la variable n.
entonces al utilizar la funcion "longLista()" que posee una complejidad
de O(n) (Ya que recorre toda la lista y retorna un contador)
esto en conjunto que se hace un ciclo para recorrer los elementos
de la lista usando "infoLista()" que tiene una complejidad de O(n) en
el peor caso, tendriamos una complejidad total de O(n^2) ya que
debemos conocer el tamaño de la lista que cuesta O(n) y ademas
recorrerla y obtener las ocurrencias O(n)

MEJOR CASO: O(1)
PEOR CASO: O(n^2)
Siendo n = tamaño de la lista

*/
int contarOcurrencias(Lista &l, Elemento v){
  int contador = 0;
  if(l.vaciaLista())
    contador = 0;
  else{
    int len = l.longLista();
    Elemento i = 1;
    while(i <= len){
      if(l.infoLista(i) == v)
        contador++;
      i++;
    }
  }
  return contador;
}

/*La complejidad de esta operacion "obtenerMenores":
La complejidad de esta operacion depende de las otras operaciones
utilizadas en la funcion, "longLista(), infoLista(), anxLista()"
en el principio se utiliza la funcion longLista que tiene una complejidad
de O(n) ya que recorre todos los elementos de la lista y retorna
su tamaño.
luego de esto se recorre la lista en un ciclo y se verifica en cada caso
si el elemento de la lista es menor al elemento dado, esto
tiene una complejidad de O(n), ya que infolista recibe una posicion
y recorre hasta esa posicion y retorna su elemento.
Despues de esto se utiliza anxLista() que tiene una complejidad de O(1) en
las listas circulares dobles, y se anexa el dato.
Por lo tanto analizandolo en el peor y mejor caso

MEJOR CASO (LISTA VACIA): O(1)
PEOR CASO (TODOS LOS ELEMENTOS SON MENORES A V): O(n^2)
Es asi ya que se debe obtener el tamaño de la lista y por cada
dato de la lista se debe verificar si es menor.

*TODO ESTO SIENDO n EL TAMAÑO DE LA LISTA
 
*/
Lista obtenerMenores(Lista &l, Elemento v){
  Lista l2;
  int len = l.longLista();
  Elemento i = 1;
  while(i <= len){
    Elemento dato = l.infoLista(i);
    if(dato < v)
      l2.anxLista(dato);
    i++;
  }
  return l2;
}


int main(){
  Lista l1;
  l1.anxLista(4);
  l1.anxLista(12);
  l1.anxLista(1);
  l1.anxLista(2);
  l1.anxLista(14);
  l1.anxLista(4);
  l1.anxLista(2);
  l1.anxLista(4);

  Elemento k = 4;

  cout << "Ejemplo de contarOcurrencias(l1, k)" << endl;
  int ocurrencias = contarOcurrencias(l1, k);
  cout << ocurrencias << endl;

  cout << "Ejemplo de obtenerMenores(l1,k)" << endl;

  Lista menores = obtenerMenores(l1, k);

  for(int i = 1; i <= menores.longLista(); i++)
    cout << menores.infoLista(i) << endl;
}
