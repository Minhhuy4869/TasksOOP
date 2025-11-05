#include <iostream>
#include <cmath>
using namespace std;
const float pi = 3.1415;

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
    float DT()
    {
        return dai*rong;
    }
};

class HT
{
    float canh, goc;
public:
    HT (float _canh = 0, float _goc = 0)
    {
        canh = _canh;
        goc = _goc;
    }
    HT (HT &h)
    {
        canh = h.canh;
        goc = h.goc;
    }
    void Set (float _canh = 0, float _goc = 0)
    {
        canh = _canh;
        goc = _goc;
    }
    float DT()
    {
        return canh*canh*sin(goc*pi/180);
    }
};

// lop con
class HV : public HCN, public HT
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
        HCN::Set(canh, canh); 
        HT::Set(canh, 90);
    }
    HV (const HV &h)
    {
        canh = h.canh;
        HCN::Set(canh, canh);
        HT::Set(canh, 90);
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
        HCN::Set(canh, canh);
        HT::Set(canh, 90);
    }
    /*
    float dt()
    {
        return canh*canh;
    }
    */
};
// Khởi tạo: Cha -> Con
// Hủy: Con -> Cha
int main()
{
    HV hv(4);
    cout<<hv.HCN::DT(); // Kế thừa bội phải chỉ rõ lớp cần kế thừa 
    return 0;
}
