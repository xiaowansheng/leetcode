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
#include<vector>
#include<limits>
#include<map>
#include<queue>
#include<algorithm>
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

    struct compare {
        //ֵԽС�����ȼ�Խ��
        bool operator()(ListNode* node1, ListNode* node2) {
            return node1->val > node2->val;
        }
    };

    //1���������ȶ��У�����������
    //���ȶ��У������ݸ������ȼ���������ȶ��У�ȡ��ʱ�����ȼ�����ߵ�ȡ��
    ListNode* mergeKLists(vector<ListNode*> lists) {
        priority_queue<ListNode*, vector<ListNode*>,compare> quene;
        ListNode result, * temp = &result;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                quene.push(lists[i]);
            }

        }
        while (!quene.empty()) {
            //ȡ�����ȶ��������ȼ���ߵ�����
            temp->next=quene.top();
            //ȡ����ɾ����ǰ���ȼ���ߵ�Ԫ��
            quene.pop();
            //��ʱָ��ָ����һ������
            temp = temp->next;
            //����ǰȡ������������һ������ʱ�����³�ȥ�����뵽���ȶ���
            if (temp->next) {
                quene.push(temp->next);
            }
        }
        return result.next;
    }


    //2�����ù鲢�㷨���ȷ֣��������ϲ���
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return mergeKLists(lists, 0, lists.size()-1);
    }
    ListNode* mergeKLists(vector<ListNode*> lists,int left,int right) {
        //���ֵ�ֻ����������ʱ�������ϲ�������
        if (right-left==1) {
            return mergeTwoList(lists[left],lists[right]);
        }
        //����ֵ�ֻ��һ������ʱ��ֱ�ӷ��ظ�����
        if (right == left) {
            return lists[left];
        }
        int mid = (left+right) / 2;
        //lists[mid]������ҲҪ����ϲ�
        return mergeTwoList(mergeKLists(lists,left,mid),mergeKLists(lists,mid+1,right));
    }
    //�ݹ�ϲ���������
    ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2) {
            return list1 ? list1 : list2;
        }
        if (list1->val < list2->val) {
            list1->next = mergeTwoList(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoList(list1, list2->next);
            return list2;
        }
    }
};
int main23()
{
    int array1[] = {1,1,2,4,8.8};
    int array2[] = { 1,3,4 ,5};
    struct ListNode list1;
    struct ListNode list2;
    list1.val = 0;
    list2.val = 0;

    struct ListNode* temp = &list1;
    for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); i++) {
        temp->next = (ListNode*)malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = array1[i];
        temp->next = nullptr;
        list1.val++;
        cout << "list1:" << temp->val << endl;
    }
    temp = &list2;
    for (int i = 0; i < sizeof(array2) / sizeof(array2[0]); i++) {
        temp->next = (ListNode*)malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = array2[i];
        temp->next = nullptr;
        list2.val++;
        cout << "list2:" << temp->val << endl;
    }
    vector<ListNode*> lists;
    lists.push_back(list1.next);
    lists.push_back(list2.next);
    Solution* s = new Solution();
    ListNode * result=s->mergeKLists2(lists);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
