class MyLinkedList
{
private:
    struct Node
    {
        Node *next = NULL, *prev = NULL;
        int val;
        Node(int _val) : val(_val) {}
    };
    void connect(Node *left, Node *right)
    {
        left->next = right;
        right->prev = left;
    }
    void add(Node *left, Node *middle, Node *right)
    {
        connect(left, middle);
        connect(middle, right);
    }
    Node *advance(Node *current, int &index)
    {
        while (current != dummy_tail && index)
        {
            current = current->next;
            index--;
        }
        return current;
    }
    Node *dummy_head, *dummy_tail;

public:
    MyLinkedList()
    {
        dummy_head = new Node(-1);
        dummy_tail = new Node(-1);
        connect(dummy_head, dummy_tail);
    }

    int get(int index)
    {
        return advance(dummy_head->next, index)->val;
    }

    void addAtHead(int val)
    {
        add(dummy_head, new Node(val), dummy_head->next);
    }

    void addAtTail(int val)
    {
        add(dummy_tail->prev, new Node(val), dummy_tail);
    }

    void addAtIndex(int index, int val)
    {
        Node *cur = advance(dummy_head->next, index);
        if (index)
            return;
        add(cur->prev, new Node(val), cur);
    }

    void deleteAtIndex(int index)
    {
        Node *cur = advance(dummy_head->next, index);
        if (cur == dummy_tail)
            return;
        connect(cur->prev, cur->next);
        delete cur;
    }
};