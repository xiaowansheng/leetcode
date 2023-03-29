/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:
    //1�������ⷨ
    //����һ���µĿ������Ѵ���ϲ������ݡ��������ڹ鲢�����еĺϲ����飩
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        struct ListNode result;
        struct ListNode* temp = &result;
        while (list1 != nullptr && list2 != nullptr) {
            temp->next = (ListNode*)malloc(sizeof(ListNode));
            temp = temp->next;
            temp->next = nullptr;
            if(list1->val<=list2->val){
                temp->val = list1->val;
                cout << "list1:" << list1->val << ", list2 : " << list2->val << endl;
                list1 = list1->next;
            }
            else{
                temp->val = list2->val;
                cout << "list1:" << list1->val << ", list2 : " << list2->val << endl;
                list2 = list2->next;
            }
        }
        while (list1 != nullptr) {
            temp->next = (ListNode*)malloc(sizeof(ListNode));
            temp = temp->next;
            temp->val = list1->val;
            temp->next = nullptr;
            list1 = list1->next;
        }
        while (list2 != nullptr) {
            temp->next = (ListNode*)malloc(sizeof(ListNode));
            temp = temp->next;
            temp->val = list2->val;
            temp->next = nullptr;
            list2 = list2->next;
        }
        return result.next;
    }

    //2������ԭ�����������������ָ�뻥��ָ��ƴ�ӳ��µ���������,��������������ָ�봮������
    ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
        //�������������м�ڵ�ָ��
        ListNode result(-1);//�������
        ListNode* temp = &result;//����������ʱ����
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        //����û�������������ڽ���������
        temp->next = (list1 == nullptr ? list2 : list1);
        return result.next;
    }

    //3���ݹ�ⷨ���緽��2��ֻ�ǰ�ѭ����Ϊ�ݹ�
    ListNode* mergeTwoLists3(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr||list2==nullptr) {
            //���ݹ鵽ĳ��������������һ�������ʣ�ಿ��ֱ�ӷ���
            return list1 == nullptr ? list2 : list1;
        }
        if (list1->val <= list2->val) {
            //����ǰlist1��>val��ֵΪ��ǰ��Сֵʱ������һ����Сֵ��list1->next��list2��ѡ��
            //���ѵ�ǰlist1->nextָ��ָ����һ����Сֵ
            list1->next = mergeTwoLists3(list1->next,list2);
            //���ص�ǰ�Ƚϵ���Сֵ
            return list1;
        }
        else {
            //��֮�����������෴
            list2->next = mergeTwoLists3(list1,list2->next);
            return list2;
        }
    }
};
int main21()
{
    int array1[] = { 1,2,4 };
    int array2[] = { 1,3,4 };
    struct ListNode list1;
    struct ListNode list2;
    list1.val = 0;
    list2.val = 0;

    struct ListNode* temp=&list1;
    for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); i++) {
        temp->next=(ListNode*)malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = array1[i];
        temp->next = nullptr;
        list1.val++;
        cout << "list1:" << temp->val << endl;
    }
    temp = &list2;
    for (int i = 0; i < sizeof(array2) / sizeof(array2[0]); i++) {
        temp->next=(ListNode*)malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = array2[i];
        temp->next = nullptr;
        list2.val++;
        cout << "list2:" << temp->val << endl;
    }

    Solution* s = new Solution();
    ListNode* result = s->mergeTwoLists3(list1.next,list2.next);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
