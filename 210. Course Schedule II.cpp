class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in(numCourses);
        for (auto pre: prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            ++in[pre[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            ans.push_back(now);
            for (int neb: adj[now]) {
                if (in[neb] == 0) {
                    return {};
                }
                if (--in[neb] == 0) {
                    q.push(neb);
                }
            }
        }
        for (int i = 0; i < numCourses; ++i) {
            if (in[i]) {
                return {};
            }
        }
        return ans;
    }
};
