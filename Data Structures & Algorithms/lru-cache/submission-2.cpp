struct ListNode {
    int key, val;
    ListNode* prev;
    ListNode* next;
    ListNode(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
public:
    int cap;
    int size;
    ListNode* front;
    ListNode* back;
   
    map<int, ListNode*> cache;
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        front = new ListNode(0, 0);
        back = new ListNode(0, 0);
        front->prev = back;
        back->next = front;
        
        
    }
    
    int get(int key) {
        if (cache.find(key)!=cache.end())
        {
            ListNode* prevNode = cache[key]->prev;
            ListNode* nextNode = cache[key]->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            ListNode* prev = front->prev;  
            prev->next = cache[key];
            cache[key]->prev = prev;
            cache[key]->next = front;
            front->prev = cache[key];
            return cache[key]->val;

        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end())
        {
             ListNode* prevNode = cache[key]->prev;
            ListNode* nextNode = cache[key]->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            ListNode* prev = front->prev;  
            prev->next = cache[key];
            cache[key]->prev = prev;
            cache[key]->next = front;
            front->prev = cache[key];
            cache[key]->val = value;
        }
        else
        {
            cache[key] = new ListNode(key, value);
            ListNode* prev = front->prev;  
            prev->next = cache[key];
            cache[key]->prev = prev;
            cache[key]->next = front;
            front->prev = cache[key];
            size++;
        }
        
        if (size > cap)
        {
            cout<<"hi"<<endl;
            ListNode* remove = back->next;
            int k = remove->key;
            remove->prev = nullptr;
            cache.erase(k);
            back = back->next;
            size--;
        }
        
    }
};
