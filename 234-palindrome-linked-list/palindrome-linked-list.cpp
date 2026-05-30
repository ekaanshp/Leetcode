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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        //getting the halfway point
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        //reversing
        ListNode* prev = nullptr;
        while(slow){
            ListNode* tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }

        ListNode* left = head;
        ListNode* right = prev;

        //palindrome
        while(right){
            if(left->val != right->val){
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};