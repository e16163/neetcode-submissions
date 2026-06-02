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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int dist = 1;
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        stack<ListNode*>reverse;
        while (head!=nullptr)
        {
            if (dist<k)
            {
                reverse.push(head);
                cout<<head->val<<endl;
                head = head->next;
                

                dist++;
            }
            else
            {
                cout<<"cycle: "<<head->val<<endl;
                ans->next = head;
                ans = ans->next;
                ListNode* nextNode = head->next;
                while (!reverse.empty())
                {
                    ans->next = reverse.top();
                    head->next = reverse.top();
                    ans = ans->next;
                    head = head->next;
                    
                    reverse.pop();
                }
                head->next = nextNode;
                head = head->next;
                dist = 1;
            }
        }
        return dummy->next;
    }
};
