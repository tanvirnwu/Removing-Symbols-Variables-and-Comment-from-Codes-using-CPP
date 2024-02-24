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
 * This program reads a C++ source code file and extracts keywords and variable names.
 * It specifically looks for variables declared with types int, float, double, long, and short.
 * The extracted keywords and variable names are then written to an output file.
 */
int main()
{
    // Array containing C++ keywords for comparison
    string keys[32] = {
        "auto", "break", "case", "char", "constant", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while"
    };

    // File streams for input and output
    ifstream fileinput("E:\\input.txt"); // Ensure the file path is correctly escaped
    ofstream fileoutput("E:\\output.txt");

    // Variables for counting and storing keywords and variables
    int count1Var = 0, count1Keys = 0;
    string line, storeKeys[55], storeVar[44], mergeVar = "";

    // Check if the input file is open
    if(fileinput.is_open())
    {
        // Read the file line by line
        while(getline(fileinput, line))
        {
            // Temporary variable for concatenating characters
            string mergeKeys = "";

            // Iterate through each character in the line
            for(int i = 0; line[i] != '\0'; i++)
            {
                // Check for space to find words
                if(line[i] == ' ' || line[i+1] == '\0') // Also consider end of the line as a separator
                {
                    for(int j = 0; j < 32; j++)
                    {
                        // If the concatenated characters form a keyword
                        if(mergeKeys == keys[j])
                        {
                            storeKeys[count1Keys] = mergeKeys; // Store the keyword
                            count1Keys++;

                            // If the keyword is a data type, look for variables
                            if(mergeKeys == "int" || mergeKeys == "float" || mergeKeys == "double" || mergeKeys == "long" || mergeKeys == "short")
                            {
                                for(int p = i + 1; line[p] != ';'; p++)
                                {
                                    if(line[p] == ' ' || line[p] == '\n')
                                    {
                                        break; // End of variable declaration
                                    }
                                    else if(line[p] == ',')
                                    {
                                        storeVar[count1Var] = mergeVar; // Store the variable
                                        count1Var++;
                                        mergeVar = ""; // Reset for the next variable
                                    }
                                    else
                                    {
                                        mergeVar += line[p]; // Add character to the current variable name
                                    }
                                }
                                storeVar[count1Var] = mergeVar; // Store the last found variable
                                count1Var++;
                                mergeVar = ""; // Reset for the next use
                            }
                            break; // Exit the loop once a keyword is found and processed
                        }
                    }
                    mergeKeys = ""; // Reset for the next word
                }
                else
                {
                    mergeKeys += line[i]; // Add character to the current word
                }
            }
        }
        // Close the input file after reading
        fileinput.close();
    }

    // Write the count and list of keywords to the output file
    fileoutput << "\nTotal Keywords: " << count1Keys << "\n";
    for(int t = 0; t < count1Keys; t++)
    {
        fileoutput << storeKeys[t] << "\n";
    }

    // Write the count and list of variables to the output file
    fileoutput << "\nTotal Variables: " << count1Var << "\n";
    for(int r = 0; r < count1Var; r++)
    {
        fileoutput << storeVar[r] << "\n";
    }

    // Close the output file after writing
    fileoutput.close();
}
