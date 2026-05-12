#include<iostream>
using namespace std;
class calculator{
    public:
    float add(float a,float b){
    return a+b;
    }
    float subtract(float a,float b){
    return a-b;
     }
     float multiply(float a,float b){
    return a*b;
    }
    float divide(float a,float b){
    if(b!=0)
    return a/b;
    else{
        cout<<"error! division by zero\n";
        return 0;
     }
    }
};
int main(){
    calculator calc;
    float num1,num2;
    char operation;
    char choice;

    do{
        cout<<"\n=======calculator menu========\n";
        cout<<"+:Addition\n";
        cout<<"-:Subtraction\n";
        cout<<"*:Multiplication\n";
        cout<<"/:Division\n";

        cout<<"\n Enter first number:";
        cin>>num1;

        cout<<"Enter operator:";
        cin>> operation;

        cout<<"Enter second number:";
        cin>> num2;

        switch (operation)
        {
        case '+':
            cout<<"result="<< calc.add(num1,num2);
        break;
        
        case '-':
            cout<<"result="<< calc.subtract(num1,num2);
        break;

        case '*':
            cout<<"result="<< calc.multiply(num1,num2);
        break;

        case '/':
            cout<<"result="<< calc.divide(num1,num2);
        break;

        default:
        cout<< "invalid operator!";
            break;
        }
        cout<<"\n do you want to continue?(y/n)";
        cin>>choice;
    }while(choice=='y'||choice=='Y');
    return 0;
};

