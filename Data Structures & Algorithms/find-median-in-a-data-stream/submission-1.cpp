class MedianFinder {
public:
int mid;
int count;
bool even;
priority_queue<int, vector<int>, greater<int>> minHeap;
priority_queue<int> maxHeap;
    MedianFinder() {
        mid = 0;
        count = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int> maxHeap;
    }
    
    void addNum(int num) {
        if (num < findMedian())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }
        count++;
        mid = count / 2;
        if (count%2==0)
        {
            even = true;
            cout<<"even"<<endl;
        }
        else
        {
            cout<<"odd"<<endl;
            even = false;
        }
        if (minHeap.size() > mid)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if (maxHeap.size() > mid)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if (count==0)
        {
            return 0;
        }
        if (even)
        {
            int s1 = minHeap.top();
            int s2 = maxHeap.top();
            return (double)(s1 + s2) / 2.0;

        }
        else
        {
            return (double)minHeap.top();
        }
    }
};
