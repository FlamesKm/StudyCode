//构建二叉树,以中序遍历输出,注意野指针
//输入样例:
// ABC##DE#G##F###
//输出样例:
// CBEGDFA
// AFDGEBC
#include <bits/stdc++.h>
using namespace std;
struct node {
    char ch;
    node* left;
    node* right;
    node(char c)
        : ch(c) {
        left = NULL;
        right = NULL;
    };
};
string s;
int si = -1;
void newTree(node*& tree) {
    si++;
    if (s[si] == '#' || si >= s.size()) {
        return;
    } else {
        tree = new node(s[si]);
        newTree(tree->left);
        newTree(tree->right);
    }
}
void printMidTree(node* tree) {
    if (tree == NULL) {
        return;
    }
    printMidTree(tree->left);
    cout << tree->ch;
    printMidTree(tree->right);
}
void printMidReverseTree(node* tree) {
    if (tree == NULL) {
        return;
    }
    printMidReverseTree(tree->right);
    cout << tree->ch;
    printMidReverseTree(tree->left);
}
int main() {
    node* tree;
    getline(cin, s);
    newTree(tree);
    printMidTree(tree);
    cout << endl;
    printMidReverseTree(tree);
}