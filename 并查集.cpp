#include <iostream>
using namespace std;
#define MAX 5000
int pre[MAX];
int treeRank[MAX];  //树的高度
void init(int n)    //初始化函数，对录入的 n个结点进行初始化
{
    for (int i = 0; i < n; i++) {
        pre[i] = i;       //每个结点的上级都是自己
        treeRank[i] = 1;  //每个结点构成的树的高度为 1
    }
}
int find(int x) {
    if (pre[x] == x)
        return x;
    return pre[x] = find(pre[x]);
}

bool isTrem(int x, int y)  //判断两个结点是否连通
{
    return find(x) == find(y);
}

bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    if (treeRank[x] > treeRank[y])
        pre[y] = x;
    else {
        if (treeRank[x] == treeRank[y])
            treeRank[y]++;
        pre[x] = y;
    }
    return true;
}

int main() {
    init(MAX);
    join(1, 2);
    join(2, 3);
    join(1, 5);
    join(4, 6);
    cout << isTrem(1, 3) << endl;
    cout << isTrem(1, 5) << endl;
    cout << isTrem(1, 4) << endl;
}