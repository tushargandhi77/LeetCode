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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr && curr->next){
            int gcd = __gcd(curr->val,curr->next->val);
            prev = curr;
            curr = curr->next;
            ListNode* node = new ListNode(gcd);
            prev->next = node;
            node->next = curr;
        }
        return head;
    }
};
