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
    void giamdan()
    {
        for(node* i = head; i != NULL; i = i->next)
        {
            for(node* j = i->next; j != NULL; j = j->next)
            {
                if(i->n < j->n)
                {
                    int tmp = i->n;
                    i->n = j->n;
                    j->n = tmp;
                }
            }
        }
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
    void giamtang()
    {
        if(size < 2)
            return;
        int mid = size/2;
        node* s1 = head; 
        node* e1 = head;
        for(int i=0; i<mid-1; ++i)
        {
            e1 = e1->next;
        }
        for(node* i = head; i != e1->next; i = i->next)
        {
            for(node* j = i->next; j != e1->next; j = j->next)
            {
                if(i->n < j->n)
                {
                    int tmp = i->n;
                    i->n = j->n;
                    j->n = tmp;
                }
            }
        }
        node* s2 = e1->next;
        node* e2 = e1->next;
        for(int i=0; i<mid-1; ++i)
        {
            e2 = e2->next;
        }
        for(node* i = s2; i != e2->next; i = i->next)
        {
            for(node* j = i->next; j != e2->next; j = j->next)
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
    void createl3(dslk& l1, dslk& l2)
    {
        node* tmp = l1.head;
        while(tmp != NULL)
        {
            if(checkexist(tmp->n)==false)
                addtail(tmp->n);
            tmp = tmp->next;
        }
        tmp = l2.head;
        while(tmp != NULL)
        {
            if(checkexist(tmp->n)==false)
                addtail(tmp->n);
            tmp = tmp->next;
        }
        giamdan();
    }
    void createl4(dslk& l1, dslk& l2)
    {
        node* tmp = l1.head;
        while(tmp != NULL)
        {
            if(l2.checkexist(tmp->n)==false)
                addtail(tmp->n);
            tmp = tmp->next;
        }
        giamtang();
    }
    void createl5(dslk& l1, dslk& l2)
    {
        node* tmp1 = l1.head;
        node* tmp2 = l2.head;
        while(tmp1 != NULL || tmp2 != NULL)
        {
            int val1 = (tmp1 != NULL) ? tmp1->n : 0;
            int val2 = (tmp2 != NULL) ? tmp2->n : 0;
            addtail(val1+val2);
            if(tmp1 != NULL)
                tmp1 = tmp1->next;
            if(tmp2 != NULL)
                tmp2 = tmp2->next;
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
