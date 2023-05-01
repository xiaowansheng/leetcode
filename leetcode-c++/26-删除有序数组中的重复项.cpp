#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	/*
		i指向找到的唯一元素序列的最大下标，总数=（i+1）
		j指向下一个唯一元素下标
	*/
	int removeDuplicates(vector<int>& nums) {
		int i = 0,j= 1 , count = nums.size();
		while (i < count && j< count) {
			while (j<count&&nums[i] == nums[j]) {
				j++;
			}
			if (j < count) {
				nums[++i] = nums[j++];
			}
		}
		return i+1;
	}
};

int main26() {

	vector<int> nums = { 0,1,1,2,2,2,3,4,4,5,6,6};
	Solution* s = new Solution();
	int count = s->removeDuplicates(nums);
	for (int i = 0; i < count; ++i) {
		std::cout << nums[i] << endl;
	}
	return 0;
}