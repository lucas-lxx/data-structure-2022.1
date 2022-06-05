#include <iostream>
#include <cmath>

int stirling(int n, int k) {
    if (k == 0 || n == 0)
        return 1;
    return stirling(n-1, k-1) + stirling(n-1, k); 
}

int fat(int n) {
    if (n == 0)
        return 1;
    return n * fat(n-1);
}

int comb(int n, int k) {
    return std::tgamma(n+1) / (std::tgamma(k+1) * std::tgamma((n-k)+1));
}


int main() {
    while (true) {
        int n, k;
        std::cout << "n:    ";
        std::cin >> n;
        if (n < 0)
            break;
        std::cout << "k:    ";
        std::cin >> k;
        if (k < 0)
            break;
        std::cout << "res:  " << stirling(n, k) << '\n';
        std::cout << "comb: " << comb(n, k) << '\n';
        if (stirling(n,k) != comb(n,k))
            std::cout << "Error============\n";
    }
}