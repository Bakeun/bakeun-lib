#include "iostream"
#include <stdlib.h>
using namespace std;

/* 
    Decorator contains a single base Component, 
    which could be a derived ConcreteComponent 
    or another derived Decorator
*/

class Decoration
{
public:
    virtual ~Decoration(){ };
    virtual void adapt_decoration() = 0;
};

class Human:public Decoration
{
private:
    string name;
public:
    Human(string name){ this->name = name; }
    ~Human(){ cout << "bye bye~!" << endl; }
    void adapt_decoration(){ cout << name << ": Let's prepare to go out~" << endl; }
};

class Wearable:public Decoration
{
private:
    Decoration* deco;
public:
    ~Wearable(){ delete deco; }
    Wearable(Decoration* deco){ this->deco = deco; }
    void adapt_decoration(){ this->deco->adapt_decoration(); }
};

class Hat:public Wearable
{
public:
    ~Hat(){ cout << "delete hat" << endl; }
    Hat(Decoration* deco):Wearable(deco){ }
    void adapt_decoration(){
        Wearable::adapt_decoration();
        cout << "    ------    " << endl;
        cout << "   |      |   " << endl;
        cout << " ------------ " << endl;
    }
};

class Bare:public Wearable
{
public:
    ~Bare(){ cout << "delete bare" << endl; }
    Bare(Decoration* deco):Wearable(deco){ }
    void adapt_decoration(){
        Wearable::adapt_decoration();
        cout << "              " << endl;
        cout << "   --------   " << endl;
        cout << "  |        |  " << endl;
    }
};

class Smile:public Wearable
{
public:
    ~Smile(){ cout << "delete smile" << endl; }
    Smile(Decoration* deco):Wearable(deco){ }
    void adapt_decoration(){
        Wearable::adapt_decoration();
        cout << "  |  ^  ^  |  " << endl;
        cout << "   |  ..  |   " << endl;
        cout << "    ------    " << endl;
    }
};

class Curt:public Wearable
{
public:
    ~Curt(){ cout << "delete curt" << endl; }
    Curt(Decoration* deco):Wearable(deco){ }
    void adapt_decoration(){
        Wearable::adapt_decoration();
        cout << "  |  -  -  |  " << endl;
        cout << "   |  ..  |   " << endl;
        cout << "    ------    " << endl;
    }
};

int main(int argc, char** argv)
{
    Decoration* Bakeun = new Smile(new Hat(new Human("Bakeun")));
    Decoration* Jun = new Curt(new Bare(new Human("Junny")));
    Decoration* Beom = new Smile(new Bare(new Human("Beomy")));
    Decoration* Hyeon = new Curt(new Hat(new Human("Hyeon")));

    Bakeun->adapt_decoration();
    cout << "Let's go home~" << endl;
    delete Bakeun;
    cout << endl;

    Jun->adapt_decoration();
    cout << "I go home.." << endl;
    delete Jun;
    cout << endl;

    Beom->adapt_decoration();
    cout << "Let's go home~" << endl;
    delete Beom;
    cout << endl;

    Hyeon->adapt_decoration();
    cout << "I go home.." << endl;
    delete Hyeon;
    cout << endl;

    return 0;
}

/* result
Bakeun: Let's prepare to go out~
    ------
   |      |
 ------------
  |  ^  ^  |
   |  ..  |
    ------
Let's go home~
delete smile
delete hat
bye bye~!

Junny: Let's prepare to go out~

   --------
  |        |
  |  -  -  |
   |  ..  |
    ------
I go home..
delete curt
delete bare
bye bye~!

Beomy: Let's prepare to go out~

   --------
  |        |
  |  ^  ^  |
   |  ..  |
    ------
Let's go home~
delete smile
delete bare
bye bye~!

Hyeon: Let's prepare to go out~
    ------
   |      |
 ------------
  |  -  -  |
   |  ..  |
    ------
I go home..
delete curt
delete hat
bye bye~!

*/

