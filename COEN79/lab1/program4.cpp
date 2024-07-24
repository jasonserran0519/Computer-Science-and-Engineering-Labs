#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    //allows the use of srand()
    int count = 0;
    int guessed_number;
    string text;

    cout << "Guess a number between 1 and 20" << endl;

    while(1)
    {

	int guessed_number = rand() % 21;
	//using srands with rand allows a differnet number to be choosen if the user says the number guessed was incorrect. This allows for the same number to not be guessed
	cout << "is this your number: " << guessed_number << "?" <<endl ;
	count ++;
	// outputs the guessed number and increments count by 1 if the guess was incorrect

	getline(cin, text);
	if (text == "yes" || text == "y")
	//if the answer was correct, it will stop the program, if a different response is inputted, the program will continue
	{
	    cout << "sweet! I found it in " << count <<endl;
	    break;
	}
    }
}


