/*
HAMNA ALIN AND HAMYAL
Project*/
#pragma once
#include <iostream>
using namespace std;
class Person			//class of person a main driver class
{
protected:
	static int ID;
	char CNIC[16];
	char Password[20];

public:
	Person();
	//using virtual functions to show polymorphism
	virtual void Login();
	virtual void Register();
	virtual void Logout();
};
Person::Person()
{
}

int Person::ID = 0;

void Person::Login()
{
}
void Person::Register()
{
}
void Person::Logout()
{
}
