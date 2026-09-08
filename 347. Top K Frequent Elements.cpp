class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> cnt;
        for (int num: nums) {
            ++cnt[num];
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for (auto c: cnt) {
            pq.push({c.second, c.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
