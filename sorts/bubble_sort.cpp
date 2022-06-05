// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int bubble_sort(vector<int>& A) {
//     int count {0};
//     int n = A.size();
//     bool swapped {true};
//     while (swapped) {
//         swapped = false;
//         count = count + 1;
//         for (int i = 0; i < n-1; i++) {
//             if (A[i] > A[i+1]){
//                 swap(A[i], A[i+1]);
//                 swapped = true;
//             }
//         }
//     }
//     return count;
// }

// int main() {
//     int n;
//     vector<int> v;
//     cin >> n;
//     v.reserve(n);
//     for (int i = 0; i < n; i++) {
//         int j;
//         cin >> j;
//         v.push_back(j);
//     }

//     for (int i:v)
//         cout << i << " ";
//     cout << '\n';
//     cout << bubble_sort(v) << endl;
// }

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int bubble_sort(vector<int>& A) {
    int count {0};
    int n = A.size();
    bool swapped {true};
    while (swapped) {
        swapped = false;
        count = count + 1;
        for (int i = 0; i < n-1; i++) {
            if (A[i] > A[i+1]){
                swap(A[i], A[i+1]);
                swapped = true;
            }
        }
    }
    return count;
}

int main() {
    int n;
    vector<int> v;
    cin >> n;
    v.reserve(n);
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        v.push_back(j);
    }

    cout << bubble_sort(v) << endl;

    for (int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}