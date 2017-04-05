#include "iostream"
#include <stdlib.h>
using namespace std;

/*
   the “model” broadcasts to many possible “views”, 
   and each “view” can dialog with the “model”
*/

class Observer
{
public:
    virtual void update(double) = 0;
};

class Subject
{
public:
    virtual void attach(Observer*) = 0;
    virtual void notify() = 0;
};

class Thermometer : public Subject
{
private:
    double temperature;
    int view_size;
    int new_index;
    Observer** viewers;
public:
    Thermometer(){
        temperature = 18.5;
        view_size = 5;
        new_index = 0;
        viewers = new Observer*[view_size];
    }
    ~Thermometer(){
        delete [] viewers;
    }
    void attach(Observer* obs){
        if(new_index >= view_size){ return; }
        viewers[new_index++] = obs;
    }
    void notify(){
        for(int i = 0; i < view_size; i++){
            Observer* each_viewer = viewers[i];
            if(each_viewer == 0){ continue; }
            each_viewer->update(temperature);
        }
    }
    void winter_season(){
        cout << "~~ It becomes winter ~~" << endl;
        temperature = -3;
        this->notify();
    }
    void autumn_season(){
        cout << "~~ It becomes autumn ~~" << endl;
        temperature = 6.3;
        this->notify();
    }
    void spring_season(){
        cout << "~~ It becomes spring ~~" << endl;
        temperature = 8.6;
        this->notify();
    }
    void summer_season(){
        cout << "~~ It becomes summer ~~" << endl;
        temperature = 26.1;
        this->notify();
    }
};

class Korean : public Observer
{
private:
    string name;
    double temper;
public:
    Korean(Subject* thermo){
        thermo->attach(this);
        this->name = "A korean";
    }
    Korean(Subject* thermo, string name){
        thermo->attach(this);
        this->name = name;
    }
    void update(double value){
        temper = value;
    }
    void view_thermo(){
        cout << name << ": Oh~! It's " << temper << " Celsius!" << endl;
    }
};

class English : public Observer
{
private:
    string name;
    double temper;
public:
    English(Subject* thermo){
        thermo->attach(this);
        this->name = "A english";
    }
    English(Subject* thermo, string name){
        thermo->attach(this);
        this->name = name;
    }
    void update(double value){
        temper = 1.8 * value + 32 ;
    }
    void view_thermo(){
        cout << name << ": AhHa, It's " << temper << " Fahrenheit." << endl;
    }
};

int main(int argc, char** argv)
{
    Thermometer* my_thermo = new Thermometer();
    Korean*  bakeun = new Korean(my_thermo, "Bakeun");
    English* frank = new English(my_thermo);

    my_thermo->notify();
    bakeun->view_thermo();
    frank->view_thermo();

    my_thermo->spring_season();
    bakeun->view_thermo();
    frank->view_thermo();

    my_thermo->summer_season();
    bakeun->view_thermo();
    frank->view_thermo();

    my_thermo->autumn_season();
    bakeun->view_thermo();
    frank->view_thermo();

    my_thermo->winter_season();
    bakeun->view_thermo();
    frank->view_thermo();

    return 0;
}

/*
Result

Bakeun: Oh~! It's 18.5 Celsius!
A english: AhHa, It's 65.3 Fahrenheit.
~~ It becomes spring ~~
Bakeun: Oh~! It's 8.6 Celsius!
A english: AhHa, It's 47.48 Fahrenheit.
~~ It becomes summer ~~
Bakeun: Oh~! It's 26.1 Celsius!
A english: AhHa, It's 78.98 Fahrenheit.
~~ It becomes autumn ~~
Bakeun: Oh~! It's 6.3 Celsius!
A english: AhHa, It's 43.34 Fahrenheit.
~~ It becomes winter ~~
Bakeun: Oh~! It's -3 Celsius!
A english: AhHa, It's 26.6 Fahrenheit.

*/
