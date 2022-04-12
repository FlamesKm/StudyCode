#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<string> str;
    for (int i = 0; i < num; i++) {
        string s;
        cin >> s;
        str.push_back(s);
    }
    sort(str.begin(), str.end());
    for (auto it : str) {
        cout << it.data() << endl;
    }
    return 0;
}
