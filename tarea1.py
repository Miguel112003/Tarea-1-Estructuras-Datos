# Miguel Alejandro Bejarano Perdomo
# 8959501

# Como pueden ver me califique a mi mismo :D

# Ejercicio 1 (5.0/5.0)

# Esta funcion se encarga de verificar si una matriz tiene iguales elementos en su diagonal principal y secundaria
# Asumo que el usuario digitara una matriz cuadrada y no lo verifico
def verificarDiagonales(matrix):
    n = len(matrix)
    for i in range(n):
        if matrix[i][i] != matrix[i][n-i-1]:
            return False
    return True

# Ejercicio 2 (5.0/5.0)

# Esta funcion revisa una lista de numeros enteros y determina si la lista se lee igual independiente del sentido


def esCapicua(listaEnteros):
    # Lo hago asi sin explorar la lista ya que si al invertirla al menos 1 numero es diferente ya deja de ser capicua
    if listaEnteros == list(reversed(listaEnteros)):
        return True
    else:
        return False

# Ejercicio 3a (5.0/5.0)

# Esta funcion obtiene la diferencia de dos listas tomando en cuenta el numero de elementos en cada lista


def diferenciaListas(listaA, listaB):
    listaResultado = []
    for i in range(len(listaA)):
        if listaA[i] in listaB:
            listaB.remove(listaA[i])
        else:
            listaResultado.append(listaA[i])
    return listaResultado

# Ejercicio 3B (5.0/5.0)

# Esta funcion toma unos datos de entrada, los separa y almacena en listas, luego se encarga de obtener la diferencia


def lecturaImpresion():
    lineas = []
    matrizResultado = []
    cantidadEjecuciones = int(input())
    cantidadLineas = cantidadEjecuciones * 2
    indice = 0
    while cantidadEjecuciones != 0:
        lineas.append(input())
        cantidadEjecuciones -= 0.5
    for i in range(len(lineas)):
        linea = lineas[i].split()
        # La linea de abajo vi que es como la forma en que se suele convertir
        # Listas de caracteres a enteros
        lineaEnteros = list(map(int, linea))
        # Elimino el dato 0, que es inutil
        lineaEnteros.pop(0)
        matrizResultado.append(lineaEnteros)
    while cantidadLineas != 0:
        listaUno = matrizResultado[indice]
        indice += 1
        listaDos = matrizResultado[indice]
        indice += 1
        listaResultado = diferenciaListas(listaUno, listaDos)
        for i in range(len(listaResultado)):
            if i != len(listaResultado)-1:
                print(listaResultado[i], end=", ")
            else:
                print(listaResultado[i], end="\n")
        cantidadLineas -= 2


# Ejercicio 4 (5.0/5.0)

# Esta funcion se encarga de mostrar primos
def mostrarPrimos(N):
    primos = []
    primosSuma = []
    # Este primer ciclo determina si el numero es primo o no
    for num in range(2, N+1):
        esPrimo = True
        for i in range(2, num):
            if (num % i) == 0:
                esPrimo = False
                break
        # Aqui una vez ya defini si es primo o no empieza lo complicado, mirar la suma con los digitos
        if esPrimo:
            primos.append(num)
            sumaDigitos = 0
            # Este ciclo se encarga de recorrer el numero separado en sus digitos y con eso luego sumo los digitos
            # Luego determino un bool que me confirma si su suma da como resultado un numero primo o no
            for digito in str(num):
                sumaDigitos += int(digito)
            digitosPrimos = True
            # En este ciclo determino si ese valor de suma de digitos es primo o no, simplemente igual a lo de arriba
            for i in range(2, sumaDigitos):
                if (sumaDigitos % i) == 0:
                    digitosPrimos = False
                    break
            if digitosPrimos:
                primosSuma.append(num)
    # Aqui ya empiezo a imprimir en pantalla
    print("Números primos entre 1 y", str(N)+":")
    for i in range(len(primos)):
        if i != len(primos)-1:
            print("-->", str(primos[i])+",")
        else:
            print("-->", primos[i])
    print()
    print("Números entre 1 y", N, "con suma de dígitos con valor primo:")
    for i in range(len(primosSuma)):
        if i != len(primosSuma)-1:
            print(str(primosSuma[i]) + ",", end=" ")
        else:
            print(str(primosSuma[i]), end="")


# Ejercicio 5 (5.0/5.0)

"""
Como tengo las posiciones de la matriz, verifico si la disp tiene los valores
del primer dato de cada tupla, como la primera (0,0) y disp tiene la clave 0
mientras que por ejemplo la tupla (3,5) si veo disp no existe 3, por lo que ignoro esa cosa

Por eso lo primero que hago es vetificar si el primer valor de las tuplas (x,)
esta dentro del diccionario, si lo esta sigo, sino sumo 0, ya que no existe el valor dentro del diccionario
despues asigno dos variables x e y, verifico si estan en la lista de tuplas de la clave del diccionario
si estan miro si el segundo valor (,y) es igual al del diccionario, de ser asi sumo el valor correspondiente al 
acumulador
"""


def sumarValoresMatriz(mat, par):
    suma = 0
    for i, j in par:
        if i in mat:
            for x, y in mat[i]:
                if j == x:
                    suma += y
                    break
        else:
            suma += 0
    return suma
