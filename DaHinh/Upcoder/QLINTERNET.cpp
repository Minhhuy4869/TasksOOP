#include <iostream>
#include <string>
using namespace std;

//KH lop truu tuong
class KH
{
    string tenkh;
    int tgsd;
    int somay;
    int dongia;
public:
    string getTenKH() 
    {
        return tenkh;
    }
    int getTgsd() 
    {
        return tgsd;
    }
    int getSomay() 
    {
        return somay;
    }
    int getDongia() 
    {
        return dongia;
    }
    KH (string _tenkh = "Huy", int _tgsd = 1, int _somay = 1, int _dongia = 1)
    {
        tenkh = _tenkh; 
        tgsd = _tgsd; 
        somay = _somay; 
        dongia = _dongia;
    }
    KH (const KH &k)
    {
        tenkh = k.tenkh; 
        tgsd = k.tgsd; 
        somay = k.somay; 
        dongia = k.dongia;
    }
    virtual string getLoai() = 0; // ham thuan ao
    virtual double getTinh() = 0; // ham thuan ao
    void print()
    {
        cout<<". Loai khach: "<<getLoai()<<endl;
        cout<<"Ho Ten: "<<tenkh<<endl;
        cout<<"Thoi gian su dung: "<<tgsd<<endl;
        cout<<"So may: "<<somay<<endl;
        cout<<"So tien phai tra: "<<getTinh()<<endl;
        cout<<endl;
    }
};
class KHVIP: public KH
{
    int dongiaVIP;
public:
    KHVIP (string _tenkh = "Huy", int _tgsd = 1, int _somay = 1, 
    int _dongia = 1, int _dongiaVIP = 0)
    :KH(_tenkh, _tgsd, _somay, _dongia)
    {
        dongiaVIP = _dongiaVIP;
    }
    KHVIP (const KHVIP &k):KH(k)
    {
        dongiaVIP = k.dongiaVIP;
    }
    string getLoai() 
    {
        return "VIP";
    }
    double getTinh() 
    {
        if(getTgsd() >= 4) 
            return dongiaVIP*4;
        return getDongia()*getTgsd();
    }
};

class KHTX: public KH
{
    int hesokm;
public:
    KHTX (string _tenkh = "Huy", int _tgsd = 1, int _somay = 1, 
    int _dongia = 1, int _hesokm = 0)
    :KH(_tenkh, _tgsd, _somay, _dongia)
    {
        hesokm = _hesokm;
    }
    KHTX (const KHTX &k):KH(k)
    {
        hesokm = k.hesokm;
    }
    string getLoai() 
    {
        return "TX";
    }
    double getTinh() 
    {
        return getTgsd()*getDongia() - getTgsd()*hesokm;
    }
};

class KHKTX: public KH
{
    int dungluongdl, dongiadl;
public:
    KHKTX(string _tenkh = "Huy", int _tgsd = 1, int _somay = 1, 
    int _dongia=1, int _dungluongdl=0, int _dongiadl=0)
    :KH(_tenkh, _tgsd, _somay, _dongia)
    {
        dungluongdl = _dungluongdl; dongiadl = _dongiadl;
    }
    KHKTX (const KHKTX &k):KH(k)
    {
        dungluongdl = k.dungluongdl; 
        dongiadl = k.dongiadl;
    }
    string getLoai() 
    {
        return "KTX";
    }
    double getTinh() 
    {
        return getTgsd()*getDongia() + dungluongdl*dongiadl;
    }
};

int main()
{
    KH *p[10];
    int n=0, dongia, dongiaVIP, dongiadl;
    cin>>n>>dongia>>dongiaVIP>>dongiadl;
    for(int i=0; i<n; ++i)
    {
        string s; 
        cin>>s;
        cin.ignore();
        string tenkh;
        int tgsd, somay;
        getline(cin, tenkh);
        cin>>tgsd>>somay;
        if(s=="VIP")
        {
            // KHVIP k = KHVIP(tenkh, tgsd, somay, dongia, dongiaVIP);
            // cout<<(i+1); k.print();
            // p[i] = &k;
            p[i]= new KHVIP(tenkh, tgsd, somay, dongia, dongiaVIP);
            //cout<<(i+1); p[i]-> print();
        }
        else if(s=="TX")
        {
            int hesokm; 
            cin>>hesokm;
            // KHTX k= KHTX(tenkh, tgsd, somay, dongia, hesokm);
            // cout<<(i+1); k.print();
            // p[i] = &k;
            p[i]= new KHTX(tenkh, tgsd, somay, dongia, hesokm);
            // cout<<(i+1); p[i]-> print();
        }
        else
        {
            int dungluongdl; 
            cin>>dungluongdl;
            //KHKTX k= KHKTX(tenkh, tgsd, somay, dongia, dungluongdl, dongiadl);
            //cout<<(i+1); k.print();
            //p[i] = &k;
            p[i]= new KHKTX(tenkh, tgsd, somay, dongia, dungluongdl, dongiadl);
            //cout<<(i+1); p[i]-> print();
        }
    }
    for (int i=0; i<n; ++i)
    {
        cout<<(i+1);
        p[i]-> print();
    }
    return 0;
}
