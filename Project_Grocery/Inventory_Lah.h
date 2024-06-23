/*
HAMNA ALIN AND HAMYAL
Project*/
#pragma once
#include <iostream>
#include <fstream>
#include "..//Project_Grocery/Manager.h"
using namespace std;
class item_l
{
    int itemnm;
    char iname[50];
    float price, qnt, tax, dis;

public:
    item_l()
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
//fstream f;
//item_k i;

// write in file
void write_to_file_l()
{
    fstream f;
    item_k i;
    f.open("store_lah.dat", ios::binary | ios::out | ios::app);
    i.getdata();
    f.write((char*)&i, sizeof(i));
    f.close();
    cout << "The Items has been created.." << endl;
}
void display_l() // this function reads all records from the file
{
    fstream f;
    item_k i;
    cout << "\t\tDisplay all Records.!\n"
        << endl;
    f.open("store_lah.dat", ios::binary | ios::in);
    while (f.read((char*)&i, sizeof(i)))
    {
        i.showdata();
        cout << "\n\n=================================" << endl;
    }
    f.close();
}
void display_sp_l(int n) // function to read specific record from the file
{
    fstream f;
    item_k i;
    int flag = 0;
    f.open("store_lah.dat", ios::in);
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
void modify_l()
{
    fstream f;
    item_k i;
    int no, found = 0;
    system("cls");
    cout << "\n\n\n\nTo Modify...." << endl;
    cout << "\n\n\nPlease Enter The Item Nm of Item.." << endl;
    cin >> no;
    f.open("store_lah.dat", ios::binary | ios::in | ios::out);
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

void delete_rec_l()
{
    fstream f;
    item_k i;
    int no;
    system("cls");
    cout << "\t\t\tDelete Record" << endl;
    cout << "\n\n\nPlease Enter the item Nm of Item That u Want to Delete." << endl;
    cin >> no;
    f.open("store_lah.dat", ios::binary | ios::in | ios::out);
    fstream f2;
    f2.open("temp_lah.dat", ios::binary | ios::out);
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
    remove("store_lah.dat");
    rename("temp_lah.dat", "store_lah.dat");
    cout << "\n\n\t\tRecord Deleted!" << endl;
}
void menu_l()//function to display all products price list
{
    fstream f;
    item_k i;
    system("cls");
    f.open("store_lah.dat", ios::binary | ios::in);
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
void place_order_l()//function to place order and generate bill
{
    fstream f;
    item_k i;
    system("clr");
    int order_arr[50], quan[50], c = 0;
    float amt, damt, total = 0;
    char ch = 'Y';
    menu_k();
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
    cout << "\n\n\t-------------------INVOICE--------------" << endl;
    cout << "\nItemNo.\tName\tQuantity\tPrice\tAmount\tAmount After Discount" << endl;
    for (int x = 0; x <= c; x++)
    {
        f.open("store_lah.dat", ios::binary | ios::in);
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
void admin_menu_l()
{
    /* fstream f;
     item_k i;*/
    int ch2;
    do{
   
    cout << "\n\n\tLahore's MENU" << endl;
    cout << "\t1):-Create Item" << endl;
    cout << "\t2):-Display All Items" << endl;
    cout << "\t3):-Query" << endl;
    cout << "\t4):-Modify Item" << endl;
    cout << "\t5):-Delete Item" << endl;
    cout << "\t6):-Back To Main Menu" << endl;
    cout << "\t7):-LogOut" << endl;
    cout << "\n\nPlease Enter choice" << endl;
    cin >> ch2;
  //  do {
        switch (ch2)
        {
        case 1:
        {
            write_to_file_l();
            break;
        }
        case 2:
        {
            display_l();
            break;
        }
        case 3:
        {
            int num;
            cout << "\n\n\tPlease Enter The Item NUmber" << endl;
            cin >> num;
            display_sp_l(num);
            break;
        }
        case 4:
        {
            modify_l();
            break;
        }
        case 5:
        {
            delete_rec_l();
            break;
        }
        case 6:
        {
            menu_l();
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
            admin_menu_l();
        }
        }
    } while (ch2 !=7);
    
}

