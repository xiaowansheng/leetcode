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
    //1、迭代
    //指针的灵活运用
    //同时旋转时要考虑需要旋转的两个节点是不是存在nullptr
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
            //此步骤可改为递归
            begin = begin->next->next;
        }
        return result;
    }

    //2、递归
    //指针的灵活运用
    //同时旋转时要考虑需要旋转的两个节点是不是存在nullptr
    ListNode* swapPairs2(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* result = head->next, * h = nullptr;
        h = head;//h先指向第一个节点
        head = head->next;//head指向了第二个节点
        h->next = head->next;//第一个节点的下一个节点是第三个节点，此时第二个节点的下一个节点指针无用
        head->next = h;//第二个节点的下一个节点是第一个节点
        h->next=swapPairs2(h->next);//把第三个节点传入递归函数，返回旋转后头节点，然后第二个节点的下一个节点指向剩下链表旋转后的头节点
        return head;//返回旋转后的头节点
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
