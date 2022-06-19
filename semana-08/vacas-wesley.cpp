#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;
 
int partition (vector<int>& v, int low, int high) {
    int j {low};
    int pivo {v[high]};
    for (int i = low; i <= high-1; i++) 
        if (v[i] <= pivo) swap(v[i], v[j++]);
    swap(v[j], v[high]);
    return j;
}
 

void quickSort(vector<int>& v, int low, int high) {
    if (low < high)
    {
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

bool isCompatible(vector<int>& v, int dist, int cows) {
    int n = v.size();
    int k = v[0];
    cows--;
    for (int i = 1; i < n; i++) {
        if(v[i] - k >= dist) {
            cows--;
            if (!cows) return true;
            k = v[i];
        }
    }
  return false;
}

void get_vec(vector<int>& v, int n) {
    for(int i = 0; i< n ;i++)
        cin >> v[i];
}

int result(vector<int>& v, int dif, int c) {
    int resultado {INT_MIN};
    for (int i = 1; i <= dif; i++){
        bool possible = isCompatible(v, i, c);
        if (possible) resultado = max(resultado, i);
    }
}

int main() {

    int n = 0, c = 0;
    cin>> n >> c;
    vector<int> v(n);
    get_vec(v, n);
    quickSort(v, 0, n-1);
    int dif = v[n - 1] - v[0];
    cout << result(v, dif, c) << '\n';
}