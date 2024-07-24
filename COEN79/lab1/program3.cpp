#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;


int main(int argc, char* argv[])
{
    if (argc < 2)
    //checks to see if there is an input file
    {
        cerr << "error: no input file. \n";
        return 0;
    }
    ifstream file(argv[1]);

    if(!file)
    //checks if it could open the file
    {
        cerr << "error: couldn't open file";
        return 0;
    }

    string line;

    while (file >> line)
    //continues the while loop until the last line has been reached and read
    {
        for (int i=0; i < line.length();) 
        { 
            if (!isalpha(line[i]))
            //checks to see if the string character at position i is not a character
	    {
               line.erase(i,1);
            }
	    else
	    {
	    // the pre increment would allow the code to increment i before erasing the non character in the previous position of i. This allows all non alpha charcters to be deleted as I noticed some would be left if i post incremented
		++i;
	    }
        }
            
	if (line.length() >= 10)
        {
	    // checks to see if the line is longer then 10 characters
            for (int i =0; i < line.length(); ++i)
            
	    {
		line[i] = toupper(line[i]);
		// converts all lowercase letters to uppercase		
            }
	    cout << line << endl;
	    //outputs the line after the non characters have been deleted and the 10+ character lines are all uppercase
        }
    }
}

