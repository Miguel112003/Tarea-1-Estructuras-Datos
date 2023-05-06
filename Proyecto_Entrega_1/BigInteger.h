/*
Autor: Miguel Bejarano
Fecha: 4/05/2023

Implementacion TAD BigInteger con Vectores


*/

#include <iostream>
#include <vector>
#include <string>

#ifndef BIGINTEGER_H
#define BIGINTEGER_H

using namespace std;

class BigInteger {
private:
    vector<int> digitos;

public:
    BigInteger(); //Constructor por defecto
    BigInteger(string numStr); //Constructor con string
    BigInteger(const BigInteger &otro); //Constructor de copia

    //Operaciones de Modificacion
    void add(BigInteger &otro);
    void product(BigInteger &otro);
    void substract(BigInteger &otro);
    void quotient(BigInteger &otro);
    void remainder(BigInteger &otro);
    void pow(BigInteger &otro);
    string toString();

    //Operadores Aritmeticos
    BigInteger operator +(BigInteger&) const;
    BigInteger operator -(BigInteger&) const;
    BigInteger operator *(BigInteger&) const;
    BigInteger operator /(BigInteger&) const;
    BigInteger operator %(BigInteger&) const;

    //Operadores Booleanos
    bool operator==(BigInteger &otro) const;
    bool operator<(BigInteger &otro) const;
    bool operator<=(BigInteger &otro) const;

    //Operaciones Estaticas
    static BigInteger sumarListaValores(vector<BigInteger> &lista);
    static BigInteger multiplicarListaValores(vector<BigInteger> &lista);

    //Operaciones Auxiliares
    void print() const;
};


#endif // BIGINTEGER_H
