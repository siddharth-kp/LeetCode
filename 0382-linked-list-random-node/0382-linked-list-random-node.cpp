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
    
    ListNode* head;
    int n=0;
    
    Solution(ListNode* head)
    {
        this->head=head;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            n++;
            temp=temp->next;
        }
    }
    
    int getRandom()
    {
        int idx=rand()%n;
        ListNode*temp=head;
        while(idx--)
            temp=temp->next;
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */