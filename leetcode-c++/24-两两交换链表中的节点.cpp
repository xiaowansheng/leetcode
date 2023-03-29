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
    //1������
    //ָ����������
    //ͬʱ��תʱҪ������Ҫ��ת�������ڵ��ǲ��Ǵ���nullptr
    ListNode* swapPairs(ListNode* head) {
        if (!head||!head->next) {
            return head;
        }
        ListNode *result=head->next,h,*temp=nullptr,*begin;
        begin = &h;
        begin->next = head;
        while (begin->next && begin->next->next) {
            temp = begin->next;
            begin->next = begin->next->next;
            temp->next = begin->next->next;
            begin->next->next = temp;
            //�˲���ɸ�Ϊ�ݹ�
            begin = begin->next->next;
        }
        return result;
    }

    //2���ݹ�
    //ָ����������
    //ͬʱ��תʱҪ������Ҫ��ת�������ڵ��ǲ��Ǵ���nullptr
    ListNode* swapPairs2(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* result = head->next, * h = nullptr;
        h = head;//h��ָ���һ���ڵ�
        head = head->next;//headָ���˵ڶ����ڵ�
        h->next = head->next;//��һ���ڵ����һ���ڵ��ǵ������ڵ㣬��ʱ�ڶ����ڵ����һ���ڵ�ָ������
        head->next = h;//�ڶ����ڵ����һ���ڵ��ǵ�һ���ڵ�
        h->next=swapPairs2(h->next);//�ѵ������ڵ㴫��ݹ麯����������ת��ͷ�ڵ㣬Ȼ��ڶ����ڵ����һ���ڵ�ָ��ʣ��������ת���ͷ�ڵ�
        return head;//������ת���ͷ�ڵ�
    }
};
int main22()
{
    int array[] = { 1,2,3,4 };
    struct ListNode list;
    list.val = 0;

    struct ListNode* temp = &list;
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        temp->next = (ListNode*)malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = array[i];
        temp->next = nullptr;
        list.val++;
        cout << "list1:" << temp->val << endl;
    }
    Solution* s = new Solution();
    ListNode* result = s->swapPairs2(list.next);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
