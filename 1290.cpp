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
    int getDecimalValue(ListNode* head) {
        ListNode* prev = nullptr;
        while(head){
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }

        int result = 0;
        int power = 0;

        while(prev){
            int val = prev->val;
            result  += (val * (int)pow(2,power));
            power++;
            prev = prev->next;
        }

        return result;
    }
};
