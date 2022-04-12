#include <bits/stdc++.h>
using namespace std;
//����С��x�ĸ���
//����
//���ҵ�һ�����ڵ��ڵ�Ŀ����
int findNextone(vector<int> nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {  //�������
            r = mid;
        } else if (nums[mid] < target) {  //�ұ�����
            l = mid + 1;
        } else if (nums[mid] > target) {
            r = mid;  //ע��,��Ϊ����Ϊ��ǰ��mid��
        }
    }
    return l;
}
/* Ѱ�ҵ�һ������Ŀ����� */
int findNextoneEque(vector<int> nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {  //�������
            l = mid + 1;
        } else if (nums[mid] < target) {  //�ұ�����
            l = mid + 1;
        } else if (nums[mid] > target) {
            r = mid;  //ע��,��Ϊ����Ϊ��ǰ��mid��
        }
    }
    return l;
}

int main() {
    vector<int> v = {2, 2, 3, 4, 4, 4, 4, 4, 4, 5, 6};
    cout << findNextone(v, 4);
}
