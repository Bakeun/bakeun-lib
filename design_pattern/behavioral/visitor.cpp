#include "iostream"
#include <stdlib.h>
#include <unistd.h>
using namespace std;

/*
   define "accept" method in first inheritance hierarchy,
   define "visit" methods in second hierarchy 
   a.k.a. "double dispatch"    
*/

class Villa
{
public:
    virtual int accept(class VillageVisitor*) = 0;
};

class VillageVisitor
{
public:
    virtual int knock(class AhnHouse*) = 0;
    virtual int knock(class BakHouse*) = 0;
    virtual int knock(class ChaHouse*) = 0;
};

class AhnHouse:public Villa
{
public:
    int accept(VillageVisitor* visitor){
        return visitor->knock(this);
    }
};

class BakHouse:public Villa
{
public:
    int accept(VillageVisitor* visitor){
        return visitor->knock(this);
    }
};

class ChaHouse:public Villa
{
public:
    int accept(VillageVisitor* visitor){
        return visitor->knock(this);
    }
};

class MrBak:public VillageVisitor
{
public:
    int knock(AhnHouse* target){
        cout << "Who are you?" << endl;
        return -1;
    }
    int knock(BakHouse* target){
        cout << "Welcome home~" << endl;
        return 0;
    }
    int knock(ChaHouse* target){
        cout << "Get out!" << endl;
        return -1;
    }
};

class MsKim:public VillageVisitor
{
public:
    int knock(AhnHouse* target){
        cout << "I'm not your honey.. You're wrong place!" << endl;
        return -1;
    }
    int knock(BakHouse* target){
        cout << "Welcome honey~. I miss you S2" << endl;
        return 0;
    }
    int knock(ChaHouse* target){
        cout << "...(No Return)" << endl;
        return -1;
    }
};

int select_villa(int villas)
{
    return rand()%villas;
}

int main(int argc, char** argv)
{
    Villa* villas[] = {    new AhnHouse, new BakHouse, new ChaHouse };
    int rtn;
    int seed;
    srand(time(0));

    MrBak Geuny;
    cout << "Mr. Bak goes his home." << endl;
    rtn = -1; seed=select_villa(3);
    while(rtn != 0){
        sleep(1);
        Villa* selected_villa = villas[seed];
        cout << "Knock Knock~! Anybody there?.. | ";
        rtn = selected_villa->accept(&Geuny);
        seed=select_villa(3);
    }
    cout << "Mr. Bak have found his home!" << endl;

    cout << endl;

    MsKim Jinny;
    cout << "Ms. Kim goes boyfriend's home." << endl;
    rtn = -1; seed=select_villa(3);
    while(rtn != 0){
        sleep(1);
        cout << "Knock Knock~! Heney, It's me~ | ";
        Villa* selected_villa = villas[seed];
        rtn = selected_villa->accept(&Jinny);
        seed=select_villa(3);
    }
    cout << "Ms. Kim have found her boyfriend's home~" << endl;

    return 0;
}


