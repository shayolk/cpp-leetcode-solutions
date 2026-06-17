class Solution {
    int n;
    map<int,string> i2s;
    map<string,int> s2i;
    vector<vector<int>> adj;
    vector<int> outd;
    vector<string> path;

    void dfs(int now) {
        while (outd[now]) {
            int neb = adj[now][--outd[now]];
            dfs(neb);
        }
        path.push_back(i2s[now]);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        set<string> st;
        for (auto& ticket: tickets) {
            st.insert(ticket[0]);
            st.insert(ticket[1]);
        }
        n = st.size();
        int ind = n - 1;
        for (string city: st) {
            s2i[city] = ind;
            i2s[ind] = city;
            --ind;
        }
        adj.resize(n);
        outd.resize(n);
        for (auto& ticket: tickets) {
            int from = s2i[ticket[0]];
            int to = s2i[ticket[1]];
            adj[from].push_back(to);
            ++outd[from];
        }
        for (int i = 0; i < n; ++i) {
            sort(adj[i].begin(), adj[i].end());
        }
        dfs(s2i["JFK"]);
        reverse(path.begin(), path.end());
        return path;
    }
};
