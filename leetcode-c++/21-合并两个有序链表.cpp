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
    //1、迭代解法
    //建立一个新的空链表，把存入合并的数据。（类似于归并排序中的合并数组）
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

    //2、迭代原链表，根据两个链表的指针互相指向，拼接出新的排序链表,即把两个链表用指针串联起来
    ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
        //结果链表和两个中间节点指针
        ListNode result(-1);//结果链表
        ListNode* temp = &result;//结果链表的临时变量
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
        //最后把没遍历完的链表接在结果链表后面
        temp->next = (list1 == nullptr ? list2 : list1);
        return result.next;
    }

    //3、递归解法，如方法2，只是把循环变为递归
    ListNode* mergeTwoLists3(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr||list2==nullptr) {
            //当递归到某个链表最后，则把另一个链表的剩余部分直接返回
            return list1 == nullptr ? list2 : list1;
        }
        if (list1->val <= list2->val) {
            //当当前list1—>val的值为当前最小值时，则下一个最小值从list1->next和list2中选出
            //并把当前list1->next指针指向下一个最小值
            list1->next = mergeTwoLists3(list1->next,list2);
            //返回当前比较的最小值
            return list1;
        }
        else {
            //反之，则与上述相反
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
