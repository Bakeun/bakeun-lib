#include "iostream"
#include <stdlib.h>
using namespace std;

/*
    define “linked list” functionality in the base class 
    and implement “domain” functionality in derived classes
*/

class ChainHandler
{
private:
    class ChainHandler* next;
    string subject;
public:
    ChainHandler(){
        subject = "";
    }
    ChainHandler(string subject){
        this->subject = subject;
    }
    void add(ChainHandler* newcomer){
        if(next == 0){ next = newcomer; }
        else{ next->add(newcomer); }
        return;
    }
    void print(){
        if(subject == ""){
            cout << "It does not handle anything." << endl;
        }
        else{
            cout << "It handles " << subject << "!" << endl;
        }

        if(next != 0){
            next->print();
        }

        return;
    }
};

int main(int argc, char** argv)
{
    ChainHandler* my_handler = new ChainHandler();
    my_handler->add(new ChainHandler("first thing"));
    my_handler->add(new ChainHandler("second thing"));
    my_handler->add(new ChainHandler("third thing"));
    my_handler->add(new ChainHandler("forth thing"));

    my_handler->print();
    return 0;
}

/* result
It does not handle anything.
It handles first thing!
It handles second thing!
It handles third thing!
It handles forth thing!

*/
