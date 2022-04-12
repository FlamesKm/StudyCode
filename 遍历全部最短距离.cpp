#include <iostream>
#include <map>
using namespace std;
#define INF 0x3f3f3f3f
#define N 101

int g[N][N];
void init(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                g[i][j] = 0;
            else
                g[i][j] = INF;
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    init(n);
    //ªÊ÷∆µÿÕº
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x][y] = w;
        g[y][x] = w;
    }

    // i->jŒ™i->k->j
    for (int k = n; k >= 1; k--)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    continue;
                }
                if (g[i][j] > g[i][k] + g[k][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }

    int maxx = -INF;
    for (int i = 1; i <= n; i++)
        if (g[1][i] > maxx)
            maxx = g[1][i];
    if (maxx == INF)
        cout << "-1" << endl;
    else
        cout << maxx << endl;

    return 0;
}