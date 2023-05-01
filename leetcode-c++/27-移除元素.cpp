#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  //  int removeElement(vector<int>& nums, int val) {
		//for (int i = nums.size()-1; i>=0; i--)
		//{
		//	if (nums[i] == val) {
		//		nums.pop_back();
		//	}
		//	else
		//	{
		//		int n = 0;
		//		while (n< nums.size() -1 &&nums[n++] != val);
		//		cout << "n:" << n << endl;
		//		cout << "number:" << nums[i] << endl;
		//		if (--n< nums.size() - 1) {
		//			swap(nums[i], nums[n]);
		//			nums.pop_back();
		//		}
		//		else
		//		{
		//			break;
		//		}
		//	}
		//}
		//return nums.size();
  //  }
	int removeElement(vector<int>& nums, int val) {
		int left = 0, right = nums.size() - 1;
		//写等于“=”的目的在于交换后留一次机会判断交换后的值是否为val
		while (left <= right) {
			if (nums[left] == val) {
				nums[left] = nums[right--];
			}
			else
			{
				left++;
			}
		}
		return left;
	}
};

int main27() {

	vector<int> nums = { 0,2 };
	//vector<int> nums = { 4,5 };
	Solution* s = new Solution();
	int count=s->removeElement(nums, 0);
	for (int i = 0; i < count; ++i) {
		std::cout << nums[i] << endl;
	}
	return 0;
}