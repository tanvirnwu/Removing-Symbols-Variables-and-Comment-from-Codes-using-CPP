#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<string>
#include<set>
#include<iomanip>
#include<iterator>
using namespace std;

/**
 * Program to process a C++ source code file. It reads from an input file and writes to an output file.
 * Specifically, this program is designed to copy lines that start with '#' and end with '>' directly to the output file.
 * It reads line by line from "input.txt" and writes to "output.txt".
 */
int main()
{
    // Array of C++ keywords, not used in the current logic but prepared for potential keyword processing
    string keys[32] = {
        "auto", "break", "case", "char", "constant", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while"
    };

    // File streams for input and output
    ifstream fileinput("E:\\input.txt"); // Adjust the file path as necessary
    ofstream fileoutput("E:\\output.txt"); // Adjust the file path as necessary

    string line; // Variable to store each line read from the input file
    int t = 0; // Variable to store the length of the line

    // Check if the input file is successfully opened
    if(fileinput.is_open())
    {
        // Read the file line by line
        while(getline(fileinput, line))
        {
            t = line.length(); // Get the length of the current line

            // Check if the line starts with '#' and ends with '>'
            if(line.front() == '#' && line.back() == '>')
            {
                // Write the entire line to the output file
                fileoutput << line;
            }

            // Optionally, write a newline to the output file (commented out as it may not be necessary)
            // fileoutput << "\n";
        }
        // Close the input file after processing
        fileinput.close();
    }

    // Close the output file
    fileoutput.close();

    return 0; // Return 0 to indicate successful execution
}
