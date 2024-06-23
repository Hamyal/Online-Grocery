/*
HAMNA ALIN AND HAMYAL
Project*/
#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
#include "..//Project_Grocery/Person.h"
#include "..//Project_Grocery/Admin.h"
#include "..//Project_Grocery/Credentials.h"
//#include "..//OOp_Project/Inventory.h"
#include"Inventory_Isl.h"
#include"Inventory_Kar.h"
#include"Inventory_Lah.h"
using namespace std;
void space(int a)				//it's a function for spacing
{
	for (int i = 0; i < a; i++)
	{
		cout << " ";
	}
}
//its a amanager class which inherits the Admin and manager can register only through Admin
class Manager : public Person {// , Admin{

protected:
	char Name[20];

public:
	Manager()
	{
	}

	void Login_Manger()				//it's a login of admin through
	{
		string cnicm, passwordm;
		cout << "PLease enter your Cnic (#####-#######-#)" << endl;
		cin >> cnicm;
		while (!(cnic_valid(cnicm)))
		{
			cout << " please enter cnic in given format" << endl;
			cin >> cnicm;
		}
		cout << "Please enter your Password containing capital letter symbol and number" << endl;
		cin >> passwordm;
		while (!(password_valid(passwordm)))
		{
			cout << "please enter password again" << endl;
			cin >> passwordm;
		}
		Manager obj0 = LoadObject_manager(cnicm.c_str());
		//
		if (strcmp(passwordm.c_str(), obj0.Password) == 0)
		{
			cout << "Login Successfully" << endl;
		}
		else
		{
			cout << "\t\tInvalid Password & CNIC" << endl;
			exit(0);
		}
	}
	//its a manager registration for Karachi Store
	void Login_Manger1()				//it's a login of admin through
	{
		string cnicm, passwordm;
		cout << "PLease enter your Cnic (#####-#######-#)" << endl;
		cin >> cnicm;
		while (!(cnic_valid(cnicm)))
		{
			cout << " please enter cnic in given format" << endl;
			cin >> cnicm;
		}
		cout << "Please enter your Password containing capital letter symbol and number" << endl;
		cin >> passwordm;
		while (!(password_valid(passwordm)))
		{
			cout << "please enter password again" << endl;
			cin >> passwordm;
		}
		Manager obj1 = LoadObject_manager1(cnicm.c_str());
		//
		if (strcmp(passwordm.c_str(), obj1.Password) == 0)
		{
			cout << "Login Successfully" << endl;
		}
		else
		{
			cout << "\t\tInvalid Password & CNIC" << endl;
			exit(0);
		}
	}
	//Its a manager registration for Lahore Store
	void Login_Manger2()				//it's a login of manager through admin	
	{
		string cnicm, passwordm;
		cout << "PLease enter your Cnic (#####-#######-#)" << endl;
		cin >> cnicm;
		while (!(cnic_valid(cnicm)))
		{
			cout << " please enter cnic in given format" << endl;
			cin >> cnicm;
		}
		cout << "Please enter your Password containing capital letter symbol and number" << endl;
		cin >> passwordm;
		while (!(password_valid(passwordm)))
		{
			cout << "please enter password again" << endl;
			cin >> passwordm;
		}
		Manager obj2 = LoadObject_manager2(cnicm.c_str());
		//
		if (strcmp(passwordm.c_str(), obj2.Password) == 0)
		{
			cout << "Login Successfully" << endl;
		}
		else
		{
			cout << "\t\tInvalid Password & CNIC" << endl;
			exit(0);
		}
	}
	//
	void Register_Manager()
	{
		string password, cnic,m_pass;

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
		SaveObject_manager();
		//cout << "\t\t---------You'r Successsfully Registered--------" << endl;
		// Menu();
		exit(0);

	}
	//its a register manager function for Karachi store
	void Register_Manager1()
	{
		string password, cnic, m_pass;

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
		SaveObject_manager1();
		//cout << "\t\t---------You'r Successsfully Registered--------" << endl;
		// Menu();
		exit(0);

	}
	//its a manager registered function for Lahore Store
	void Register_Manager2()
	{
		string password, cnic, m_pass;

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
		SaveObject_manager2();
		//cout << "\t\t---------You'r Successsfully Registered--------" << endl;
		// Menu();
		exit(0);

	}

	//void Logout();
	//its a file writing for manager 1(Islamabad)
	bool SaveObject_manager()
	{
		Manager temp1;
		ifstream infile("Manager.bin", ios::binary);
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
		ofstream ofile("Manager.bin", ios::binary | ios::app);
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
	//its a file writing data for manager Karachi
	bool SaveObject_manager1()
	{
		Manager temp1;
		ifstream infile("Manager_Kar.bin", ios::binary);
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
		ofstream ofile("Manager_Kar.bin", ios::binary | ios::app);
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
	//its a manager writing file for Lahore Store
	bool SaveObject_manager2()
	{
		Manager temp1;
		ifstream infile("Manager_Lah.bin", ios::binary);
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
		ofstream ofile("Manager_Lah.bin", ios::binary | ios::app);
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
	//its a reading file for Manager Islamabad
	Manager LoadObject_manager(const char cnic[15]) // read the whole data of admin from the file
	{
		{
			bool f = true;
			Manager temp;
			ifstream myfile("Manager.bin", ios::binary);
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
			Manager c;
			return c;
		}
	}

	//its a reading file for Manager Karachi
	Manager LoadObject_manager1(const char cnic[15]) // read the whole data of admin from the file
	{
		{
			bool f = true;
			Manager temp;
			ifstream myfile("Manager_Kar.bin", ios::binary);
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
			Manager c;
			return c;
		}
	}

	//its a reading file for Manager  Lahore
	Manager LoadObject_manager2(const char cnic[15]) // read the whole data of admin from the file
	{
		{
			bool f = true;
			Manager temp;
			ifstream myfile("Manager_Lah.bin", ios::binary);
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
			Manager c;
			return c;
		}
	}
	void manager_registeration()
	{
		Manager object;
		int c = 0;
		int choice;
		cout << "Enter Manager's Location : " << endl;
		cout << "Press 1:- Islamabad" << endl;
		cout << "Press 2:- Karachi" << endl;
		cout << "Press 3:- Lahore" << endl;
		cin >> choice;
		//do{
		switch (choice)
		{
		case 1:
		{
			{
				cout << "If you are want to register a Manager Enter 1 to Register (ISLAMABAD)" << endl;
				space(20);
				cout << "1. Register" << endl;
				cout << "if you Alraedy have an account of Manager Enter 2 (ISLAMABAD)" << endl;
				space(20);
				cout << "2. Login" << endl;

				cin >> c;
				while (c > 2 && c < 0)
				{
					cin >> c;
				}

				if (c == 2)
				{
					space(40);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 100);
					cout << "<~~ Login ~~>";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << endl
						<< endl;
					object.Login_Manger();
					admin_menu();		//its a menu for islamabad store
					break;
				}
				if (c == 1)
				{
					space(40);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 70);
					cout << "<~~ Register ~~>";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << endl
						<< endl;
					object.Register_Manager();
				}
			}
			break;
		}
		case 2:
		{
			{
				cout << "If you are want to register a Manager Enter 1 to Register (KARACHI)" << endl;
				space(20);
				cout << "1. Register" << endl;
				cout << "if you Alraedy have an account of Manager Enter 2 (KARACHI)" << endl;
				space(20);
				cout << "2. Login" << endl;

				cin >> c;
				while (c > 2 && c < 0)
				{
					cin >> c;
				}

				if (c == 2)
				{
					space(40);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 100);
					cout << "<~~ Login ~~>";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << endl
						<< endl;
					object.Login_Manger1();
					admin_menu_k();
					break;
				}
				if (c == 1)
				{
					space(40);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 70);
					cout << "<~~ Register ~~>";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << endl
						<< endl;
					object.Register_Manager1();
					break;
				}
			}
			break;
		}
		case 3:
		{
			{
				cout << "If you are want to register a Manager Enter 1 to Register (LAhore)" << endl;
				space(20);
				cout << "1. Register" << endl;
				cout << "if you Alraedy have an account of Manager Enter 2 (LAhore)" << endl;
				space(20);
				cout << "2. Login" << endl;

				cin >> c;
				while (c > 2 && c < 0)
				{
					cin >> c;
				}

				if (c == 2)
				{
					space(40);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 100);
					cout << "<~~ Login ~~>";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << endl
						<< endl;
					object.Login_Manger2();
					admin_menu_l();
					break;

				}
				if (c == 1)
				{
					space(40);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 70);
					cout << "<~~ Register ~~>";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << endl
						<< endl;
					object.Register_Manager2();
					break;
				}
			}
			break;
		}
		default:
		{
			cout << "Invalid Choice \n Please Enter Valid Choice" << endl;
			cin >> choice;
		}
		}
		//} while (choice >= 1 && choice <= 3);
		//switch and while ends




	}
};

