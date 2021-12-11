#include <iostream>
#include <fstream>
using namespace std;


class product
{
public:
    int id;

    string prod_name;
    double price;
    string seller;
    string description[10];
    string category;

    product()
    {
        category = "Others";
    }

    void setseller(string);
    void setdescript();
    void setprod_name(string);
    void setprice(double);
    void setcategory(string);


    string getcategory();
    string getprod_name();
    double getprice();
    string getseller();
    string* getdescript();

    virtual void display_details();

    virtual void input_productdata();
    void read_file();


    friend ostream& operator <<(ostream& os, const product& product);
    friend istream& operator >>(istream& is, product& product);
};


class clothes :public product
{
public:
    string size;
    void setsize(string);
    string getsize();

    clothes()
    {
        category = "Clothes";
    }

    void input_productdata() override;
    void display_details() override
    {
        product::display_details();
        cout << "\x1b[93;96mSize: \x10 \x1b[35;1m" << getsize() << "\x1b[0;m" << endl;

    }
    friend ostream& operator <<(ostream& os, const clothes& clothes);
    friend istream& operator >>(istream& is, clothes& clothes);
};


class gadgets :public product
{

public:
    int used;   //used for how many months
    gadgets()
    {
        category = "Gadgets";
    }
    void set_usage(int);
    int get_usage();

    void input_productdata() override;
    void display_details() override;

    friend ostream& operator <<(ostream& os, const gadgets& gadgets);
    friend istream& operator >>(istream& is, gadgets& gadgets);
};

class shoes :public product
{

public:
    shoes()
    {
        category = "Shoes";
    }

    int shoe_size = 0;
    void set_shoes_size(int);
    int get_shoes_size();
    void input_productdata() override;
    void display_details() override
    {
        product::display_details();
        cout << "\x1b[93;96mShoes size: \x10 \x1b[35;1m" << get_shoes_size() << "\x1b[0;m" << endl;
    }
    friend ostream& operator <<(ostream& os, const shoes& shoes);
    friend istream& operator >>(istream& is, shoes& shoes);
};
