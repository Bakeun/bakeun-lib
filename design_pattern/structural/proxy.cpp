#include "iostream"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

/*
   Proxy wrap an object with a surrogate object 
   that provides additional functionality
*/

class Interface{
public:
    virtual int do_with_count() = 0;
    virtual int do_with_auth(string)  = 0;
    virtual int do_with_auto()  = 0;
};


class RealObj:public Interface{
private:
    string name;
public:
    RealObj(){
        name = "RealObj";
    }
    RealObj(string input){
        name = input;
    }
    int do_with_count(){
        cout << name << ":do_with_count" << endl;
        return 1;
    }
    int do_with_auth(string guest){
        cout << name << ":do_with_authorization" << endl;
        return 1;
    }
    int do_with_auto(){
        cout << name << ":do_with_automation" << endl;
        return 1;
    }
};

class Proxy:public Interface{
private:
    RealObj* real;
    int count;
    int max_authors;
    string* author;
    void init_proxy(){
        count = 0;
        max_authors = 2;
        author = new string[max_authors];
        author[0] = "bakeun";
        author[1] = "yoojiny";
    }
    int is_accessible(string guest){
        for(int i=0; i<max_authors; i++){
            if(!guest.compare(author[i]))
            { return 1; }
        }
        return 0;
    }
public:
    Proxy(){
        real = new RealObj;
        this->init_proxy();
    }
    Proxy(RealObj* target){
        real = target;
        this->init_proxy();
    }
    ~Proxy(){
        delete[] author;
    }

    int do_with_count(){
        count++;
        cout << "call count: " << count << endl;
        real->do_with_count();
        return 1;
    }
    int do_with_auth(string guest){
        if(is_accessible(guest)){ 
            cout << "Welcome, " << guest << endl;
            real->do_with_auth(guest); 
        }
        else
        { cout << guest << " is not accessable!!" << endl; }
        return 1;
    }
    int do_with_auto(){
        if(!access("./proxy_auto", 0)){
            cout << "There is proxy_auto file. "
                 << "Then remove the file" << endl;
            remove("./proxy_auto");
        }
        else{
            cout << "There is no proxy_auto file. "
                 << "Then create the file" << endl;
            creat("./proxy_auto", 644);
        }
        cout << "do_with_automation" << endl;
        return 1;
    }
};

int main(int argc, char** argv){
    RealObj* my_obj = new RealObj("my_obj");
    Proxy my_proxy(my_obj);

    for(int i=0; i<5; i++){
        my_proxy.do_with_count();
    }

    my_proxy.do_with_auth("yoojiny");
    my_proxy.do_with_auth("doduknom");

    my_proxy.do_with_auto();

    return 0;
};
