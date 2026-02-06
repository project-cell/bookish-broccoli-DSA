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
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         ListNode * slow = head;
//         ListNode *fast = head->next;

//         // to find the middlle element in the linked list
//         while( slow->val != NULL && fast->val != NULL ){
//             slow = head->next;
//             fast= head->next->next;
//         } 

//         // reversal of second half of the linked list eg 12 21 // 12 12
//         ListNode *prev= NULL;
//         ListNode *curr=slow->next;
//         while (curr->next != NULL){
//             ListNode *temp = curr->next;
//             //reverse the pointer
//             curr->next=prev;
//             // shifting the pointerrs
//             prev = curr;
//             curr =temp;
//         }
//         while(prev!=NULL){
//             if(head->val != prev->val){
//             return 0;
//             }
//             head=head->next;
//             prev= prev->next;
//         }
//         return 0;
//     }
// };
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Find the middle of the linked list using two pointers
        // slow moves one step, fast moves two steps
        ListNode* slowPtr = head;
        ListNode* fastPtr = head->next;
      
        while (fastPtr != nullptr && fastPtr->next != nullptr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
      
        // Reverse the second half of the linked list
        // slowPtr->next points to the start of second half
        ListNode* prev = nullptr;
        ListNode* curr = slowPtr->next;
      
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;  // Store next node
            curr->next = prev;                 // Reverse the link
            prev = curr;                        // Move prev forward
            curr = nextTemp;                    // Move curr forward
        }
      
        // Compare the first half and reversed second half
        // prev now points to the head of reversed second half
        while (prev != nullptr) {
            if (prev->val != head->val) {
                return false;  // Values don't match, not a palindrome
            }
            prev = prev->next;
            head = head->next;
        }
      
        return true;  // All values matched, it's a palindrome
    }
};