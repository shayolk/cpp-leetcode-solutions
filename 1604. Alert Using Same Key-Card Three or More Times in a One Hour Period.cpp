class Solution {
    int conv(string time) {
        int hour = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3, 2));
        return hour * 60 + min;
    }

public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string,vector<int>> mp;
        int n = keyName.size();
        for (int i = 0; i < n; ++i) {
            mp[keyName[i]].push_back(conv(keyTime[i]));
        }
        vector<string> ans;
        for (auto &p: mp) {
            sort(p.second.begin(), p.second.end());
            int m = p.second.size();
            int i = 0, j = 0;
            while (i < m && j < m) {
                while(j < m && p.second[j] - p.second[i] <= 60) {
                    ++j;
                }
                if (j - i >= 3) {
                    ans.push_back(p.first);
                    break;
                }
                ++i;
            }
        }
        return ans;
    }
};
