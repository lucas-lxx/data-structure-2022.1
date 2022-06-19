#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
ostream& operator<<(ostream& os, vector<int>& v) {
    for (int i = 0; i < v.size(); i++)
        if (i < v.size()-1)
            os << v[i] << ' ';
        else
            os << v[i];
    return os;
}

void vira(vector<int>& v, int start, int end) {
    if (start < end) {
        swap(v[start++], v[end--]);
        vira(v, start, end);
    }
}

int particiona(vector<int>& v, int start, int end) {
    int j {start};
    int pivo {v[end]};
    for (int i = start; i <= end-1; i++) 
        if (v[i] <= pivo) swap(v[i], v[j++]);
    swap(v[j], v[end]);
    return j;
}

void quick_sort(vector<int>& v, int start, int end) {
    if (start < end) {
        int j = particiona(v, start, end);
        quick_sort(v, start, j-1);
        quick_sort(v, j+1, end);
    }
}

bool eh_ordenado(vector<int>& v) {
    for (int i = 0; i < v.size()-1; i++) 
        if (v[i] > v[i+1]) return false;
    return true;
}

void tapioca_sort(vector<int>& v, vector<int>& aux) {
    quick_sort(aux, 0, aux.size()-1);
    for (int i = aux.size()-1; i >= 0; i--) {
        if (eh_ordenado(v)) break;
        cout << "asdf: " << aux[i] << '\n';
        for (int j = 0; j < v.size(); j++) {
            if (v[j] == aux[i]){
                cout << "v[j] " << v[j];
                cout << " aux[i]" << aux[i] << '\n';
                cout << "v: " << v << '\n';
                cout << "aux: " << aux << '\n';
                vira(v, 0, j);
                cout << (v.size() -j) << ' ';
                break;
            }
        }
    }
    cout << "0\n";
}

void get_vec(vector<int>& v, vector<int>& aux, int size) {
    for (int i = 0; i < size; i++) {
        cin >> v[i];
        aux[i] = v[i];
    }
}

int main() {
    int size;
    cin >> size;
    vector<int> v(size);
    vector<int> aux(size);
    get_vec(v, aux, size);
    tapioca_sort(v, aux);
    // cout << v << '\n';
}