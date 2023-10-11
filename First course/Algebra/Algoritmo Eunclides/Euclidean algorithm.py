import math

def mcd(a, b):
    return math.gcd(a, b)

def euclides(a, b):
    i=0
    while b:
        i+=1
        a, b = b, a % b
    print("El número de iteraciones es:", i)
    return a

def euclides_extendido(a, b):
    ua,ub = 1,0
    va,vb = 0,1
    while b:
        c= a//b
        a,b=b,a-c*b
        ua,ub = ub,ua-c*ub
        va,vb = vb,va-c*vb
    return a,[ua,va]
   


def menu():
    while True:
        print("Introduce una opción:")
        print("1. Maximo Comun Divisor")
        print("2. Algoritmo de Euclides")
        print("3. Algoritmo de Euclides extendido")
        print("4. Salir")
        print()

        n = input("")

        if n == '1':
            a = int(input("Introduce el primer número: "))
            b = int(input("Introduce el segundo número: "))
            print("El máximo común divisor es:", mcd(a, b))
            print()
        elif n == '2':
            a = int(input("Introduce el primer número: "))
            b = int(input("Introduce el segundo número: "))
            print("El máximo común divisor por Euclides es:", euclides(a, b))
            print()
        elif n == '3':
            a = int(input("Introduce el primer número: "))
            b = int(input("Introduce el segundo número: "))
            print("El máximo común divisor por Euclides extendido es:", euclides_extendido(a, b))
            print()
        elif n == '4':
            print("Adios")
            print()
            break
        else:
            print("Opción incorrecta")
            print()
    

menu()




