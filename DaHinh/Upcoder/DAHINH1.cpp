#include <iostream>
using namespace std;

class HH
{
public:
    virtual int getCV() = 0;  
};

class HCN: public HH
{
    int dai, rong;
public:
    HCN (int _dai = 2, int _rong = 1) 
    {
        dai = _dai; 
        rong = _rong;
    }
    HCN (const HCN &h) 
    {
        dai = h.dai; 
        rong = h.rong;
    }
    friend istream& operator >> (istream &in, HCN &h)
    {
        return in>>h.dai>>h.rong;
    }
    int getCV() 
    {
        return (dai+rong)*2;
    }
};

class HV: public HCN
{
    int canh;
public:
    HV (int c = 1):HCN(c,c) 
    {
        canh = c;
    }
    HV (const HV &h):HCN(h) 
    {
        canh = h.canh;
    }
    friend istream& operator >> (istream &in, HV &h)
    {
        int c;
        cin>>c;
        h = HV(c);
        return in;
    }
};

int main()
{
    char c; 
    int n = 0;
    HH *p[10];
    int a, b;
    while (cin>>c)
    {
        if (c=='a')
        {
            cin>>a;
            p[n] = new HV(a);
            n++;
        }
        else
        {
            cin>>a>>b;
            p[n] = new HCN(a,b);
            n++;
        }
    }
    for (int i=0; i<n; ++i) 
    {
        cout<<p[i]-> getCV()<<endl;
    }
    return 0;
}
