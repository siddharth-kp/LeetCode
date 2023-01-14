class DSU {
private:
    vector<int> parent;

public:
    DSU()
    {
        parent = vector<int>(26,-1);
    }

    int find(int a)
    {
        if(parent[a] == -1)
            return a;
        return parent[a] = find(parent[a]);
    }

    void Union(int n1, int n2)
    {
        int r1 = find(n1);
        int r2 = find(n2);
        if(r1 != r2)
            parent[max(r1, r2)] = min(r1, r2);
    }

};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        DSU dsu;
        for(int i=0;i<s1.size();i++)
        {
            int ch1 = s1[i]-'a';
            int ch2 = s2[i]-'a';
            dsu.Union(ch1, ch2);
        }
        for(int i=0;i<baseStr.size();i++)
        {
            int mn=dsu.find(baseStr[i]-'a');
            baseStr[i]=mn+'a';
        }
        return baseStr;
        
        
    //     vector<unordered_set<char>> v;
    //     string ans="";
    //     for(int i=0;i<s1.length();i++)
    //     {
    //         char c1=s1[i];
    //         char c2=s2[i];
    //         bool found=0;
    //         for(auto &i:v)
    //         {
    //             if(i.count(c1) || i.count(c2))
    //             {
    //                 found=1;
    //                 i.insert(c1);
    //                 i.insert(c2);
    //                 break;
    //             }
    //         }
    //         if(!found)
    //         {
    //             unordered_set<char> st;
    //             st.insert(c1);
    //             st.insert(c2);
    //             v.push_back(st);
    //         }
    //     }
    //     vector<char> v2(v.size());
    //     for(int i=0;i<v.size();i++)
    //     {
    //         char small='z';
    //         for(auto it=v[i].begin();it!=v[i].end();it++)
    //             if(*it<small)
    //                 small=*it;
    //         v2[i]=small;
    //     }
    //     for(char c:baseStr)
    //     {
    //         bool found=false;
    //         for(int i=0;i<v.size();i++)
    //         {
    //             if(v[i].count(c))
    //             {
    //                 ans+=v2[i];
    //                 found=1;
    //                 break;
    //             }
    //         }
    //         if(!found)
    //             ans+=c;
    //     }
    //     return ans;
    }
    
    
};