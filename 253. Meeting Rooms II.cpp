class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for (auto in: intervals) {
            while (!pq.empty() && pq.top() <= in[0]) {
                pq.pop();
            }
            pq.push(in[1]);
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};
