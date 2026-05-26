class MinStack {
public:
    stack<int> s;
    map<pair<int,int>,int> ans;
    stack<int> time;
    int t;
    MinStack() {
        t=0;
    }
    
    void push(int val) {
        s.push(val);
        t++;
        time.push(t);
        pair<int,int> add = {val, t};
        ans[add]++;
    }
    
    void pop() {
        
        pair<int, int> rem = {s.top(), time.top()};
        ans.erase(rem);
        time.pop();
        cout<<getMin()<<endl;
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        auto last = ans.begin();
        pair<int,int> maxi = last->first;
        return maxi.first;
        
    }
};
