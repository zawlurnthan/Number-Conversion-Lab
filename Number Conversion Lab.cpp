// Number Conversion Lab.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

void decToAny(int, int);
int anytoDecimal(string, int);

int main()
{
	int choice, base;
	string number;
	char again;

	do {
		cout << "Enter 1 for converting to binary number,\n"
				"Enter 2 for converting to decimal number,\n"
				"Enter 3 for converting to hexadecimal number: ";
		cin >> choice;

		cout << "\nEnter number: ";
		cin >> number;
		cout << "Enter original base: ";
		cin >> base;

		switch (choice)
		{
		case 1:
			decToAny(anytoDecimal(number, base), 2);
			break;

		case 2:
			cout << "Decimal number is: " << anytoDecimal(number, base) << endl;
			break;

		case 3:
			decToAny(anytoDecimal(number, base), 16);
			break;

		default:
			cout << "Invalid number!" << endl;
			break;
		}

		cout << "\nDo you still need to convert numbers?\n" 
				"Enter y for Yes or n for No: ";
		cin >> again;
		cout << endl;

	} while (again == 'y' || again == 'Y');

	return 0;
}

int anytoDecimal(string s, int base)
{
	const char *c = s.c_str();
	int b = 1, dec_val = 0;

	// Extracting characters as digits from last character 
	for (int i = s.length() - 1; i >= 0; i--)
	{
		// if character lies in '0'-'9', converting  
		// it to integral 0-9 by subtracting 48 from 
		// ASCII value. 
		if (c[i] >= '0' && c[i] <= '9')
		{
			dec_val += (c[i] - 48)*b;
			// incrementing base by power 
			b = b * base;
		}
		// if character lies in 'A'-'F' , converting  
		// it to integral 10 - 15 by subtracting 55  
		// from ASCII value 
		else if (c[i] >= 'A' && c[i] <= 'F')
		{
			dec_val += (c[i] - 55)*b;
			// incrementing base by power 
			b *= base;
		}
	}
	return dec_val;
}


void decToAny(int decimal, int base)
{
	int i = 0, arr[100];
	while (decimal > 0)
	{
		arr[i] = decimal % base;
		decimal /= base;
		i++;
	}

	cout << "Converted number is: ";
	for (int j = i - 1; j >= 0; j--)
	{
		cout << arr[j];
	}
	cout << endl;
}
