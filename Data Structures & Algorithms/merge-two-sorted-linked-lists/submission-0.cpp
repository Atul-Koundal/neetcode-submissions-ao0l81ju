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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* L1 = list1;
        ListNode* L2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;

        while(L1 && L2){
            if(L1->val <= L2->val){
                prev->next = L1;
                prev = L1;
                L1 = L1->next;
            }
            else{
                prev->next = L2;
                prev = L2;
                L2 = L2->next;
            }
        }
        if (L1) prev->next = L1;
        else if (L2) prev->next = L2;

        return dummy->next;
    }
};