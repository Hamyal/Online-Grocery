/*
HAMNA ALIN AND HAMYAL
Project*/
#pragma once
#include <iostream>
#include "..//Project_Grocery/Person.h"
#include "..//Project_Grocery/Credentials.h"
#include <fstream>
using namespace std;
// class of customer which inherits the class parent class(Person)
class Customer : public Person
{

private:
	char Name[20];

public:
	Customer();

	void Login();
	void Register();
	void Logout();
	bool SaveObject();
	Customer LoadObject(const char cnic[15]);
};

void spaces(int a)
{
	for (int i = 0; i < a; i++)
	{
		cout << " ";
	}
}

bool Customer::SaveObject()
{
	Customer temp1;
	ifstream infile("Customer.bin",ios::binary);
	bool flag = false;
	while (infile.read((char*)&temp1, sizeof(temp1)))
			{
		//cout << "this cnic:" << this->CNIC << "temp cnic: " << temp1.CNIC<<endl;
				if (strcmp(this->CNIC, temp1.CNIC) == 0)
				{
					cout << "User Already exists.!" << endl;
					flag = true;
					break;
				}

			}
	infile.close();
	ofstream ofile("Customer.bin", ios::binary|ios::app);
	if(!flag)
	if (ofile.write((char*)this, sizeof(*this)))
	{
		cout << "\t\t---------You'r Successsfully Registered--------" << endl;
		return 1;
	}
	else
	{
		cout << "ERROR" << endl;
		return 0;
	}
	ofile.close();
}

Customer Customer::LoadObject(const char cnic[20])
{
	bool f = true;
	Customer temp;
	ifstream myfile("Customer.bin", ios::binary);
	while (myfile.read((char*)&temp, sizeof(temp)))
	{

		f = true;
		for (int i = 0; cnic[i] != '\0'; i++)
		{
			if (cnic[i] != temp.CNIC[i])
			{

				f = false;
				break;
			}
		}
		if (f)
			return temp;
	}
	Customer c;
	myfile.close();
	return c;
}


Customer::Customer()
{
}
void Customer::Login()
{
	string cnic, password;
	cout << "PLease enter your Cnic (#####-#######-#)" << endl;
	cin >> cnic;
	while (!(cnic_valid(cnic)))
	{
		cout << " please enter cnic in given format" << endl;
		cin >> cnic;
	}
	cout << "Please enter your Password containing capital letter symbol and number" << endl;
	cin >> password;
	while (!(password_valid(password)))
	{
		cout << "please enter password again" << endl;
		cin >> password;
	}
	Customer obj = LoadObject(cnic.c_str());
	//
	if (strcmp(password.c_str(), obj.Password) == 0)
	{
		cout << "Login Successfully" << endl;
	}
	else
	{
		cout << "\t\tInvalid Password & CNIC" << endl;
		exit(0);
	}
}
void Customer::Register()
{
	//Customer object;
	string password, cnic,m_pass;

	cout << "PLease enter your Cnic (#####-#######-#)" << endl;
	cin >> cnic;
	while (!(cnic_valid(cnic)))
	{
		cout << " please enter cnic in given format" << endl;
		cin >> cnic;
	}
	//if(cnic==)
	cout << "Please enter your Password containing capital letter symbol and number" << endl;
	cin >> password;
	while (!(password_valid(password)))
	{
		cout << "please enter password again" << endl;
		cin >> password;
	}
	//re_entering passs
	//reentering the password
	cout << "Please Re_Enter Your Password." << endl;
	cin >> m_pass;
	while (!(password_valid(password)))
	{
		cout << "please enter password again" << endl;
		cin >> m_pass;
	}
	while (strcmp(password.c_str(), m_pass.c_str()) != 0)
	{
		cout << "Please Re Enter The Password.." << endl;
		cin >> m_pass;
		while (!(password_valid(password)))
		{
			cout << "please enter password again" << endl;
			cin >> m_pass;
		}

	}

	int i = 0;
	for (; password[i] != '\0'; i++)
	{
		Password[i] = password[i];
	}
	Password[i] = '\0';

	i = 0;
	for (; cnic[i] != '\0'; i++)
	{
		CNIC[i] = cnic[i];
	}
	CNIC[i] = '\0';

	ID++;

	SaveObject();
	//cout << "\t\t---------You'r Successsfully Registered--------" << endl;

	exit(0);
}
void Customer::Logout()
{
}