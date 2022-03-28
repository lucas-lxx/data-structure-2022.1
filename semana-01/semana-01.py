import math


""" Questão 1 """
def triangulo_quadrado_v1(qnt):
    if qnt == 1:
        return 3
    return (math.pow((math.sqrt(triangulo_quadrado_v1(qnt-1)-(qnt-1) * 2) + 1), 2) + (qnt * 2))

def triangulo_quadrado_v2(n):
    if n == 1:
        return 3
    return (((triangulo_quadrado_v2(n-1) / (n-1)) + 1) * n)

""" Questão 2 """
def pontos_v1(n):
    if n == 1:
        return 1
    return (pontos_v1(n-1) + n)

def fact(n):
    if n == 1:
        return 1
    return n * fact(n-1)

while True:
    n = int(input("Digite um número: "))
    if n == 0:
        break
    print("v1: " + str(int(fact(n))))
