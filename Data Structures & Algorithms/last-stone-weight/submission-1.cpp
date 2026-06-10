class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        
        for (int s: stones)
        {
            maxHeap.push(s);
        }
        int size = maxHeap.size();
        while (size>1)
        {
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();
            if (x < y)
            {
                maxHeap.push(y-x);
                size--;
            }
            else if (x == y)
            {
                size-=2;
            }
        
        }
        if (maxHeap.size()>0)
        {
            return maxHeap.top();
        }
        return 0;

    }
};
