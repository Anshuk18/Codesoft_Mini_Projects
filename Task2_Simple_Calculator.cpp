#include<iostream>
using namespace std;

int main(){
    float a, b;
    cout <<"----------WELCOME TO THE CPP BASIC CALCULATOR----------" << endl;
    cout <<endl;
    //Asking User for the value of Operand 'a'
    cout <<"Enter the value of a: ";
    cin >> a;
    //Asking User for an Operation to Perform
    char var;
    cout <<"Select an Opration That You Want To Perform(ADDITION(+) / SUBTRACTION(-) / DIVISION(/) / MULTIPLICATION(*) / MOD(%)) : ";
    cin >> var;
    //Asking User for the value of Operand 'b'
    cout <<"Enter the value of b: ";
    cin >> b;

    switch(var){
        case '+': cout <<a <<" + "<<b<<" = "<< (a + b) <<endl;
        break;
        case '-': cout <<a <<" - "<<b<<" = "<< (a - b) <<endl;
        break;
        case '/': 
        if(b == 0){
            cout<<"Error! Division by ZERO not allowed."<<endl;
        }
        else{
            cout <<a <<" / "<<b<<" = "<< (a / b) <<endl;
        }
        break;
        case '*': cout <<a <<" * "<<b<<" = "<< (a * b) <<endl;
        break;
        case '%': 
        if(static_cast<int>(a) == a && static_cast <int>(b) == b){
            if(b == 0){
                cout <<"Error! Division by ZERO is not allowed." <<endl;
            }
            else{
                cout <<a <<" % "<<b<<" = "<< (static_cast<int>(a) % static_cast<int>(b)) <<endl;
            }
        }
        else{
            cout <<"Error! Modulus operation is only applicable for integers." <<endl;
        }
        break;

        default : cout <<"Error! You have entered an Invalid Operation." << endl;
        break;
    }
    return 0;
}