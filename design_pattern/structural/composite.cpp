#include "iostream"
#include <stdlib.h>
using namespace std;

/*
   derived Composites contain one or more base Components,
   each of which could be a derived Composite
*/

class Snack
{
public:
    virtual void open() = 0;
    virtual string get_name() = 0;
};

class Piece:public Snack
{
private:
    string name;
    string flavor;
    string padding;
public:
    Piece(){
        this->name = "Unknown Thing";
        this->flavor = "not good";
    }
    Piece(string name){
        this->name = name;
        this->flavor = "not good";
    }
    Piece(string name, string flavor){
        this->name = name;
        this->flavor = flavor;
    }
    string get_name(){ return name; };
    void open(){
        cout << "   It's " << flavor << endl;
    }
};

class Package:public Snack
{
private:
    string name;
    Snack** box;
    int index;
    int maximum;
    void make_box(){
        maximum = 5;
        box = new Snack*[maximum];
        index = 0;
    }
public:
    Package(){
        this->name = "Unknown Box";
        make_box();
    }
    Package(string name){
        this->name = name;
        make_box();
    }
    ~Package(){
        delete [] box;
    }
    string get_name(){ return name; }
    void pack(Snack* input){
        if(index >= maximum){
            cout << "There is no room in box" << endl;
            return;
        }
        box[index++] = input;
    }
    void open(){
        cout << "The " << name << " is package. ";
        cout << "What this " << name << " include?" << endl;
        for(int cur = 0; cur < maximum; cur++){
            if(box[cur] == 0){ break; }
            Snack* current_item = box[cur];
            cout << "  The " << current_item->get_name() << " is contained in " << name << endl;
            current_item->open();
        }
        return;
    }
};

int main(int argc, char** argv){
    Piece* choco_pie = new Piece("ChocoPie","sweet");
    Piece* ace = new Piece("Ace","a little salty");
    Piece* potato_chip = new Piece("PotatoChip","good");
    Piece* my_goomy = new Piece("MyGoomy","chewy");
    Piece* unknown_piece = new Piece();

    Package* happy_box = new Package("Happy Box");
    Package* unknown_box = new Package();

    unknown_box->pack(my_goomy);
    unknown_box->pack(unknown_piece);

    happy_box->pack(choco_pie);
    happy_box->pack(ace);
    happy_box->pack(unknown_box);
    happy_box->pack(potato_chip);

    cout << "I'm presented with " << happy_box->get_name() << endl;
    cout << "Let's open the gift" << endl;
    happy_box->open();

    return 0;
}

/* result
I'm presented with Happy Box
Let's open the gift
The Happy Box is package. What this Happy Box include?
  The ChocoPie is contained in Happy Box
     It's sweet
  The Ace is contained in Happy Box
     It's a little salty
  The Unknown Box is contained in Happy Box
The Unknown Box is package. What this Unknown Box include?
  The MyGoomy is contained in Unknown Box
    It's chewy
  The Unknown Thing is contained in Unknown Box
    It's not good
  The PotatoChip is contained in Happy Box
    It's good
*/
