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
    ListNode* middleNode(ListNode* head)
    {
        int count=0;
        ListNode* h=head;
        while(h!=NULL)
        {
            h=h->next;
            count++;
        }
        count/=2;
        //count++;
        h=head;
        while(count--)
            h=h->next;
        return h;
    }
};