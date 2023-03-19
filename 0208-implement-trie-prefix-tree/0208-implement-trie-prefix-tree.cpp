class TrieNode
{
    public:
    TrieNode* child[26];
    bool isend=false;
    
    TrieNode()
    {
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
};

class Trie {
public:
    
    TrieNode* head = NULL;
    
    Trie()
    {
        head = new TrieNode();
    }
    
    void insert(string word)
    {
        TrieNode* temp=head;
        for(char ch:word)
        {
            int idx=ch-'a';
            if(temp->child[idx]==NULL)
            {
                TrieNode* temp2=new TrieNode();
                temp->child[idx]=temp2;
                temp=temp2;
            }
            else
                temp=temp->child[idx];
        }
        temp->isend=true;
    }
    
    bool search(string word)
    {
        TrieNode* temp=head;
        for(char ch:word)
        {
            int idx=ch-'a';
            if(temp->child[idx]==NULL)
                return false;
            temp=temp->child[idx];
        }
        return temp->isend;
    }
    
    bool startsWith(string prefix)
    {
        TrieNode* temp=head;
        for(char ch:prefix)
        {
            int idx=ch-'a';
            if(temp->child[idx]==NULL)
                return false;
            temp=temp->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */