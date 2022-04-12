/* 质数判断 */
bool isPrim(int x) {
    if (x == 1) {
        return false;
    }
    for (int i = 2; i <= x / 2; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
/*回文数*/
bool isHuiwen(int data) {
    int data1 = data;
    int data2 = 0;
    while (data1) {
        data2 = data2 * 10 + data1 % 10;
        data1 /= 10;
    }
    return data2 == data;
}
/* 分解质因数,质因数个数 */
int fact(int k, int n) {
    int end = sqrt(n), sum = 1;
    for (int i = k; i <= end; i++)
        if (n % i == 0)
            sum += fact(i, n / i);
    return sum;
}
/* 分解质因数 */
vector<int> fenjie(int x) {
    vector<int> v;
    for (int i = 2; i < x; i++) {
        while (x != i) {
            if (x % i == 0) {
                v.push_back(i);
                x = x / i;
            } else {
                break;
            }
        }
    }
    v.push_back(x);
    return v;
}
//判断年月日的合法性
bool is_valid(int y, int m, int d) {
    if (y <= 0 || m < 1 || m > 12 || d < 1 || d > 31)
        return 0;
    bool ret;
    switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            ret = 1;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            ret = (d <= 30);
            break;
        case 2:
            if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0)
                ret = (d <= 29);
            else
                ret = (d <= 28);
    }
    return ret;
}