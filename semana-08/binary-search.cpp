#include <iostream>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, vector<int>& v) {
    for(int i: v)
        os << i << " ";
    os << '\n';
    return os;
}

void printv(vector<int>& v, int start, int end) {
    for (int i = start; i < end; i++)
        cout << v[i] << ' ';
    cout << '\n';
}

int binary_search(vector<int>& v, int size, int item) {
    int start {0};
    int end {size-1};
    int count {0};
    while(start <= end) {
        int mid = (start+end) / 2;
        count++;
        if (item == v[mid]) {
            break;
        } else {
            if (v[mid] > item)
                end = mid-1;
            else 
                start = mid+1;
        }
    }
    return count;
}

void get_vec(vector<int>& v, int size) {
    for(int i = 0; i < size; i++)
        cin >> v[i];
}

void questions(vector<int>& p, vector<int>& v) {
    for (int i = 0; i < p.size(); i++) 
        if (i+1 < p.size())
            cout << binary_search(v, v.size(), p[i]) << " ";
        else
            cout << binary_search(v, v.size(), p[i]) << "\n";
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> v(n);
    vector<int> p(m);
    get_vec(v, n);
    get_vec(p, m);
    questions(p, v);
}