class Leaderboard {
    map<int,int> scores;
    set<pair<int,int>> st;

public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if (scores.count(playerId)) {
            st.erase({scores[playerId], playerId});
        }
        scores[playerId] += score;
        st.insert({scores[playerId], playerId});
    }
    
    int top(int K) {
        int ans = 0;
        auto it = st.rbegin();
        while (it != st.rend() && K--) {
            ans += it->first;
            ++it;
        }
        return ans;
    }
    
    void reset(int playerId) {
        if (!scores.count(playerId)) {
            return;
        }
        st.erase({scores[playerId], playerId});
        scores.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
