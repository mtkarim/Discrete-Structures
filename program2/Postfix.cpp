
#include<iostream>
#include<stack>
#include<string>

using namespace std;

// Function to evaluate Postfix expression and return output
double EvaluatePostfix(string expression);
// Function to evaluate Prefix expression and return output
double EvaluatePrefix(string expression);

// Function to perform an operation and return output.
double PerformOperation(char operation, double operand1, double operand2);

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C);

// Function to verify whether a character is numeric digit.
bool IsNumericDigit(char C);

int main()
{
    string expression;
    double result;
   
    
    while (!getline(cin,expression).eof()) {
        
        
        if (IsOperator(expression[0]))
        {
            result = EvaluatePrefix(expression);
            cout<<"Output = "<<result<<"\n";
        }
        else
        {
            result = EvaluatePostfix(expression);
            cout<<"Output = "<<result<<"\n";
        }
        
    }
    
    
}
double EvaluatePostfix(string expression)
{
    // Declaring a Stack from Standard template library in C++.
    stack<double> S;
    
    for(double i = 0;i< expression.length();i++) {
        
        // Scanning each character from left.
        // If character is a delimitter, move on.
        if(expression[i] == ' ' || expression[i] == ',') continue;
        
        // If character is operator, pop two elements from stack, perform operation and push the result back.
        else if(IsOperator(expression[i])) {
            // Pop two operands.
            double operand2 = S.top(); S.pop();
            double operand1 = S.top(); S.pop();
            // Perform operation
            double result = PerformOperation(expression[i], operand1, operand2);
            //Push back result of operation on stack.
            S.push(result);
        }
        else if(IsNumericDigit(expression[i])){
            // Extract the numeric operand from the string
            // Keep incrementing i as long as you are getting a numeric digit.
            double operand = 0;
            while(i<expression.length() && IsNumericDigit(expression[i])) {
                // For a number with more than one digits, as we are scanning from left to right.
                // Everytime , we get a digit towards right, we can multiply current total in operand by 10
                // and add the new digit.
                operand = (operand*10) + (expression[i] - '0');
                i++;
            }
            // Finally, you will come out of while loop with i set to a non-numeric character or end of string
            // decrement i because it will be incremented in increment section of loop once again.
            // We do not want to skip the non-numeric character by incrementing i twice.
            i--;
            
            // Push operand on stack.
            S.push(operand);
        }
    }
    // If expression is in correct format, Stack will finally have one element. This will be the output.
    return S.top();
}

// Function to evaluate Postfix expression and return output
double EvaluatePrefix(string expression)
{
    // Declaring a Stack from Standard template library in C++.
    stack<double> S;
    
    for(double i = expression.length();i>= 0;i--) {
        
        // Scanning each character from left.
        // If character is a delimitter, move on.
        if(expression[i] == ' ' || expression[i] == ',') continue;
        
        // If character is operator, pop two elements from stack, perform operation and push the result back.
        else if(IsOperator(expression[i])) {
            // Pop two operands.
            double operand1 = S.top(); S.pop();
            double operand2 = S.top(); S.pop();
           
            // Perform operation
            double result = PerformOperation(expression[i], operand1, operand2);
            //Push back result of operation on stack.
            S.push(result);
        }
        else if(IsNumericDigit(expression[i])){
            // Extract the numeric operand from the string
            // Keep incrementing i as long as you are getting a numeric digit.
            double operand = 0;
            while(i>=0 && IsNumericDigit(expression[i])) {
                // For a number with more than one digits, as we are scanning from left to right.
                // Everytime , we get a digit towards right, we can multiply current total in operand by 10
                // and add the new digit.
                operand = (operand*10) + (expression[i] - '0');
                i--;
            }
            // Finally, you will come out of while loop with i set to a non-numeric character or end of string
            // decrement i because it will be incremented in increment section of loop once again.
            // We do not want to skip the non-numeric character by incrementing i twice.
            i++;
            
            // Push operand on stack.
            S.push(operand);
        }
    }
    // If expression is in correct format, Stack will finally have one element. This will be the output.
    return S.top();
}

// Function to verify whether a character is numeric digit.
bool IsNumericDigit(char C)
{
    if(C >= '0' && C <= '9') return true;
    return false;
}

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/')
        return true;
    
    return false;
}

// Function to perform an operation and return output.
double PerformOperation(char operation, double operand1, double operand2)
{
    if(operation == '+') return operand1 +operand2;
    else if(operation == '-') return operand1 - operand2;
    else if(operation == '*') return operand1 * operand2;
    else if(operation == '/') return operand1 / operand2;
    
    else cout<<"Unexpected Error \n";
    return -1; 
}
