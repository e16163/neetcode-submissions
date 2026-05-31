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
        vector<ListNode*> arr;
        ListNode* dummy = head;
        
        while (head!=nullptr)
        {
            
            arr.push_back(head);
            head = head->next;
        }
        head = dummy;
        int left = 0;
        int right = arr.size()-1;
        while (left <= right)
        {
            head->next = arr[left];
            left++;
            head = head->next;
            head->next = arr[right];
            head = head->next;
            right--;
            head->next = nullptr;
        }
        
    }
};
