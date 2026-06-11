class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, int>> maxHeap;
        queue<pair<int,int>> cooldown;
        map<char, int> freq;
        int cycle = 0;
        for (char t: tasks)
        {
            freq[t]++;
        }
        for (const auto& [key, value] : freq) {
            maxHeap.push({value, 100000});
        }
        while (!maxHeap.empty() || !cooldown.empty()) {
            if (!cooldown.empty() && cycle - cooldown.front().second > n) {
                maxHeap.push(cooldown.front());
                cooldown.pop();
            }

            if (!maxHeap.empty()) {
                auto task = maxHeap.top(); maxHeap.pop();
                task.first--;
                task.second = cycle;
                if (task.first > 0) cooldown.push(task);
            }
            cycle++;
        }
        return cycle;
        

    }
};
