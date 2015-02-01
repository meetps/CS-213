#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <string.h> 

using namespace std;

string letters= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string numbers = "0123456789";

int getRandomNumberLetters()
{
	int i = rand()% 26;	
}

int getRandomNumberNumbers()
{
	int i = rand()% 10;	
}

string generateRandomCarNumber()
{


string first = letters.substr(getRandomNumberLetters(),1);
string second = letters.substr(getRandomNumberLetters(),1);
string number_1 = numbers.substr(getRandomNumberNumbers(),1);
string number_2 = numbers.substr(getRandomNumberNumbers(),1);
string number_3 = numbers.substr(getRandomNumberNumbers(),1);
string number_4 = numbers.substr(getRandomNumberNumbers(),1);

string car_number = first + second + number_1 + number_2 + number_3 + number_4;	
//cout<<car_number << endl;
return letters;
}

int main()
{

long long int size ;
cin >> size;
string car_number_to_be_filed;
fstream output;
output.open("Entry_Logs.txt",ios::app);
for(int i= 0; i< size; i++)
	{	
		car_number_to_be_filed = generateRandomCarNumber();
		output << car_number_to_be_filed << " ";
	}
}
