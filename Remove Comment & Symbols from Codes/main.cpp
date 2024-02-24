#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <string>
#include <set>
#include <iterator>
using namespace std;

/**
 * This program reads a C++ source code from an input file, removes comments, 
 * identifies and outputs symbols to an output file. It also prepares to identify
 * keywords and variables, though the implementation for these functionalities 
 * is not fully developed in this script.
 */

int main()
{
    // List of C++ keyword for reference
    string keys[32] = {"auto","break","case","char","constant","continue","default", "do","double","else","enum","extern","float","for","goto",
                       "if","int","long","register","return","short","signed", "sizeof","static","struct","switch","typedef","union",
                       "unsigned","void","volatile","while"
                      }; 

    // File stream objects for reading and writing files
    ifstream fileinput("E:\\input.txt"); // Corrected slashes for file path
    ofstream fileoutput("E:\\output.txt");

    // Variables for storing counts and flags
    int count1Var=0,count1=0,count1Keys=0,flag=1,p=0,count1Sym=0;
    string line,storeKeys[55],word1="",storeVar[44],mergeVar="",symbol[100];

    if(fileinput.is_open())
    {
        while(getline(fileinput,line))
        {
            char* newline = new char[line.length()+1];
            strcpy (newline,line.c_str());
            for(int j=0; j<line.length(); j++)
            {
                // Handling multi-line comments
                if(newline[j]=='/' && newline[j+1]=='*')
                {
                    flag=0;
                }

                // Handling single-line comments
                if(newline[j]=='/' && newline[j+1]=='/')
                {
                    for(int k=0; k<line.length(); k++)
                    {
                        newline[j+k]='\0'; // Correctly terminating string instead of setting to false
                        fileoutput<<newline[j+k];
                    }
                }

                // Resuming after multi-line comment
                if(newline[j]=='*' && newline[j+1]=='/')
                {
                    flag=1;
                    j=j+2;
                }

                // Outputting non-commented parts of the code
                if(flag==1)
                {
                    fileoutput<<newline[j];
                }

                // Detecting and storing symbols
                // Each case adds a symbol to the symbol array and increments count
                if(newline[j]=='#') symbol[count1Sym]="# (Hash)";
                else if(newline[j]=='.') symbol[count1Sym]=". (Dot)";
                else if(newline[j]==';') symbol[count1Sym]="; (Semi Colon)";
                else if(newline[j]==',') symbol[count1Sym]=", (Comma)";
                else if(newline[j]=='=') symbol[count1Sym]="= (Equal)";
                else if(newline[j]=='<') symbol[count1Sym]="< (Less Than)";
                else if(newline[j]=='>') symbol[count1Sym]="> (Greater Than)";
                else if(newline[j]=='(') symbol[count1Sym]="( (Opening Parenthesis)";
                else if(newline[j]==')') symbol[count1Sym]=") (Closing Parenthesis)";
                else if(newline[j]=='{') symbol[count1Sym]="{ (Opening Curly Bracket)";
                else if(newline[j]=='}') symbol[count1Sym]="} (Closing Curly Bracket)";
                else if(newline[j]=='[') symbol[count1Sym]="[ (Opening Square Bracket)";
                else if(newline[j]==']') symbol[count1Sym]="] (Closing Square Bracket)";
                else if(newline[j]=='+') symbol[count1Sym]="+ (Plus)";
                else if(newline[j]=='-') symbol[count1Sym]="- (Minus)";
                
                if(symbol[count1Sym].length() > 0) count1Sym++; // Increment symbol count if a symbol was added
            }
            fileoutput<<"\n";
            delete[] newline; // Free allocated memory
        }
    }

    // Outputting total symbols and their descriptions
    fileoutput<<"\nTotal Symbols: "<<count1Sym<<"\n";
    for(int g=0; g<count1Sym; g++)
    {
        fileoutput<<symbol[g]<<"\n";
    }

    // Close the file streams
    fileinput.close();
    fileoutput.close();

    return 0;
}
