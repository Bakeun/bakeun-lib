#include "iostream"
#include <stdlib.h>
using namespace std;

/*
   define “createInstance” placeholder in the base class, 
   each derived class calls the “new” operator
   and returns an instance of itself
*/

class Mixer{
public:
    static Mixer* mix_fruits(int input);
    virtual string what_juice_i_am() = 0;
};

class AppleJuice:public Mixer{
public:
    string what_juice_i_am(){ return "Apple juice"; }
};

class TomatoJuice:public Mixer{
public:
    string what_juice_i_am(){ return "Tomato juice"; }
};

class PotatoJuice:public Mixer{
public:
    string what_juice_i_am(){ return "Potato juice"; }
};

class UncannyJuice:public Mixer{
public:
    string what_juice_i_am(){ return "Uncanny juice.."; }
};

Mixer* Mixer::mix_fruits(int input)
{
    if(input == 1)
    { return new AppleJuice; }
    else if(input == 2)
    { return new TomatoJuice; }
    else if(input == 3)
    { return new PotatoJuice; }
    else{ return new UncannyJuice; }
}

int main(int argc, char** argv)
{
    cout << "select fruit 1)Apple, 2)Tomato, 3)Potato\n";
    int choice;
    cin >> choice;

    Mixer* my_juice;
    my_juice = Mixer::mix_fruits(choice);
    cout << "TaDa~! Here is your " << my_juice->what_juice_i_am() << endl;
    return 1;
}


