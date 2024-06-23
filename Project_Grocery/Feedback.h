/*
HAMNA ALIN AND HAMYAL
Project*/
#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Feedback {			//class of feedback
public:
	char feed_back[50];
	int code=0;
	Feedback()
	{
		code = 0;
	}
	/*void setcode(int c)
	{
		code = c;
		cout << "\n\n\tPlease Enter YOUR BILL CODE----" << endl;
		cin >> code;
	}
	int getcode()
	{
		return code;
	}*/
	void getfeedback()
	{
		cout << "\n\n\tPlease Enter YOUR BILL CODE----" << endl;
		cin >> code;
		
		cout << "\n\n\tPlease Enter FEEDBACK----" << endl;
		cin >> feed_back;
	}
	void showFeedback()
	{
		cout << code << endl;
		cout << feed_back<<endl;
		
	}

	void feedback()		//feedback function to add feedback of people
	{
		int ch;
		do {
			cout << "\n\n\tIF YOU WANT TO GIVE FEEDBACK RELATED TO OUR STORE THEN PRESS 1\n Else Press 2 For LogOut" << endl;
			cin >> ch;
			switch (ch)
			{
			case 1:
			{
				write_feedback();
				break;
			}
			case 2:
			{
				//write_feedback();
				exit(0);
				break;
			}
			default:
			{
					cout << "JUST PRESS 1 :)" << endl;
					cin >> ch;

				//}

			}
			}
		} while (ch!=1);
	}
	void write_feedback()
	{
		Feedback obj;
		fstream file;
		file.open("feedback.dat", ios::binary | ios::out | ios::app);
		obj.getfeedback();
		file.write((char*)&obj, sizeof(obj));
		file.close();
		cout << "The FEEDBACK has been created.." << endl;
	}
	void display_feedback() // this function reads all records from the file
	{
		Feedback obj;
		fstream file1;
		cout << "\t\tDisplay Feedback.!\n"
			<< endl;
		file1.open("feedback.dat", ios::binary | ios::in);
		while (file1.read((char*)&obj, sizeof(obj)))
		{
			obj.showFeedback();
			cout << "\n\n=================================" << endl;
		}
		file1.close();
	}

	void delete_Feedback()
	{
		Feedback obj;
		fstream file;
		int no;
		system("cls");
		cout << "\t\t\tDelete FEEDBACK!" << endl;
		cout << "\n\n\nPlease Enter THE BILL CODE OF CUSTOMER That U Want to Delete." << endl;
		cin >> no;
		file.open("feedback.dat", ios::binary | ios::in | ios::out);
		fstream f5;
		f5.open("temporary.dat", ios::out);
		file.seekg(0, ios::beg);
		while (file.read((char*)&obj, sizeof(obj)));
		{
			if (obj.code != no)
			{
				f5.write((char*)&obj, sizeof(obj));
			}
		}
		file.close();
		f5.close();
		remove("feedback.dat");
		rename("temporary.dat", "feedback.dat");
		cout << "\n\n\t\tFEEDBACK Deleted!" << endl;
	}
};
