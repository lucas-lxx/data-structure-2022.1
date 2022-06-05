#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int selection_sort(vector<int>& v, int start, int end) {
    int count {0};
    if (start < end) {
        int minidix = start;
        bool swaped {false};
        for (int i = start+1; i <= end; i++) {
            if (v[i] < v[minidix]) {
                minidix = i;
                swaped = true;
            }
        }
        swap(v[start], v[minidix]);
        if (swaped) count++;
        return count + selection_sort(v, start+1, end);
    }
    return count;
}

void get_vec(vector<int>& v, int size) {
    for(int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

ostream& operator<<(ostream& os, vector<int> v) {
    for (int i = 0; i < v.size(); i++) 
        (i+1) < v.size() ? os << v[i] << ' ':os << v[i] << '\n';
    return os;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    get_vec(v, n);
    selection_sort(v, 0, n-1);
    cout << v;
}