# def stirling(n, k):
#     if k == 0:
#         return 1
#     if k == n:
#         return 1
#     else:
#         return stirling(n - 1, k - 1) + stirling(n - 1, k)

# while (True):
#     n = int(input("Enter n: "))
#     if n < 0:
#         break
#     k = int(input("Enter k: "))
#     print(stirling(n, k))
def w(n):
        if n == 1:
            return 1
        return w(n-1) + 3


while (True):
    n = int(input("Enter n: "))
    if n < 0:
        break
    print(w(n))