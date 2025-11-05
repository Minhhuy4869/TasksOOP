#include <iostream>
#include <vector>
using namespace std;

// lop cha
class HCN
{
    int dai, rong;
public:
    // get - set
    int getD()
    {
        return dai;
    }
    int getR()
    {
        return rong;
    }
    void setD(int value)
    {
        dai = value;
    }
    void setR(int value)
    {
        rong = value;
    }
    // constructor
    HCN (int _dai = 1, int _rong = 2)
    {
        dai = _dai;
        rong = _rong;
    }
    HCN (const HCN &h)
    {
        dai = h.dai;
        rong = h.rong;
    }
    // overloading
    friend istream& operator >> (istream &in, HCN &h)
    {
        in>>h.dai>>h.rong;
        return in;
    }
    friend ostream& operator << (ostream &out, HCN h)
    {
        out<<h.dai<<" "<<h.rong;
        return out;
    }
    int CV()
    {
        return (dai+rong)*2;
    }
    void Set (int _dai = 1, int _rong = 2)
    {
        dai = _dai;
        rong = _rong;
    }
};

// lop con
class HV : public HCN
{
    int canh;
public:
    // get - set
    int getC()
    {
        return canh;
    }
    void setC(int value)
    {
        canh = value;
    }
    // constructor
    HV (int _canh = 1)
    {
        canh = _canh;
        HCN::Set(canh, canh);
    }
    HV (const HV &h)
    {
        canh = h.canh;
        HCN::Set(canh, canh);
    }
    // overloading
    friend istream& operator >> (istream &in, HV &h)
    {
        in>>h.canh;
        return in;
    }
    /* ham du thua
    int CV()
    {
        return canh*4;
    }
    */
    void Set (int _canh = 1)
    {
        canh = _canh;
        HCN::Set(canh, canh);
    }
};

int main()
{
    string s;
    cin>>s;
    if (s=="HCN")
    {
        HCN h;
        vector <HCN> v;
        while (cin>>h)
        {
            v.push_back(h);
        }
        int MaxHCN = v[0].CV();
        for (int i=1; i<v.size(); ++i)
        {
            if (MaxHCN<v[i].CV())
                MaxHCN = v[i].CV();
        }
        cout<<MaxHCN;
    }
    else
    {
        HV k;
        vector <HV> w;
        while (cin>>k)
        {
            w.push_back(k);
        }
        int MaxHV = w[0].CV();
        for (int i=1; i<w.size(); ++i)
        {
            if (MaxHV<w[i].CV())
            {
                MaxHV = w[i].CV();
            }
        }
        cout<<MaxHV;
    }
    return 0;
}
