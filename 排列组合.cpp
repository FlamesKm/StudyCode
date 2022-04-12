//�����ַ���
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
    for (auto it = hashSet.begin(); it != hashSet.end(); it++)  //�������ı���
        cout << (*it) << " ";
}
void stringCombination(int pos, string s, unordered_set<string>& hashSet) {
    if (pos + 1 == s.length()) {
        hashSet.insert(s);  //�����ϣ��
    }
    for (int i = pos; i < s.length(); ++i) {
        // swap(s[pos], s[i]); /����һ��
        stringCombination(pos + 1, s, hashSet);
        swap(s[pos], s[i]);  //��������
        // ���ݵ�ԭ�򣺱���ڶ��ν�������"BAC"����Ҫ���ݵ�"ABC"
        // Ȼ����е����ν��������ܵõ�"CBA"
    }
}