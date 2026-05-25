class LRUCache {
    struct Data {
        int key;
        int val;
        Data* prev;
        Data* next;

        Data(int key, int val, Data* prev = nullptr, Data* next = nullptr) {
            this->key = key;
            this->val = val;
            this->prev = prev;
            this->next = next;
        }
    };

    int cur_cap, tot_cap;
    Data* first;
    Data* last;
    map<int,Data*> mp_loc;

    void add(Data* data) {
        mp_loc[data->key] = data;
        last->prev->next = data;
        data->prev = last->prev;
        data->next = last;
        last->prev = data;
    }

    void rem() {
        mp_loc.erase(first->next->key);
        Data* tmp = first->next;
        first->next = first->next->next;
        first->next->prev = first;
        delete tmp;
    }

    void use(Data* data) {
        data->prev->next = data->next;
        data->next->prev = data->prev;
        add(data);
    }

public:
    LRUCache(int capacity) {
        cur_cap = 0;
        tot_cap = capacity;
        first = new Data(-1, -1);
        last = new Data(-1, -1);
        first->next = last;
        last->prev = first;
    }
    
    int get(int key) {
        if (!mp_loc.count(key)) {
            return -1;
        }
        Data* data = mp_loc[key];
        use(data);
        return data->val;
    }
    
    void put(int key, int value) {
        if (mp_loc.count(key)) {
            Data* data = mp_loc[key];
            data->val = value;
            use(data);
            return;
        }
        if (cur_cap == tot_cap) {
            --cur_cap;
            rem();
        }
        ++cur_cap;
        Data* data = new Data({key, value});
        add(data);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
