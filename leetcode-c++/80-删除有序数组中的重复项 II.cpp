#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

	}
};

int main() {

	vector<int> nums = { 0,1,1,2,2,2,3,4,4,5,6,6 };
	Solution* s = new Solution();
	int count = s->removeDuplicates(nums);
	for (int i = 0; i < count; ++i) {
		std::cout << nums[i] << endl;
	}
	return 0;
}