/*
Autor: Miguel Bejarano
Fecha: 4/05/2023

Implementacion del TAD BigInteger con Vectores

*/

#include "BigInteger.h"
#include <algorithm>

//Operaciones Auxiliares

void BigInteger::print() const{ // Imprime el número
    for (int i = digitos.size() - 1; i >= 0; i--) {
        cout << digitos[i];
    }
    cout << endl;
}

//Constructor por defecto
BigInteger::BigInteger() {
}

// Constructor que toma una cadena de dígitos
BigInteger::BigInteger(string numStr) {
    for (int i = numStr.length() - 1; i >= 0; i--) {
        digitos.push_back(numStr[i] - '0');
    }
}

//Constructor de Copia
BigInteger::BigInteger(const BigInteger& otro) {
    digitos = otro.digitos;
}

//Sobrecarga de Operador +
BigInteger BigInteger::operator +(BigInteger &otro) const{
    BigInteger resultado;
    int llevamos = 0;
    int i = 0;
    while(i < digitos.size() || i < otro.digitos.size() || llevamos){
        int suma = llevamos;
        if(i < digitos.size()){
            suma += digitos[i];
        }
        if(i < otro.digitos.size()) {
            suma += otro.digitos[i];
        }
        llevamos = suma / 10;
        resultado.digitos.push_back(suma % 10);
        i++;
    }
    return resultado;
}

//Sobrecarga de Operador *
BigInteger BigInteger::operator*(BigInteger& otro) const{
    BigInteger resultado;
    resultado.digitos.resize(digitos.size() + otro.digitos.size(), 0); //La cantidad de digitos en una multiplicacion es el total de digitos de los operandos -1 por lo que con resize puedo solucionar el tamaño
    for (int i = 0; i < digitos.size(); i++) {
        int llevamos = 0;
        for (int j = 0; j < otro.digitos.size() || llevamos; j++) {
            long long temp;
            if (j < otro.digitos.size()) {
                temp = (long long)digitos[i] * otro.digitos[j];
            } else {
                temp = 0;
            }
            temp += resultado.digitos[i + j] + llevamos;
            resultado.digitos[i + j] = temp % 10;
            llevamos = temp / 10;
        }
    }
    while (resultado.digitos.size() > 1 && resultado.digitos.back() == 0) {
        resultado.digitos.pop_back();
    }
    return resultado;
}

//Sobrecarga del Operador -

BigInteger BigInteger::operator -(BigInteger& otro) const{
    BigInteger resultado;
    if (*this == otro) {
        resultado.digitos.push_back(0);
        return resultado;
    }
    int prestame = 0;
    int tamMin = min(digitos.size(), otro.digitos.size());
    // Si el primer operando es menor que el segundo, se intercambian
    if (*this < otro) {
        for (int i = 0; i < tamMin; i++) {
            int diferen = otro.digitos[i] - digitos[i] - prestame;
            if (diferen < 0) {
                prestame = 1;
                diferen += 10;
            }
            else {
                prestame = 0;
            }
            resultado.digitos.push_back(diferen);
        }
        // Si otro tiene más dígitos que digitos
        for (int i = tamMin; i < otro.digitos.size(); i++) {
            int diferen = otro.digitos[i] - prestame;
            if (diferen < 0) {
                prestame = 1;
                diferen += 10;
            }
            else {
                prestame = 0;
            }
            resultado.digitos.push_back(diferen);
        }
        // Elimina los ceros a la izquierda
        while (resultado.digitos.size() > 1 && resultado.digitos.back() == 0) {
            resultado.digitos.pop_back();
        }
        resultado.digitos.back() = -resultado.digitos.back();
    }
    else {
        for (int i = 0; i < tamMin; i++) {
            int diferen = digitos[i] - otro.digitos[i] - prestame;
            if (diferen < 0) {
                prestame = 1;
                diferen += 10;
            }
            else {
                prestame = 0;
            }
            resultado.digitos.push_back(diferen);
        }
        // Si digitos tiene más dígitos que otro
        for (int i = tamMin; i < digitos.size(); i++) {
            int diferen = digitos[i] - prestame;
            if (diferen < 0) {
                prestame = 1;
                diferen += 10;
            }
            else {
                prestame = 0;
            }
            resultado.digitos.push_back(diferen);
        }
        // Elimina los ceros a la izquierda
        while (resultado.digitos.size() > 1 && resultado.digitos.back() == 0) {
            resultado.digitos.pop_back();
        }
    }
    return resultado;
}

//Sobrecarga del operador /

BigInteger BigInteger::operator /(BigInteger& otro) const{}

//Sobrecarga del operador %

BigInteger BigInteger::operator %(BigInteger& otro) const{}

//Sobrecarga del operador ==

bool BigInteger::operator==(BigInteger& otro) const{
    if (digitos.size() != otro.digitos.size()) {
        return false;
    }
    for (int i = digitos.size() - 1; i >= 0; i--) {
        if (digitos[i] != otro.digitos[i]) {
            return false;
        }
    }
    return true;
}

//Sobrecarga del operador <

bool BigInteger::operator<(BigInteger& otro) const{
    if (digitos.size() != otro.digitos.size()) {
        return digitos.size() < otro.digitos.size();
    }
    for (int i = digitos.size() - 1; i >= 0; i--) {
        if (digitos[i] != otro.digitos[i]) {
            return digitos[i] < otro.digitos[i];
        }
    }
    return false;
}


//Sobrecarga del operador <=
bool BigInteger::operator<=(BigInteger& otro) const{
    return (*this == otro) || (*this < otro);
}

//Operacion add

void BigInteger::add(BigInteger &otro){
    *this = *this + otro;
}

//Operacion product

void BigInteger::product(BigInteger &otro){
    *this = *this * otro;
}

//Operacion substract

void BigInteger::substract(BigInteger &otro){
    *this = *this - otro;
}

//Operacion quotient


//Operacion remainder


//Operacion pow


//Operacion toString

string BigInteger::toString() {
    string resultado = "";
    for (int i = digitos.size() - 1; i >= 0; i--) {
        resultado += to_string(digitos[i]);
    }
    return resultado;
}

//Operacion sumarListaValores

BigInteger BigInteger::sumarListaValores(vector<BigInteger> &lista){
    BigInteger suma;
    for(int i = 0; i < lista.size(); i++){
        suma = suma + lista[i];
    }
    return suma;
}

//Operacion multiplicarListaValores


BigInteger BigInteger::multiplicarListaValores(vector<BigInteger> &lista){
    BigInteger multi("1");
    for(int i = 0; i < lista.size(); i++){
        multi = multi * lista[i];
    }
    return multi;
}



/*Calculadora para verificar las operaciones:
https://www.calculator.net/big-number-calculator.html?cx=1&cy=1&cp=20&co=plus

Pdf del proyecto:
https://drive.google.com/file/d/123UBvTiAnt8cjyKfZrQNzXHAFqcBOsiD/view
*/

/*
LO QUE FALTA A DIA 4/05/2023
Me falta sobrecargar el operador de division (Dificultad 10/10)
Me falta sobrecargar el operador de modulo (Dificultad 10/10)
Me falta definir las operaciones propias sobre el BigInteger (Depende si puedo reciclar lo que hice con operadores o si tengo que hacer algo diferente)
Me falta Hacer los caculos de Complejidad (Dificultad 11/10 es potentesisimo)
Me falta ver como solucionar uno de los probleams de la arena (Tengo un par de ideas pero necesito la division)
*/
