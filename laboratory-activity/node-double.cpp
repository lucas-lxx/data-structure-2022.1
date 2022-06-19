#include <iostream>

using namespace std;

class Node{
    public:
    int val;
    Node * next;
    Node * prev;
    Node(int val) : val(val), next(nullptr), prev(nullptr) {};
    Node(int val, Node * prev, Node * next) : val(val), prev(prev), next(next) {};
};

ostream& operator<<(ostream& os, Node * ptr){
    if(ptr == nullptr)
        os << "nullptr";
    else{
        os << ptr->val << "<->" << ptr->next;
        if( ptr->next && ptr->next->prev != ptr){
            cout << "lista duplamente encadeada inválida" << endl;
        }
    }
    return os;
}


// 1. Complete a função auxiliar que realiza a leitura de uma lista encadeada.
Node * readList(int n){
    if(n == 0){
        return nullptr;
    }else{
        int x;
        cout << "Entre com o elemento da lista:";
        cin >> x;
        Node * ptr = new Node(x);  
        ptr->next = readList(n-1); //chamada recursiva
        if(ptr->next != nullptr)
            ptr->next->prev = ptr;
        return ptr;
    }

}

// 2. Complete a função que realiza a remoção dos nós com o valor val de maneira iterativa
Node * remove(Node * head, int val){
    Node * curr = head;
    head = nullptr;

    while( curr != nullptr){
        if(curr->val == val){
            if(curr->prev == nullptr){
                Node * temp = curr;
                curr->next->prev = nullptr;
                curr = temp->next;
                delete temp;
            }else{
                Node * temp = curr;
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                curr = curr->next;
                delete temp;
            }
        }else{
            if(head == nullptr){
                head = curr;
            }
            curr = curr->next;
        }
    }

    return head;

}

// 3. Complete a função que realiza a remoção dos nós com o valor valde maneira recursiva
Node * remove_recursive(Node * head, int val){
    if(head == nullptr){
        return nullptr;
    }else{
        if(head->val == val){
            Node * temp = head;
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
            delete temp;
            return remove_recursive(head, val); 
        }else{
            head->next = remove_recursive(head->next, val);
            if(head->next != nullptr) head->next->prev = head; 
            return head;
        }
    }
}

int main() {
    int n;
    cin >> n;
    Node * head = readList(n);
    cout << head << '\n';
    head = remove_recursive(head, 2);
    cout << head << '\n';
}