#include <iostream>
#include <cmath>
using namespace std;

class TG
{
    float a, b, c;
public:
    // get - set
    float getA()
    {
        return a;
    }
    float getB()
    {
        return b;
    }
    float getC()
    {
        return c;
    }
    void setA(float value)
    {
        a = value;
    }
    void setB(float value)
    {
        b = value;
    }
    void setC(float value)
    {
        c = value;
    }
    // constructor
    TG (float _a = 1, float _b = 2, float _c = 3)
    {
        a = _a;
        b = _b;
        c = _c; 
    }
    TG (const TG &k)
    {
        a = k.a;
        b = k.b;
        c = k.c;
    }
    ~TG() {};
    // overloading
    friend istream& operator >> (istream &in, TG &k)
    {
        in>>k.a>>k.b>>k.c;
        return in;
    }
    friend ostream& operator << (ostream &out, TG k)
    {
        out<<k.a<<" "<<k.b<<" "<<k.c;
        return out;
    }
    // ham bo tro
    void Set (float _a = 1, float _b = 2, float _c = 3)
    {
        a = _a;
        b = _b;
        c = _c; 
    }
    float DT()
    {
        float p = (a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
};

class TGD : public TG
{
    float canh;
public:
    // get - set
    float getC()
    {
        return canh;
    }
    void setC(float value)
    {
        canh = value;
    }
    // constructor
    TGD (float _canh = 1)
    {
        canh = _canh;
        TG::Set(canh, canh, canh);
    }
    TGD (const TGD &k)
    {
        canh = k.canh;
        TG::Set(canh, canh, canh);
    }
    ~TGD() {};
    // overloading
    friend istream& operator >> (istream &in, TGD &k)
    {
        in>>k.canh;
        return in;
    }
    /*
    friend ostream& operator << (ostream &out, TG k)
    {
        out<<k.a<<" "<<k.b<<" "<<k.c;
        return out;
    }
    */
    // ham bo tro
    void Set (float _canh = 1)
    {
        canh = _canh;
        TG::Set(canh, canh, canh); 
    }
    /*
    float DT()
    {
        float p = (a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    */
};

int main()
{
    TG a;
    cin>>a;
    cout<<a.DT();
    return 0;
}
