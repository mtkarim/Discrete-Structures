//Mubasshir Karim
//chapter 11 program - #8 & #9

#include<iostream>
#include<stack>
#include<string>

using namespace std;

double CheckPost(string expression);
double CheckPre(string expression);
double Operation(char operation, double operand1, double operand2);
bool IsOperator(char C);
bool Numeric(char C);

int main(int argc, char* argv[])
{
    string expression;
    double result;
   
    
    while (!getline(cin,expression).eof())
    {
        
        
        if (IsOperator(expression[0]))
        {
            result = CheckPre(expression);
            cout<<"Output = "<<result<<"\n";
        }
        else
        {
            result = CheckPost(expression);
            cout<<"Output = "<<result<<"\n";
        }
        
    }
    
    
}
double CheckPost(string expression)
{

    stack<double> S;
    
    for(double i = 0;i< expression.length();i++)
    {
        
       
        if(expression[i] == ' ' || expression[i] == ',') continue;
        
        
        else if(IsOperator(expression[i]))
        {
            double operand1 = S.top(); S.pop();
            double operand2 = S.top(); S.pop();
            double result = Operation(expression[i], operand1, operand2);
            S.push(result);
        }
        
        else if(Numeric(expression[i]))
        {
            double operand = 0;
            
            while(i<expression.length() && Numeric(expression[i]))
            {
                operand = (operand*10) + (expression[i] - '0');
                i++;
            }
            
            i--;
            
            S.push(operand);
        }
    }
    return S.top();
}

double CheckPre(string expression)
{
    stack<double> S;
    
    for(double i = expression.length();i>= 0;i--)
    {
        
        if(expression[i] == ' ' || expression[i] == ',') continue;
        
        else if(IsOperator(expression[i]))
        {
            double operand1 = S.top(); S.pop();
            double operand2 = S.top(); S.pop();
            double result = Operation(expression[i], operand1, operand2);
            S.push(result);
        }
        else if(Numeric(expression[i]))
        {
            double operand = 0;
            while(i>=0 && Numeric(expression[i]))
            {
                operand = (operand*10) + (expression[i] - '0');
                i--;
            }
            
            i++;
            
            S.push(operand);
        }
    }
    return S.top();
}

bool Numeric(char C)
{
    if(C >= '0' && C <= '9') return true;
    return false;
}

bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/')
        return true;
    
    return false;
}

double Operation(char operation, double operand1, double operand2)
{
    if(operation == '+') return operand1 +operand2;
    else if(operation == '-') return operand1 - operand2;
    else if(operation == '*') return operand1 * operand2;
    else if(operation == '/') return operand1 / operand2;
    
    else cout<<"Unexpected Error \n";
    return -1; 
}
