// #include <iostream>
// #include <algorithm>

// void bubble_sort(std::vector<lint>& vec, int p, int r) {
//     if (r > p) {
//         bool changed {false};
//         for (int i = r; i >= p+1; i--) {
//             if (vec[i-1] > vec[i]) {
//                 std::swap(vec[i-1], vec[i]);
//                 changed = true;
//             }
//         }
//         if (changed) {
//             bubble_sort(vec, p+1, r);
//         }
//     }
// }



// int main() {

// }

// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int bubble_sort(vector<int>& A) {
//     int count {0};
//     bool swapped {true};
//     int n = A.size();
//     while (swapped) {
//         count++;
//         swapped = false;
//         for (int i = 1; i < n-1; i++) {
//             if (A[i] > A[i+1]){
//                 swap(A[i], A[i+1]);
//                 swapped = true;
//             }
//         }
//     }
//     return count;
// }

// int main() {
//     while (true) {
//         int n;
//         string line;
//         cin >> n;
//         if (n < 0)
//             break;
//         vector<int> v;
//         v.reserve(n);
//         for (int i = 0; i < n; i++) {
//             int j;
//             cin >> j;
//             v.push_back(j);
//         }
//         cout << bubble_sort(v) << endl;
//     }
// }

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v) {
    for (T i : v)
        os << i << " ";
    return os;
}

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
    cout << "in: " << A << '\n';
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
    cout << v << '\n';
}