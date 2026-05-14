class Solution {
    vector<int> adj[26];
    int ids[26], low[26], scc[26];
    bool on_stack[26], exists[26];
    stack<int> st;
    int id = 0, scc_count = 0;

    void dfs(int now) {
        ids[now] = low[now] = id++;
        st.push(now);
        on_stack[now] = true;
        for (int neb: adj[now]) {
            if (ids[neb] == -1) {
                dfs(neb);
            }
            if (on_stack[neb]) {
                low[now] = min(low[now], low[neb]);
            }
        }
        if (low[now] == ids[now]) {
            while(!st.empty()) {
                int node = st.top();
                scc[node] = scc_count;
                st.pop();
                on_stack[node] = false;
                if (node == now) {
                    break;
                }
            }
            ++scc_count;
        }
    }

public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n), last(26, -1);
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            exists[c] = true;
            first[c] = min(first[c], i);
            last[c] = max(last[c], i);
        }
        for (int i = 0; i < 26; ++i) {
            if (!exists[i]) {
                continue;
            }
            vector<bool> vis(26);
            for (int j = first[i]; j <= last[i]; ++j) {
                int c = s[j] - 'a';
                if (c != i && !vis[c]) {
                    adj[i].push_back(c);
                    vis[c] = true;
                }
            }
        }
        memset(ids, -1, sizeof(ids));
        for (int i = 0; i < 26; ++i) {
            if (exists[i] && ids[i] == -1) {
                dfs(i);
            }
        }
        vector<int> out(26, -1);
        for (int i = 0; i < 26; ++i) {
            if (!exists[i]) {
                continue;
            }
            if (out[scc[i]] == -1) {
                out[scc[i]] = 0;
            }
            for (int j: adj[i]) {
                if (scc[i] != scc[j]) {
                    ++out[scc[i]];
                }
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            if (!out[i]) {
                int mn = n, mx = -1;
                for (int j = 0; j < 26; ++j) {
                    if (scc[j] == i) {
                        mn = min(mn, first[j]);
                        mx = max(mx, last[j]);
                    }
                }
                ans.push_back(s.substr(mn, mx - mn + 1));
            }
        }
        return ans;
    }
};
