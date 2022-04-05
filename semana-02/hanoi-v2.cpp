#include <iostream>

void hanoi_v2(int n, int start, int help_1, int help_2, int end) {
    if (n == 0) {
        return;
    } else if (n == 1) {
        std::cout << "Move disc 1 from " << start << " to " << end << '\n';
        return;
    }
    hanoi_v2(n-2, start, help_2, end, help_1);
    std::cout << "Move disc " << n-1 << " from " << start << " to " << help_2 << '\n';
    std::cout << "Move disc " << n << " from " << start << " to " << end << '\n';
    std::cout << "Move disc " << n-1 << " from " << help_2 << " to " << end << '\n';
    hanoi_v2(n-2, help_1, help_2, start, end);
}


int main() {
    while (true) {
        int n;
        std::cin >> n;
        if (n < 0)
            break;
        hanoi_v2(n, 1, 2, 3, 4);
    }
}