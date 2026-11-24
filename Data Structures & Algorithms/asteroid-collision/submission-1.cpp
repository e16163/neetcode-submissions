class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> roids;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                roids.push(asteroids[i]);
            }
            else {
                if (roids.empty()) {
                    roids.push(asteroids[i]);
                    continue;
                }
                if (!roids.empty()) {
                    int left = roids.top();
                    int right = asteroids[i];
                    if (left < 0) {
                        roids.push(asteroids[i]);
                        continue;
                    }
                    if (left > abs(right)) {
                        continue;
                    }
                    else if (left == abs(right)) {
                        roids.pop();
                    }
                    else if (left < abs(right)) {
                        while (left > 0 && left < abs(right)) {
                            roids.pop();
                            if (roids.empty()) {
                                break;
                            }
                            left = roids.top();
                        }
                        if (roids.empty() || roids.top() < 0) {
                            roids.push(right);
                        }
                        else if (roids.top() == abs(right)) {
                            roids.pop();
                        }
                    }
                }
            }
        }
        vector<int> ans;
        while (roids.size() > 0) {
            ans.push_back(roids.top());
            roids.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};