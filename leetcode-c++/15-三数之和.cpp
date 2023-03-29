#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    //�������������
    //����������������Сֵ����0�������ֵС��0���򲻿�����1��������
    //Ȼ��������飺��ѭ����ÿһ����a����ȷ����������֮һ��Ȼ���ѯ��������δ֪����
    //������������������𽥱��������������ֵΪb���ұ�Ϊc
    //�����1��a+b+c>0���ұ�����-1����������
    //      2��a+b+c<0���������+1����������
    //      3��a+b+c=0,���¼��ǰ��������
    //      4����������b����������c������ʱ������������������һ��ѭ��
    //      5����һ��ѭ�������������a������+1��ʼ����
    vector<vector<int>> threeSum(vector<int>& nums) {
        //�����
        vector<vector<int>> result;
        //�����������������
        sort(nums.begin(),nums.end());
        //��������������
        int left;
        int right;
        //��¼��������ӵĽ��
        int total;
        for (int i = 0; i < nums.size(); i++) {
            //�ظ���ֵ�����ټ��㣬��ֻʹ��һ�Σ�֮������
            if (i>0&&nums[i] == nums[i - 1]) {
                continue;
            }
            //��nums[i]>0ʱ��total��ֵ�ض�����0�������������з���Ҫ�����������������ѭ��
            if (nums[i] > 0) {
                break;
            }
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                //�ظ�������Ҳ���������ұ�����nums[right]==nums[right+1]���������nums[left]==nums[left-1]��Ҳ������ͬ������ֻʹ��һ�Σ�֮������
                //ͬʱҪ��֤���鲻Խ��
                while (left < right&& nums[i] + nums[left] + nums[right]> 0|| right < nums.size() - 1&&nums[right]==nums[right+1]) right--;
                while (left < right&& nums[i] + nums[left] + nums[right] < 0||left>i+1&&nums[left]==nums[left-1]) left++;
                if (left<right&&nums[i] + nums[left] + nums[right] ==0) {
                    //��Ӽ�¼
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    result.push_back(temp);
                    //��left+1���������������
                    left++;
                }
            }
        }
        return result;
    }
};
int main15()
{
    vector<int> num = { -1, 0,0,0,0, 1, 2, -1, -4 };
    Solution* s = new Solution();
    vector<vector<int>> result=s->threeSum(num);
    vector<int>::iterator iter;
    cout << "[";
    for (int i = 0; i < result.size();i ++) {
        cout << "[";
        for (iter = result[i].begin(); iter != result[i].end(); iter++) {
            cout << *iter<<",";
        }
        cout << "]";
    }
    cout << "]";

    return 0;
}
