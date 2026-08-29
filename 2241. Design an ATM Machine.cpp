class ATM {
    vector<int> notes{20, 50, 100, 200, 500};
    vector<int> count{0, 0, 0, 0, 0};

public:
    ATM() {
        
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i) {
            count[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5);
        for (int i = 4; i >= 0; --i) {
            int num = min(count[i], amount / notes[i]);
            amount -= num * notes[i];
            ans[i] = num;
        }
        if (amount) {
            return {-1};
        }
        for (int i = 0; i < 5; ++i) {
            count[i] -= ans[i];
        }
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
