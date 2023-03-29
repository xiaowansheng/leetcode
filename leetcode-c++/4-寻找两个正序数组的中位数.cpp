
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //二分查找
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int t1 = 0, t2 = 0;//逻辑上，记录两个数组的中间分割线位置，即两个数中间，而不表示数组下标
        //如果是偶数，则指向中间平分数组，是奇数则让右边多一个
        t1 = a.size() / 2;
        t2 = b.size() / 2;
        //当分割线左边所有值小于分割线右边，则总数为偶数则中位数是左边最大值加右边最小值，再除二。
        //                                        为奇数则因为划分时右边多一，所以分割线右边最小值就是中位数。
        while (true) {

        }
        return 0;
    }

    double findMedianSortedArrays2(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        int len = m + n;
        int left = -1, right = -1;
        int aStart = 0, bStart = 0;
        for (int i = 0; i <= len / 2; i++) {
            left = right;
            if (aStart < m && (bStart >= n || A[aStart] < B[bStart])) {
                right = A[aStart++];
            }
            else {
                right = B[bStart++];
            }
        }
        if ((len & 1) == 0)
            return (left + right) / 2.0;
        else
            return right;
    }

};
int main()
{
    vector<int> a= { 1,2,3 };
    vector<int> b = { 1,3,4 };
    Solution* s = new Solution();
    double r=s->findMedianSortedArrays2(a, b);//1,1,2,3,3,4---2.5
    cout <<"中位数：" << r << endl;
    return 0;
}
