class StockPrice {
    map<int,int> time2price, prices;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (time2price.count(timestamp) && prices.count(time2price[timestamp])) {
            if (--prices[time2price[timestamp]] == 0) {
                prices.erase(time2price[timestamp]);
            }
        }
        time2price[timestamp] = price;
        ++prices[price];
    }
    
    int current() {
        return time2price.rbegin()->second;
    }
    
    int maximum() {
        return prices.rbegin()->first;
    }
    
    int minimum() {
        return prices.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
