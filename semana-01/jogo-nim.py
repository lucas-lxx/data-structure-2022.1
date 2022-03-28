import math

""" Number of max picks == 4 """
def start_definition(amount):
    if (amount % 5) == 0:
        return False 
    else:
        return True 

def game_remove(amount):
    return amount % 5

def player_remove(amount):
    play = int(input("Remove amount in range 1 to 4: "))
    if play > 5:
        print("Invalid amount")
        return
    return play

def game_start(n):
    print("===Game Turn===")
    n -= game_remove(n)
    if n == 0:
        return n
    print("=======Current amount: " + str(n))
    print("===Player Turn===")
    n -= player_remove(n)
    return n

def player_start(n):
    print("===Player Turn===")
    n -= player_remove(n)
    if n == 0:
        return n
    print("=======Current amount: " + str(n))
    print("===Game Turn===")
    n -= game_remove(n)
    return n

    
while True:
    n = int(input("Enter the number of the game pieces: "))
    if n == -1:
        break
    bool_start = start_definition(n)
    while n != 0:
        print("=======Current amount: " + str(n))
        if bool_start:
            n = game_start(n)
        else:
            n = player_start(n)
        if n == 0:
            print("You Lost")
