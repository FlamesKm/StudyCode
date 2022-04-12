//*文件可视化
// input:
// 3
// a/b/c
// a/b
// b/sss
// output
// a
//|----b
//|    |----c
// b
//|----sss

#include <bits/stdc++.h>

#include <utility>

using namespace std;

const string front = "|    ";
const string last = "|----";

// 文件夹
struct File {
    string name;             // 文件名
    int level;               // 文件所在的层数
    map<string, File*> sub;  // 文件下的子文件

    File(string name, int level)
        : name(name), level(level) {}
};

vector<string> split(const string& s, const char& separator) {
    size_t prePos = 0;
    size_t pos = s.find(separator, prePos);
    vector<string> res;
    while (pos != s.npos) {
        res.push_back(s.substr(prePos, pos - prePos));
        prePos = pos + 1;
        pos = s.find(separator, prePos);
    }
    res.push_back(s.substr(prePos));
    return res;
}

void showFileStructure(File* file) {
    if (file == nullptr)
        return;
    if (file->level >= 2) {
        for (int i = 0; i < file->level - 2; i++) {
            cout << front;
        }
        cout << last;
    }
    if (file->level >= 1) {
        cout << file->name << endl;
    }
    auto it = file->sub.begin();
    while (it != file->sub.end()) {
        showFileStructure(it->second);
        it++;
    }
}

int main() {
    int n;
    cin >> n;
    string filename;
    getchar();
    File* top = new File("top", 0);
    while (n--) {
        cin >> filename;
        File* p = top;
        for (auto it : split(filename, '/')) {
            if (p->sub.count(it) == 0) {  //如果没有重复
                p->sub[it] = new File(it, p->level + 1);
            }
            p = p->sub[it];
        }
    }
    showFileStructure(top);
    return 0;
}