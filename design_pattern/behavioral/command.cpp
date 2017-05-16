#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*
    encapsulate an object, the method to be invoked,
    and the parameters to be passed behind the method signature "execute"
*/

class Command{
public:
    virtual void execute() = 0;
};

class Throwing:public Command{
private:
    string what;
    string how;
    int number_of_throwing;
    void _make_what_composite_or_not(){
        if(this->number_of_throwing > 1){
            this->what = this->what + "s(es)";
        }
        return;
    }
public:
    Throwing(string what, int number_of_throwing, string how){
        this->what = what;
        this->how  = how;
        this->number_of_throwing = number_of_throwing;
        _make_what_composite_or_not();
    };
    Throwing(string what, int number_of_throwing){
        this->what = what;
        this->number_of_throwing = number_of_throwing;
        this->how  = "as it is";
        _make_what_composite_or_not();
    };
    Throwing(string what){
        this->what = what;
        this->number_of_throwing = 1;
        this->how  = "as it is";
    };
    void execute(){
        cout << "Throw "
             << this->number_of_throwing << " "
             << this->what << " "
             << this->how
             << endl;
        return;
    }
};

class Receiving:public Command{
private:
    string what;
    string how;
    int number_of_receiving;
    void _make_what_composite_or_not(){
        if(this->number_of_receiving > 1){
            this->what = this->what + "s(es)";
        }
        return;
    }
public:
    Receiving(string what, int number_of_receiving, string how){
        this->what = what;
        this->how  = how;
        this->number_of_receiving = number_of_receiving;
        _make_what_composite_or_not();
    };
    Receiving(string what, int number_of_receiving){
        this->what = what;
        this->number_of_receiving = number_of_receiving;
        this->how  = "as it is";
        _make_what_composite_or_not();
    };
    Receiving(string what){
        this->what = what;
        this->number_of_receiving = 1;
        this->how  = "as it is";
    };
    void execute(){
        cout << "Recieve "
             << this->number_of_receiving << " "
             << this->what << " "
             << this->how
             << endl;
        return;
    };
};

int main(int argc, char** argv)
{
    queue<Command*> cmd_queue;
    cmd_queue.push(new Throwing("Ice",3, "softly"));
    cmd_queue.push(new Receiving("Ice",2,"using right hand"));
    cmd_queue.push(new Receiving("Ice",1,"using left hand"));
    cmd_queue.push(new Throwing("Stone",2));
    cmd_queue.push(new Receiving("Stone",2,"easily~"));
    cmd_queue.push(new Throwing("Sand",100,"U Ha Ha Ha!!!"));
    cmd_queue.push(new Receiving("Sand",0,"\b...\nYou bastard!"));

    for(
        Command* cmd_interator = cmd_queue.front();
        !cmd_queue.empty();
        cmd_queue.pop(), cmd_interator = cmd_queue.front()
    ){
        cmd_interator->execute();
        delete cmd_interator;
    }

    return 0;
}

/* result
Throw 3 Ices(es) softly
Recieve 2 Ices(es) using right hand
Recieve 1 Ice using left hand
Throw 2 Stones(es) as it is
Recieve 2 Stones(es) easily~
Throw 100 Sands(es) U Ha Ha Ha!!!
Recieve 0 Sand...

*/
