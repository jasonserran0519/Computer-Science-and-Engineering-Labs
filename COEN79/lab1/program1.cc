#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string text;
    int letters;
    int non_letters;

    cout << "Enter a text:";
    getline(cin, text);

    for(int i = 0; i < text.length();  i++)
    {
	if(isalpha(text[i]))
	{
	    letters++;
	}
	else
	{
	    non_letters++;
	}

    }

    cout <<"Number of alphanumeric characters: \n" << letters <<endl;
    cout <<"Number of Non-Alphanumic characers: \n" << non_letters;

    return 0;
}
