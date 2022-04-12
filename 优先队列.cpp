//更改一个数组数据
//获取最小数值
//优先队列与结构体的用法

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
    //因为默认是大顶堆,为小于号,重构小于为大则为小顶
    bool operator<(const node& right) const {
        return data > right.data;  //小顶堆
    }
};
unordered_map<int, long int> m;
priority_queue<node> pq;
int number = 1;
void add(int data) {
    //优先队列维护
    pq.push(node(number, data));
    m[number] = data;
    number++;
}
void change(int id, int data) {
    //更新数据
    m[id] = (m[id] + data);
    pq.push(node(id, m[id]));
}
int getMin() {
    //不是当前最新的数值
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