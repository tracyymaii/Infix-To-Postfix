/**
 * Title:		Lab 03 - infix_to_postfix.cpp
 * Purpose:		Converts a math function as how people read it (infix) to a
 *              statement that computers understand to evaluate it (postfix).
 * Author:		Tracy Mai
 * Date:		May 05, 2024
 */

#include "expression.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using std::stack;
using std::string;
using std::stringstream;

/**
 * Got this from: https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * W A R N I N G        W A R N I N G        W A R N I N G        W A R N I N G    * *
 * Even when I am giving you code that I found on the Internet, you are still      * *
 * not allowed to copy ANY code from the Internet or from any AI tool.             * *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @param str the string that we want to trim from trailing and leading spaces
 * @param whitespace the whitespaces we want to remove, by default it will remove space and tab
 * @return a string without leading or trailing spaces.
 */

/**
 * Expression Constructor
 * Sets both the infix and postfix to empty strings if there is no equation
 * given to the infix
 * @param none
 * @return none
 */
Expression::Expression(): _infix(""), _postfix("") {
}

/**
 * Expression Constructor
 * Sets the infix to the equation given and the postfix to an empty string
 * @param the equation to put into _infix
 * @return none
 */
Expression::Expression(const string& infix): _infix(infix), _postfix("") {
}

/**
 * Convert to Postfix
 * Turns the infix equation to the the postfix that the computer will understand.
 * Details will be outlined in the function.
 * Cases to think about that are addressed in the function:
 *  - Numbers with multiple digits
 *  - Spaces in equations
 *  - Words in equations
 * @param none
 * @return none
 */
void Expression::ConvertToPostfix() {
    stack<char> convert;
    char symbol;


    for (size_t i = 0; i < _infix.length(); ++i) {

        symbol = _infix.at(i);

        if (isdigit(symbol) || isalpha(symbol)) {
            _postfix.push_back(symbol);

            /**
             * Appends a space to the string following the alphanumeric only when
             * there is no alphanumerical after it or it is the last alphanumeric.
             * Does this check to make sure that multi-digit numbers or words stay
             * together.
             */
            if (i + 1 == _infix.length() ||
                (i + 1 < _infix.length() && (!isdigit(_infix.at(i+1)) && (!isalpha(_infix.at(i+1)))))) {
                _postfix.push_back(' ');
            }


        } else if (symbol == '(') {
            convert.push(symbol);

        } else if (symbol == ')') {


            while (!convert.empty() && convert.top() != '(') {
                _postfix.push_back(convert.top());
                _postfix.push_back(' ');
                convert.pop();
            }
            convert.pop();

        /**
         * Symbol handeling whilst poping and pushing off and on of stack and
         * appending to the string.
         */
        } else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {

            if (convert.empty()) {
                convert.push(symbol);
            } else {

                /**
                 * Handles operator precedence
                 */
                while (!convert.empty() && convert.top() != '(') {

                    /**
                     * If the symbol is a + or -, then everything in the stack
                     * will have greater or equal operator precedence and get popped
                     * off the stack and appended to the string.
                     */
                    if (symbol == '+' || symbol == '-') {
                        _postfix.push_back(convert.top());
                        _postfix.push_back(' ');
                        convert.pop();

                    /**
                     * If the symbol is a * or /, then the top of the stack can
                     * only be popped if it is also a * or /.
                     */
                    } else if (convert.top() == '*' || convert.top() == '/') {
                        _postfix.push_back(convert.top());
                        _postfix.push_back(' ');
                        convert.pop();
                    } else {
                        break;
                    }

                }

                /**
                 * Pushes on the current symbol after popping the top of
                 * the stack if the if statements passed.
                 */
                convert.push(symbol);
            }
        }
    }

    /**
     * Pops any symbols still in the stack off and appends it to the string.
     */
    while (!convert.empty()) {
        _postfix.push_back(convert.top());
        _postfix.push_back(' ');
        convert.pop();
    }

    _postfix = trim(_postfix);
}

/**
 * Get Infix
 * @param none
 * @return the string _infix
 */
string Expression::GetInfix()const {
    return _infix;
}

/**
 * Get PostFix
 * @param none
 * @return the string _postfix
 */
string Expression::GetPostfix()const {
    return _postfix;
}

/**
 * To JSON
 * Puts the infix and postfix information in the required JSON format
 * @param none
 * @return the string of the infix and postfix information
 */
string Expression::ToJSON()const {

    stringstream myJSON;

    myJSON << "{\"infix\":\"" << _infix;
    myJSON << "\", \"postfix\":\"" << _postfix << "\"}";

    return myJSON.str();
}

/**
 * Evaluate
 * Evaluates the answer the actual equation, and sets the boolean to true
 * if it is able to.
 * @param error boolean where it is true or false if the function was able to
 * evaluate
 * @return the answer to the expression as a double
 */
double Expression::Evaluate(bool& error)const {
    return 0;
}

/**
 * Trim
 * Searches through the string given, and gets ride of any whitespace at the
 * beginning and at the end of the string.
 * @param str, the string to be cleaned up
 * @param whitespace, the whitespace that is searched for if it exists.
 * @return the string now trimmed
 */
string trim(const string& str, const string& whitespace){
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == string::npos)
        return ""; // no content
    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;
    return str.substr(strBegin, strRange);
}


