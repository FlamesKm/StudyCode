#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Person {
    int x;
    int y;
    bool isGanran = false;
    // Person(int x, int y)
    //     : x(x), y(y) { isGanran = false; };
};
Person pson[1000];
int N, M, D, IT, DT;
double getJuli(int x, int y) {
    return sqrt(pow(pson[x].x - pson[y].x, 2) + pow(pson[x].y - pson[y].y, 2));
}
//查找并入队
queue<int> find(queue<int> que) {
    vector<int> v;
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        for (int i = 0; i < N; i++) {
            //如果可以被传染
            if (getJuli(i, x) < (double)D && pson[i].isGanran == false) {
                v.push_back(i);
                pson[i].isGanran = true;
            }
        }
    }
    for (auto it : v) {
        que.push(it);
    }
    return que;
}
int main() {
    // N = 3, M = 1, D = 3, IT = 10, DT = 20;
    cin >> N >> M >> D >> IT >> DT;
    // pson[0].x = 0, pson[0].y = 0;
    // pson[1].x = 1, pson[1].y = 0;
    // pson[2].x = 0, pson[2].y = 3;
    //  pson[3].x = 0, pson[3].y = 2;
    int data1, data2;
    //记录坐标
    for (int i = 0; i < N; i++) {
        cin >> data1 >> data2;
        pson[i].x = data1, pson[i].y = data2;
    }
    queue<int> que;
    for (int i = 0; i < M; i++) {
        cin >> data1;
        pson[data1].isGanran = true;
        que.push(data1);
    }
    //广度查找并记录时间
    int time = 0;
    while (!que.empty() && time + IT <= DT) {
        que = find(que);
        time += IT;
    }
    if (que.empty()) {  //结束处理
        time -= IT;
    }
    //寻找幸存者
    int cntXingcun = 0;
    for (int i = 0; i < N; i++) {
        if (pson[i].isGanran == false) {
            cntXingcun++;
        }
    }
    cout << cntXingcun << " " << time;
    //时间结束或者感染结束
}