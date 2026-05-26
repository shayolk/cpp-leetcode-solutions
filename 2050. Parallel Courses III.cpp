class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> in(n);
        for (auto rel: relations) {
            adj[rel[0] - 1].push_back(rel[1] - 1);
            ++in[rel[1] - 1];
        }
        queue<int> q;
        vector<int> deps(n);
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int neb: adj[now]) {
                deps[neb] = max(deps[neb], deps[now] + time[now]);
                if(--in[neb] == 0) {
                    q.push(neb);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, deps[i] + time[i]);
        }
        return ans;
    }
};
