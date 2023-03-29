#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    //对数组进行排序
    //如果排完序的数组最小值大于0或者最大值小于0，则不可能有1这三个数
    //然后遍历数组：把循环的每一个数a当作确定的三个数之一，然后查询其它两个未知的数
    //从排完序的数组两边逐渐遍历，遍历的左边值为b，右边为c
    //如果：1、a+b+c>0，右边索引-1，继续遍历
    //      2、a+b+c<0，左边索引+1，继续遍历
    //      3、a+b+c=0,则记录当前的三个数
    //      4、当遍历到b的索引等于c的索引时，遍历结束，进入下一个循环
    //      5、下一轮循环，左边索引从a的索引+1开始遍历
    vector<vector<int>> threeSum(vector<int>& nums) {
        //结果集
        vector<vector<int>> result;
        //对数组进行升序排序
        sort(nums.begin(),nums.end());
        //定义遍历所需变量
        int left;
        int right;
        //记录三个数相加的结果
        int total;
        for (int i = 0; i < nums.size(); i++) {
            //重复的值不必再计算，即只使用一次，之后跳过
            if (i>0&&nums[i] == nums[i - 1]) {
                continue;
            }
            //当nums[i]>0时，total的值必定大于0，即不可能再有符合要求的三个数，即跳出循环
            if (nums[i] > 0) {
                break;
            }
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                //重复的数据也跳过，即右边满足nums[right]==nums[right+1]，左边满足nums[left]==nums[left-1]，也就是相同的数组只使用一次，之后跳过
                //同时要保证数组不越界
                while (left < right&& nums[i] + nums[left] + nums[right]> 0|| right < nums.size() - 1&&nums[right]==nums[right+1]) right--;
                while (left < right&& nums[i] + nums[left] + nums[right] < 0||left>i+1&&nums[left]==nums[left-1]) left++;
                if (left<right&&nums[i] + nums[left] + nums[right] ==0) {
                    //添加记录
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    result.push_back(temp);
                    //让left+1，继续向里面查找
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
