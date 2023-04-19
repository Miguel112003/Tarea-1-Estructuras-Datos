/*
 * Autor: Carlos Ramírez
 * Fecha de creación: 30 de Octubre
 * Fecha última modificación: 30 de Octubre
 * Versión: 1.0
 * 
 * Archivo encabezado libreria TAD Lista
 * Representación Estructuras Circulares Dobles
 */

#ifndef __LISTA_H
#define __LISTA_H

#include <iostream>

using namespace std;

/************************
* ESTRUCTURAS DE DATOS *
************************/
typedef int Elemento; //Sinonimo de decir solo int

class Nodo{ //Definicion de clase Nodo
   public:
     Elemento dato; //int dato
     Nodo* sig; //Un apuntador al siguiente Nodo de la lista
     Nodo* ant; //Un apuntador al nodo anterior de la lista

     ~Nodo(); //El destructor
};

class Lista{ //Definicion de la clase lista
  private:
    Nodo* act; //El apuntador a la cabeza de la lista

  public:
    /************************
    * OPERACIONES DEL TAD *
    ************************/

    /* Constructoras */
    Lista(); //Construye la lista

    /* Modificadoras */
    void anxLista(Elemento elem); //Anexa un elemento a la lista
    void insLista(Elemento elem, int pos); //Inserta un elemento en una posicion de la lista
    void elimLista(int pos); //Elimina una posicion de la lista

    /* Analizadoras */
    Elemento infoLista(int pos); //Devuelve el elemento en una pos de la list
    int longLista(); //Devuelve el tamaño de la lista
    bool vaciaLista(); //Verifica si la lista esta vacia
};

#endif
