#include <iostream>
using namespace std;

// lop cha
class HCN 
{
    float dai, rong;
public:
    // get - set
    float getD()
    {
        return dai;
    }
    float getR()
    {
        return rong;
    }
    void setD (float value)
    {
        dai = value;
    }
    void setR (float value)
    {
        rong = value;
    }
    // constuctor
    HCN (float _dai=0, float _rong = 1)
    {
        dai = _dai;
        rong = _rong;
    }
    HCN (const HCN &h)
    {
        dai = h.dai;
        rong = h.rong;
    }
    ~HCN() {};
    // overloading
    friend istream& operator >> (istream &in, HCN &h)
    {
        in>>h.dai>>h.rong;
        return in;
    }
    friend ostream& operator << (ostream &out, HCN h)
    {
        out<<"Chieu dai HCN: "<<h.dai<<"\n";
        out<<"Chieu rong HCN: "<<h.rong;
        return out;
    }
    // ham ho tro
    void Set (float _dai = 0, float _rong = 0)
    {
        dai = _dai;
        rong = _rong;
    }
    float dt()
    {
        return dai*rong;
    }
};

// lop con
class HV : public HCN
{
    float canh;
public:
    // get - set
    float getC()
    {
        return canh;
    }
    void setC (float value)
    {
        canh = value;
    }
    // constuctor
    HV (float _canh=0)
    {
        canh = _canh;
        //HCN::Set(canh, canh); 
    }
    HV (const HV &h)
    {
        canh = h.canh;
        HCN::Set(canh, canh);
    }
    ~HV() {};
    // overloading
    friend istream& operator >> (istream &in, HV &h)
    {
        in>>h.canh;
        return in;
    }
    friend ostream& operator << (ostream &out, HV h)
    {
        out<<"Canh HV: "<<h.canh;
        return out;
    }
    // ham ho tro
    void Set (float _canh = 0)
    {
        canh = _canh;
        HCN::Set(canh, canh)
    }
    /*
    float dt()
    {
        return canh*canh;
    }
    */
};

int main()
{
    return 0;
}
