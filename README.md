
# Infix to Postfix
Conversion of an arithmetic expression from infix notation to postfix notation.
Infix to Postfix conversion, from D.S. Malik, Exercise #10 Chapter 19

## Goal
In this lab. I practiced:
* Solving a problem given a general algorithm
* Further practice using classes
* **Use** the C++ STL class `stack`

The main idea for this lab is to create a class that will help the user to input an infix arithmetic operation and convert it to a postfix arithmetic operation.

## Infix and Postfix

Arithmetic expression are regularly written in infix notation. One might say that infix notation is the "human natural" notation. Here are some examples of expressions in infix notation:
* $2+3$ evaluates 5
* $2+5*2$ evaluates 12
* $(2+12)/(9-2)$ evaluates 2
* $A+((B+C)*(E-F)-G)/(H-I)$ does not evaluate as we don't know the values for those variables.

However, computers in general don't understand infix notation. The best way to process an arithmetic operation for a computer is using postfix notation. One is called infix because its operators are "in" and the other postfix because its operators are "post" or after the operands. The following table shows some infix expressions with their corresponding postfix equivalent.

|Infix| Postfix                         |
|-----|---------------------------------|
|$a+b+c$| $a b + c +$                     |
|$a+b*c$| $a b c * +$                     |
|$(a+b)/c$| $a b + c /$                     |
|$A+B*(C+D)-E/F*G+H$| $A B C D + * + E F / G * - H +$ |
|$125/5*3$| $125\  5\ /\ 3\ *$          |

For more information of postfix notation research is **strongly** suggested.

## General Algorithm
The rules to convert an infix expression into an equivalent postfix expression are as follows:

1. Set variables `postfix` and `infix` as strings that will contain a postfix and infix expression respectively.
2. Initialize `postfix` to empty string.
3. Create and initialize an empty stack.
4. Get the next symbol `sym` from `infix`
   1. If `sym` is an operand, append `sym` to `postfix`.
   2. If `sym` is `(`, push `sym` into the stack.
   3. If `sym` is `)`, pop and append all the symbols from the stack until the most recent left parentheses. Pop and discard the left parentheses.
   4. If `sym` is an operator:
      1. Pop and append all the operators from the stack to `postfix` that are above the most recent left parentheses and have precedence greater than or equal to `sym`.
      2. Push `sym` onto the stack.
5. After processing `infix`, some operators may be left in the stack. Pop and append to `postfix` everything from the stack.

## Additional Comments
In this program, I considered the following (binary) arithmetic operators: +, -, *, and /. I assume that the expressions I will process are error free.

Design a class `Expression` that stores the infix and postfix strings. The class must include the following methods:

* `GetInfix` returns a string holding the infix expression
* `GetPostfix` returns a string holding the postfix expression
* `ConvertToPostfix` it will convert the infix expression stored in the data member `_infix` and place the converted postfix expression in the data member `_postfix`.

Recommendations (Not required but possibly good ideas)
* Create a _function_ `Precedence` determines the precedence between two operators. If the first operator is of higher or equal precedence than the second operator, it returns `true`, it will return `false` otherwise.
* Create a _function_ `Next` that takes in a string and returns the next "thing" (operator, operand or parenthesis) from the string send as parameter.

## A Good Learning Opportunity
It will be of tremendous benefit if you study the provided `main.cpp`. You are not allowed to change its code, but it has many _goodies_, tips and tricks that may prove useful in the future.

## Assessment

You are given expressions like the following infix expressions as part of your tests. There are some hard-coded expressions and some will be held in a file. You will read each of these expressions and then output the postfix expressions. You will need to separate the symbols with space in your postfix expressions result. Do not assume that the infix expressions are separated by space. Below are six infix notation expressions.
```
A+B+C
A + B - C
(A + B) * C
(A+B)*(C-D)
A + ( ( B + C ) * ( E - F ) - G ) / ( H - I)
A + B * ( C + D ) - E / F * G + H
```

## How to run
This program needs to be run from the command line. Running from CLion may result a little cumbersome. Steps as follows, with different ways to run the program.

* First, you will need to compile the program using the make utility. This will compile each of the elements of the program (`main.cpp`, `expression.cpp`, `expression.h`) and produce an executable named `postfix`
  > `make`
* Once you have compiled the program without errors or warnings you can proceed to run it.
* The program takes in command line parameters
  > `./cmake-build-debug/postfix -flag -file [-v]`
* How does the flags work, here are examples for each of the options
  * If you want to run the program using the _hard-coded_ tests
    > `./cmake-build-debug/postfix -hard`
  * The previous example will only output for numbers. Those numbers stand for: number of conversion tests passed, number of `ToJSON` passed, number of extra credit passed, and total number of tests. Below it shows what you should get for this.
    > `10	10	0	10`
  * If you want a more detailed output you can run the command below. Note that this time the `-v` parameter has been included. This parameter turns on the _verbose_ mode.
    > `./cmake-build-debug/postfix -hard -v`
  * Below is the output of using the `-v` parameter:
    >
   ```
   TEST - 0
        Input:           a+b+c
        Your Output:     a b + c +
        Expected Output: a b + c +
        Your JSON:       {"infix":"a+b+c", "postfix":"a b + c +"}
        Expected JSON:   {"infix":"a+b+c", "postfix":"a b + c +"}
   TEST - 1
        Input:           a+b*c
        Your Output:     a b c * +
        Expected Output: a b c * +
        Your JSON:       {"infix":"a+b*c", "postfix":"a b c * +"}
        Expected JSON:   {"infix":"a+b*c", "postfix":"a b c * +"}
   TEST - 2
        Input:           (a+b)/c
        Your Output:     a b + c /
        Expected Output: a b + c /
        Your JSON:       {"infix":"(a+b)/c", "postfix":"a b + c /"}
        Expected JSON:   {"infix":"(a+b)/c", "postfix":"a b + c /"}
   TEST - 3
        Input:           (A+B)*(C-D)
        Your Output:     A B + C D - *
        Expected Output: A B + C D - *
        Your JSON:       {"infix":"(A+B)*(C-D)", "postfix":"A B + C D - *"}
        Expected JSON:   {"infix":"(A+B)*(C-D)", "postfix":"A B + C D - *"}
   TEST - 4
        Input:           A + ( ( B + C ) * ( E - F ) - G ) / ( H - I)
        Your Output:     A B C + E F - * G - H I - / +
        Expected Output: A B C + E F - * G - H I - / +
        Your JSON:       {"infix":"A + ( ( B + C ) * ( E - F ) - G ) / ( H - I)", "postfix":"A B C + E F - * G - H I - / +"}
        Expected JSON:   {"infix":"A + ( ( B + C ) * ( E - F ) - G ) / ( H - I)", "postfix":"A B C + E F - * G - H I - / +"}
   TEST - 5
        Input:           A+B*(C+D)-E/F*G+H
        Your Output:     A B C D + * + E F / G * - H +
        Expected Output: A B C D + * + E F / G * - H +
        Your JSON:       {"infix":"A+B*(C+D)-E/F*G+H", "postfix":"A B C D + * + E F / G * - H +"}
        Expected JSON:   {"infix":"A+B*(C+D)-E/F*G+H", "postfix":"A B C D + * + E F / G * - H +"}
   TEST - 6
        Input:           (1+2)*3
        Your Output:     1 2 + 3 *
        Expected Output: 1 2 + 3 *
        Your JSON:       {"infix":"(1+2)*3", "postfix":"1 2 + 3 *"}
        Expected JSON:   {"infix":"(1+2)*3", "postfix":"1 2 + 3 *"}
   TEST - 7
        Input:           4 + 3 - 2 * 5 / 1
        Your Output:     4 3 + 2 5 * 1 / -
        Expected Output: 4 3 + 2 5 * 1 / -
        Your JSON:       {"infix":"4 + 3 - 2 * 5 / 1", "postfix":"4 3 + 2 5 * 1 / -"}
        Expected JSON:   {"infix":"4 + 3 - 2 * 5 / 1", "postfix":"4 3 + 2 5 * 1 / -"}
   TEST - 8
        Input:           alpha * beta + gamma
        Your Output:     alpha beta * gamma +
        Expected Output: alpha beta * gamma +
        Your JSON:       {"infix":"alpha * beta + gamma", "postfix":"alpha beta * gamma +"}
        Expected JSON:   {"infix":"alpha * beta + gamma", "postfix":"alpha beta * gamma +"}
   TEST - 9
        Input:           125/5*3
        Your Output:     125 5 / 3 *
        Expected Output: 125 5 / 3 *
        Your JSON:       {"infix":"125/5*3", "postfix":"125 5 / 3 *"}
        Expected JSON:   {"infix":"125/5*3", "postfix":"125 5 / 3 *"}
   
   
   Total tests:          10
   Conversion succeeded: 10
   JSON output correct:  10
   Total Extra Credit:   0
   
   
   10	10	0	10
   ```
  * If you want to test using the provided test file, use the following command.
    > `./cmake-build-debug/postfix -file test`
  * The command above tells the program to use file `test.input` for the infix expressions, and it will use `test.output` and `test.json` to check if your program is generating the correct postfix expressions and JSON strings. The given file has 20 tests. We may use a different file to test for grading.
  * If you want to do the extra credit (add the code to evaluate the postfix expression) then you can run the following command.
   > `./cmake-build-debug/postfix -extra test`
  * The `-extra` command line parameter tells the program to check the conversion from infix to postfix, and then to check the evaluation of the expressions that *only* have numbers. The output of the test file is:
    > `20	20	8	20`
  * It reports eight because there are only eight expressions in the test set that are made exclusively by numbers.
  * You may use the `-v` flag with `-file test` or `-extra test` or `-hard`.

## Sample Outputs

Here are some possible outputs for the given files. Note the differences between the flags that are used.

### Only Grading Options

> `./cmake-build-debug/postfix`
```
There is an error on your parameters
Usage:
./postfix -flag file-prefix

Flags:
-hard Use the hard coded tests, when using hard coded test use x as file prefix
-file Use the provided file to read the infix expressions
-extra Use the provided file to read the infix expressions, and evaluate them for extra credit
```
Note that no parameters were given!

> `./cmake-build-debug/postfix -file not-there`
```
Unable to open file not-there.input
Unable to open file not-there.output
Unable to open file not-there.json
```
The flag is correct, but there is no `not-there` file in the current directory.

> `./cmake-build-debug/postfix -hard`
```
10	10	0	10
```
This runs the hard coded tests that are on `main.cpp`. The output means 10 passed tests, 10 passed JSON, 0 extra credit, 10 total tests made.

> `./cmake-build-debug/postfix -file test`
```
20	20	0	20
```
When using the provided test files, you are expected to pass all 20 tests. **We may use a different test file to grade your lab**.

### Verbose Options
If you would like to see your results and the expected results you may use the `-v` flag to run your program.

> `./cmake-build-debug/postfix -file test -v`
```
TEST - 0
	 Input:           a+b+c
	 Your Output:     a b + c +
	 Expected Output: a b + c +
	 Your JSON:       {"infix":"a+b+c", "postfix":"a b + c +"}
	 Expected JSON:   {"infix":"a+b+c", "postfix":"a b + c +"}
TEST - 1
	 Input:           a+b-c
	 Your Output:     a b + c -
	 Expected Output: a b + c -
	 Your JSON:       {"infix":"a+b-c", "postfix":"a b + c -"}
	 Expected JSON:   {"infix":"a+b-c", "postfix":"a b + c -"}
TEST - 2
	 Input:           a+b*c
	 Your Output:     a b c * +
	 Expected Output: a b c * +
	 Your JSON:       {"infix":"a+b*c", "postfix":"a b c * +"}
	 Expected JSON:   {"infix":"a+b*c", "postfix":"a b c * +"}
TEST - 3
	 Input:           (a+b)/c
	 Your Output:     a b + c /
	 Expected Output: a b + c /
	 Your JSON:       {"infix":"(a+b)/c", "postfix":"a b + c /"}
	 Expected JSON:   {"infix":"(a+b)/c", "postfix":"a b + c /"}
TEST - 4
	 Input:           ( a + b ) * c
	 Your Output:     a b + c *
	 Expected Output: a b + c *
	 Your JSON:       {"infix":"( a + b ) * c", "postfix":"a b + c *"}
	 Expected JSON:   {"infix":"( a + b ) * c", "postfix":"a b + c *"}
TEST - 5
	 Input:           (A+B)*(C-D)
	 Your Output:     A B + C D - *
	 Expected Output: A B + C D - *
	 Your JSON:       {"infix":"(A+B)*(C-D)", "postfix":"A B + C D - *"}
	 Expected JSON:   {"infix":"(A+B)*(C-D)", "postfix":"A B + C D - *"}
TEST - 6
	 Input:           A + ( ( B + C ) * ( E - F ) - G ) / ( H - I)
	 Your Output:     A B C + E F - * G - H I - / +
	 Expected Output: A B C + E F - * G - H I - / +
	 Your JSON:       {"infix":"A + ( ( B + C ) * ( E - F ) - G ) / ( H - I)", "postfix":"A B C + E F - * G - H I - / +"}
	 Expected JSON:   {"infix":"A + ( ( B + C ) * ( E - F ) - G ) / ( H - I)", "postfix":"A B C + E F - * G - H I - / +"}
TEST - 7
	 Input:           A + B * ( C + D ) - E / F * G + H
	 Your Output:     A B C D + * + E F / G * - H +
	 Expected Output: A B C D + * + E F / G * - H +
	 Your JSON:       {"infix":"A + B * ( C + D ) - E / F * G + H", "postfix":"A B C D + * + E F / G * - H +"}
	 Expected JSON:   {"infix":"A + B * ( C + D ) - E / F * G + H", "postfix":"A B C D + * + E F / G * - H +"}
TEST - 8
	 Input:           A+((B+C)*(E-F)-G)/(H-I)
	 Your Output:     A B C + E F - * G - H I - / +
	 Expected Output: A B C + E F - * G - H I - / +
	 Your JSON:       {"infix":"A+((B+C)*(E-F)-G)/(H-I)", "postfix":"A B C + E F - * G - H I - / +"}
	 Expected JSON:   {"infix":"A+((B+C)*(E-F)-G)/(H-I)", "postfix":"A B C + E F - * G - H I - / +"}
TEST - 9
	 Input:           A+B*(C+D)-E/F*G+H
	 Your Output:     A B C D + * + E F / G * - H +
	 Expected Output: A B C D + * + E F / G * - H +
	 Your JSON:       {"infix":"A+B*(C+D)-E/F*G+H", "postfix":"A B C D + * + E F / G * - H +"}
	 Expected JSON:   {"infix":"A+B*(C+D)-E/F*G+H", "postfix":"A B C D + * + E F / G * - H +"}
TEST - 10
	 Input:           1+2+3
	 Your Output:     1 2 + 3 +
	 Expected Output: 1 2 + 3 +
	 Your JSON:       {"infix":"1+2+3", "postfix":"1 2 + 3 +"}
	 Expected JSON:   {"infix":"1+2+3", "postfix":"1 2 + 3 +"}
TEST - 11
	 Input:           (1+2)*3
	 Your Output:     1 2 + 3 *
	 Expected Output: 1 2 + 3 *
	 Your JSON:       {"infix":"(1+2)*3", "postfix":"1 2 + 3 *"}
	 Expected JSON:   {"infix":"(1+2)*3", "postfix":"1 2 + 3 *"}
TEST - 12
	 Input:           (7+5)/( 5 - 2 )
	 Your Output:     7 5 + 5 2 - /
	 Expected Output: 7 5 + 5 2 - /
	 Your JSON:       {"infix":"(7+5)/( 5 - 2 )", "postfix":"7 5 + 5 2 - /"}
	 Expected JSON:   {"infix":"(7+5)/( 5 - 2 )", "postfix":"7 5 + 5 2 - /"}
TEST - 13
	 Input:           1 + (( 7 - 2) * ( 5 - 1) + 5) / 2
	 Your Output:     1 7 2 - 5 1 - * 5 + 2 / +
	 Expected Output: 1 7 2 - 5 1 - * 5 + 2 / +
	 Your JSON:       {"infix":"1 + (( 7 - 2) * ( 5 - 1) + 5) / 2", "postfix":"1 7 2 - 5 1 - * 5 + 2 / +"}
	 Expected JSON:   {"infix":"1 + (( 7 - 2) * ( 5 - 1) + 5) / 2", "postfix":"1 7 2 - 5 1 - * 5 + 2 / +"}
TEST - 14
	 Input:           4 + 3 - 2 * 5 / 1
	 Your Output:     4 3 + 2 5 * 1 / -
	 Expected Output: 4 3 + 2 5 * 1 / -
	 Your JSON:       {"infix":"4 + 3 - 2 * 5 / 1", "postfix":"4 3 + 2 5 * 1 / -"}
	 Expected JSON:   {"infix":"4 + 3 - 2 * 5 / 1", "postfix":"4 3 + 2 5 * 1 / -"}
TEST - 15
	 Input:           alpha * beta + gamma
	 Your Output:     alpha beta * gamma +
	 Expected Output: alpha beta * gamma +
	 Your JSON:       {"infix":"alpha * beta + gamma", "postfix":"alpha beta * gamma +"}
	 Expected JSON:   {"infix":"alpha * beta + gamma", "postfix":"alpha beta * gamma +"}
TEST - 16
	 Input:           (delta - alpha) / (delta - beta)
	 Your Output:     delta alpha - delta beta - /
	 Expected Output: delta alpha - delta beta - /
	 Your JSON:       {"infix":"(delta - alpha) / (delta - beta)", "postfix":"delta alpha - delta beta - /"}
	 Expected JSON:   {"infix":"(delta - alpha) / (delta - beta)", "postfix":"delta alpha - delta beta - /"}
TEST - 17
	 Input:           25+10/2
	 Your Output:     25 10 2 / +
	 Expected Output: 25 10 2 / +
	 Your JSON:       {"infix":"25+10/2", "postfix":"25 10 2 / +"}
	 Expected JSON:   {"infix":"25+10/2", "postfix":"25 10 2 / +"}
TEST - 18
	 Input:           (25+10)/7
	 Your Output:     25 10 + 7 /
	 Expected Output: 25 10 + 7 /
	 Your JSON:       {"infix":"(25+10)/7", "postfix":"25 10 + 7 /"}
	 Expected JSON:   {"infix":"(25+10)/7", "postfix":"25 10 + 7 /"}
TEST - 19
	 Input:           125/5*3
	 Your Output:     125 5 / 3 *
	 Expected Output: 125 5 / 3 *
	 Your JSON:       {"infix":"125/5*3", "postfix":"125 5 / 3 *"}
	 Expected JSON:   {"infix":"125/5*3", "postfix":"125 5 / 3 *"}


Total tests:          20
Conversion succeeded: 20
JSON output correct:  20
Total Extra Credit:   0


20	20	0	20
```

The last numbers are the same, but this time it is showing the results and expected results for each of the tests.

> `./cmake-build-debug/postfix -extra test -v`
```
TEST - 0
	 Input:           a+b+c
	 Your Output:     a b + c +
	 Expected Output: a b + c +
	 Your JSON:       {"infix":"a+b+c", "postfix":"a b + c +"}
	 Expected JSON:   {"infix":"a+b+c", "postfix":"a b + c +"}
	 Your Result:     0
	 Expected Result: e
TEST - 1
	 Input:           a+b-c
	 Your Output:     a b + c -
	 Expected Output: a b + c -
	 Your JSON:       {"infix":"a+b-c", "postfix":"a b + c -"}
	 Expected JSON:   {"infix":"a+b-c", "postfix":"a b + c -"}
	 Your Result:     0
	 Expected Result: e
TEST - 2
	 Input:           a+b*c
	 Your Output:     a b c * +
	 Expected Output: a b c * +
	 Your JSON:       {"infix":"a+b*c", "postfix":"a b c * +"}
	 Expected JSON:   {"infix":"a+b*c", "postfix":"a b c * +"}
	 Your Result:     0
	 Expected Result: e
TEST - 3
	 Input:           (a+b)/c
	 Your Output:     a b + c /
	 Expected Output: a b + c /
	 Your JSON:       {"infix":"(a+b)/c", "postfix":"a b + c /"}
	 Expected JSON:   {"infix":"(a+b)/c", "postfix":"a b + c /"}
	 Your Result:     0
	 Expected Result: e
TEST - 4
	 Input:           ( a + b ) * c
	 Your Output:     a b + c *
	 Expected Output: a b + c *
	 Your JSON:       {"infix":"( a + b ) * c", "postfix":"a b + c *"}
	 Expected JSON:   {"infix":"( a + b ) * c", "postfix":"a b + c *"}
	 Your Result:     0
	 Expected Result: e
TEST - 5
	 Input:           (A+B)*(C-D)
	 Your Output:     A B + C D - *
	 Expected Output: A B + C D - *
	 Your JSON:       {"infix":"(A+B)*(C-D)", "postfix":"A B + C D - *"}
	 Expected JSON:   {"infix":"(A+B)*(C-D)", "postfix":"A B + C D - *"}
	 Your Result:     0
	 Expected Result: e
TEST - 6
	 Input:           A + ( ( B + C ) * ( E - F ) - G ) / ( H - I)
	 Your Output:     A B C + E F - * G - H I - / +
	 Expected Output: A B C + E F - * G - H I - / +
	 Your JSON:       {"infix":"A + ( ( B + C ) * ( E - F ) - G ) / ( H - I)", "postfix":"A B C + E F - * G - H I - / +"}
	 Expected JSON:   {"infix":"A + ( ( B + C ) * ( E - F ) - G ) / ( H - I)", "postfix":"A B C + E F - * G - H I - / +"}
	 Your Result:     0
	 Expected Result: e
TEST - 7
	 Input:           A + B * ( C + D ) - E / F * G + H
	 Your Output:     A B C D + * + E F / G * - H +
	 Expected Output: A B C D + * + E F / G * - H +
	 Your JSON:       {"infix":"A + B * ( C + D ) - E / F * G + H", "postfix":"A B C D + * + E F / G * - H +"}
	 Expected JSON:   {"infix":"A + B * ( C + D ) - E / F * G + H", "postfix":"A B C D + * + E F / G * - H +"}
	 Your Result:     0
	 Expected Result: e
TEST - 8
	 Input:           A+((B+C)*(E-F)-G)/(H-I)
	 Your Output:     A B C + E F - * G - H I - / +
	 Expected Output: A B C + E F - * G - H I - / +
	 Your JSON:       {"infix":"A+((B+C)*(E-F)-G)/(H-I)", "postfix":"A B C + E F - * G - H I - / +"}
	 Expected JSON:   {"infix":"A+((B+C)*(E-F)-G)/(H-I)", "postfix":"A B C + E F - * G - H I - / +"}
	 Your Result:     0
	 Expected Result: e
TEST - 9
	 Input:           A+B*(C+D)-E/F*G+H
	 Your Output:     A B C D + * + E F / G * - H +
	 Expected Output: A B C D + * + E F / G * - H +
	 Your JSON:       {"infix":"A+B*(C+D)-E/F*G+H", "postfix":"A B C D + * + E F / G * - H +"}
	 Expected JSON:   {"infix":"A+B*(C+D)-E/F*G+H", "postfix":"A B C D + * + E F / G * - H +"}
	 Your Result:     0
	 Expected Result: e
TEST - 10
	 Input:           1+2+3
	 Your Output:     1 2 + 3 +
	 Expected Output: 1 2 + 3 +
	 Your JSON:       {"infix":"1+2+3", "postfix":"1 2 + 3 +"}
	 Expected JSON:   {"infix":"1+2+3", "postfix":"1 2 + 3 +"}
	 Your Result:     6
	 Expected Result: 6
TEST - 11
	 Input:           (1+2)*3
	 Your Output:     1 2 + 3 *
	 Expected Output: 1 2 + 3 *
	 Your JSON:       {"infix":"(1+2)*3", "postfix":"1 2 + 3 *"}
	 Expected JSON:   {"infix":"(1+2)*3", "postfix":"1 2 + 3 *"}
	 Your Result:     9
	 Expected Result: 9
TEST - 12
	 Input:           (7+5)/( 5 - 2 )
	 Your Output:     7 5 + 5 2 - /
	 Expected Output: 7 5 + 5 2 - /
	 Your JSON:       {"infix":"(7+5)/( 5 - 2 )", "postfix":"7 5 + 5 2 - /"}
	 Expected JSON:   {"infix":"(7+5)/( 5 - 2 )", "postfix":"7 5 + 5 2 - /"}
	 Your Result:     4
	 Expected Result: 4
TEST - 13
	 Input:           1 + (( 7 - 2) * ( 5 - 1) + 5) / 2
	 Your Output:     1 7 2 - 5 1 - * 5 + 2 / +
	 Expected Output: 1 7 2 - 5 1 - * 5 + 2 / +
	 Your JSON:       {"infix":"1 + (( 7 - 2) * ( 5 - 1) + 5) / 2", "postfix":"1 7 2 - 5 1 - * 5 + 2 / +"}
	 Expected JSON:   {"infix":"1 + (( 7 - 2) * ( 5 - 1) + 5) / 2", "postfix":"1 7 2 - 5 1 - * 5 + 2 / +"}
	 Your Result:     13.5
	 Expected Result: 13.5
TEST - 14
	 Input:           4 + 3 - 2 * 5 / 1
	 Your Output:     4 3 + 2 5 * 1 / -
	 Expected Output: 4 3 + 2 5 * 1 / -
	 Your JSON:       {"infix":"4 + 3 - 2 * 5 / 1", "postfix":"4 3 + 2 5 * 1 / -"}
	 Expected JSON:   {"infix":"4 + 3 - 2 * 5 / 1", "postfix":"4 3 + 2 5 * 1 / -"}
	 Your Result:     -3
	 Expected Result: -3
TEST - 15
	 Input:           alpha * beta + gamma
	 Your Output:     alpha beta * gamma +
	 Expected Output: alpha beta * gamma +
	 Your JSON:       {"infix":"alpha * beta + gamma", "postfix":"alpha beta * gamma +"}
	 Expected JSON:   {"infix":"alpha * beta + gamma", "postfix":"alpha beta * gamma +"}
	 Your Result:     0
	 Expected Result: e
TEST - 16
	 Input:           (delta - alpha) / (delta - beta)
	 Your Output:     delta alpha - delta beta - /
	 Expected Output: delta alpha - delta beta - /
	 Your JSON:       {"infix":"(delta - alpha) / (delta - beta)", "postfix":"delta alpha - delta beta - /"}
	 Expected JSON:   {"infix":"(delta - alpha) / (delta - beta)", "postfix":"delta alpha - delta beta - /"}
	 Your Result:     0
	 Expected Result: e
TEST - 17
	 Input:           25+10/2
	 Your Output:     25 10 2 / +
	 Expected Output: 25 10 2 / +
	 Your JSON:       {"infix":"25+10/2", "postfix":"25 10 2 / +"}
	 Expected JSON:   {"infix":"25+10/2", "postfix":"25 10 2 / +"}
	 Your Result:     30
	 Expected Result: 30
TEST - 18
	 Input:           (25+10)/7
	 Your Output:     25 10 + 7 /
	 Expected Output: 25 10 + 7 /
	 Your JSON:       {"infix":"(25+10)/7", "postfix":"25 10 + 7 /"}
	 Expected JSON:   {"infix":"(25+10)/7", "postfix":"25 10 + 7 /"}
	 Your Result:     5
	 Expected Result: 5
TEST - 19
	 Input:           125/5*3
	 Your Output:     125 5 / 3 *
	 Expected Output: 125 5 / 3 *
	 Your JSON:       {"infix":"125/5*3", "postfix":"125 5 / 3 *"}
	 Expected JSON:   {"infix":"125/5*3", "postfix":"125 5 / 3 *"}
	 Your Result:     75
	 Expected Result: 75


Total tests:          20
Conversion succeeded: 20
JSON output correct:  20
Total Extra Credit:   8


20	20	8	20
```

This example shows what it would look like if you implement the `Evaluate` method. This set of tests has only 8 expressions with integers, the other expressions have letters, thus these can't be evaluated.
