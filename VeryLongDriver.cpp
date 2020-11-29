#include<iostream>
//#include "verylongint-incomplete.h"  // Uncomment this when testing with test-given-fns.txt
#include "verylongint.h"          // Uncomment this (and comment above) when testing test-all.txt.
#include "VeryLongDriver.h"

using namespace std;

void VeryLongDriver::setUpFiles()
{
    const string INFILE_PROMPT   =
        "Please enter the path for the input file: ";

    const string OUTFILE_PROMPT  =
        "Please enter the path for the output file: ";

    const string IN_FAILURE =
        "*** Error opening input file: ";

    string inFileName, outFileName;

    cout << endl << INFILE_PROMPT;
    cin >> inFileName;
    inFile.open (inFileName.c_str(), ios::in);
    while (inFile.fail ())
    {
        cout << endl << IN_FAILURE << inFileName << endl;
        cout << endl << INFILE_PROMPT;
        cin >> inFileName;
        inFile.open (inFileName.c_str(), ios::in);
    } // if input file incorrect

    cout << endl << OUTFILE_PROMPT;
    cin >> outFileName;
    outFile.open (outFileName.c_str(), ios::out);
} // setUpFiles

void VeryLongDriver::callMethod (const string& method)
{
    const string INITIALIZE = "initialize";
    const string SIZE = "size";
    const string READ = ">>";
    const string PRINT = "<<";
    const string ADD = "+";
    const string LESS = "<";
    const string GREATER = ">";
    const string EQUALS = "==";
    const string ASSIGN = "=";
    const string FIBONACCI = "fibonacci";
	const string SUBTRACT = "-";
	const string MULTIPLY = "*";

    const string INT_MESSAGE = "The integer is ";
     const string VERY_LONG_MESSAGE =
         "The current very_long\'s value is ";

    const string NEW_VERY_LONG_MESSAGE =
	      "The new very long integer is ";

    const string FIRST_VERY_LONG_MESSAGE =
	      "The first very long integer is ";

    const string SECOND_VERY_LONG_MESSAGE =
	      "The second very long integer is ";

    const string EQUAL_MESSAGE   = " equal to ";

    const string LESS_MESSAGE    = " less than ";

    const string GREATER_MESSAGE = " greater than ";

    const string FALSE_MESSAGE   = " is false.";

    const string TRUE_MESSAGE    = " is true.";

    const string COPY_MESSAGE    = "The copy\'s value is ";

    const string NOT_A_METHOD_MESSAGE =
   	   "The line entered does not start with a method.";

    const string PRE_NEW_MESSAGE =
	      "Here is the new very long integer before copying: ";

    const string NEW_MESSAGE =
	      "Here is the new very long integer after copying: ";

    const string ALTERED_NEW_MESSAGE =
	      "Here is the new very long integer after alteration: ";


    very_long_int very_long_1,
                  very_long_2;

    unsigned n;

    if (method == INITIALIZE)
    {
        inFile >> n;
        outFile << endl << INT_MESSAGE << n << endl;
        very_long.initialize (n);
    } // initialize
    else if (method == READ)
        inFile >> very_long;
    else if (method == PRINT)
        outFile << VERY_LONG_MESSAGE << very_long << endl;
    else if (method == ADD)
    {
        inFile >> very_long_1;
        outFile << endl << FIRST_VERY_LONG_MESSAGE
                << very_long_1 << endl;
        inFile >> very_long_2;
        outFile << endl << SECOND_VERY_LONG_MESSAGE
                << very_long_2 << endl;

        very_long = very_long_1 + very_long_2;
    } // add
    else if (method == LESS)
    {
        inFile >> very_long_1;
        outFile << endl << NEW_VERY_LONG_MESSAGE
                << very_long_1 << endl;
        outFile << very_long << LESS_MESSAGE << very_long_1;
        if (very_long < very_long_1)
            outFile << TRUE_MESSAGE << endl;
        else
            outFile << FALSE_MESSAGE << endl;
    } // less
    else if (method == GREATER)
    {
        inFile >> very_long_1;
        outFile << endl << NEW_VERY_LONG_MESSAGE
                << very_long_1 << endl;
        outFile << very_long << GREATER_MESSAGE << very_long_1;
        if (very_long > very_long_1)
            outFile << TRUE_MESSAGE << endl;
        else
            outFile << FALSE_MESSAGE << endl;
    } // greater
    else if (method == EQUALS)
    {
        inFile >> very_long_1;
        outFile << endl << NEW_VERY_LONG_MESSAGE
                << very_long_1 << endl;
        outFile << very_long << EQUAL_MESSAGE << very_long_1;
        if (very_long == very_long_1)
            outFile << TRUE_MESSAGE << endl;
        else
            outFile << FALSE_MESSAGE << endl;
    } // equals
    else if (method == ASSIGN)
    {
        // Put something in very_long_1:
        very_long_1.initialize (50);
        outFile << endl << PRE_NEW_MESSAGE << very_long_1 << endl;

        very_long_1 = very_long;  // both integers are the same
        outFile << NEW_MESSAGE << very_long_1 << endl;

        // Make very_long_1 different from very_long;
        very_long_1.initialize (20);
        outFile << ALTERED_NEW_MESSAGE << very_long_1 << endl;
    } // operator=
    else if (method == FIBONACCI)
    {
        inFile >> n;
        outFile << INT_MESSAGE << n << endl;
        very_long = very_long.fibonacci(n);
    } // fibonacci
    else if (method == SUBTRACT)
	{
		inFile >> very_long_1;
		outFile << endl << FIRST_VERY_LONG_MESSAGE
			<< very_long_1 << endl;
		inFile >> very_long_2;
		outFile << endl << SECOND_VERY_LONG_MESSAGE
			<< very_long_2 << endl;

		very_long = very_long_1 - very_long_2;
	} // subtract
	else if (method == MULTIPLY)
	{
		inFile >> very_long_1;
		outFile << endl << FIRST_VERY_LONG_MESSAGE
			<< very_long_1 << endl;
		inFile >> very_long_2;
		outFile << endl << SECOND_VERY_LONG_MESSAGE
			<< very_long_2 << endl;

		very_long = very_long_1 * very_long_2;
	} // multiply
	else
        cout << NOT_A_METHOD_MESSAGE << endl;
} // callMethod


void VeryLongDriver::readAndProcess()
{
    const string METHOD_MESSAGE = "The method is ";

    const string PRINT_HEADING  = "The current very_long_int is: ";

    string method;
    while (inFile >> method)
    {
        outFile << METHOD_MESSAGE << method << endl;
        callMethod (method);
        outFile << endl << PRINT_HEADING;
        outFile << endl << very_long << endl << endl << endl;
    } // while
    outFile.close();
} // readAndProcess

int main()
{
   const string CLOSE_WINDOW_PROMPT =
      "Please press the Enter key to close this output window.";

   VeryLongDriver driver;

   driver.setUpFiles();
   driver.readAndProcess();

   cout << endl << endl << CLOSE_WINDOW_PROMPT;
   cin.get();
   return 0;
} // main
