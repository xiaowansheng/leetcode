
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //���ֲ���
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int t1 = 0, t2 = 0;//�߼��ϣ���¼����������м�ָ���λ�ã����������м䣬������ʾ�����±�
        //�����ż������ָ���м�ƽ�����飬�����������ұ߶�һ��
        t1 = a.size() / 2;
        t2 = b.size() / 2;
        //���ָ����������ֵС�ڷָ����ұߣ�������Ϊż������λ����������ֵ���ұ���Сֵ���ٳ�����
        //                                        Ϊ��������Ϊ����ʱ�ұ߶�һ�����Էָ����ұ���Сֵ������λ����
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
    cout <<"��λ����" << r << endl;
    return 0;
}
