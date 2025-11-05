#include <bits/stdc++.h>
using namespace std;

class AdaptiveRobot;
class Robot
{
protected:
    string Name, UserName;
    int EnergyLevel,  LocationX, LocationY;
public:
    Robot()
    {
        Name = "Robot";
        UserName = "NoName";
        EnergyLevel = 100; 
        LocationX = 0;
        LocationY = 0;
    }
    Robot (string name, string username, int x, int y)
    {
        Name = name;
        UserName = username;
        EnergyLevel = 100;
        LocationX = x;
        LocationY = y;
        
    }
    Robot (string name, string username)
    {
        Name = name;
        UserName = username;
        EnergyLevel = 100;
        LocationX = 0;
        LocationY = 0;
    }
    Robot (string name, string username, int energy, int x, int y)
    {
        Name = name;
        UserName = username;
        EnergyLevel = energy;
        LocationX = x;
        LocationY = y;
    }
    Robot (const Robot &r)
    {
        Name = r.Name;
        UserName = r.UserName;
        EnergyLevel = r.EnergyLevel;
        LocationX = r.LocationX;
        LocationY = r.LocationY;
    }
    virtual ~Robot(){}
    void setEnergy(int e) 
    {
        EnergyLevel=e;
    }
    int getEnergy()
    {
        return EnergyLevel;
    }
    virtual void Charge()
    {
        EnergyLevel += 10;
        if (EnergyLevel>100) 
            EnergyLevel = 100;
    }
    virtual bool Move(int direc)
    {
        if (EnergyLevel<=0) 
            return false;
    if (direc<0 || direc>3) 
        return false;
    switch(direc)
    {
        case 0: LocationX-=1; break;
        case 1: LocationX+=1; break;
        case 2: LocationY+=1; break;
        case 3: LocationY-=1; break;
    }
        EnergyLevel -= 5;
        return true;
    }
    virtual void DisplayInfo()
    {
        cout<<"{"<<Name<<"}:{"<<UserName<<"}"<<endl;
        cout<<"("<<LocationX<<","<<LocationY<<")"<<endl;
        cout<<EnergyLevel<<endl;
    }
};

class AdaptiveRobot:public Robot
{
public:
    AdaptiveRobot():Robot()
    {
        Name = "AdaptiveRobot";
        UserName = "NoName";
        EnergyLevel = 100;
        LocationX = 0;
        LocationY = 0;
    }
    AdaptiveRobot (string name, string username, int energy, int x, int y)
    :Robot(name, username, energy, x, y){}
    AdaptiveRobot(const AdaptiveRobot& r):Robot(r){}
    bool Move(int direc) override
    {
        if (EnergyLevel<=0) 
            return false;
        if(direc<0 || direc>3) 
            return false;
        switch(direc)
        {
            case 0: LocationX -= 1; break;
            case 1: LocationX += 1; break;
            case 2: LocationY += 1; break;
            case 3: LocationY -= 1; break;
        }
        return true;
    }
};

int main()
{
    int n; 
    cin>>n;
    vector <Robot*> ds;
    string name, username, line;
    int energy,x,y;
    cin.ignore();
    for (int i=0; i<n; ++i)
    {
        getline(cin, name);
        getline(cin, username);
        cin>>energy>>x>>y;
        cin.ignore();
        Robot* r;
        if(name[0]=='A') 
            r = new AdaptiveRobot(name, username, energy, x, y);
        else 
            r = new Robot(name, username, energy, x, y);
        getline(cin, line);
        stringstream ss(line);
        int d;
        while (ss>>d)
        {
            if (d==-1) 
                break;
            if (d==4) 
                r->Charge();
            else if(name[0]!='A')
            {
                r->Move(d);
            }
            else if(r->getEnergy()>50)
            {
                r->Move(d);
                ss>>d; 
                if(!ss) 
                    break; 
                r->Move(d);
                ss>>d; 
                if(!ss) 
                    break; 
                r->Move(d);
                r->setEnergy(r->getEnergy()-12);
            }
            else if(r->getEnergy()>20)
            {
                r->Move(d);
                ss>>d; 
                if(!ss) 
                    break; 
                r->Move(d);
                r->setEnergy(r->getEnergy()-9);
            }
            else
            {
                r->Move(d);
                r->setEnergy(r->getEnergy()-6);
            }
        }
        ds.push_back(r);
    }
    for (Robot* r:ds)
    {
        r->DisplayInfo();
        delete r;
    }
    return 0;
}
