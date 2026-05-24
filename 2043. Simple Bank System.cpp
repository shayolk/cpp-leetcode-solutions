class Bank {
    int n;
    vector<long long>& bal;

    bool check_acc(int acc) {
        return acc >=0 && acc < n;
    }

    bool check_bal(int acc, long long mon) {
        return check_acc(acc) && bal[acc] >= mon;
    }

public:
    Bank(vector<long long>& balance) : bal(balance), n(balance.size()) {}
    
    bool transfer(int account1, int account2, long long money) {
        --account1;
        --account2;
        if (!check_acc(account2) || !check_bal(account1, money)) {
            return false;
        }
        bal[account1] -= money;
        bal[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        --account;
        if (!check_acc(account)) {
            return false;
        }
        bal[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        --account;
        if (!check_bal(account, money)) {
            return false;
        }
        bal[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
