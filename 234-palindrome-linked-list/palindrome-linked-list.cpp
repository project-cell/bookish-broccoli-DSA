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
        // Find the middle of the linked list using two pointers
       
        ListNode* slow = head;
        ListNode* fast = head->next;
      
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
      
        // Reverse the second half of the linked list
        // slowPtr->next points to the start of second half
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
      
        while (curr != NULL) {
            ListNode* Temp = curr->next;  // Store next node
            curr->next = prev;                 // Reverse the link
            prev = curr;                        // Move prev forward
            curr = Temp;                    // Move curr forward
        }
      
        // Compare the first half and reversed second half
        // prev now points to the head of reversed second half
        while (prev != NULL) {
            if (prev->val != head->val) {
                return false;  // Values don't match, not a palindrome
            }
            prev = prev->next;
            head = head->next;
        }
      
        return true;  // All values matched, it's a palindrome
    }
};