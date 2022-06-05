#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& v1, int start, int mid, int end) {
    vector<int> v2;
    v2.resize(end-start+1);
    int start1 = start;
    int start2 = mid+1;
    int start3 = 0;

    while (start1 <= mid && start2 <= end) {
        if (v1[start1] <= v1[start2]) 
            v2[start3++] = v1[start1++];
        else 
            v2[start3++] = v1[start2++];
    }

    while (start1 <= mid) {
        v2[start3++] = v1[start1++];
    }
    while (start2 <= end) {
        v2[start3++] = v1[start2++];
    }

    for (int i = start, j = 0; i <= end; i++, j++) {
        v1[i] = v2[j];
    }
}

void merge_sort(vector<int>& v, int start, int end) {
    if (end > start) {
        int mid = (start+end) / 2;
        merge_sort(v, start, mid);
        merge_sort(v, mid+1, end);
        merge(v, start, mid, end);
    }
}


int main() {
    vector<int> v;
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    merge_sort(v, 0, n-1);
    for (int i:v)
        cout << i << ' ';
    cout << '\n';
}