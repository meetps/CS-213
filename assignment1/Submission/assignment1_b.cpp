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
return car_number;
}

int main()
{

long long int size_entry ;
long long int size_exit ;
cin >> size_entry;
cin >> size_exit;
string car_number_exit;
string car_number_entry;
ofstream output_entry;
output_entry.open("Entry_Logs.txt",ios::app);
for(int i= 0; i< size_entry; i++)
	{	
		car_number_entry = generateRandomCarNumber();
		output_entry << car_number_entry << " ";
		// cout << car_number_entry<< " ";
	}
output_entry.close();	
ofstream output_exit;
output_exit.open("Exit_Logs.txt",ios::app);
for(int i= 0; i< size_exit; i++)
	{	
		car_number_exit = generateRandomCarNumber();
		output_exit << car_number_exit << " ";
	}
output_exit.close();		
}
