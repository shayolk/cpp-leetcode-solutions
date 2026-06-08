class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), ind = 0, cnt = 0;
        int nn = n;
        char now = '*';
        auto push = [&](char c) {
            if (ind == nn) {
                chars.push_back('*');
                ++nn;
            }
            chars[ind++] = c;
        };
        auto push_int = [&](int num) {
            string scnt;
            while (num) {
                scnt += ('0' + (num % 10));
                num /= 10;
            }
            reverse(scnt.begin(), scnt.end());
            for (char s: scnt) {
                push(s);
            }
        };
        for (int i = 0; i < n; ++i) {
            char c = chars[i];
            if (c == now) {
                ++cnt;
            } else {
                if (cnt) {
                    push(now);
                    if (cnt > 1) {
                        push_int(cnt);
                    }
                }
                now = c;
                cnt = 1;
            }
        }
        if (cnt) {
            push(now);
            if (cnt > 1) {
                push_int(cnt);
            }
        }
        return ind;
    }
};
