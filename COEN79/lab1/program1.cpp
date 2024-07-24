#include <iostream>
#include <string>

using namespace std; 
//This is not have to continuosly use std in cin and cout

int main ()
{
    string text;
    int letters;
    int non_letters;

    cout << "Enter a text:";
    getline(cin, text);
    // receives a text from the input

    for(int i = 0; i < text.length();  i++)
    // searches through the text to see is there are letters in the text
    {
	if(isalpha(text[i]))
	{
	    letters++;
	    //increments by one if there is a letter
	}
    }
    non_letters = text.length() - letters;

    cout <<"Number of alphanumeric characters: \n" << letters << endl;
    cout <<"Number of Non-Alphanumic characers: \n" << non_letters << endl;

    //prints out the number of alphanumeric characters and non-alphanumic in a line

    return 0;
}
