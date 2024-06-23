/*
HAMNA ALIN AND HAMYAL
Project*/ 
#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
#include "..//Project_Grocery/Feedback.h"
using namespace std;
class Product {
public:
    int itemnm;
    char iname[50];
    float price, qnt, tax, dis;
    Product()
    {
        itemnm = 0;
        iname[50] = {};
        price = 0;
        qnt = 0;
        tax = 0;
        dis = 0;
    }
};
//class of product catalogue which inherits from the Product class
class Product_Catalogue :public Product
{
public:
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

    //FUNCTIONS FOR STORE KARACHI
    void getdata1()
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
    void showdata1()
    {
        cout << "Item #  : \t" << itemnm << endl;
        cout << "Item Name: \t" << iname << endl;
        cout << "Price : \t" << price << endl;
        cout << "Discount : \t" << dis << endl;
    }
    int getItemnm1()
    {
        return itemnm;
    }
    float getPrice1()
    {
        return price;
    }
    char* getname1()
    {
        return iname;
    }
    int getDis1()
    {
        return dis;
    }

    //FUNCTIONS FOR STORE KARACHI
    void getdata2()
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
    void showdata2()
    {
        cout << "Item #  : \t" << itemnm << endl;
        cout << "Item Name: \t" << iname << endl;
        cout << "Price : \t" << price << endl;
        cout << "Discount : \t" << dis << endl;
    }
    int getItemnm2()
    {
        return itemnm;
    }
    float getPrice2()
    {
        return price;
    }
    char* getname2()
    {
        return iname;
    }
    int getDis2()
    {
        return dis;
    }

}; // class ends of item
//fstream file;




// write in file of islamabad store
void write_to_file1()
{
    Product_Catalogue
        foo;
    fstream file;
    file.open("store.dat", ios::binary | ios::out | ios::app);
    foo.getdata();
    file.write((char*)&foo, sizeof(foo));
    file.close();
    cout << "The Items has been created.." << endl;
}

// write in file of Karachi store
void write_to_file1_K()
{
    Product_Catalogue
        foo;
    fstream file;
    file.open("store_kar.dat", ios::binary | ios::out | ios::app);
    foo.getdata1();
    file.write((char*)&foo, sizeof(foo));
    file.close();
    cout << "The Items has been created.." << endl;
}

// write in file of Lahore store
void write_to_file1_L()
{
    Product_Catalogue
        foo;
    fstream file;
    file.open("store_lah.dat", ios::binary | ios::out | ios::app);
    foo.getdata2();
    file.write((char*)&foo, sizeof(foo));
    file.close();
    cout << "The Items has been created.." << endl;
}


//DISPLAY ITEMS  OF ISLAMABAD STORE
void display1() // this function reads all records from the file
{
    Product_Catalogue
        foo;
    fstream file;
    cout << "\t\tDisplay all Records.!\n"
        << endl;
    file.open("store.dat", ios::binary | ios::in);
    while (file.read((char*)&foo, sizeof(foo)))
    {
        foo.showdata();
        cout << "\n\n=================================" << endl;
    }
    file.close();
}

//DISPLAY ITEMS  OF kARACHI STORE
void display1_K() // this function reads all records from the file
{
    Product_Catalogue
        foo;
    fstream file;
    cout << "\t\tDisplay all Records.!\n"
        << endl;
    file.open("store_kar.dat", ios::binary | ios::in);
    while (file.read((char*)&foo, sizeof(foo)))
    {
        foo.showdata1();
        cout << "\n\n=================================" << endl;
    }
    file.close();
}


//DISPLAY ITEMS  OF Lahore STORE
void display1_L() // this function reads all records from the file
{
    Product_Catalogue
        foo;
    fstream file;
    cout << "\t\tDisplay all Records.!\n"
        << endl;
    file.open("store_lah.dat", ios::binary | ios::in);
    while (file.read((char*)&foo, sizeof(foo)))
    {
        foo.showdata2();
        cout << "\n\n=================================" << endl;
    }
    file.close();
}

//Display Specific Item From ISLAMABAD Store
void display_sp1(int n) // function to read specific record from the file
{
    Product_Catalogue
        foo;
    fstream file;
    int flag = 0;
    file.open("store.dat", ios::binary | ios::in);
    while (file.read((char*)&foo, sizeof(foo)))
    {
        if (foo.getItemnm() == n)
        {
            foo.showdata();
            flag = 1;
        }
    }
    file.close();
    if (flag == 1)
    {
        cout << "Records does not Exist...`:(" << endl;
    }
}

//Display Specific Item From kARACHI Store
void display_sp1_K(int n) // function to read specific record from the file
{
    Product_Catalogue
        foo;
    fstream file;
    int flag = 0;
    file.open("store_kar.dat", ios::binary | ios::in);
    while (file.read((char*)&foo, sizeof(foo)))
    {
        if (foo.getItemnm1() == n)
        {
            foo.showdata1();
            flag = 1;
        }
    }
    file.close();
    if (flag == 1)
    {
        cout << "Records does not Exist...`:(" << endl;
    }
}

//Display Specific Item From Lahore Store
void display_sp1_L(int n) // function to read specific record from the file
{
    Product_Catalogue
        foo;
    fstream file;
    int flag = 0;
    file.open("store_lah.dat", ios::binary | ios::in);
    while (file.read((char*)&foo, sizeof(foo)))
    {
        if (foo.getItemnm2() == n)
        {
            foo.showdata2();
            flag = 1;
        }
    }
    file.close();
    if (flag == 1)
    {
        cout << "Records does not Exist...`:(" << endl;
    }
}

//modify items from the ISLAMABAD sTORE
void modify1()
{
    Product_Catalogue
        foo;
    fstream file;
    int no, found = 0;
    system("cls");
    cout << "\n\n\n\nTo Modify...." << endl;
    cout << "\n\n\nPlease Enter The Item Nm of Item.." << endl;
    cin >> no;
    file.open("store.dat", ios::binary | ios::in | ios::out);
    while (file.read((char*)&foo, sizeof(foo)) && found == 0)
    {
        if (foo.getItemnm() == no)
        {
            system("cls");
            foo.showdata();
            int pos = -1 * ((int)sizeof(foo));
            file.seekp(pos, ios::cur);
            file.write((char*)&foo, sizeof(foo));
            cout << "\t\tRecord Updated!" << endl;
            found = 1;
        }
    }
    file.close();
    if (found == 0)
    {
        cout << "\t\tRecord Not Found!!!!!!!!!" << endl;
    }
}


//modify items from the KARACHI sTORE
void modify1_K()
{
    Product_Catalogue
        foo;
    fstream file;
    int no, found = 0;
    system("cls");
    cout << "\n\n\n\nTo Modify...." << endl;
    cout << "\n\n\nPlease Enter The Item Nm of Item.." << endl;
    cin >> no;
    file.open("store_kar.dat", ios::binary | ios::in | ios::out);
    while (file.read((char*)&foo, sizeof(foo)) && found == 0)
    {
        if (foo.getItemnm1() == no)
        {
            system("cls");
            foo.showdata1();
            int pos = -1 * ((int)sizeof(foo));
            file.seekp(pos, ios::cur);
            file.write((char*)&foo, sizeof(foo));
            cout << "\t\tRecord Updated!" << endl;
            found = 1;
        }
    }
    file.close();
    if (found == 0)
    {
        cout << "\t\tRecord Not Found!!!!!!!!!" << endl;
    }
}


//modify items from the LAHORE sTORE
void modify1_L()
{
    Product_Catalogue
        foo;
    fstream file;
    int no, found = 0;
    system("cls");
    cout << "\n\n\n\nTo Modify...." << endl;
    cout << "\n\n\nPlease Enter The Item Nm of Item.." << endl;
    cin >> no;
    file.open("store_lah.dat", ios::binary | ios::in | ios::out);
    while (file.read((char*)&foo, sizeof(foo)) && found == 0)
    {
        if (foo.getItemnm2() == no)
        {
            system("cls");
            foo.showdata2();
            int pos = -1 * ((int)sizeof(foo));
            file.seekp(pos, ios::cur);
            file.write((char*)&foo, sizeof(foo));
            cout << "\t\tRecord Updated!" << endl;
            found = 1;
        }
    }
    file.close();
    if (found == 0)
    {
        cout << "\t\tRecord Not Found!!!!!!!!!" << endl;
    }
}


//DELETINg specific items from Islamabad STore
void delete_rec1()
{
    Product_Catalogue
        foo;
    fstream file;
    int no;
    system("cls");
    cout << "\t\t\tDelete Record" << endl;
    cout << "\n\n\nPlease Enter the item Nm of Item That u Want to Delete." << endl;
    cin >> no;
    file.open("store.dat", ios::binary | ios::in | ios::out);
    fstream f2;
    f2.open("temp.dat", ios::out);
    file.seekg(0, ios::beg);
    while (file.read((char*)&foo, sizeof(foo)));
    {
        if (foo.getItemnm() != no)
        {
            f2.write((char*)&foo, sizeof(foo));
        }
    }
    file.close();
    f2.close();
    remove("store.dat");
    rename("temp.dat", "store.dat");
    cout << "\n\n\t\tRecord Deleted!" << endl;
}

//DELETINg specific items from Karachi STore
void delete_rec1_K()
{
    Product_Catalogue
        foo;
    fstream file;
    int no;
    system("cls");
    cout << "\t\t\tDelete Record" << endl;
    cout << "\n\n\nPlease Enter the item Nm of Item That u Want to Delete." << endl;
    cin >> no;
    file.open("store_kar.dat", ios::binary | ios::in | ios::out);
    fstream f2;
    f2.open("temp_kar.dat", ios::out);
    file.seekg(0, ios::beg);
    while (file.read((char*)&foo, sizeof(foo)));
    {
        if (foo.getItemnm1() != no)
        {
            f2.write((char*)&foo, sizeof(foo));
        }
    }
    file.close();
    f2.close();
    remove("store_kar.dat");
    rename("temp_kar.dat", "store_kar.dat");
    cout << "\n\n\t\tRecord Deleted!" << endl;
}

//DELETINg specific items from Lahore STore
void delete_rec1_L()
{
    Product_Catalogue
        foo;
    fstream file;
    int no;
    system("cls");
    cout << "\t\t\tDelete Record" << endl;
    cout << "\n\n\nPlease Enter the item Nm of Item That u Want to Delete." << endl;
    cin >> no;
    file.open("store_lah.dat", ios::binary | ios::in | ios::out);
    fstream f2;
    f2.open("temp_lah.dat", ios::out);
    file.seekg(0, ios::beg);
    while (file.read((char*)&foo, sizeof(foo)));
    {
        if (foo.getItemnm2() != no)
        {
            f2.write((char*)&foo, sizeof(foo));
        }
    }
    file.close();
    f2.close();
    remove("store_lah.dat");
    rename("temp_lah.dat", "store_lah.dat");
    cout << "\n\n\t\tRecord Deleted!" << endl;
}

class Cart {
public:
    //cart of islamabad store
    void menu1()//function to display all products price list
    {
        Product_Catalogue
            foo;
        fstream file;
        system("cls");
        file.open("store.dat", ios::in);
        if (!file)
        {
            cout << "\t\tError 404 !File Could Not be Open\n\n\nGo to Admin Menu to Create File" << endl;
            cout << "\n\n\nProgram is Closing.." << endl;
            exit(0);

        }
        cout << "\n\n\t\tITEM MENU\n\n" << endl;
        cout << "==========================================================" << endl;
        cout << "ITEM_NO\t\tNAME\t\tPRICE" << endl;
        cout << "==========================================================" << endl;
        while (file.read((char*)&foo, sizeof(foo)))
        {
            cout << foo.getItemnm() << "\t\t" << foo.getname() << "\t\t" << foo.getPrice() << endl;
        }
        file.close();
    }
    //cart of KARACHI store
    void menu1_K()//function to display all products price list
    {
        Product_Catalogue
            foo;
        fstream file;
        system("cls");
        file.open("store_kar.dat", ios::in);
        if (!file)
        {
            cout << "\t\tError 404 !File Could Not be Open\n\n\nGo to Admin Menu to Create File" << endl;
            cout << "\n\n\nProgram is Closing.." << endl;
            exit(0);

        }
        space(40);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 90);
        cout << "<~~ MAIN MENU ~~>";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << endl
            << endl;
        cout << "==========================================================" << endl;
        cout << "ITEM_NO\t\tNAME\t\tPRICE" << endl;
        cout << "==========================================================" << endl;
        while (file.read((char*)&foo, sizeof(foo)))
        {
            cout << foo.getItemnm1() << "\t\t" << foo.getname1() << "\t\t" << foo.getPrice1() << endl;
        }
        file.close();
    }
    //Cart of LAhore Store
    void menu1_L()//function to display all products price list
    {
        Product_Catalogue
            foo;
        fstream file;
        system("cls");
        file.open("store_lah.dat", ios::in);
        if (!file)
        {
            cout << "\t\tError 404 !File Could Not be Open\n\n\nGo to Admin Menu to Create File" << endl;
            cout << "\n\n\nProgram is Closing.." << endl;
            exit(0);

        }
        space(40);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 90);
        cout << "<~~ MAIN MENU ~~>";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << endl
            << endl;
        cout << "==========================================================" << endl;
        cout << "ITEM_NO\t\tNAME\t\tPRICE" << endl;
        cout << "==========================================================" << endl;
        while (file.read((char*)&foo, sizeof(foo)))
        {
            cout << foo.getItemnm2() << "\t\t" << foo.getname2() << "\t\t" << foo.getPrice2() << endl;
        }
        file.close();
    }

};
//void menu1()//function to display all products price list
//{
//    fstream file;
//    Product_Catalogue foo;
//    system("cls");
//    file.open("store.dat", ios::in);
//    if (!file)
//    {
//        cout << "\t\tError 404 !File Could Not be Open\n\n\nGo to Admin Menu to Create File" << endl;
//        cout << "\n\n\nProgram is Closing.." << endl;
//        exit(0);
//
//    }
//    cout << "\n\n\t\tITEM MENU\n\n" << endl;
//    cout << "==========================================================" << endl;
//    cout << "ITEM_NO\t\tNAME\t\tPRICE" << endl;
//    cout << "==========================================================" << endl;
//    while (file.read((char*)&foo, sizeof(foo)))
//    {
//        cout << foo.getItemnm() << "\t\t" << foo.getname() << "\t\t" << foo.getPrice() << endl;
//    }
//    file.close();
//}
class Add_To_Cart : public Feedback,Cart {
public:
    float total = 0;
    //Billing pay;
    Feedback fb;
public:
    //ITS A PLACING ORDER CART FOR ISLAMABAD STORE
    void place_order1()//function to place order and generate bill
    {
        Product_Catalogue
            foo;
        fstream file;
        system("clr");
        int order_arr[50], quan[50], c = 0;
        float amt, damt; //, total = 0;
        char ch = 'Y';
        menu1();
        cout << "==========================================================" << endl;
        cout << "----------------------PLACE YOUR ORDER--------------------" << endl;
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
        system("cls");
        cout << "\n\n\tThank You For For Selecting Items.." << endl;
        space(40);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 90);
        cout << "<~~ INVOICE ~~>";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << endl
            << endl;
        cout << "\nItemNo.\tName\tQuantity\tPrice\tAmount\tAmount After Discount" << endl;
        for (int x = 0; x <= c; x++)
        {
            file.open("store.dat", ios::in);
            file.read((char*)&foo, sizeof(foo));
            while (!file.eof())
            {
                if (foo.getItemnm() == order_arr[x])
                {
                    amt = foo.getPrice() * quan[x];
                    damt = amt - (amt * foo.getDis() / 100);
                    cout << "\n" << order_arr[x] << "\t" << foo.getname() << "\t" << quan[x] << "\t\t" << foo.getPrice() << "\t" << amt << "\t\t" << damt << endl;
                    total += damt;
                }
                file.read((char*)&foo, sizeof(foo));
            }
            file.close();
        }
        cout << "\n\n\t\tTotal Bill : " << total << endl;
        cout << "\n\n\t\tHow Would You Pay Your Bill: " << endl;
        int choice;
        cout << "\tPress 1 :- For CASH" << endl;
        cout << "\tPress 2 :- For Online Banking" << endl;
        cout << "\tPress 3 :- If You SHop Online" << endl;
        cin >> choice;
        do {

            switch (choice)
            {
            case 1:
            {
                int cash;
                cout << "\nPlease Enter Amount" << endl;
                cin >> cash;
                while (cash < total)
                {
                    cout << "\nPlease Enter Correct Amount" << endl;
                    cin >> cash;
                }
                cash -= total;
              
                
                cout << "\n\tYour remaining Amount :- " << cash << endl;
                cout << "\n\t\tThank You For Shopping..." << endl;
                break;
            }
            case 2:
            {
                string bank_name;
                int acc_nm;
                int pin;
                //cout << "You Want to Pay " << endl;

                cout << "\n\t\tYOU WANT TO PAY THROUGH CARD\n" << endl;
                cout << "\tBank Name Please\n" << endl;
                cin >> bank_name;
                cout << "\tAccount Number Please\n" << endl;
                cin >> acc_nm;
                cout << "\tEnter PIN# Please\n" << endl;
                cin >> pin;
                cout << "\t-----------------------------------------------" << endl;
                cout << "\nAMOUNT HAS BEEN DEDUCTED FROM YOUR ACCOUNT" << endl;
                cout << "\n\tTHANK YOU FOR SHOPPING!  :)" << endl;

                break;
            }
            case 3:
            {
                int press;
                cout << "\n\tCASH ON DELIVERY CHARGES ON YOUR CITY IS 30\nON Other CITY IS 50" << endl;
                cout << "\n\tIF you Want to Deliver on YOur City Press 1 \n Else Press 2" << endl;
                cin >> press;
                switch (press)
                {
                case 1:
                {
                    total += 30;
                    cout << "\nYour Total Bill Is :- " << total << endl;
                    break;
                }
                case 2:
                {
                    total += 50;
                    cout << "\nYour Total Bill Is :- " << total << endl;
                    break;
                }
                default:
                {
                    cout << "Please Enter Valid Choice.." << endl;
                }
                }
            }
            default:
            {
                cout << "Please Enter Valid Choice" << endl;
                //cin >> choice;
            }
            }
        } while (choice >= 3);
    }

    //ITS A PLACING ORDER CART FROM KARACHI STORE
    void place_order1_K()//function to place order and generate bill
    {
        Product_Catalogue
            foo;
        fstream file;
        system("clr");
        int order_arr[50], quan[50], c = 0;
        float amt, damt; //, total = 0;
        char ch = 'Y';
        menu1_K();
        cout << "==========================================================" << endl;
        cout << "----------------------PLACE YOUR ORDER--------------------" << endl;
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
        system("cls");
        cout << "\n\n\tThank You For Shopping........" << endl;
        space(40);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 90);
        cout << "<~~ INVOICE ~~>";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << endl
            << endl;
        cout << "\nItemNo.\tName\tQuantity\tPrice\tAmount\tAmount After Discount" << endl;
        for (int x = 0; x <= c; x++)
        {
            file.open("store_kar.dat", ios::in);
            file.read((char*)&foo, sizeof(foo));
            while (!file.eof())
            {
                if (foo.getItemnm1() == order_arr[x])
                {
                    amt = foo.getPrice1() * quan[x];
                    damt = amt - (amt * foo.getDis1() / 100);
                    cout << "\n" << order_arr[x] << "\t" << foo.getname1() << "\t" << quan[x] << "\t\t" << foo.getPrice1() << "\t" << amt << "\t\t" << damt << endl;
                    total += damt;
                }
                file.read((char*)&foo, sizeof(foo));
            }
            file.close();
        }
        cout << "\n\n\t\tTotal Bill : " << total << endl;
        cout << "\n\n\t\tHow Would You Pay Your Bill: " << endl;
        int choice;
        cout << "\tPress 1 :- For CASH" << endl;
        cout << "\tPress 2 :- For Online Banking" << endl;
        cout << "\tPress 3 :- If You SHop Online" << endl;
        cin >> choice;
        do {

            switch (choice)
            {
            case 1:
            {
                int cash1;
                cout << "\nPlease Enter Amount" << endl;
                cin >> cash1;
                while (cash1 < total)
                {
                    cout << "\nPlease Enter Correct Amount" << endl;
                    cin >> cash1;
                }
              
                cash1 -= total;
                cout << "\n\tYour remaining Amount :- " << cash1 << endl;
                cout << "\n\t\tThank You For Shopping..." << endl;
                break;
            }
            case 2:
            {
                string bank_name;
                int acc_nm;
                int pin;
                //cout << "You Want to Pay " << endl;

                cout << "\n\t\tYOU WANT TO PAY THROUGH CARD\n" << endl;
                cout << "\tBank Name Please\n" << endl;
                cin >> bank_name;
                cout << "\tAccount Number Please\n" << endl;
                cin >> acc_nm;
                cout << "\tEnter PIN# Please\n" << endl;
                cin >> pin;
                cout << "\t-----------------------------------------------" << endl;
                cout << "\nAMOUNT HAS BEEN DEDUCTED FROM YOUR ACCOUNT" << endl;
                cout << "\n\tTHANK YOU FOR SHOPPING!  :)" << endl;

                break;
            }
            case 3:
            {
                int press;
                cout << "\n\tCASH ON DELIVERY CHARGES ON YOUR CITY IS 30\nON Other CITY IS 50" << endl;
                cout << "\n\tIF you Want to Deliver on YOur City Press 1 \n Else Press 2" << endl;
                cin >> press;
                switch (press)
                {
                case 1:
                {
                    total += 30;
                    cout << "\nYour Total Bill Is :- " << total << endl;
                    break;
                }
                case 2:
                {
                    total += 50;
                    cout << "\nYour Total Bill Is :- " << total << endl;
                    break;
                }
                default:
                {
                    cout << "Please Enter Valid Choice.." << endl;
                }
                }
                break;
            }
            default:
            {
                cout << "Please Enter Valid Choice" << endl;
               // cin >> choice;
            }
            }
        } while (choice >= 3);
    }

    //ITS A CART ADDIING FUNCTION FOR LAHORE STORE
    void place_order1_L()//function to place order and generate bill
    {
        Product_Catalogue
            foo;
        fstream file;
        system("clr");
        int order_arr[50], quan[50], c = 0;
        float amt, damt; //, total = 0;
        char ch = 'Y';
        menu1_L();
        cout << "==========================================================" << endl;
        cout << "----------------------PLACE YOUR ORDER--------------------" << endl;
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
        system("cls");
        cout << "\n\n\tThank You For SHopping.." << endl;
        space(40);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 90);
        cout << "<~~ INVOICE ~~>";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << endl
            << endl;
        cout << "\nItemNo.\tName\tQuantity\tPrice\tAmount\tAmount After Discount" << endl;
        for (int x = 0; x <= c; x++)
        {
            file.open("store_lah.dat", ios::in);
            file.read((char*)&foo, sizeof(foo));
            while (!file.eof())
            {
                if (foo.getItemnm2() == order_arr[x])
                {
                    amt = foo.getPrice2() * quan[x];
                    damt = amt - (amt * foo.getDis2() / 100);
                    cout << "\n" << order_arr[x] << "\t" << foo.getname2() << "\t" << quan[x] << "\t\t" << foo.getPrice2() << "\t" << amt << "\t\t" << damt << endl;
                    total += damt;
                }
                file.read((char*)&foo, sizeof(foo));
            }
            file.close();
        }
        cout << "\n\n\t\tTotal Bill : " << total << endl;
        cout << "\n\n\t\tHow Would You Pay Your Bill: " << endl;
        int choice;
        cout << "\tPress 1 :- For CASH" << endl;
        cout << "\tPress 2 :- For Online Banking" << endl;
        cout << "\tPress 3 :- If You Shop Online" << endl;
        cin >> choice;
        do {

            switch (choice)
            {
            case 1:
            {
                int cash;
                cout << "\nPlease Enter Amount" << endl;
                cin >> cash;

                while (cash < total)
                {
                    cout << "\nPlease Enter Correct Amount" << endl;
                    cin >> cash;
                }
                cash -= total;
                cout << "\n\tYour remaining Amount :- " << cash << endl;
                cout << "\n\t\tThank You For Shopping..." << endl;
                break;
            }
            case 2:
            {
                string bank_name;
                int acc_nm;
                int pin;
                //cout << "You Want to Pay " << endl;

                cout << "\n\t\tYOU WANT TO PAY THROUGH CARD\n" << endl;
                cout << "\tBank Name Please\n" << endl;
                cin >> bank_name;
                cout << "\tAccount Number Please\n" << endl;
                cin >> acc_nm;
                cout << "\tEnter PIN# Please\n" << endl;
                cin >> pin;
                cout << "\t-----------------------------------------------" << endl;
                cout << "\nAMOUNT HAS BEEN DEDUCTED FROM YOUR ACCOUNT" << endl;
                cout << "\n\tTHANK YOU FOR SHOPPING!  :)" << endl;

                break;
            }
            case 3:
            {
                int press;
                cout << "\n\tCASH ON DELIVERY CHARGES ON YOUR CITY IS 30\nON Other CITY IS 50" << endl;
                cout << "\n\tIF you Want to Deliver on YOur City Press 1 \n Else Press 2" << endl;
                cin >> press;
                switch (press)
                {
                case 1:
                {
                    total += 30;
                    cout << "\nYour Total Bill Is :- " << total << endl;
                    break;
                }
                case 2:
                {
                    total += 50;
                    cout << "\nYour Total Bill Is :- " << total << endl;
                    break;
                }
                default:
                {
                    cout << "Please Enter Valid Choice.." << endl;
                }
                }
            }
            default:
            {
                cout << "Please Enter Valid Choice" << endl;
               // cin >> choice;
            }
            }
        } while (choice >= 3);
    }
};
//Class of billing which cal the invoice of your bill
class Billing {
public:
    string bank_name;
    int acc_nm;
    int pin;
    void onlinePay()
    {
        cout << "\n\t\tYOU WANT TO PAY THROUGH CARD\n" << endl;
        cout << "\tBank Name Please\n" << endl;
        cin >> bank_name;
        cout << "\tAccount Number Please\n" << endl;
        cin >> acc_nm;
        cout << "\tEnter PIN# Please\n" << endl;
        cin >> pin;
        cout << "\t-----------------------------------------------" << endl;
        cout << "\nAMOUNT HAS BEEN DEDUCTED FROM YOUR ACCOUNT" << endl;
        cout << "\n\tTHANK YOU FOR SHOPPING!  :)" << endl;

    }

};
//ITS A WHOLE STORE MENU INFRONT OF THE ADMINISTRATOR(islamabad)
void store_menu1()
{
    Feedback pay;
   Cart obj;
    int ch2;
    do
    {
        space(40);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 90);
        cout << "<~~ ADMIN MAIN MENU ~~>";
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
        cout << "\t8):-LogOut" << endl;
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
           obj.menu1();
            break;
        }
        case 7:
        {
            exit(0);
            break;
        }
        case 8:
        {
            pay.display_feedback();
            break;
        }
        default:
        {
            cout << "\a";
            store_menu1();
        }
        }
    } while (ch2 != 8);

}


//ITS A WHOLE MENU OPERATOR FOR THE KARACHI sTORE

void store_menu1_K()
{
    Feedback pay;
    Cart obj;
    int ch2;
    do
    {
        space(40);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 90);
        cout << "<~~ ADMIN MAIN MENU ~~>";
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
        cout << "\t8):-LogOut" << endl;
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
            obj.menu1_K();
            break;
        }
        case 7:
        {
            exit(0);
            break;
        }
        case 8:
        {
            pay.display_feedback();
            break;
        }
        default:
        {
            cout << "\a";
            store_menu1_K();
        }
        }
    } while (ch2 != 8);

}

//ITS A WHOLE OPERATUION FOR THE lAHORE STORE

void store_menu1_L()
{
    Feedback pay;
    Cart obj;
    int ch2;
    do
    {
        space(40);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 90);
        cout << "<~~ ADMIN MAIN MENU ~~>";
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
        cout << "\t8):-LogOut" << endl;
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
            obj.menu1_L();
            break;
        }
        case 7:
        {
            exit(0);
            break;
        }
        case 8:
        {
            pay.display_feedback();
            break;
        }
        default:
        {
            cout << "\a";
            store_menu1_L();
        }
        }
    } while (ch2 != 8);

}