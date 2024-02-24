#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<string>
#include<set>
#include<iterator>
using namespace std;

/**
 * Reads a file specified by the file path, identifies various symbols (e.g., hash, dot, semi colon, etc.), 
 * and writes the count and type of each symbol found to an output file.
 */
int main()
{
    // List of C++ reserved keywords
    string keys[32] = {"auto", "break", "case", "char", "constant", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto",
                       "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union",
                       "unsigned", "void", "volatile", "while"};

    // File stream objects for reading and writing files
    ifstream fileinput("E:\\input.txt"); // Note: Ensure to use double backslashes for Windows paths
    ofstream fileoutput("E:\\output.txt");

    // Variables to keep track of symbols
    int count1Sym = 0;
    string line, symbol[100];

    // Check if the file is open
    if(fileinput.is_open())
    {
        // Read the file line by line
        while(getline(fileinput, line))
        {
            // Convert the line read into a char array for processing
            char* newline = new char[line.length() + 1];
            strcpy(newline, line.c_str());

            // Iterate through each character in the line
            for(int j = 0; j < line.length(); j++)
            {
                // Check for symbols and increment their count
                switch(newline[j]) {
                    case '#': symbol[count1Sym++] = "# (Hash)"; break;
                    case '.': symbol[count1Sym++] = ". (Dot)"; break;
                    case ';': symbol[count1Sym++] = "; (Semi Colon)"; break;
                    case ',': symbol[count1Sym++] = ", (Comma)"; break;
                    case '=': symbol[count1Sym++] = "= (Equal)"; break;
                    case '<': symbol[count1Sym++] = "< (Less Than)"; break;
                    case '>': symbol[count1Sym++] = "> (Greater Than)"; break;
                    case '(': symbol[count1Sym++] = "' (Single Quotation)"; break;
                    case ')': symbol[count1Sym++] = ") (Closing First Bracket)"; break;
                    case '{': symbol[count1Sym++] = "{ (Starting Second Bracket)"; break;
                    case '}': symbol[count1Sym++] = "} (Closing Second Bracket)"; break;
                    case '[': symbol[count1Sym++] = "[ (Starting Third Bracket)"; break;
                    case ']': symbol[count1Sym++] = "] (Closing Third Bracket)"; break;
                    case '+': symbol[count1Sym++] = "+ (Plus)"; break;
                    case '-': symbol[count1Sym++] = "- (Minus)"; break;
                }
            }
            // Free the allocated memory
            delete[] newline;
        }
        // Close the input file after reading
        fileinput.close();
    }

    // Write the total number of symbols and their types to the output file
    fileoutput << "\nTotal Symbols: " << count1Sym << "\n";
    for(int g = 0; g < count1Sym; g++)
    {
        fileoutput << symbol[g] << "\n";
    }

    // Close the output file after writing
    fileoutput.close();
}
