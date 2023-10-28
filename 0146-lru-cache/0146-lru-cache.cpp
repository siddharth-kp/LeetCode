class node {
public:
    int key;
    int val;
    node* next;
    node* prev;

    node(int key, int val)
    {
        this->key=key;
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};

class LRUCache {
private:
    node* head = new node(-1,-1);
    node* tail = new node(-2,-2);
    int capacity;
    unordered_map<int,node*> mp;

public:
    LRUCache(int capacity)
    {
        this->capacity=capacity;
        head->next=tail;
    }
    
    int get(int key)
    {
        // cout<<"get "<<key<<endl;
        if(!mp.count(key))
            return -1;
        node* curr = mp[key];
        curr->next->prev=curr->prev;
        curr->prev->next=curr->next;
        curr->next=head->next;
        curr->prev=head;
        head->next=curr;
        curr->next->prev=curr;
        return curr->val;
    }
    
    void put(int key, int value)
    {
        // cout<<"put  "<<key<<":"<<value<<endl;
        if(mp.count(key))
        {
            node* curr=mp[key];
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
            curr->next=head->next;
            curr->prev=head;
            head->next=curr;
            curr->next->prev=curr;
            curr->val=value;
            return;
        }
        bool del = mp.size()==capacity;
        node* curr = new node(key,value);
        curr->next=head->next;
        curr->prev=head;
        head->next=curr;
        curr->next->prev=curr;
        mp[key]=curr;
        if(del)
        {
            node* curr2 = tail->prev;
            int d = curr2->key;
            mp.erase(d);
            // cout<<"erased: "<<d;
            curr2->next->prev=curr2->prev;
            curr2->prev->next=curr2->next;
            delete curr2;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */