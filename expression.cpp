// Remember to add the header comments, and comments for each
// of the functions and methods you implement
#include "expression.h"

#include <stack>
using std::stack;

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
string trim(const string& str, const string& whitespace){
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == string::npos)
        return ""; // no content
    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;
    return str.substr(strBegin, strRange);
}


