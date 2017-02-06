#include "iostream"
#include <stdlib.h>
using namespace std;

/*
   define algorithm interface in a base class 
   and implementations in derived classes
*/

template<class ALGORITHM, typename OPER_TYPE>
class MyCalc{
private:
    ALGORITHM operation;
public:
    OPER_TYPE operate(OPER_TYPE a, OPER_TYPE b){
        return operation.calculate(a, b);
    }
};

class Addition
{
public:
    int calculate(int a, int b){ return a+b; }
};

class Multiply
{
public:
    int calculate(int a, int b){ return a*b; }
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
        return calc_power(a,b);
    }
};


int main(int argc, char** argv)
{
    string algorithm = "Addition";
    if(argc > 1){ algorithm = argv[1]; }

    int result;
    if(!algorithm.compare("Addition")){
        MyCalc<Addition, int> my_calc;
        result = my_calc.operate(5,4);
    }
    else if(!algorithm.compare("Multiply")){
        MyCalc<Multiply, int> my_calc;
        result = my_calc.operate(5,4);
    }
    else if(!algorithm.compare("Power")){
        MyCalc<Power, int> my_calc;
        result = my_calc.operate(5,4);
    }
    else{
        cout << algorithm << " operation is not supported!" << endl;
        return -1;
    }
    cout << algorithm << " operation result: " << result << endl;
    return 0;
}

