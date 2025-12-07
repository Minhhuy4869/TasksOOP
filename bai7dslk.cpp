#include <iostream>
#include <cmath>
using namespace std;

class node
{
    friend class dathuc;
    float heso;
    int somu;
    node* next;
public:
    node(float hs, int sm)
    {
        heso = hs;
        somu = sm;
        next = NULL;
    }
};

class dathuc
{
    node* head;
    node* tail;
public:
    dathuc()
    {
        head = tail = NULL;
    }
    void addTern(float hs, int sm)
    {
        if(hs == 0)
            return;
        // TH1. Da thuc rong
        if(head == NULL)
        {
            head = tail = new node(hs, sm);
            return;
        }
        // TH2. So mu lon hon head => chen dau 
        if(sm > head->somu)
        {
            node* p = new node(hs, sm);
            p->next = head;
            head = p;
            return;
        }
        // TH3. Tim vi tri thich hop
        node* cur = head;
        node* pre = NULL;
        while(cur != NULL && cur->somu > sm)
        {
            pre = cur;
            cur = cur->next;
        }
        // Neu trung so mu => cong don
        if(cur != NULL && cur->somu == sm)
        {
            cur->heso += hs;
            if(cur->heso == 0)
            {
                if(pre == NULL)
                    head = cur->next;
                else
                    pre->next = cur->next;
                if(cur == tail)
                    tail = pre;
                delete cur;
            }
        }
        //Neu khong trung => chen vao giua pre voi cur
        else
        {
            node* p = new node(hs, sm);
            if(pre != NULL)
                pre->next = p;
            p->next = cur;
            if(cur == NULL)
                tail = p;
        }
    }
    friend istream& operator >> (istream& in, dathuc& dt)
    {
        float hs; 
        int sm;
        while(in>>hs>>sm)
        {
            dt.addTern(hs, sm);
            char next = in.get();
            while(next == ' ')
                next = in.get();
            if(next == '\n')
                break;
            in.putback(next);
        }
        return in;
    }
    void out()
    {
        if(head == NULL)
        {
            cout<<"0";
            return;
        }
        node* tmp = head;
        bool first = true;
        while(tmp != NULL)
        {
            float hs = tmp->heso;
            int sm = tmp->somu;
            if(first == true)
            {
                if(hs < 0)
                    cout<<"-";
            }
            else
            {
                if(hs > 0)
                    cout<<"+";
                else
                    cout<<"-";
            }
            if(sm == 0)
                cout<<abs(hs);
            else
            {
                if(abs(hs) != 1)
                    cout<<abs(hs);  // chi in he so neu khac 1
                cout<<"x";
                if(sm != 1)
                    cout<<"^"<<sm;   // chi in so mu neu khac 1
            }
            first = false;
            tmp = tmp->next;
        }
    }
    friend ostream& operator << (ostream& out, dathuc& dt)
    {
        dt.out();
        return out;
    }
    dathuc cong(dathuc& p)
    {
        dathuc res;
        node* tmp = head;
        while(tmp != NULL)
        {
            res.addTern(tmp->heso, tmp->somu);
            tmp = tmp->next;
        }
        tmp = p.head;
        while(tmp != NULL)
        {
            res.addTern(tmp->heso, tmp->somu);
            tmp = tmp->next;
        }
        return res;
    }
    dathuc daoham()
    {
        dathuc res;
        
        node* tmp = head; 
        while(tmp != NULL)
        {
            if(tmp->somu != 0)
                res.addTern(tmp->heso * tmp->somu, tmp->somu - 1);
            tmp = tmp->next;
        }
        return res;
    }
    float tinhgiatri(float x)
    {
        float sum = 0;
        node* tmp = head;
        while(tmp != NULL)
        {
            sum += tmp->heso * pow(x, tmp->somu);
            tmp = tmp->next;
        }
        return sum;
    }
};

int main()
{
    dathuc f1, f2;
    cin>>f1>>f2;
    float x;
    cin>>x;
    cout<<f1<<" "<<f2<<"\n";
    dathuc f3 = f1.cong(f2);
    dathuc daohamf3 = f3.daoham();
    cout<<daohamf3<<"\n";
    cout<<f3.tinhgiatri(x)<<"\n";
    cout<<f3;
    return 0;
}
