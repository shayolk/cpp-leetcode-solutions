class Solution {
    static constexpr int INF = 1e9 + 5;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INF);
        dist[src] = 0;
        for (int i = 0; i <= k; ++i) {
            vector<int> here = dist;
            for (auto fl: flights) {
                if (here[fl[0]] != INF) {
                    here[fl[1]] = min(here[fl[1]], dist[fl[0]] + fl[2]);
                }
            }
            dist = here;
        }
        if (dist[dst] == INF) {
            return -1;
        }
        return dist[dst];
    }
};
