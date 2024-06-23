/*
HAMNA ALIN AND HAMYAL
Project*/
#pragma once
#include <iostream>
#include <fstream>
#include "..//Project_Grocery/Person.h"
#include "..//Project_Grocery/Credentials.h"
using namespace std;

// class of admin_panel
class Admin : public Person
{

protected:
	char Name[20];

public:
	Admin()
	{
	}

	void Login_Admin()				//it's a login of admin through
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
		Admin obj = LoadObject_admin(cnic.c_str());
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
	void Register_Admin()
	{
		string password, cnic,re_pass;

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
		//reentering the password
		cout << "Please Re_Enter Your Password." << endl;
		cin >> re_pass;
		while (!(password_valid(password)))
		{
			cout << "please enter password again" << endl;
			cin >> re_pass;
		}
		while (strcmp(password.c_str(), re_pass.c_str()) != 0)
		{
			cout << "Please Re Enter The Password.." << endl;
			cin >> re_pass;
			while (!(password_valid(password)))
			{
				cout << "please enter password again" << endl;
				cin >> re_pass;
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
		SaveObject_admin();
		//cout << "\t\t---------You'r Successsfully Registered--------" << endl;
		// Menu();
		exit(0);

	}
	//void Logout();
	bool SaveObject_admin()
	{
		Admin temp1;
		ifstream infile("Admin.bin", ios::binary);
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
		ofstream ofile("Admin.bin", ios::binary | ios::app);
		if (!flag)
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
	Admin LoadObject_admin(const char cnic[15]) // read the whole data of admin from the file
	{
		{
			bool f = true;
			Admin temp;
			ifstream myfile("Admin.bin", ios::binary);
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
			Admin c;
			return c;
		}
	}
};
