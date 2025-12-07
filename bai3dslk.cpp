#include <iostream>
using namespace std;

class node
{
    friend class dslk;
    int n;
    node* next;
public:
    node(int k)
    {
        n = k;
        next = NULL;
    }
};

class dslk
{
    node* head;
    node* tail;
    int size;
public:
    dslk()
    {
        head = tail = NULL;
        size = 0;
    }
    void addtail(int k)
    {
        node* add = new node(k);
        if(head == NULL)
            head = tail = add;
        else
        {
            tail->next = add;
            tail = add;
        }
        size++;
    }
    void out()
    {
        node* tmp = head;
        while(tmp != NULL)
        {
            cout<<tmp->n<<" ";
            tmp = tmp->next;
        }
    }
    bool checkexist(int k)
    {
        node* tmp = head;
        while(tmp != NULL)
        {
            if(tmp->n == k)
                return true;
            tmp = tmp->next;
        }
        return false;
    }
    void tangdan()
    {
        for(node* i = head; i != NULL; i = i->next)
        {
            for(node* j = i->next; j != NULL; j = j->next)
            {
                if(i->n > j->n)
                {
                    int tmp = i->n;
                    i->n = j->n;
                    j->n = tmp;
                }
            }
        }
    }
    int getMin()
    {
        if(head == NULL)
            return 0;
        int Min = head->n;
        node* tmp = head->next;
        while(tmp != NULL)
        {
            if(tmp->n < Min)
                Min = tmp->n;
            tmp = tmp->next;
        }
        return Min;
    }
    void createl3(dslk& l1, dslk& l2)
    {
        node* tmp = l1.head;
        while(tmp != NULL)
        {
            if(l2.checkexist(tmp->n)==true && checkexist(tmp->n)==false)
                addtail(tmp->n);
            tmp = tmp->next;
        }
        tangdan();
    }
    void createl4(dslk& l1, dslk& l2)
    {
        node* bestStart = NULL;
        int maxLen = 0;
        for(node* i = l1.head; i != NULL; i = i->next)
        {
            for(node* j = l2.head; j != NULL; j = j->next)
            {
                node* tmp1 = i;
                node* tmp2 = j;
                int curLen = 0;
                while(tmp1 != NULL && tmp2 != NULL && tmp1->n == tmp2->n)
                {
                    curLen++;
                    tmp1 = tmp1->next;
                    tmp2 = tmp2->next;
                }
                if(curLen > maxLen)
                {
                    maxLen = curLen;
                    bestStart = i;
                }
            }
        }
        if(bestStart != NULL)
        {
            for(int i=0; i<maxLen; ++i)
            {
                addtail(bestStart->n);
                bestStart = bestStart->next;
            }
        }
    }
    void createl5(dslk& l1, dslk& l2)
    {
        if(l2.head == NULL)
            return;
        int Min = l2.getMin();
        node* tmp = l1.head;
        while(tmp != NULL)
        {
            if(tmp->n != Min)
                addtail(tmp->n);
            tmp = tmp->next;
        }
    }
    friend istream& operator >> (istream& in, dslk& l)
    {
        int k;
        while(in>>k)
        {
            l.addtail(k);
            char next = in.get();
            if(next == '\n')
                break;
        }
        return in;
    }
    friend ostream& operator << (ostream& out, dslk& l)
    {
        l.out();
        return out;
    }
};

int main()
{
    dslk l1, l2, l3, l4, l5;
    cin>>l1>>l2;
    l3.createl3(l1, l2);
    cout<<l3<<"\n";
    l4.createl4(l1, l2);
    cout<<l4<<"\n";
    l5.createl5(l1, l2);
    cout<<l5;
    return 0;
}
