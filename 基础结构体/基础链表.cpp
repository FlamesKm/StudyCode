#include <iostream>
using namespace std;
typedef struct Node {
    int number;
    Node* next;
    Node* front;
    Node(int number)
        : number(number) {
        next = nullptr;
    }
    Node() {
        next = nullptr;
    }
} Node;
void add(Node* n, int number) {
    while (n->next != nullptr) {
        n = n->next;
    }
    Node* node = new Node(number);
    n->next = node;
}
//返回前一个
Node* findPreNode(Node* n, int number) {
    if (n->next->number == number || n->next == nullptr) {
        return n;
    }
    return findPreNode(n->next, number);
}
//移除某一元素
void remove(Node* n, int number) {
    Node* p = findPreNode(n, number);
    Node* q = p->next;
    p->next = q->next;
    delete q;
}
// A插在B前面
void insert(Node* n, int A, int B) {
    Node* p = findPreNode(n, B);
    Node* q = new Node(A);
    q->next = p->next;
    p->next = q;
}
void printNode(Node* n) {
    n = n->next;
    while (n) {
        cout << n->number << "->";
        n = n->next;
    }
    cout << "null";
}
int main() {
    Node* node = new Node;
    node->next = nullptr;
    add(node, 1);
    add(node, 5);
    add(node, 2);
    add(node, 4);
    add(node, 6);
    remove(node, 4);
    insert(node, 3, 6);
    printNode(node);
}