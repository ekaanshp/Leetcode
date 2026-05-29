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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = slow->next;
        slow->next = nullptr;
        ListNode* previous = nullptr;

        while(secondHalf){
            ListNode* tmp = secondHalf->next;
            secondHalf->next = previous;
            previous = secondHalf;
            secondHalf = tmp;
        }

        ListNode* firstHalf = head;
        secondHalf = previous;

        while(secondHalf){
            ListNode* tmp1 = firstHalf->next;
            ListNode* tmp2 = secondHalf->next;
            firstHalf->next = secondHalf;
            secondHalf->next = tmp1;
            firstHalf = tmp1;
            secondHalf = tmp2;
        }
    }
};