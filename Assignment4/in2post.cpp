#include <iostream>
#include <string>
#include "tlist.h"
#include "stack.h"
using namespace std;
using namespace cop4530;
#include <sstream>


int precedence(char input) {                                // returns the precedence of operator
    if (input == '*' || input == '/')
        return 0;
    if (input == '+' || input == '-')
        return 1;
    
}

template <typename T>
T operate(const string& operation, T a, T b) {              // returns the operation done on a and b
    if (operation == "+")
        return a + b;
    if (operation == "-")
        return b - a;
    if (operation == "*")
        return a * b;
    if (operation == "/")
        return b / a;
}

bool isOperator(const string& s){                           // returns true if s is an operator
    if (s == "+" || s == "*" || s == "-" || s == "/" || s == "(" || s == ")")
        return true;
    else
        return false;
}

void compute(const string& output, int type){               // computes the postfix equation
    Stack<string> stack;
    istringstream pass3(output);                            // object class of istringstream
    cout << "Results: ";
    for (string s; pass3 >> s; ) {                          // loops through all of output
        if (!isOperator(s))                                 // checks for operators
            stack.push(s);                                  // pushes to stack if not an operator
        else {
            if (type == 0) {                                // type 0 for int
                auto a = stoi(stack.top());                 // sets a to int
                stack.pop();                                // pops a from stack
                auto b = stoi(stack.top());                 // sets b to int
                stack.pop();                                // pops b from stack
                stack.push(to_string(operate(s, a, b))); 		// computes operation
            }
            else {                                          // type 1 for float
                auto a = stof(stack.top());                 // sets a to int
                stack.pop();                                // pops a from stack
                auto b = stof(stack.top());                 // sets b to int
                stack.pop();                                // pops b from stack
                stack.push(to_string(operate(s, a, b))); 		// computes operation
            }
        }
    }
    cout << stack.top() << endl;                            // prints the top, now containing the results
}
int canEvaluate(const string& output){
    istringstream pass2(output);                                            // object class of istringstream
    for (char i : output) {                                                 // loops through output
        if (int(i) > 64) {                                                  // breaks if variable is found
            cout << "Can not compute, equation has variables" << endl;
            return 0;                                                       // variables mean unsolvable, set type to 0
        }
    }
    istringstream pass4(output);                                            // object class of istringstream
    for (char i : output){
        if (i == '.') {                                                     // sets type to 1 if data is of float type
            return 1;
        }
        else
            return 2;                                                       // sets type to 2 if data is int type
    }
}

string makePostfix(const string& input, string output, Stack<string> operators){
    istringstream pass1(input);                                             // Object class of istringstream
    for (string s; pass1 >> s; ) {                                          // travel string looking for char seperated by spaces
        if (!isOperator(s))                                                 // checks if char is not operator
            output.append(s + " ");                         		            // appends s to output string if it's not an operator
        else {
            if (s == "(")                                                   // checks if char is open parenthesis
                operators.push(s);                                          // pushes it to the stack
            else if (s == ")") {                                            // checks if char is closing parenthesis
                while (!operators.empty() && operators.top() != "(") {      // looks until stack is empty, or opening parenthesis is found
                    output.append(operators.top() + " ");       		        // appends top element to output
                    operators.pop();                                        // pops top value from operator
                }
                if (operators.empty()) {                                    // checks stack is empty
                    cout << "Unbalanced parenthesis" << endl;
                    return "unbalanced";                                    // sets output to unbalanced for error checking
                }
                operators.pop();                                            // pops the last opening parenthesis
            }
            else if (operators.empty() || precedence(s[0]) < precedence(operators.top()[0]))  // pushes operator to stack if the precedence is lower than the top
                operators.push(s);
            else {
                while (!operators.empty()) {                        		        	// loops until operators is empty
                    if (precedence(s[0]) >= precedence(operators.top()[0])) { 		// appends to output if precedence is higher than the top
                        output.append(operators.top() + " ");
                        operators.pop();
                    }
                    else
                        break;                                              			// breaks otherwise
                }
                operators.push(s);                                          			// pushes the operator
            }
        }
    }

    while (!operators.empty()) {                                            			// loops until stack is empty
        if (operators.top() == "(") {                                       			// checks if there are any unclosed parenthesis
            cout << "Unbalanced parenthesis" << endl;
            return "unbalanced";                                            			// sets output to unbalanced for error checking
        }
        output.append(operators.top() + " ");                           					// appends remaining operators to output
        operators.pop();
    }
    return output;
}

void inToPost() {
    while (true) {                                                              	// infinite loop unless broken out of
        start:                                                                  	// label to return to start of loop to reset for errors
        string input;                                                           	// string for input
        string output;                                                          	// string for output
        Stack<string> operators;                                                	// stack used for operators
        cout << "Please enter an expression. Enter Quit to stop program." << endl;
        getline(cin, input);                                             					// gets input
        if (input == "Quit" || input == "quit")                                 	// checks input for loop for exit conditions
            return;

        cout << "Infix notation: " << input << endl;                            	// prints the input string
        output = makePostfix(input, output, operators);														// converts infix to postfix
        if (output == "unbalanced")																								// if output is unbalanced a missing paranthesis was found
            goto start;																														// returns to start label
        cout << "Postfix notation: " << output << endl;

        int type = canEvaluate(output);                                         	// checks if input can be evaluated and if it is int or float
        if (type == 0)                                                          	// if type is 0 a variable was found
            goto start;                                                         	// returns to start label
        compute(output, type);																										// computes the postfix equation
    }
}


int main() {
    inToPost();
    return 0;
}
