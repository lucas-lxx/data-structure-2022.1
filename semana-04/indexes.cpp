#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

void counting_sort(std::vector<int> &v) {

  int n = v.size();
  int min = *std::min_element(v.begin(), v.end());
  int max = *std::max_element(v.begin(), v.end());

  std::vector<int> counting(max - min + 1, 0);
  for (int i = 0; i < n; i++) {
    counting[v[i] - min]++;
  }

  partial_sum(counting.begin(), counting.end(), counting.begin());

  std::vector<int> ordered(n);
  for (int i = 0; i < n; i++) {
    ordered[--counting[v[i] - min]] = v[i];
  }

  copy(ordered.begin(), ordered.end(), v.begin());
}

void counting_sort_index(std::vector<int> &v) {

  int n = v.size();
  int min = *std::min_element(v.begin(), v.end());
  int max = *std::max_element(v.begin(), v.end());

  std::vector<int> counting(max - min + 1, 0);
  for (int i = 0; i < n; i++) {
    counting[v[i] - min]++;
  }

  partial_sum(counting.begin(), counting.end(), counting.begin());

  std::vector<int> ordered(n);
  for (int i = 0; i < n; i++) {
    ordered[--counting[v[i] - min]] = i;
  }
  copy(ordered.begin(), ordered.end(), v.begin());
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> v(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }
  std::vector<int> v2(n, 0);
  copy(v.begin(), v.end(), v2.begin());
  counting_sort(v);
  for (int i : v)
    std::cout << i << " ";
  std::cout << '\n';
  counting_sort_index(v2);
  for (int i : v2)
    std::cout << i << " ";
  std::cout << '\n';
}
