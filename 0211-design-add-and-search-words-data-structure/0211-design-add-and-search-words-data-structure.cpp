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

class WordDictionary {
public:
    
    TrieNode* head;
    
    WordDictionary()
    {
        head = new TrieNode();
    }
    
    void addWord(string word)
    {
        TrieNode* temp=head;
        for(char ch:word)
        {
            int idx=ch-'a';
            if(temp->child[idx]==NULL)
                temp->child[idx]=new TrieNode();
            temp=temp->child[idx];
        }
        temp->isend=true;
    }
    
   bool search(string &word, int ind, TrieNode* cur)
   {
        for(int i=ind;i<word.size();i++)
        {
            if(word[i]=='.')
            {
                for(int k=0;k<26;k++)
                {
                    TrieNode* temp = cur->child[k];
                    if(temp!=NULL && search(word,i+1,temp))
                        return true;
                }   
                return false;
            }
            else
            {
                int k = word[i] - 'a';
                cur = cur->child[k];   
                if(cur==NULL)
                    return false;
            }
        }
        return cur->isend;
    }
    
    bool search(string word)
    {
        return search(word,0,head);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */