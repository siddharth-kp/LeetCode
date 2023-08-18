class NumArray {
private:
	vector<int> sgt_arr;
	vector<int> arr;
	
	void update(int idx, int chng, int st, int en, int sgt_arr_idx)
	{
		// cout<<"update: "<<idx<<" "<<chng<<" "<<st<<" "<<en<<" "<<sgt_arr_idx<<endl;
		if(idx>=st && idx<=en)
			sgt_arr[sgt_arr_idx]+=chng;
        else
            return;
		if(st==en)
			return;
		int mid=st+(en-st)/2;
		update(idx,chng,st,mid,sgt_arr_idx*2+1);
		update(idx,chng,mid+1,en,sgt_arr_idx*2+2);
		sgt_arr[sgt_arr_idx]=sgt_arr[sgt_arr_idx*2+1]+sgt_arr[sgt_arr_idx*2+2];
	}
	
	int sum(int arr_left, int arr_right, int st, int en, int sgt_arr_idx)
	{
		// cout<<"sum: "<<arr_left<<" "<<arr_right<<" "<<st<<" "<<en<<" "<<sgt_arr_idx<<endl;
		if(st>=arr_left && en<=arr_right)
			return sgt_arr[sgt_arr_idx];
		if(en<arr_left || st>arr_right)
			return 0;
		if(st==en)
			return sgt_arr[sgt_arr_idx];
		int mid=st+(en-st)/2;
		int q1 = sum(arr_left,arr_right,st,mid,sgt_arr_idx*2+1);
		int q2 = sum(arr_left,arr_right,mid+1,en,sgt_arr_idx*2+2);
		return q1+q2;
	}
	
	void build(int st, int en, int idx) // start and end of arr_idx, curr sgt_arr_idx
	{
		if(st==en)
		{
			sgt_arr[idx] = arr[st];
			return;
		}
		int mid = st + (en-st)/2;
		build(st,mid,idx*2+1);
		build(mid+1,en,idx*2+2);
		sgt_arr[idx]=sgt_arr[2*idx+1]+sgt_arr[2*idx+2];
	}

public:
    NumArray(vector<int>& nums)
    {
		sgt_arr.resize(4*nums.size(),0);
		arr=nums;
		build(0,nums.size()-1,0);
		// for(int i=0;i<5;i++)
		// 	cout<<sgt_arr[i]<<" ";
		// cout<<endl;
    }
	
	void update(int idx, int val)
	{
		int change = val-arr[idx];
		arr[idx]=val;
		update(idx,change,0,arr.size()-1,0);
		// cout<<"update: "<<idx<<" "<<val<<endl;
		// for(int i=0;i<5;i++)
		// 	cout<<sgt_arr[i]<<" ";
		// cout<<endl;
	}
    
    int sumRange(int left, int right)
    {
		// cout<<"sum: "<<left<<" "<<right<<endl;
		return sum(left,right,0,arr.size()-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */