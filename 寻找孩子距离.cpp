// L2-2 ��������Ϸ
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
void preOrder(int r) //�������
{
    if (r <= n)
    {
        mp[p[r].name] = r;
        preOrder(r * 2);
        preOrder(r * 2 + 1);
    }
}
//Ѱ�ҵڼ���
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
    for (i = 1; i <= n; i++) //����
    {
        cin >> p[i].name >> p[i].high;
        cin.ignore();
    }
    //����ߡ��������� ���ź�����м�Ϊ�������Ĳ����������
    sort(p + 1, p + n + 1, cmp);
    //������������������ڽ�����ÿ����������Ϊ����ӳ��
    preOrder(1);

    int q;
    cin >> q;
    string name1, name2;
    while (q--)
    {
        cin >> name1 >> name2;                                        //�������Ѱ���������ӵ�����
        if (mp.find(name1) == mp.end() || mp.find(name2) == mp.end()) //��һ������Ҳ���
            cout << "Name not found!" << endl;
        else
        {
            int a = mp[name1]; //����Ѱ����1��Ӧ�Ľ����
            int b = mp[name2]; //����Ѱ����2��Ӧ�Ľ����

            if (a > b)
                swap(a, b);
            int c = 0;
            while (log(a) != log(b)) //��b���ϵȼ۵�a����һ��
            {
                b = b / 2;
                c++; //��b��Ϊ�丸�ڵ�
            }
            if (a == b)
            {
                if (c == 0) // a��bԭ������ͬ
                    cout << 0 << endl;
                else // b�ȼۺ���a��ͬ
                    cout << c - 1 << endl;
            }
            else
            {
                while (a != b) // a��bͬʱ���ϵȼ�
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