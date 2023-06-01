class dsuf{
	public:
	vector<int> arr;
    
    void disp()
    {
        for(int i:arr)
            cout<<i<<" ";
        cout<<endl;
    }

	dsuf(int n){
		arr.resize(n,-1);
	}

	int parent(int a){
		if(arr[a]==-1)
		return a;
		else
		return arr[a]=parent(arr[a]);
	}

	void merge(int a, int b){
		int p1=parent(a);
		int p2=parent(b);
		arr[p1]=p2;
	}

	bool sameset(int a, int b){
		return (parent(a)==parent(b) && parent(a)!=-1);
	}
};



class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        dsuf d(edges.size()+1);
	    for(int i=0;i<edges.size();i++){
	        vector<int> v=edges[i];
	        // cout<<i<<endl;
		    if(d.sameset(v[0],v[1]))
			    return v;
		    else
			    d.merge(v[0],v[1]);
            // d.disp();
	    }
	    return {};
    }
};