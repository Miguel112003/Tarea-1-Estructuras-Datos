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


mostrarPrimos(5000)
