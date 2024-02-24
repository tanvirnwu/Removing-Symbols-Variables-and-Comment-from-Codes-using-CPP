#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <string>
#include <set>
#include <iomanip>
#include <iterator>
using namespace std;

/**
 * This program reads a file, filters out comments, and writes the modified content to another file.
 * It processes line-by-line and supports single-line (//) and multi-line (/* */) comments removal.
 * The output is written to a specified file with comments removed.
 */
int main()
{
    // Array of C++ keywords
    string keys[32] = {"auto", "break", "case", "char", "constant", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto",
                       "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union",
                       "unsigned", "void", "volatile", "while"};

    // File streams for input and output files
    ifstream fileinput("E:\\input.txt"); // Adjust the path as needed
    ofstream fileoutput("E:\\output.txt"); // Adjust the path as needed

    int flag = 1; // A flag to detect multi-line comments
    string line; // String to store each line read from the file

    // Check if input file is successfully opened
    if (fileinput.is_open())
    {
        // Read file line by line
        while (getline(fileinput, line))
        {
            // Dynamically allocate memory for a char array to store the current line
            char* newline = new char[line.length() + 1];
            // Copy the line into the char array
            strcpy(newline, line.c_str());

            // Process each character in the line
            for (int j = 0; j < line.length(); j++)
            {
                // Detect the start of a multi-line comment
                if (newline[j] == '/' && newline[j + 1] == '*')
                {
                    flag = 0; // Set flag to 0 indicating the start of a comment
                }

                // Detect single-line comment and ignore the rest of the line
                if (newline[j] == '/' && newline[j + 1] == '/')
                {
                    break; // Exit the loop, ignoring the rest of the line
                }

                // Detect the end of a multi-line comment
                if (newline[j] == '*' && newline[j + 1] == '/')
                {
                    flag = 1; // Reset flag to 1 indicating the end of a comment
                    j += 1; // Skip the next character as it is part of the comment ending
                    continue; // Move to the next iteration
                }

                // Write characters to output file if not within a comment
                if (flag == 1)
                {
                    fileoutput << newline[j];
                }
            }
            // Write a newline character to the output file after processing each line
            fileoutput << "\n";

            // Free the allocated memory
            delete[] newline;
        }
        // Close the input file after reading
        fileinput.close();
    }
    // Close the output file after writing
    fileoutput.close();
    
    return 0; // Return 0 to indicate successful execution
}
