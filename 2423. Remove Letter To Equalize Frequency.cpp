class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> cnt(26, -1);
        for (char c: word) {
            int cc = c - 'a';
            if (cnt[cc] == -1) {
                cnt[cc] = 0;
            }
            ++cnt[cc];
        }
        map<int,int> freq;
        for (int c: cnt) {
            if (c != -1) {
                ++freq[c];
            }
        }
        if (freq.size() > 2) {
            return false;
        }
        auto one = freq.begin();
        if (freq.size() == 1) {
            return one->first == 1 || one->second == 1;
        }
        if (one->first == 1 && one->second == 1) {
            return true;
        }
        return next(one)->first - one->first == 1 && next(one)->second == 1;
    }
};
