class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> times;
        vector<int> idx(position.size());
        std::iota(idx.begin(), idx.end(), 0);
        std::sort(idx.begin(), idx.end(), [&](int a, int b) {
            return position[a] > position[b];  
        });
        vector<float> sorted_position(position.size()), sorted_speed(speed.size());
        for (int i = 0; i < idx.size(); i++) {
            sorted_position[i] = position[idx[i]];
            sorted_speed[i] = speed[idx[i]];
        }
        for (int i = 0; i<sorted_position.size(); i++)
        {
            int remaining = target - sorted_position[i];
            double time = (double)(remaining) / sorted_speed[i];
            cout<<time<<endl;
            if (times.empty())
            {
                times.push(time);
                //cout<<sorted_position[i]<<endl;
            }
            else if (time<=times.top())
            {
                //join
                cout<<sorted_position[i]<<endl;

            }
            else if (time>times.top())
            {
                times.push(time);
            }

            
        }
        return times.size();

    }
};
