#include "lista.h"
#include <iostream>

/*RESPECTO A LA COMPLEJIDAD DE LA OPERACION "concatenarListas()"
Se reciben dos listas por referencia, y se guarda la longitud de la lista 2 O(n);
Luego de esto se recorre por la longitud de la lista 2 y se adiciona a la lista 1 Adicionar: O(1), Encontrar el valor O(n)
Finalmente obtenemos una complejidad de O(n^2)

*/

void concatenarListas(Lista &l1, Lista &l2){
    int len = l2.longLista();
    int i = 1;
    for(i = 1; i <= len; i++){
        l1.anxLista(l2.infoLista(i));
    }
}

int main(){
  Lista l1;
  l1.anxLista(1);
  l1.anxLista(2);
  l1.anxLista(3);
  l1.anxLista(4);
  l1.anxLista(5);
  l1.anxLista(6);
  l1.anxLista(7);
  l1.anxLista(8);

  Lista l2;
  l2.anxLista(9);
  l2.anxLista(10);
  l2.anxLista(11);
  l2.anxLista(12);
  l2.anxLista(13);
  l2.anxLista(14);
  l2.anxLista(15);
  l2.anxLista(16);


  for(int i = 1; i <= l1.longLista(); i++)
    cout << l1.infoLista(i) << endl;

  for(int i = 1; i <= l2.longLista(); i++)
    cout << l2.infoLista(i) << endl;


  concatenarListas(l1, l2);

  cout << "Ejemplo concatenarListas" << endl;
  for(int i = 1; i <= l1.longLista(); i++)
    cout << l1.infoLista(i) << endl;

}
