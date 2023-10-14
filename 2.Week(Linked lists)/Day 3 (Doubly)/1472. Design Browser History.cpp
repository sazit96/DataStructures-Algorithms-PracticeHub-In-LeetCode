struct node
{
    node *prev = NULL;
    node *next = NULL;
    const string url;
    node(const string &url) : url(url){};
};
class BrowserHistory
{
private:
    node *curr = NULL;

public:
    BrowserHistory(string homepage)
    {
        curr = new node(homepage);
    }

    void visit(string url)
    {
        node *newnode = new node(url);
        curr->next = newnode;
        newnode->prev = curr;
        curr = newnode;
    }

    string back(int steps)
    {
        while (curr->prev && steps > 0)
        {
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }

    string forward(int steps)
    {
        while (curr->next && steps > 0)
        {
            curr = curr->next;
            steps--;
        }
        return curr->url;
    }
};
