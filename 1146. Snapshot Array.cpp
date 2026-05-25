class SnapshotArray {
    int snap_id;
    vector<vector<int>> arr, snaps;

public:
    SnapshotArray(int length) {
        snap_id = 0;
        arr.resize(length);
        snaps.resize(length);
    }
    
    void set(int index, int val) {
        if (!snaps[index].empty() && snaps[index].back() == snap_id) {
            arr[index].back() = val;
            return;
        }
        arr[index].push_back(val);
        snaps[index].push_back(snap_id);
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        int id = lower_bound(snaps[index].begin(), snaps[index].end(), snap_id) - snaps[index].begin();
        if (id >= snaps[index].size()) {
            if (!snaps[index].empty()) {
                return arr[index].back();
            }
            return 0;
        }
        while (id >= 0 && snaps[index][id] > snap_id) {
            --id;
        }
        if (id == -1) {
            return 0;
        }
        return arr[index][id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
