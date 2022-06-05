#include <bits/stdc++.h>
#include <vector>

int repetidos(std::vector<int>& v) {
    int n = v.size();
    int max = *std::max_element(v.begin(), v.end());
    int min = *std::min_element(v.begin(), v.end());

    std::vector<int> counting(++max-min, 0);
    for (int i = 0; i < n; i++)
        counting[v[i]-min]++;
    int count {0};
    for (int i:counting)
        if (i > 1)
            count += (i-1);
    return count;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    std::cout << repetidos(v) << '\n';
}