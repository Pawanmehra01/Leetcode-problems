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
       ListNode* slow = head ;
       ListNode* fast = head ;
       while(fast!=NULL  && fast->next!=NULL){
        slow = slow->next ;
        fast = fast->next->next ;
       }
       ListNode* current = slow ;
       /*prev->NULL
        curr-> 1->next->2->next-> 1->next->2->NULL
       // 1 2 2 2ghn*/
       ListNode* prev = NULL ;
       //reversed the l;inked list succesfully
        while(current!=NULL ){
           ListNode* temp = current->next ;
           current->next = prev ;
           prev = current ;
           current = temp ;
        }
       current= head ;
       ListNode* last = prev ;
       while(last != NULL ){
            if(current->val != last->val)return false;
                last = last->next ;
                current = current ->next ;   
       }
       return true ;
    }
};