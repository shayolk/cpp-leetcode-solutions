class OrderedStream {
    int end, n;
    vector<string> stream;

public:
    OrderedStream(int n) {
        end = 0;
        this->n = n;
        stream.resize(n, "");
    }
    
    vector<string> insert(int idKey, string value) {
        stream[idKey - 1] = value;
        int start = end;
        while (end < n && stream[end] != "") {
            ++end;
        }
        return vector<string>(stream.begin() + start, stream.begin() + end);
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
