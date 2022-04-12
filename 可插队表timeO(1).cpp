#include <iostream>
using namespace std;
typedef struct Node {
    int next = 0;
    int front = 0;
} Node;
int duiwei = 0;
void add(Node n[], int number) {
    n[duiwei].next = number;
    n[number].front = duiwei;
    duiwei = number;
}
void remove(Node n[], int number) {
    int p = n[number].front;
    int q = n[number].next;
    //Œ¨ª§∂”Œ≤
    if (q == 0) {
        duiwei = n[duiwei].front;
    }
    if (n[duiwei].next == 0) {
    }
    n[p].next = q;
    n[q].front = p;
    //Õ—¿Î∂”ŒÈ
    n[number].next = 0;
    n[number].front = 0;
}
void insert(Node n[], int A, int B) {
    int bf = n[B].front;
    n[A].next = B;
    n[A].front = bf;
    n[B].front = A;
    n[bf].next = A;
}
void printNode(Node n[]) {
    int i = n[0].next;
    while (n[i].next != 0) {
        cout << i << " ";
        i = n[i].next;
    }
    cout << i << " ";
}
int main() {
    Node n[100001];
    int M, N;
    cin >> N >> M;
    while (M--) {
        char a;
        cin >> a;
        switch (a) {
            case 'I':
                int data1;
                cin >> data1;
                add(n, data1);
                break;
            case 'C':
                int data2, data3;
                cin >> data2 >> data3;
                insert(n, data2, data3);
                break;
            case 'L':
                int data4;
                cin >> data4;
                remove(n, data4);
                break;
        }
    }
    printNode(n);
}