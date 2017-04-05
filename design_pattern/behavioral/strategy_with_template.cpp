#include "iostream"
#include <stdlib.h>
using namespace std;

/*
   define algorithm interface in a base class 
   and implementations in derived classes
*/

template<class ALGORITHM>
class MyCalc{
private:
    ALGORITHM operation;
public:
    int operate(int a, int b){
        return operation.calculate(a, b);
    }
};

class Addition
{
public:
    int calculate(int a, int b){
        cout << "Addition operation is selected" << endl;
        cout << "operand a=" << a << ", ";
        cout << "operand b=" << b << endl;
        return a+b; 
    }
};

class Multiply
{
public:
    int calculate(int a, int b){ 
        cout << "Multiply operation is selected" << endl;
        cout << "operand a=" << a << ", ";
        cout << "operand b=" << b << endl;
        return a*b; 
    }
};

class Power
{
private:
    int calc_power(int a, int b){
        int temp = 1;
        for(int i = 0; i < b; i++){
            temp *= a;
        }
        return temp;
    }
public:
    int calculate(int a, int b){
        cout << "Power operation is selected" << endl;
        cout << "operand a=" << a << ", ";
        cout << "operand b=" << b << endl;
        return calc_power(a,b);
    }
};


int main(int argc, char** argv)
{
    int condition;
    int result;
    srand(time(0));
    condition = rand()%3;
    if(condition == 0){
        MyCalc<Addition> my_calc;
        result = my_calc.operate(5,4);
    }
    else if(condition == 1){
        MyCalc<Multiply> my_calc;
        result = my_calc.operate(5,4);
    }
    else if(condition == 2){
        MyCalc<Power> my_calc;
        result = my_calc.operate(5,4);
    }
    cout << "operation result: " << result << endl;
    return 0;
}

