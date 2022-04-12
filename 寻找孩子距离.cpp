// L2-2 金字塔游戏
#include <iostream>
using namespace std;
#include <algorithm>
#include <cmath>
#include <map>
#define N 1005

struct node
{
    string name;
    int high;
} p[N];
int n;

bool cmp(node x, node y)
{
    if (x.high == y.high)
        return x.name < y.name;
    return x.high > y.high;
}

map<string, int> mp;
void preOrder(int r) //先序遍历
{
    if (r <= n)
    {
        mp[p[r].name] = r;
        preOrder(r * 2);
        preOrder(r * 2 + 1);
    }
}
//寻找第几层
int log(int a) // log2 a
{
    int c = 0;
    while (a)
    {
        a /= 2;
        c++;
    }
    return c - 1;
}

int main()
{
    int i;
    cin >> n;
    cin.ignore();
    for (i = 1; i <= n; i++) //输入
    {
        cin >> p[i].name >> p[i].high;
        cin.ignore();
    }
    //按身高、姓名排序 ，排后的序列即为二叉树的层序遍历序列
    sort(p + 1, p + n + 1, cmp);
    //先序遍历二叉树，用于建立以每个孩子姓名为键的映射
    preOrder(1);

    int q;
    cin >> q;
    string name1, name2;
    while (q--)
    {
        cin >> name1 >> name2;                                        //输入待查寻的两个孩子的姓名
        if (mp.find(name1) == mp.end() || mp.find(name2) == mp.end()) //有一个结点找不到
            cout << "Name not found!" << endl;
        else
        {
            int a = mp[name1]; //待查寻孩子1对应的结点编号
            int b = mp[name2]; //待查寻孩子2对应的结点编号

            if (a > b)
                swap(a, b);
            int c = 0;
            while (log(a) != log(b)) //将b向上等价到a的那一层
            {
                b = b / 2;
                c++; //将b置为其父节点
            }
            if (a == b)
            {
                if (c == 0) // a和b原本就相同
                    cout << 0 << endl;
                else // b等价后与a相同
                    cout << c - 1 << endl;
            }
            else
            {
                while (a != b) // a和b同时向上等价
                {
                    a = a / 2;
                    b = b / 2;
                    c += 2;
                }
                cout << c - 1 << endl;
            }
        }
    }
    return 0;
}