/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode* head = new ListNode();
        ListNode* h = head;
        bool f=true;
        while(f)
        {
            f=false;
            int minim=-1,mini = INT_MAX;
            for(int i=0;i<lists.size();i++)
            {
                if (lists[i]!=NULL && lists[i]->val <= mini)
                {
                    minim = i;
                    mini = lists[i]->val;
                    f=true;
                }
            }
            if(minim!=-1)
            {
                ListNode* temp = new ListNode(mini);
                lists[minim]=lists[minim]->next;
                h->next=temp;
                h=h->next;
            }
            
        }
        head=head->next;
        return head;
    }
};