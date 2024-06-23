/*
HAMNA ALIN AND HAMYAL
Project*/
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string.h>
#include "..//Project_Grocery/Admin.h"
#include "..//Project_Grocery/Credentials.h"
#include "..//Project_Grocery/Customer.h"
#include "..//Project_Grocery/Manager.h"
#include "..//Project_Grocery/Person.h"
#include"..//Project_Grocery/Inventory_Isl.h"
#include"..//Project_Grocery/Product_Catalogue.h"
#include "..//Project_Grocery/Feedback.h"
using namespace std;

void Mainmenu()		//it is a main menu function which checks the whole Regstration and Login Cridentials.
{
	Add_To_Cart bill;
	Cart add;
	Feedback fb;
	// OldCustomer obj;
	Customer obj;
	Admin obj1;
	Manager obj3;
	int a = 0;
	bool f = false;
	bool f1 = false;
	cout << endl;
	cout << "-----///";
	for (int i = 0; i < 50; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "*";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "~";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "\\\\\\-----" << endl;
	// cout << endl;
	space(25);
	for (int i = 0; i < 25; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "*";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "~";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << endl;
	space(35);
	for (int i = 0; i < 13; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "*";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "~";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << endl
		<< endl;
	;

	space(30);
	cout << "|----->>>";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "  Welcome to New Grocery Store  "<<endl;
	cout << "    HAMNA AND HAMYAL";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "<<<-----|";
	cout << endl
		<< endl;
	;

	space(35);
	for (int i = 0; i < 13; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "*";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "~";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << endl;

	space(25);
	for (int i = 0; i < 25; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "*";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "~";
	}
	cout << endl;
	space(8);
	for (int i = 0; i < 50; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "*";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "~";
	}

	cout << endl
		<< endl;

	space(40);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 90);
	cout << "<~~ MAIN MENU ~~>";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << endl
		<< endl;

	cout << "Which type of User are you" << endl
		<< endl;
	;
	space(20);
	cout << "1. Admin" << endl;
	space(20);
	cout << "2. Customer" << endl;
	// space(20); cout << "3. Manager" << endl;

	cin >> a;
	if ((a > 0 && a < 3))
	{
		f = true;
	}
	else
	{
		f1 = true;
	}
	if (f1 == true)
	{

		cout << "please enter valid number" << endl;
		Mainmenu();
	}
	if (f == true)
	{
		if (a == 2)
		{
			int c = 0;
			cout << "If you are a new user Enter 1 to Register" << endl;
			space(20);
			cout << "1. Register" << endl;
			cout << "if you are OldCustomer Enter 2" << endl;
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
				obj.Login();
				system("cls");
				int ch;
				do {
					space(40);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 90);
					cout << "<~~ MAIN MENU ~~>";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << endl
						<< endl;
					space(40);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 100);
					cout << "<~~ Press 1 :- For Shopping (P) ~~>";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << endl
						<< endl;
					//Online shpping Case

					space(40);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 100);
					cout << "<~~ Press 2 :- For Online Shopping ~~>";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << endl
						<< endl;

					space(40);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 100);
					cout << "<~~ Press 3:- For Logout ~~>";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << endl
						<< endl;
					cout << "\n\n\tPlease Select Your Choice.." << endl;
					cin >> ch;
					switch (ch)
					{
					case 1:
					{
						int choice1;
						cout << "\nPlease Enter Your Location where U Want to Shop.." << endl;
						cout << "\tPress 1 :- Islamabad" << endl;
						cout << "\tPress 2 :- Karachi" << endl;
						cout << "\tPress 3 :- Lahore" << endl;
						cout << "\tPress 4 :- Logout" << endl;
						cin >> choice1;
						switch (choice1)
						{
						case 1:
						{
							bill.place_order1();
							fb.feedback();
							break;
						}
						case 2:
						{
							bill.place_order1_K();
							fb.feedback();
							break;
						}
						case 3:
						{
							bill.place_order1_L();
							fb.feedback();
							break;
						}
						case 4:
						{
							exit(0);
							break;
						}
						default:
						{
							cout << "Please Enter Valid Choice" << endl;
							cin >> choice1;
						}
						}




						

						break;
					}
					case 2:
					{
						int choice1;
						system("cls");

						cout << "\n\n\n-----///";
						for (int i = 0; i < 50; i++)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
							cout << "*";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
							cout << "~";
						}
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						cout << "\\\\\\-----" << endl;
						// cout << endl;
						space(25);
						for (int i = 0; i < 25; i++)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
							cout << "*";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
							cout << "~";
						}
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						cout << endl;
						space(35);
						for (int i = 0; i < 13; i++)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
							cout << "*";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
							cout << "~";
						}
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						cout << endl
							<< endl;
						;

						space(30);
						cout << "|----->>>";

						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
						cout << "  Welcome to Online Grocery Store  ";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						cout << "<<<-----|";
						cout << endl
							<< endl;
						;

						space(35);
						for (int i = 0; i < 13; i++)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
							cout << "*";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
							cout << "~";
						}
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						cout << endl;

						space(25);
						for (int i = 0; i < 25; i++)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
							cout << "*";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
							cout << "~";
						}
						cout << endl;
						space(8);
						for (int i = 0; i < 50; i++)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
							cout << "*";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
							cout << "~";
						}

						cout << endl
							<< endl;

						cout << "\nPlease Enter Your Location where U Want to Shop.." << endl;
						cout << "\tPress 1 :- Islamabad" << endl;
						cout << "\tPress 2 :- Karachi" << endl;
						cout << "\tPress 3 :- Lahore" << endl;
						cout << "\tPress 4 :- Logout" << endl;
						cin >> choice1;
						switch (choice1)
						{
						case 1:
						{
							bill.place_order1();
							fb.feedback();
							break;
						}
						case 2:
						{
							bill.place_order1_K();
							fb.feedback();
							break;
						}
						case 3:
						{
							bill.place_order1_L();
							fb.feedback();
							break;
						}
						case 4:
						{
							exit(0);
							break;
						}
						default:
						{
							cout << "Please Enter Valid Choice" << endl;
							cin >> choice1;
						}
						}






						break;
					}



					case 3:
					{
						exit(0);
						break;
					}
					default:
					{
						cout << "\a";
						break;
					}

					}
				} while (ch != 3);
			}
			if (c == 1)
			{
				space(40);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 70);
				cout << "<~~ Register ~~>";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << endl
					<< endl;
				obj.Register();
			}
		}
		else if (a == 1)
		{
			int c = 0;
			cout << "If you are Admin Enter 1 to Register" << endl;
			space(20);
			cout << "1. Register" << endl;
			cout << "if you are Already have an account then Enter 2" << endl;
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
				obj1.Login_Admin();

				//its a registration for manager
				space(40);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 70);
				cout << "<~~If you Want to Register a Manager~~>";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << endl
					<< endl;
				int choice;			//cridentials for manager registration
				cout << "Press 1:- To Register a Manager" << endl;
				//its Product Catalogue for manager
				space(40);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 70);
				cout << "<~~If you Want to go On Product Catalogue~~>";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << endl
					<< endl;
				cout << "Press 2:- Product Catalogue" << endl;

				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					obj3.manager_registeration();
					break;
				}
				case 2:
				{

					int fig;
					//do {
					cout << "------------------------------" << endl;
					cout << "\n\tPress 1:- Check Islamabad's Catalogue." << endl;
					cout << "\n\tPress 2:- Check Karachi's Catalogue." << endl;
					cout << "\n\tPress 3:- Check Lahore's Catalogue." << endl;
					cin >> fig;
					//while ends for case 1


					do       //THIS DO/WHILE LOOP JSUT CHECK THE CREDENTIALS
					{
					if (fig == 1)		//THIS IS THE CASE FOR ISLAMABAD CATALOGUE
					{
						Feedback pay;
						int ch2;
						do
						{
							space(40);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 90);
							cout << "<~~ MAIN MENU (ISL)~~>";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
							cout << endl
								<< endl;
							cout << "\t1):-Create Item" << endl;
							cout << "\t2):-Display All Items" << endl;
							cout << "\t3):-Query" << endl;
							cout << "\t4):-Modify Item" << endl;
							cout << "\t5):-Delete Item" << endl;
							cout << "\t6):-Back To Main Menu" << endl;
							cout << "\t7):-See FeedBacks of Customers" << endl;
							cout << "\t8):-Delete FeedBacks of Customers" << endl;
							cout << "\t9):-LogOut" << endl;
							cout << "\n\nPlease Enter choice" << endl;
							cin >> ch2;

							switch (ch2)
							{
							case 1:
							{
								write_to_file1();
								break;
							}
							case 2:
							{
								display1();
								break;
							}
							case 3:
							{
								int num;
								cout << "\n\n\tPlease Enter The Item NUmber" << endl;
								cin >> num;
								display_sp1(num);
								break;
							}
							case 4:
							{
								modify1();
								break;
							}
							case 5:
							{
								delete_rec1();
								break;
							}
							case 6:
							{
								add.menu1();
								break;
							}
							case 7:
							{
								pay.display_feedback();
								//exit(0);
								break;
							}
							case 8:
							{
								pay.delete_Feedback();
								//exit(0);
								break;
							}
							case 9:
							{
								exit(0);
								break;
							}
							default:
							{
								cout << "\a";
								store_menu1();
							}
							}
						} while (ch2 != 8);			//nested switch ends

						break;
					}//if case for fig
					else if (fig == 2)
					{

						Feedback pay;
						int ch2;
						do
						{
							space(40);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 90);
							cout << "<~~ MAIN MENU (KRC) ~~>";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
							cout << endl
								<< endl;
							cout << "\t1):-Create Item" << endl;
							cout << "\t2):-Display All Items" << endl;
							cout << "\t3):-Query" << endl;
							cout << "\t4):-Modify Item" << endl;
							cout << "\t5):-Delete Item" << endl;
							cout << "\t6):-Back To Main Menu" << endl;
							cout << "\t7):-See FeedBacks of Customers" << endl;
							cout << "\t8):-Delete FeedBacks of Customers" << endl;
							cout << "\t9):-LogOut" << endl;
							cout << "\n\nPlease Enter choice" << endl;
							cin >> ch2;

							switch (ch2)
							{
							case 1:
							{
								write_to_file1_K();
								break;
							}
							case 2:
							{
								display1_K();
								break;
							}
							case 3:
							{
								int num;
								cout << "\n\n\tPlease Enter The Item NUmber" << endl;
								cin >> num;
								display_sp1_K(num);
								break;
							}
							case 4:
							{
								modify1_K();
								break;
							}
							case 5:
							{
								delete_rec1_K();
								break;
							}
							case 6:
							{
								add.menu1_K();
								break;
							}
							case 7:
							{
								pay.display_feedback();
								//exit(0);
								break;
							}
							case 8:
							{
								pay.delete_Feedback();
								//exit(0);
								break;
							}
							case 9:
							{
								exit(0);
								break;
							}
							default:
							{
								cout << "\a";
								store_menu1_K();
							}
							}
						} while (ch2 != 8);			//nested switch ends

						break;
					}
					else if (fig == 3)			//THIS IS FOR LAHORE STORE
					{

						Feedback pay;
						int ch2;
						do
						{
							space(40);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 90);
							cout << "<~~ MAIN MENU (LHR) ~~>";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
							cout << endl
								<< endl;;
							cout << "\t1):-Create Item" << endl;
							cout << "\t2):-Display All Items" << endl;
							cout << "\t3):-Query" << endl;
							cout << "\t4):-Modify Item" << endl;
							cout << "\t5):-Delete Item" << endl;
							cout << "\t6):-Back To Main Menu" << endl;
							cout << "\t7):-See FeedBacks of Customers" << endl;
							cout << "\t8):-Delete FeedBacks of Customers" << endl;
							cout << "\t9):-LogOut" << endl;
							cout << "\n\nPlease Enter choice" << endl;
							cin >> ch2;

							switch (ch2)
							{
							case 1:
							{
								write_to_file1_L();
								break;
							}
							case 2:
							{
								display1_L();
								break;
							}
							case 3:
							{
								int num;
								cout << "\n\n\tPlease Enter The Item NUmber" << endl;
								cin >> num;
								display_sp1_L(num);
								break;
							}
							case 4:
							{
								modify1_L();
								break;
							}
							case 5:
							{
								delete_rec1_L();
								break;
							}
							case 6:
							{
								add.menu1_L();
								break;
							}
							case 7:
							{
								pay.display_feedback();
								//exit(0);
								break;
							}
							case 8:
							{
								pay.delete_Feedback();
								//exit(0);
								break;
							}
							case 9:
							{
								exit(0);
								break;
							}
							default:
							{
								cout << "\a";
								store_menu1_L();
							}
							}
						} while (ch2 != 8);			//nested switch ends

						break;
					}
					else if(fig==4)
					{
						/*cout << "PLEASE ENTER IN THE RANGE FROM 1-3" << endl;
						cin >> fig;*/
						exit(0);
					}
				}while (fig != 4);

				default:
				{
					cout << "\t\tInvalid Choice Please Enter Right Choice" << endl;
					cin >> choice;
				}
				}		//Case 2 ends
			}	//anything
			
}		// Switch end

			//For Register Admin Work
			if (c == 1)
			{
				space(40);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 70);
				cout << "<~~ Register ~~>";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << endl
					<< endl;
				obj1.Register_Admin();


			}
		}
	}
}

int main()
{
	Mainmenu();

}
