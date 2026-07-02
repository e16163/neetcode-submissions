class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, deque<string>> adj;
        for (auto& v: tickets)
        {
            adj[v[0]].push_back(v[1]);
        }
        for (auto& p: adj)
        {
            
            sort(p.second.rbegin(), p.second.rend());
        }
        vector<string> itinerary;
        dfs("JFK", adj, itinerary);
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
        

    }
    void dfs(string start, unordered_map<string, deque<string>>& adj, vector<string>& itinerary)
    {
        while (!adj[start].empty())
        {
            string end = adj[start].back();
            adj[start].pop_back();
            dfs(end, adj, itinerary);
        }  
        itinerary.push_back(start); 
    }
};
