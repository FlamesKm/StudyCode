#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, less<int>> pq1;  //�󶥶�,����
priority_queue<int, vector<int>, less<int>> pq2;  //С����,����
//����1
struct tmp1  //���������<
{
    int x;
    tmp1(int a) { x = a; }
    bool operator<(const tmp1& a) const {
        return x < a.x;  //�󶥶�
    }
};

//����2
struct tmp2  //��д�º���
{
    bool operator()(tmp1 a, tmp1 b) {
        return a.x < b.x;  //�󶥶�
    }
};

int main() {
    tmp1 a(1);
    tmp1 b(2);
    tmp1 c(3);
    priority_queue<tmp1> d;
    d.push(b);
    d.push(c);
    d.push(a);
    while (!d.empty()) {
        cout << d.top().x << '\n';
        d.pop();
    }
    cout << endl;

    priority_queue<tmp1, vector<tmp1>, tmp2> f;
    f.push(b);
    f.push(c);
    f.push(a);
    while (!f.empty()) {
        cout << f.top().x << '\n';
        f.pop();
    }
}