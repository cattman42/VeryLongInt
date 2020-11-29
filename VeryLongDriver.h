// verylongdriver.h
// class to run tests on verylongints - definitions in verylongdriver.cpp

#include <fstream>
#include <string>

using namespace std;

class VeryLongDriver
{
    typedef string T;    // Make T another name for string

    protected:

        fstream inFile,
                outFile;

        very_long_int very_long;

    public:

        // Postcondition: The input and output files have been created
        //                with their names read in from the keyboard.
        void setUpFiles();


        // Postcondition: the method in the line just read in has
        //                been processed.
        void callMethod (const string& line);


        // Postcondition: All of the input has been read in and processed.
        void readAndProcess();

}; // class VeryLongDriver
