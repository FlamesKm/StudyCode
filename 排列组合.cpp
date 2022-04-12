//排列字符串
// *output:
// cbad cabd acbd abcd bcad bacd
#include <iostream>
#include <string>
#include <tr1/unordered_set>
using namespace std;
using namespace std::tr1;

void stringCombination(int pos, string s, unordered_set<string>& hashSet);

int main() {
    string str = "abcd";
    unordered_set<string> hashSet;
    stringCombination(0, str, hashSet);
    for (auto it = hashSet.begin(); it != hashSet.end(); it++)  //迭代器的遍历
        cout << (*it) << " ";
}
void stringCombination(int pos, string s, unordered_set<string>& hashSet) {
    if (pos + 1 == s.length()) {
        hashSet.insert(s);  //插入哈希表
    }
    for (int i = pos; i < s.length(); ++i) {
        // swap(s[pos], s[i]); /交换一次
        stringCombination(pos + 1, s, hashSet);
        swap(s[pos], s[i]);  //交换回来
        // 回溯的原因：比如第二次交换后是"BAC"，需要回溯到"ABC"
        // 然后进行第三次交换，才能得到"CBA"
    }
}