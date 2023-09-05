/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void pnt(Node* temp2)
    {
        Node* temp = temp2;
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
public:
    Node* copyRandomList(Node* head)
    {
        if(head==NULL)
            return NULL;
        Node* head2 = new Node(head->val);
        Node* temp1=head, *temp2=head2;
        while(temp1!=NULL)
        {
            if(temp1->next!=NULL)
                temp2->next=new Node(temp1->next->val);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        unordered_map<Node*,int> mp1;
        unordered_map<int,Node*> mp2;
        temp1=head, temp2=head2;
        int cnt=0;
        while(temp1!=NULL)
        {
            mp1[temp1]=cnt;
            mp2[cnt]=temp2;
            temp1=temp1->next;
            temp2=temp2->next;
            cnt++;
        }
        temp1=head, temp2=head2;
        // pnt(temp2);
        while(temp1!=NULL)
        {
            Node* ran = temp1->random;
            if(ran==NULL)
                temp2->random=NULL;
            else
            {
                cnt=mp1[ran];
                Node* temp3=mp2[cnt];
                temp2->random=temp3;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return head2;
    }
};