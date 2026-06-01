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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int length = 0;
        while (curr!=nullptr)
        {
            curr = curr->next;
            length++;
        }
        
        ListNode* prev = new ListNode(0);
        ListNode* dummy = head;
        prev->next = head;
        int index = 0;
        while (index<length-n&&prev!=nullptr)
        {
            
            prev = prev->next;
            index++;
        }
        cout<<prev->val<<endl;
        if (prev->val==0)
        {
            prev->next=nullptr;
            
            return dummy->next;
        }

        if (prev->next->next!=nullptr)
        {
            prev->next = prev->next->next;
        }
        else
        {
            prev->next = nullptr;
        }
        return dummy;
    }
};
