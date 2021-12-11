#include <iostream>
#include <fstream>
#include "Innventory.h"
#include "ProjFunctions.h"
#include <string>
#include <math.h>
using namespace std;
int getlatest();
int main()
{
    double pprice[4];
   // welcomescreen();
    while (1)
    {
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\x1b[92;93m\x2  \x1b[94;7m 1 \x1b[0m \x1b[92;96m Want to buy something?\x1b[0m";
        cout << "\n\n\n\n\t\t\t\t\t\x1b[92;93m\x2  \x1b[94;7m 2 \x1b[0m \x1b[92;96m Or are you here to sell something of your own?\x1b[0m";
        int bos;
        cin >> bos;
        while (bos != 1 && bos != 2)
        {
            cout << "\x1b[90;31m\n      : (    Invalid Option.Enter again.\x1b[90;92m";
            cin >> bos;
        }
        system("cls");
        if (bos == 1)
        {
            cout << "\n\n\n\n\n\n\t\t\t\t\x1b[99;41m 1- \x1b[0m\x1b[94;33m Looking for something specific? Search for it and let us see if we have it in store!\x1b[0m\n\n\t\t\t\t\x1b[99;41m 2- \x1b[0m\x1b[94;33m Not sure what you want? Let us guide you through.\x1b[0m\n\n\t\t\t\t\x1b[99;41m 3- \x1b[0m\x1b[94;33m See all products, you'll surely find SOMETHING. \x1b[0m\n\n\t\t\t\t\x1b[99;41m 4- \x1b[0m\x1b[94;33m See things we picked ourselves specifically for YOU!\x1b[0m\n ";
            int choice; cin >> choice;
            while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
            {
                cout << "\x1b[90;31m\n      : (    Invalid Option.Enter again.\x1b[90;92m";
                cin >> choice;

            }
            if (choice == 1)
            {
                system("cls");
                product searchh; cin.ignore();
                ifstream ff("txt.txt", ios::in);
                cout << "\n\n\n\n\t\t\t  \x1b[95;3mWhat are you looking for?\n\t\tType it out and we'll see if we have it in store \x1b[92;93m\x2  \x1b[0m\n";
                string searchword;
                cin >> searchword;
                search(searchword, 1);
                continue;
            }
            else if (choice == 2)
            {
                system("cls");
                cout << "\n\n\n\t\t\t\t\t\t\x1b[96;96m\x1b[97;41m M  E  N  U \x1b[0m\n\x1b[96;5m\n        \x1b[0m";
                cout << "\n\t\t  \x1b[97;41m \x3 \x1b[0m\x1b[98;23m1- Clothes\t \x1b[97;41m \x4 \x1b[0m 2- Shoes \t \x1b[97;41m \x5 \x1b[0m 3- Gadgets \t\x1b[97;41m \x6 \x1b[0m 4- Others\x1b[0m\n";
                int menu;
                cin >> menu;
                while (menu > 4 || menu < 1)
                {
                    cout << "\x1b[90;31m\n      : (    Invalid Option.Enter again.\x1b[90;92m";
                    cin >> menu;
                }
                if (menu == 1)
                {
                    search("Clothes", 2);
                }
                else if (menu == 2)
                {
                    search("Shoes", 2);
                }
                else if (menu == 3)
                {
                    search("Gadgets", 2);
                }
                else if (menu == 4)
                {
                    search("Others", 2);
                }

            }
            else if (choice == 3)
            {

                int temp = getlatest();  //how many objects to read
                ifstream f2("txt.txt", ios::in);   //opening inventory
                double run;
                run = (double)temp / 4;
                int y = floor(run);

                for (int p = 0; p < y; p++)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        string cat = "Shoes";
                        getline(f2, cat);
                        string s = "Shoes"; string c = "Clothes";  string g = "Gadget";


                        if (s == cat)
                        {
                            shoes p;
                            f2 >> p;

                            p.display_details();
                            pprice[i] = p.price;

                        }
                        else if (c == cat)
                        {
                            clothes p;
                            f2 >> p;
                            p.display_details();

                            pprice[i] = p.price;

                        }

                        else if (cat == g)
                        {
                            gadgets p;
                            f2 >> p;
                            p.display_details();
                            pprice[i] = p.price;
                        }
                        else
                        {
                            product p;
                            f2 >> p;
                            p.display_details();
                            pprice[i] = p.price;
                        }

                        // else prod->display_details();
                         //        f2.close();
                    }

                    cout << "\nPress 1-4 to buy relevant item. Press 5 to continue to next page.\n";
                    int view;
                    cin >> view;
                    system("cls");
                    while (view >= 1 && view <= 4)
                    {

                        addtocart(pprice[view - 1]);
                        cout << "\nItem Added to cart.\nCurren Bill: " << bill << "\nPress 1-4 to continue Shopping from same page.\nPress 5 to Checkout.Press any other number to continue Shopping.\n";
                        int f;
                        cin >> f;
                        if (f == 5)
                        {
                            checkout();
                        }
                         if (f >= 1 && f <= 4)
                        {
                            view = f;
                        }
                        // else if (f == -1) { break; }
                        else { view = 5; }
                    }
                    if (view == 5)
                    {
                        continue;

                    }
                    system("cls");
                    f2.close();
                }
            }


            else if (choice == 4)
            {

                search_acc_to_history();

            }
        }
        else if (bos == 2)
        {
            int option; string categ;
            cout << "What kind of product do you wish to sell?  Press relevant number.";
            cout << "\n1. Clothes\n2.Gadgets\n3.Shoes\n4.Other ";
            cin >> option;
            if (option == 1)
            {
                clothes c1;

                ofstream f("txt.txt", ios::app);
                c1.input_productdata();
                f << "Clothes" << endl;
                f << c1;
                f.close();
            }
            else if (option == 2)
            {
                gadgets g1;

                ofstream f("txt.txt", ios::app);
                g1.input_productdata();
                f << "Gadget" << endl;
                f << g1;
                f.close();
            }
            else if (option == 3)
            {
                shoes s1;

                ofstream f("txt.txt", ios::app);
                s1.input_productdata();
                f << "Shoes" << endl;
                f << s1;
                f.close();
            }

            else if (option == 4)
            {
                ofstream f("txt.txt", ios::app);
                product testing;

                testing.input_productdata();
                f << "Other" << endl;
                f << testing;
                f.close();
            }

        }

        cout << "\nPress 1 to exit. Any other number to go back to home page. \x1b[98;33m\x2";
        cin >> bos;
        system("cls");
        if (bos == 1)
        {
            system("cls");
            break;
        }


    }
}


int getlatest()
{
    int prod_id;
    //reading the file here before, in order to get the latest product id and then increment it with 1 for the next product id
    ifstream ifs("product.txt");

    string word = "Product ID: ";      //to be searched in file
    string line;                       //each file to be fetched in file reading
    string prod_id_string = "a";    //initilized it with "a" just to check if there is already any "word" in that file
    while (getline(ifs, line))
    {
        int pos = line.find(word);     //getting positon of "word" in that fetched "line"
        //"npos" means no position
        if (pos != string::npos)       // checks whether position is valid or not  (-1 means not valid so "word" not existing)
            prod_id_string = line;    //prod_id_string = Product ID: ID of the last product from the file

    }

    if (prod_id_string == "a") {

        prod_id = 1;                          // if file is empty or "word" doesn't exist, set the prod_id to 1
    }
    else                                    // if latest prod_id_string was fetched then extract the number(prod_id) from the string
    {                                        //e.g prod_id_string is Product ID: 2, now we will erase Product ID to only get 2
        string::size_type i = prod_id_string.find(word);  //e.g calculating now size of "Product ID:" from "Product ID:2"
        if (i != string::npos)                           //if it is valid size
            prod_id_string.erase(i, word.length());      // then we erase "Product ID:" in order to get 2 only
        prod_id = stoi(prod_id_string);              // stoi converting from string to int //then we increment our prod_id by 1 that we required

    }
    return prod_id;
}