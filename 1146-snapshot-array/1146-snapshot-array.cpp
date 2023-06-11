class SnapshotArray {
public:
    
    vector<vector<pair<int,int>>> v;
    int snap_cnt=0;
    
    SnapshotArray(int length)
    {
        v.resize(length);
    }
    
    void set(int index, int val) 
    {
        v[index].push_back({snap_cnt,val});
    }
    
    int snap()
    {
        return snap_cnt++;
    }
    
    int get(int index, int snap_id)
    {
        int x = upper_bound(v[index].begin(), v[index].end(), pair<int, int>{snap_id, INT_MAX}) - v[index].begin();
        if(x >= 1)
            return v[index][x-1].second;
        else
            return 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */