#include <iostream>
#include <iomanip>
#include <string> 

using namespace std;

void print_reverse(string numbers)
//function used to reverse the numbers
{
    string reverse = numbers;

    int repetition = 5;
    int indent = 2 ;
    //int repetition and indent will be used to help make the indentations as the different lines are printed
    
    for (int i=0; i < repetition; i++)
    {
	cout << setw(indent * (i+1)) << "";
	// will constantly indent as the lines are outputted

	int length = reverse.length();
	//creates the length into an integer

    
	cout <<  "" << numbers << "   ";
    
	for (int i = length; i >0; i--)
	//loop used to reverse the numbers
	{
	    cout << "" << reverse[i];
	}
	cout << "" << endl;
    }


}


int main()
//function used to take in the users 10 numbers
{
    string numbers; 

    cout << "Enter a 10 digit number: ";
    getline(cin, numbers);
 
 
    print_reverse(numbers);
    //passes the numbers taken from the input 
    return 0;
}
