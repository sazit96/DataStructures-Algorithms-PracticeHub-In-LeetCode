class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *newnode, *prvnode = NULL;
        while (head)
        {
            newnode = head->next;
            head->next = prvnode;
            prvnode = head;
            head = newnode;
        }
        return prvnode;
    }
};