#include <bits/stdc++.h>
using namespace std;
//查找小于x的个数
//或者
//查找第一个大于等于的目标数
int findNextone(vector<int> nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {  //左边收缩
            r = mid;
        } else if (nums[mid] < target) {  //右边收缩
            l = mid + 1;
        } else if (nums[mid] > target) {
            r = mid;  //注意,因为可能为当前的mid是
        }
    }
    return l;
}
/* 寻找第一个大于目标的数 */
int findNextoneEque(vector<int> nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {  //左边收缩
            l = mid + 1;
        } else if (nums[mid] < target) {  //右边收缩
            l = mid + 1;
        } else if (nums[mid] > target) {
            r = mid;  //注意,因为可能为当前的mid是
        }
    }
    return l;
}

int main() {
    vector<int> v = {2, 2, 3, 4, 4, 4, 4, 4, 4, 5, 6};
    cout << findNextone(v, 4);
}
