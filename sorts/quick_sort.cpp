#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& os, vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        i+1 < v.size() ? os << v[i] << " ":os << v[i];
    }
    return os;
}

void partition(vector<int>& v, int start, int end) {
    int j { start };
    int pivo { end };


    for (int k = start; k < end-1; k++) {
        cout << start << ' ' << end << '\n';
        // cout << k << ' ' << j << ' ' << v[k] << '\n';
        if (v[k] <= pivo) swap(v[k], v[j++]);
        if (k > 1000) break;
    }

    swap(v[end], v[j]);
}

// gets lines with products
void gline(vector<int>& v, int n) {
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
}

int main() {
    vector<int> A {1, 3, 2, 7 , 3 , 9, 8};
    cout << A << '\n';
    partition(A, 0, A.size());
    cout << A << '\n';
}