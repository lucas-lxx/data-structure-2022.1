#include <iostream>

// returns the most eficient way so that every one knows everything
void gossip(int n) {
    std::cout << "gossip(" << n << ")\n";
    if (n == 1) {
        std::cout << "No call needed\n";
    } else if (n == 2) {
        std::cout << "Person 1 calls person 2\n";
    } else if (n == 3) {
        std::cout << "Person 1 calls person 2\n";
        std::cout << "Person 2 calls person 3\n";
        std::cout << "Person 3 calls person 1\n";
    } else if (n == 4) {
        std::cout << "Person 1 calls person 2\n";
        std::cout << "Person 3 calls person 4\n";
        std::cout << "Person 1 calls person 3\n";
        std::cout << "Person 2 calls person 4\n";
    } else {
        std::cout << "Person " << n << " calls person 1\n";
        gossip(n-1);
        std::cout << "Person " << 1 << " calls person " << n << '\n';
    }
}


int main() {
    while(true) {
        std::cout << "Enter the amount of people: ";
        int person_counter;
        std::cin >> person_counter;
        if (person_counter < 1)
            break;
        gossip(person_counter);
    }
}