#include "iostream"
#include <stdlib.h>
using namespace std;

/*
   the FiniteStateMachine delegates to the "current" state object, 
   and that state object can set the "next" state object
*/

class CoinThrow
{
private:
    class State* top_bottom;
public:
    CoinThrow();
    void set_state(State* s){
        top_bottom = s;
    }
    string throw_coin();
};

class State
{
public: 
    virtual string turn_out(CoinThrow*) = 0;
};

class TOP:public State
{
public: 
    string turn_out(CoinThrow* wrapper);
};

class BOTTOM:public State
{
public: 
    string turn_out(CoinThrow* wrapper);
};

CoinThrow::CoinThrow(){
    top_bottom = new TOP();
}

string CoinThrow::throw_coin(){
    srand(time(0));
    int turn_out_tries = rand()%100;
    string result;
    for(;turn_out_tries > 0;turn_out_tries--){
        result = top_bottom->turn_out(this);
    }
    return result;
}

string TOP::turn_out(CoinThrow* wrapper){
    wrapper->set_state(new BOTTOM());
    return "bottom";
}

string BOTTOM::turn_out(CoinThrow* wrapper){
    wrapper->set_state(new TOP());
    return "top";
}

int main(int argc, char** argv)
{
    CoinThrow my_cthrow;
    cout << "Throw a coin!!" << endl;
    cout << "The coin fall~" << endl;
    cout << "The upper side of the coin is " << my_cthrow.throw_coin() << endl;
    return 0;
}

