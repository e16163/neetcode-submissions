/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> rando;
        //cout<<head->random->val;
        Node* curr = head;
        
        Node* copy = head;
        while (curr!=nullptr)
        {
            rando[curr] = new Node(curr->val);
            curr = curr->next;
        }
        Node* ans = new Node(0);
        ans->next = copy;
        while (copy!=nullptr)
        {
           
           rando[copy]->random = rando[copy->random];
           rando[copy]->next = rando[copy->next];
            copy = copy->next;
        }
        return rando[head];

        
    }
};
