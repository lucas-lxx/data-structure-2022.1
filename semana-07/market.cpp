#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
    public:
    Product(string product_name, int price);

    bool operator<=(const Product& b);

    friend ostream& operator<<(ostream& os, Product p);

    private:
    string product_name;
    int price;

};

Product::Product(string product_name = " ", int price = -1) : product_name(product_name), price(price) {
}

// compare products
bool Product::operator<=(const Product& b) {
    if ( this->price != b.price) {
        return this->price < b.price;
    } else {
        return this->product_name <= b.product_name;
    }
}

ostream& operator<<(ostream& os, Product p) {
    os << p.product_name;
    return os;
}

// gets lines with products
void gline(vector<Product>& v, int n) {
    for (int i = 0; i < n; i++) {
        string name;
        int price;
        cin >> name;
        cin >> price;
        Product pdct(name, price);
        v[i] = pdct;
    }
}

// prints lines with products
void pline(vector<Product>& v, int n) {
    for (int i = 0; i < n; i++) 
        (i+1) < n ? cout << v[i] << ' ':cout << v[i] << '\n';
}


// copy of merge
void merge(vector<Product>& v, int start, int mid, int end) {
    int start1 = start;
    int start2 = mid+1;
    int start3 = 0;
    vector<Product> b;
    b.resize(end-start+1);
    // compare vectors to insert on result vector b
    while (start1 <= mid && start2 <= end) {
        if (v[start1] <= v[start2]) {
            b[start3++] = v[start1++];
        } else {
            b[start3++] = v[start2++];
        }
    }

    while (start1 <= mid) {
        b[start3++] = v[start1++];
    }

    while (start2 <= end) {
        b[start3++] = v[start2++];
    }
    
    for (int i = start, j = 0; i <= end; i++, j++) {
        v[i] = b[j];
    }
}


void merge_sort(vector<Product>& v, int start, int end) {
    if (start < end) {
        int mid = (start+end) / 2;
        merge_sort(v, start, mid);
        merge_sort(v, mid+1, end);
        merge(v, start, mid, end);
    }
}

void select_from(vector<Product>& res, vector<Product>& sectd, int count, int& last_res) {
    for (int j = 0; j < count; j++) 
        res[last_res++] = sectd[j];
}

int main() {
    // size of the first isle
    int n;
    cin >> n;
    // size of the second isle
    int m;
    cin >> m;
    // chosed itens of the first isle
    int p;
    cin >> p;
    // chosed itens of the second isle
    int q;
    cin >> q;

    // first isle
    vector<Product> ip(n);
    gline(ip, n);
    //second isle
    vector<Product> iq(m);
    gline(iq, m);

    merge_sort(ip, 0, n-1);
    merge_sort(iq, 0, m-1);

    int last_res { 0 };
    vector<Product> res;
    res.resize((p+q));
    select_from(res, ip, p, last_res);
    select_from(res, iq, q, last_res);
    merge_sort(res, 0, p+q-1);
    pline(res, p + q);
}