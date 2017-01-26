#include "iostream"
#include <stdlib.h>
using namespace std;

/*
   wrap a complicated subsystem with an object 
   that provides a simple interface
*/

/* required interface */
class UserInterface{
public:
    virtual void set_option(string) = 0;
    virtual void drive() = 0;
};

/* subsystems */
class Subsystem_One{
public:
    void handle_A(){ cout << "Subsystem one starts to handle A" << endl; }
};

class Subsystem_Two{
public:
    void handle_B(){ cout << "Subsystem two starts to handle B" << endl; }
};

class Subsystem_Three{
public:
    void handle_C(){ cout << "Subsystem three starts to handle C" << endl; }
};

/* Facade */
class FullSystem: public UserInterface{
private:
    Subsystem_One one;
    Subsystem_Two two;
    Subsystem_Three three;
    string option;

public:
    FullSystem(){ option = "basic"; }
    void set_option(string input_option){
        if( !input_option.empty() ){
            option = "full";
        }
    }
    void drive(){
        if( !option.compare("full") ){ drive_with_full(); }
        else{ drive_with_basic(); }
    }
    void drive_with_basic(){
        one.handle_A();
        two.handle_B();
    }
    void drive_with_full(){
        one.handle_A();
        two.handle_B();
        three.handle_C();
    }
};

int main(int argc, char** argv){
    string option;
    if(argc > 1){ option = argv[1]; }

    FullSystem my_system;
    my_system.set_option(option);
    my_system.drive();
    return 0;
}

