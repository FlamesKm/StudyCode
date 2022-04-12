#include <iostream>
using namespace std;
#define MAX 5000
int pre[MAX];
int treeRank[MAX];  //���ĸ߶�
void init(int n)    //��ʼ����������¼��� n�������г�ʼ��
{
    for (int i = 0; i < n; i++) {
        pre[i] = i;       //ÿ�������ϼ������Լ�
        treeRank[i] = 1;  //ÿ����㹹�ɵ����ĸ߶�Ϊ 1
    }
}
int find(int x) {
    if (pre[x] == x)
        return x;
    return pre[x] = find(pre[x]);
}

bool isTrem(int x, int y)  //�ж���������Ƿ���ͨ
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