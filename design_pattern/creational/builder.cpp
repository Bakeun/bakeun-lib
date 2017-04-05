#include "iostream"
#include <stdlib.h>
#include <string.h>
using namespace std;

/*
   the “reader” delegates to its configured “builder”
   each builder corresponds to a different representation or target
*/

class CookingPot{
private:
    int water_amount;
    string main_material;
    string spice;

public:
    void set_water_amount(int mili_litter){ 
        this->water_amount = mili_litter; 
    }
    void set_main_metirial(string matirial){
        this->main_material = matirial;
    }
    void set_spice(string spice){
        this->spice = spice;
    }
    string open_lid(){
        if(
            !main_material.compare("potato")
            && !spice.compare("salt")
        ){
            return "potato suop";
        }else if(
            !main_material.compare("fish")
            && !spice.compare("red_pepper")
        ){
            return "spicy soup";
        }else{
            return "odd soup";
        }
    }
};

class Cooker{
public:
    virtual void pour_water() = 0;
    virtual void put_metirial_on_pot() = 0;
    virtual void sprinkle_spice() = 0;
    virtual CookingPot* hand_pot_to_customer() = 0;
};

class KoreanCooker: public Cooker{
private:
    class CookingPot* pot;

public:
    KoreanCooker()
    { this->pot = new CookingPot(); }
    void pour_water()
    { this->pot->set_water_amount(500); }
    void put_metirial_on_pot()
    { this->pot->set_main_metirial("fish"); }
    void sprinkle_spice()
    { this->pot->set_spice("red_pepper"); }
    class CookingPot* hand_pot_to_customer(){
        cout << "음식 나왔습니다 손님~!" <<endl;
        return this->pot;
    }
};

class AmericanCooker: public Cooker{
private:
    class CookingPot* pot;

public:
    AmericanCooker()
    { this->pot = new CookingPot(); }
    void pour_water()
    { this->pot->set_water_amount(100); }
    void put_metirial_on_pot()
    { this->pot->set_main_metirial("potato"); }
    void sprinkle_spice()
    { this->pot->set_spice("salt"); }
    class CookingPot* hand_pot_to_customer(){
        cout << "Here your dish, sir!" <<endl;
        return this->pot;
    }
};

class OddCooker: public Cooker{
private:
    class CookingPot* pot;

public:
    OddCooker()
    { this->pot = new CookingPot(); }
    void pour_water()
    { this->pot->set_water_amount(1000); }
    void put_metirial_on_pot()
    { this->pot->set_main_metirial("ham"); }
    void sprinkle_spice()
    { this->pot->set_spice("unkown"); }
    class CookingPot* hand_pot_to_customer(){
        cout << "hire yu fuud~!@#!@" <<endl;
        return this->pot;
    }
};

class Chef
{
private:
    class Cooker* assistant;

public:
    Chef(string food_style){
        if(!food_style.compare("Korean"))
        { assistant = new KoreanCooker(); }
        else if(!food_style.compare("American"))
        { assistant = new AmericanCooker(); }
        else
        { assistant = new OddCooker(); }
    }
    void make_food(){
        assistant->pour_water();
        assistant->put_metirial_on_pot();
        assistant->sprinkle_spice();
    }
    class Cooker* send_assistant_to_customer(){
        return this->assistant;
    }
};

int main(int argc, char** argv)
{
    cout << "select which you like to eat" << endl;
    cout << "1)Korean Food, 2)American Food, 3)Anything" << endl;
    int choice;
    cin >> choice;

    string food;
    Chef* my_chef;
    if( choice == 1){
        my_chef = new Chef("Korean");
    }
    else if( choice == 2 ){
        my_chef = new Chef("American");
    }
    else{
        my_chef = new Chef("Anything");
    }
    my_chef->make_food();
    Cooker* food_carrier = my_chef->send_assistant_to_customer();
    CookingPot* receipt = food_carrier->hand_pot_to_customer();
    food = receipt->open_lid();
    cout << "You received " << food << endl;
    return 1;
}



