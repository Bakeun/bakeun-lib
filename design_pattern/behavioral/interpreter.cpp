#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;

/*
   map a domain to a language, 
   the language to a recursive grammar,
   and the grammar to the Composite pattern
*/


class Operand
{
public:
    virtual int interpret() = 0;
};

class Expression:public Operand
{
private:
    char m_operator;
    Operand* left;
    Operand* right;
public:
    Expression( char op ){ m_operator = op; }
    Expression( Operand* left, Operand* right ){
        this->left  = left;
        this->right = right;
    }
    Expression( char op, Operand* left, Operand* right ){
        m_operator = op;
        this->left  = left;
        this->right = right;
    }
    int interpret(){
        if(m_operator == '+'){
            return left->interpret() + right->interpret();
        }
        if(m_operator == '-'){
            return left->interpret() - right->interpret();
        }
        else{ return 0; }
    }
};

class Number:public Operand
{
private:
    int value;
public:
    Number(int value){ this->value = value; }
    Number(string value){ this->value = std::stoi(value); }
    int interpret(){
        return value;
    }
};


class Parser
{
private:
    string opers;
    string* parsed_expr;
    int parsed_index;
    int parse_maximum;
    bool is_operation(string token){
        return !(opers.find_first_of(token));
    };
public:
    Parser(){
        parse_maximum = 10;
        parsed_index = 0;
        opers = "+-";
        parsed_expr = new string[parse_maximum];
    };
    ~Parser(){
        delete [] parsed_expr;
    }

    int operate(string expr){
        cout << "make_split_expr: " << expr << endl;
        int op_position = expr.find_first_of("+|-");
        char oper = expr[op_position];
        Number* left = new Number(expr.substr(0,op_position));
        
        string right_str = expr.substr(op_position+1);
        int right_int;
        Operand* right;
        if(right_str.find_first_of("+|-") != -1){
            right_int = operate(right_str);
        }

        if(right_str.find_first_of("+|-") != -1){
            right = new Number(right_int);
        }else{
            right = new Number(right_str);
        }

        Expression* result = new Expression(oper, left, right);
        
        return result->interpret();
    }
};


int main(int argc, char** argv){
    Parser my_parse;
    cout << my_parse.operate("12+3+5-2") << endl;
    return 1;
}
