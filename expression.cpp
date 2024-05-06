/**
 * Title:		Lab 03 - infix_to_postfix.cpp
 * Purpose:		Converts a math function as how people read it (infix) to a
 *              statement that computers understand to calculate (postfix).
 * Author:		Tracy Mai
 * Date:		May 05, 2024
 */

#include "expression.h"
#include <iomanip>
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

Expression::Expression(): _infix(""), _postfix("") {
}

Expression::Expression(const string& infix): _infix(infix), _postfix("") {


}

void Expression::ConvertToPostfix() {
    stack<char> convert;
    char symbol;

    for (size_t i = 0; i < _infix.length(); ++i) {

        symbol = _infix.at(i);

        if (isdigit(symbol) || isalpha(symbol)) {
            _postfix.push_back(symbol);

            if (i + 1 == _infix.length() ||
                (i + 1 < _infix.length() && (!isdigit(_infix.at(i+1)) && (!isalpha(_infix.at(i+1)))))) {
                _postfix.push_back(' ');
            }


        } else if (symbol == '(') {
            convert.push(symbol);

        } else if (symbol == ')') {

            // does not count for uneven parenthesis, so might gotta write in
            while (!convert.empty() && convert.top() != '(') {
                _postfix.push_back(convert.top());
                _postfix.push_back(' ');
                convert.pop();
            }
            convert.pop();

        } else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {

            if (convert.empty()) {
                convert.push(symbol);
            } else {
                while (!convert.empty() && convert.top() != '(') {
                    if (symbol == '+' || symbol == '-') {
                        _postfix.push_back(convert.top());
                        _postfix.push_back(' ');
                        convert.pop();
                    } else {
                        if (convert.top() == '*' || convert.top() == '/') {
                            _postfix.push_back(convert.top());
                            _postfix.push_back(' ');
                            convert.pop();
                        } else {
                            break;
                        }
                    }
                }
                convert.push(symbol);
            }

        }

    }

    while (!convert.empty()) {
        _postfix.push_back(convert.top());
        _postfix.push_back(' ');
        convert.pop();
    }

    _postfix = trim(_postfix);

}

string Expression::GetInfix()const {
    return _infix;
}

string Expression::GetPostfix()const {
    return _postfix;
}


string Expression::ToJSON()const {

    stringstream myJSON;

    myJSON << "{\"infix\":\"" << _infix;
    myJSON << "\", \"postfix\":\"" << _postfix << "\"}";
  //  std::cout << myJSON.str() <<std::endl;
    return myJSON.str();
}
double Expression::Evaluate(bool& error)const {
    return 0;
}

string trim(const string& str, const string& whitespace){
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == string::npos)
        return ""; // no content
    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;
    return str.substr(strBegin, strRange);
}


