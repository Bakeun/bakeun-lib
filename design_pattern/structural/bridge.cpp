#include "iostream"
#include <stdlib.h>
using namespace std;

/*
   the wrapper models “abstraction” and 
   the wrappee models many possible “implementations” … 
   the wrapper can use inheritance to support abstraction specialization
*/

class Item
{
public:
    virtual void use() = 0;
    virtual string get_name() = 0;
};

class RedPotion:public Item
{
public:
    void use(){
        cout << "Pyo Ro Rong~~" << endl;
        cout << "Your HP is restored!!" << endl;
    }
    string get_name(){ return "red potion"; }
};

class BluePotion:public Item
{
public:
    void use(){
        cout << "Ti Ri Ring!!" << endl;
        cout << "Your MP is restored~" << endl;
    }
    string get_name(){ return "blue potion"; }
};

class User
{
public:
    virtual void use_item() = 0;
    virtual void root_item(Item*) = 0;
    virtual void drop_item() = 0;
};

class Player:public User
{
private:
    Item* possessed;
    string name;
public:
    Player(){
        this->name = "Bakeun";
    }
    Player(string name){
        this->name = name;
    }
    string get_name(){ return this->name; }
    void use_item(){
        cout << name << " use";
        if(possessed != 0){
            cout << " " << possessed->get_name() << endl;
            possessed->use();
            possessed = 0;
        }else{
            cout << "..." << endl;
            cout << "There is no items..." << endl;
        }
    }
    void root_item(Item* gotten){
        if(possessed != 0){
            cout << name << " already has a item." << endl;
        }else{
            cout << name << " gets a " << gotten->get_name() << endl;
            possessed = gotten;
        }
    }
    void drop_item(){
        if(possessed != 0){
            cout << name << " drop the " << possessed->get_name() << endl;
            possessed = 0;
        }
    }
};

int main(int argc, char** argv)
{
    Item* rp = new RedPotion();
    Item* bp = new BluePotion();
    Player* bakeun = new Player("Bakeun");
    string player_name = bakeun->get_name();
    cout << "I'm " << player_name << endl;
    bakeun->root_item(rp);
    bakeun->root_item(bp);
    bakeun->use_item();
    bakeun->root_item(bp);
    bakeun->drop_item();
    bakeun->use_item();
    return 1;
}

/* Result

I'm Bakeun
Bakeun gets a red potion
Bakeun already has a item.
Bakeun use red potion
Pyo Ro Rong~~
Your HP is restored!!
Bakeun gets a blue potion
Bakeun drop the blue potion
Bakeun use...
There is no items...

*/
