/*
HAMNA ALIN AND HAMYAL
Project*/
#pragma once
#include <iostream>
#include <fstream>
#include "..//Project_Grocery/Manager.h"
using namespace std;
class item
{
    int itemnm;
    char iname[50];
    float price, qnt, tax, dis;

public:
    item()
    {
        /*itemnm = 0;
        iname[50]= {};
        price = 0;
        qnt = 0;
        tax = 0;
        dis = 0;*/
    }
    void getdata()
    {
        cout << "\nPlease Enter Item nm of Item: \t" << endl;
        cin >> itemnm;
        cout << "\nPlease Enter Name of Item: \t" << endl;
        cin >> iname;
        cout << "\nPlease Enter Price of Item: \t" << endl;
        cin >> price;
        cout << "\nPlease Enter Discount on Item: \t" << endl;
        cin >> dis;
    }
    void showdata()
    {
        cout << "Item #  : \t" << itemnm << endl;
        cout << "Item Name: \t" << iname << endl;
        cout << "Price : \t" << price << endl;
        cout << "Discount : \t" << dis << endl;
    }
    int getItemnm()
    {
        return itemnm;
    }
    float getPrice()
    {
        return price;
    }
    char* getname()
    {
        return iname;
    }
    int getDis()
    {
        return dis;
    }
}; // class ends of item
fstream f;
item i;

// write in file
void write_to_file()
{
    f.open("store.dat", ios::binary | ios::out | ios::app);
    i.getdata();
    f.write((char*)&i, sizeof(i));
    f.close();
    cout << "The Items has been created.." << endl;
}
void display() // this function reads all records from the file
{
    cout << "\t\tDisplay all Records.!\n"
        << endl;
    f.open("store.dat", ios::in);
    while (f.read((char*)&i, sizeof(i)))
    {
        i.showdata();
        cout << "\n\n=================================" << endl;
    }
    f.close();
}
void display_sp(int n) // function to read specific record from the file
{
    int flag = 0;
    f.open("store.dat", ios::in);
    while (f.read((char*)&i, sizeof(i)))
    {
        if (i.getItemnm() == n)
        {
            i.showdata();
            flag = 1;
        }
    }
    f.close();
    if (flag == 1)
    {
        cout << "Records does not Exist...`:(" << endl;
    }
}
void modify()
{
    int no, found = 0;
    system("cls");
    cout << "\n\n\n\nTo Modify...." << endl;
    cout << "\n\n\nPlease Enter The Item Nm of Item.." << endl;
    cin >> no;
    f.open("store.dat", ios::binary | ios::in | ios::out);
    while (f.read((char*)&i, sizeof(i)) && found == 0)
    {
        if (i.getItemnm() == no)
        {
            system("cls");
            i.showdata();
            int pos = -1 * ((int)sizeof(i));
            f.seekp(pos, ios::cur);
            f.write((char*)&i, sizeof(i));
            cout << "\t\tRecord Updated!" << endl;
            found = 1;
        }
    }
    f.close();
    if (found == 0)
    {
        cout << "\t\tRecord Not Found!!!!!!!!!" << endl;
    }
}

void delete_rec()
{
    int no;
    system("cls");
    cout << "\t\t\tDelete Record" << endl;
    cout << "\n\n\nPlease Enter the item Nm of Item That u Want to Delete." << endl;
    cin >> no;
    f.open("store.dat", ios::binary | ios::in | ios::out);
    fstream f2;
    f2.open("temp.dat", ios::binary | ios::out);
    f.seekg(0, ios::beg);
    while (f.read((char*)&i, sizeof(i)));
    {
        if (i.getItemnm() != no)
        {
            f2.write((char*)&i, sizeof(i));
        }
    }
    f.close();
    f2.close();
    remove("store.dat");
    rename("temp.dat", "store.dat");
    cout << "\n\n\t\tRecord Deleted!" << endl;
}
void menu()//function to display all products price list
{
    system("cls");
    f.open("store.dat", ios::binary | ios::in);
    if (!f)
    {
        cout << "\t\tError 404 !File Could Not be Open\n\n\nGo to Admin Menu to Create Products" << endl;
        cout << "\n\n\nProgram is Closing.." << endl;
        exit(0);

    }/*
    space(40);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 90);
    cout << "<~~ MAIN MENU ~~>";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << endl
        << endl;*/
    cout << "==========================================================" << endl;
    cout << "ITEM_NO\t\tNAME\t\tPRICE" << endl;
    cout << "==========================================================" << endl;
    while (f.read((char*)&i, sizeof(i)))
    {
        cout << i.getItemnm() << "\t\t" << i.getname() << "\t\t" << i.getPrice() << endl;
    }
    f.close();
}
void place_order()//function to place order and generate bill
{
    system("clr");
    int order_arr[50], quan[50], c = 0;
    float amt, damt, total = 0;
    char ch = 'Y';
    menu();
    cout << "==========================================================" << endl;
    cout << "----------------------PLACE YOUR ORDER---------------" << endl;
    cout << "==========================================================" << endl;
    do {
        cout << "\n\nEnter The Item Nm of ITem" << endl;
        cin >> order_arr[c];
        cout << "\nQuantity in Numbers" << endl;
        cin >> quan[c];
        c++;
        cout << "\nDo you Want More Items to Order?(Y/N)" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\n\tThank You For Placing Order.." << endl;
    cout << "-------------------INVOICE--------------" << endl;
    cout << "\nItemNo.\tName\tQuantity\tPrice\tAmount\tAmount After Discount" << endl;
    for (int x = 0; x <= c; x++)
    {
        f.open("store.dat", ios::binary | ios::in);
        f.read((char*)&i, sizeof(i));
        while (!f.eof())
        {
            if (i.getItemnm() == order_arr[x])
            {
                amt = i.getPrice() * quan[x];
                damt = amt - (amt * i.getDis() / 100);
                cout << "\n" << order_arr[x] << "\t" << i.getname() << "\t" << quan[x] << "\t\t" << i.getPrice() << "\t" << amt << "\t\t" << damt << endl;
                total += damt;
            }
            f.read((char*)&i, sizeof(i));
        }
        f.close();
    }
    cout << "\t\tTotal Bill : " << total << endl;

}
void admin_menu()
{
    int ch2;
    do {
        cout << "\n\n\tMENU" << endl;
        cout << "\t1):-Create Item" << endl;
        cout << "\t2):-Display All Items" << endl;
        cout << "\t3):-Query" << endl;
        cout << "\t4):-Modify Item" << endl;
        cout << "\t5):-Delete Item" << endl;
        cout << "\t6):-Back To Main Menu" << endl;
        cout << "\t7):-LogOut" << endl;
        cout << "\n\nPlease Enter choice" << endl;
        cin >> ch2;
        switch (ch2)
        {
        case 1:
        {
            write_to_file();
            break;
        }
        case 2:
        {
            display();
            break;
        }
        case 3:
        {
            int num;
            cout << "\n\n\tPlease Enter The Item NUmber" << endl;
            cin >> num;
            display_sp(num);
            break;
        }
        case 4:
        {
            modify();
            break;
        }
        case 5:
        {
            delete_rec();
            break;
        }
        case 6:
        {
            menu();
            break;
        }
        case 7:
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "\a";
            admin_menu();
        }
        }
    } while (ch2 != 7);

}
