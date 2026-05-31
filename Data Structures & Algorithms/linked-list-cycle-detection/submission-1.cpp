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
    bool hasCycle(ListNode* head) {
        map<ListNode*, int> visited;
        while (head!=nullptr)
        {
            ListNode* next = head->next;
            if (visited[next]!=0)
            {
                return true;
            }
            else
            {
                visited[next]++;
            }
            head = head->next;
        }
        return false;
    }
};
