//����һ����������
//��ȡ��С��ֵ
//���ȶ�����ṹ����÷�

#include <iostream>
#include <queue>
#include <tr1/unordered_map>
#include <vector>
using namespace std::tr1;
using namespace std;
#define MOD 1000000007
struct node {
    int number;
    long int data;
    node(int number, long int data)
        : number(number), data(data){};
    //��ΪĬ���Ǵ󶥶�,ΪС�ں�,�ع�С��Ϊ����ΪС��
    bool operator<(const node& right) const {
        return data > right.data;  //С����
    }
};
unordered_map<int, long int> m;
priority_queue<node> pq;
int number = 1;
void add(int data) {
    //���ȶ���ά��
    pq.push(node(number, data));
    m[number] = data;
    number++;
}
void change(int id, int data) {
    //��������
    m[id] = (m[id] + data);
    pq.push(node(id, m[id]));
}
int getMin() {
    //���ǵ�ǰ���µ���ֵ
    while (pq.top().data != m[pq.top().number]) {
        pq.pop();
    }
    return pq.top().data % MOD;
}
int main() {
    int N, M;
    cin >> N >> M;
    getchar();
    while (N--) {
        int data;
        cin >> data;
        add(data);
    }
    while (M--) {
        int flg, data1, data2;
        cin >> flg;
        switch (flg) {
            case 1:
                cin >> data1;
                add(data1);
                break;
            case 2:
                cin >> data1 >> data2;
                change(data1, data2);
            default:
                break;
        }
        cout << getMin() << endl;
    }
}