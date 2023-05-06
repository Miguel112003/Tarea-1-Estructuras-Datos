#include "BigInteger.h"

int main() {

    /*

    BigInteger num1("234567891234344544656565556677565553423456789123434454465656555667756555342345678912343445446565655566775655534");
    BigInteger num2("32432432345334654634344311111111123456789123434454465656555667756555342345678912343445446565655566775655534");
    BigInteger sum = num1 + num2;
    BigInteger sust = num1 - num2;
    BigInteger product = num1 * num2;

    //Aqui pruebo los operadores sobrecargados



    cout << "Probemos la suma de BigIntegers, Primero el valor que obtengo, luego el real" << endl;
    sum.print();
    cout << "La suma de los BigInteger es: " << endl <<"234600323666689879311199900988676664546913578246868908931313111335513110684691357824686890893131311133551311068" << endl;
    cout << endl <<"Probemos la resta de BigIntegers, Primero el valor que obtengo, luego el real" << endl;
    sust.print();
    cout << "La resta de los BigInteger es: " << endl <<"234535458801999210001931212366454442300000000000000000000000000000000000000000000000000000000000000000000000000" << endl;
    cout << endl <<"Probemos el producto de BigIntegers, Primero el valor que obtengo, luego el real" << endl;
    product.print();
    cout << "El producto de los BigInteger es: " << endl <<"7607607262845697216863839390086237719228869097473211656016692948199979629203672749304668676939359484526015493618742653496063651801671651545030911643406156978417723245836856145311735307059829858284424813245995424825156" << endl;



    //Aqui pruebo las operaciones

    cout << endl << endl << endl;

    cout << "Ahora vamos a probar las operaciones que actuan sobre la clase" << endl;

    num1.add(num2);
    num1.print();
    cout << "La suma de los BigInteger es: " << endl <<"234600323666689879311199900988676664546913578246868908931313111335513110684691357824686890893131311133551311068" << endl;

    BigInteger num3("234567891234344544656565556677565553423456789123434454465656555667756555342345678912343445446565655566775655534");
    num3.product(num2);
    num3.print();
    cout << "El producto de los BigInteger es: " << endl <<"7607607262845697216863839390086237719228869097473211656016692948199979629203672749304668676939359484526015493618742653496063651801671651545030911643406156978417723245836856145311735307059829858284424813245995424825156" << endl;

    cout << endl;

    BigInteger num4("234567891234344544656565556677565553423456789123434454465656555667756555342345678912343445446565655566775655534");
    num4.substract(num2);
    num4.print();
    cout << "La resta de los BigInteger es: " << endl <<"234535458801999210001931212366454442300000000000000000000000000000000000000000000000000000000000000000000000000" << endl;


    cout << "Probando el toString" << endl;
    BigInteger num8("234567891234344544656565556677565553423456789123434");
    string prueba = num8.toString();
    cout << prueba << endl;


    cout << endl << endl << endl;

    cout << "Ahora probemos los operadores Booleanos" << endl;

    BigInteger num5("234567891234344544656565556677565553423456789123434454465656555667756555342345678912343445446565655566775655534");
    BigInteger num6("234567891234344544656565556677565553423456789123434454465656555667756555342345678912343445446565655566775655534");
    BigInteger num7("234567891234344544656565556677565553423456");

    cout << (num5 == num6) << endl; //Deberia ser 1
    cout << (num5 <= num6) << endl; //Deberia ser 1
    cout << (num7 < num6) << endl; //Deberia ser 1
    cout << (num6 < num7) << endl; //Deberia ser 0



    */

    cout << "Probemos las operaciones estaticas" << endl;
    vector<BigInteger> listado;

    BigInteger num5("234567891234344544656565556677565553423456789123434454465656555667756555342345678912343445446565655566775655534");
    BigInteger num6("234567891234344544656565556677565553423456789123434454465656555667756555342345678912343445446565655566775655534");
    BigInteger num7("234567891234344544656565556677565553423456");

    listado.push_back(num5);
    listado.push_back(num6);
    listado.push_back(num7);

    //BigInteger sumadaNumeros = BigInteger::sumarListaValores(listado);
    //sumadaNumeros.print();

    BigInteger multiplicadaNumeros = BigInteger::multiplicarListaValores(listado);
    multiplicadaNumeros.print();

    return 0;
}
