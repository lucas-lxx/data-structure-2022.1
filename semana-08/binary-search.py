def busca_binaria(vetor, n, item):
    inicio = 0 #inicio do vetor
    fim   = n - 1 # fim do vetor
    contador = 0 # numero de iteracoes para encontrar um elemento no vetor
    while inicio <= fim:
        meio = (inicio + fim)//2 #divisão inteira
        contador = contador + 1
        if vetor[meio] == item:
            break             
        else:
            if vetor[meio] > item:
                fim = meio - 1
            else:
                inicio = meio + 1
    return contador