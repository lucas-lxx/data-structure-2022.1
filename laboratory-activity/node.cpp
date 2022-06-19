#include <iostream>

using namespace std;

class Node{
    public:
    int val;
    Node * next;
    Node(int val) : val(val), next(nullptr) {};
    Node(int val, Node * next) : val(val), next(next) {};
};

//sobrecarga do operador << 
ostream& operator<<(ostream& os, Node * ptr){
    if(ptr == nullptr)
        os << "nullptr";
    else
        os << ptr->val << "," << ptr->next;
    return os;
}

Node * readList(int n){
    if(n == 0){
        return nullptr;
    }else{
        int x;
        cout << "Entre com o elemento da lista: ";
        cin >> x;
        Node * ptr = new Node(x);  
        ptr->next = readList(n-1); //chamada recursiva
        return ptr;
    }

}

// 2. Complete a função que realiza a remoção dos nós com o valor valde maneira iterativa
Node * remove(Node * head, int val){
    Node * prev = nullptr;
    Node * curr = head;

    while( curr != nullptr){
        if(curr->val == val){
            Node * temp = curr;
            curr = temp->next;
            delete temp;
        }else{
            if(prev == nullptr){
                prev = curr;
                head = prev;
            }else{
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }
    }
    prev->next = nullptr;

    return head;

}

// 3. Complete a função que realiza a remoção dos nós com o valor valde maneira recursiva
Node * remove_recursive(Node * head, int val){
    if(head == nullptr){
        return nullptr;
    }else{
        if(head->val == val){
            auto temp = head->next;
            delete head;
            return remove_recursive(temp, val); //chamada recursiva
        }else{
            head->next = remove_recursive(head->next, val); //chamada recursiva
            return head;
        }
    }
}


int main(){
    Node * head;
    int n, val;

    cout << "Entre com o tamanho da lista: ";
    cin >> n;
    head = readList(n);
    cout << head << endl;
    cout << "Entre com o valor a ser removido:";
    cin >> val;
    head = remove_recursive(head, val);
    cout << head << endl;

}