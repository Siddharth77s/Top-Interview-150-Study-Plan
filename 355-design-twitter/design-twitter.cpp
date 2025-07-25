class Twitter {
private:
    deque<pair<int, int>> feeds;
    unordered_map<int, unordered_set<int>> followerToFollowee;
public:
    Twitter() {}
    void postTweet(int userId, int tweetId) {
        feeds.push_front(make_pair(userId, tweetId));
    }
    vector<int> getNewsFeed(int userId) {
        vector<int> v;
        auto it = feeds.begin();
        auto &followees = followerToFollowee[userId];
        int cnt = 0;
        while (it != feeds.end() && cnt < 10) {
            int posterId = it->first;
            if (posterId == userId
            || followees.find(posterId) != followees.end()) {
                v.push_back(it->second);
                ++cnt;
            }
            ++it;
        }
        return v;
    }
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followerToFollowee[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followerToFollowee[followerId].erase(followeeId);
    }
};