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
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return nullptr;
    }

};
int main25()
{
    int array[] = { 1,2,3,4,5 };
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
    ListNode* result = s->reverseKGroup(list.next,3);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
