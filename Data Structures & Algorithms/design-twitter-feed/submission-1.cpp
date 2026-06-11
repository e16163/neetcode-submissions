class Twitter {
public:

map<int, map<int, bool>> following;
priority_queue<pair<int, pair<int, int>>> maxHeap;
int time;
    Twitter() {
        time = 0;
        map<int, map<int, bool>> following;
        priority_queue<pair<int, pair<int, int>>> maxHeap;
    }
    
    void postTweet(int userId, int tweetId) {
        maxHeap.push({time, {userId, tweetId}});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> news;
        priority_queue<pair<int, pair<int, int>>> tweets = maxHeap;
        int length = tweets.size();
        for (int i = 0; i<length; i++)
        {
            pair<int, int> tweet = tweets.top().second;
            map<int, bool> flist = following[userId];
            if (flist[tweet.first]==true || userId == tweet.first)
            {
                if (news.size()<10)
                {
                    news.push_back(tweet.second);
                }
            }
            tweets.pop();
        }
        return news;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId][followeeId] = true;
        
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId][followeeId] = false;
    }
};
