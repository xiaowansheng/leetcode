#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /*void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /// <summary>
        /// 插入排序合并有序数组
        /// </summary>
        /// <param name="nums1"></param>
        /// <param name="m"></param>
        /// <param name="nums2"></param>
        /// <param name="n"></param>
        for (int i = 0; i < n; i++)
        {
            int temp = nums2[i];
            if (m == 0) {
                nums1[i] = nums2[i];
            }
            else
            {
                for (int j = m-1; j >=0; j--) {
                    if (temp < nums1[j]) {
                            nums1[j + 1] = nums1[j];
                            nums1[j] = temp;
                            m++;
                    }
                    else {
                        nums1[j+1] = temp;
                        m++;
                        break;
                    }
                }
            }
        }
    }*/
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /// <summary>
        /// 归并排序的归并思想
        /// </summary>
        /// <param name="nums1"></param>
        /// <param name="m"></param>
        /// <param name="nums2"></param>
        /// <param name="n"></param>
        int i = nums1.size() - 1;
        m--;
        n--;
        while (n >= 0) {
            while (m >= 0 && nums1[m] > nums2[n]) {
                nums1[i--] = nums1[m--];
            }
            nums1[i--]=nums2[n--];
        }
    }
};

int main88() {
    //vector<int> nums1 = { 1,2,3,0,0,0 }, nums2 = { 2,5,6 };
    //int m = 3, n = 3;
    vector<int> nums1 = { 2,0}, nums2 = {1 };
    int m = 1, n = 1;
    Solution* s =new Solution();
    s->merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << endl;
    }
    return 0;
}