import math
import numpy as np



while True:
    print("Select Grid Size========")
    line = int(input("Enter number of lines: "))
    if line == 0:
        break
    column = int(input("Enter number of columns: "))
    if column == 0:
        break
    poison_array = np.zeros((line, column))
    print(poison_array)
    while poison_array[0][0] != 1:
        line = int(input("Enter number of lines: "))
        column = int(input("Enter number of columns: "))
        poison_array[line][column] = 1
        print(poison_array)