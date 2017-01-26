#include "iostream"
#include <stdlib.h>
using namespace std;

/*
   Adapter is about creating an intermediary abstraction 
   that translates, or maps, the old component to the new system
*/

class MyAdaptee{
public:
    void do_something(int ten_volt){
        cout << "The output voltage is " << ten_volt << endl;
    }
};

class Interface{
public:
    virtual void do_something_with_adaptee(int) = 0;
};

class MyAdapter:public Interface{
private:
    MyAdaptee worker;

public:
    void do_something_with_adaptee(int thirty_volt){
        worker.do_something(thirty_volt/3);
    }
};


int main(int argc, char** argv)
{
    int input_volt = 30;
    if(argc > 1){ input_volt = atoi(argv[1]); }

    MyAdapter my_adapter;
    my_adapter.do_something_with_adaptee(input_volt);
    return 1;
}

