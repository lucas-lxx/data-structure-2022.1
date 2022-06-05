#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

void bubble_sort(std::vector<int>& v, int p, int r) {
    if (p < r) {
        bool swapped {false};
        for (int i = p; i < r-1; i++) {
            if (v[i] > v[i+1]) {
                std::swap(v[i], v[i+1]);
                swapped = true;
            }
        }
        if (swapped)
            bubble_sort(v, p, r-1);
    }
}

bool vaccines_save_checker(std::vector<int>& v, std::vector<int>& t) {
    // Vectors must be ordered
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= t[i])
            return false;
    }
    return true;
}

void get_vec(std::vector<int>& v, int vec_size) {
    for (int i = 0; i < vec_size; i++) {
        std::cin >> v[i];
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n, 0);
    get_vec(v, n);
    std::vector<int> t(n, 0);
    get_vec(t, n);
    bubble_sort(v, 0, v.size());
    bubble_sort(t, 0, t.size());
    std::cout << (vaccines_save_checker(v, t) ? "Yes":"No") << '\n';
}