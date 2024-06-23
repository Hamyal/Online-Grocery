/*
HAMNA ALIN AND HAMYAL
Project*/
#pragma once
#include <iostream>
using namespace std;

bool password_valid(string p = " ", string k = " ")
{
	int count = 0;
	bool f = false;
	bool f1 = false;
	bool f2 = false;
	bool f3 = false;

	for (int i = 0; p[i] != '\0'; i++)
	{
		count++;
		if ((p[i] >= 33 && p[i] <= 47) || (p[i] >= 58 && p[i] <= 64) || (p[i] >= 91 && p[i] <= 96))
		{
			f = true;
		}
	}
	for (int i = 0; p[i] != '\0'; i++)
	{
		if ((p[i] >= 33 && p[i] <= 47) || (p[i] >= 58 && p[i] <= 64) || (p[i] >= 91 && p[i] <= 96))
		{
			f1 = true;
		}
	}
	for (int i = 0; p[i] != '\0'; i++)
	{
		if ((p[i] >= 48 && p[i] <= 57))
		{
			f3 = true;
		}
	}
	if (count < 8)
	{
		f2 = false;
	}
	else
		f2 = true;

	if (f == true && f1 == true && f2 == true && f3)
	{
		return true;
	}
	else
		return 0;
}

// validates cnic in login and registration
bool cnic_valid(string s = " ", string j = " ")
{
	if (s.length() < 15)
	{
		return 0;
	}
	bool f = false;
	if (s[5] == '-' && s[13] == '-')
	{
		for (int i = 0; s[i] != '\0'; i++)
		{
			if (i != 5 && i != 13)
			{
				if (s[i] >= 48 && s[i] <= 57)
				{

					f = true;
				}
				else
				{
					f = false;
					break;
				}
			}
		}
	}
	if (f)
	{
		return f;
	}
	else
		return 0;
}

