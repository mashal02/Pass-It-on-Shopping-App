#include <iostream>
#include "Innventory.h"
#include <string>
#include "ProjFunctions.h"
using namespace std;

//setters
void product::setprod_name(string x)
{
    prod_name = x;
}
void product::setprice(double x)
{
    price = x;
}

void product::setseller(string x)
{
    seller = x;
}
void product::setdescript()
{

    ofstream outfile;
    outfile.open("product.txt", ios_base::app);
    outfile << "Description: ";
    cout << "\x1b[93;96m*****Description of Product***\n\x1b[35;1mEnter any ten words that best describe your product.Consider the concept of\nInstagram hashtags, these will help in boosting/promoting your product.\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "\nTag no." << i + 1 << endl;
        cin >> description[i];
        lowercase(description[i]);
        outfile << description[i] << " ";
    }
    outfile.close();
}
void product::setcategory(string x)
{
    category = x;
}

//getters
string product::getprod_name()
{
    return prod_name;
}
double product::getprice()
{
    return price;
}
string product::getseller()
{
    return seller;
}
string* product::getdescript()
{
    return description;
}
string product::getcategory()
{
    return category;
}

void clothes::setsize(string x)
{
    size = x;
}
string clothes::getsize()
{
    return size;
}


void product::display_details()
{
    
    cout << "\n\n\n\n\x1b[93;96mProduct ID: \x10 \x1b[35;1m" << id<< "\x1b[0;m" << endl;
    cout << "\t  \x1b[93;48m\x12\n";
    cout << "\x1b[95;48m ***** Product details  ***** \x1b[0m";
    cout << "\n\x1b[93;96mName: \x10 \x1b[35;1m" << getprod_name()<<"\x1b[0;m" << endl;
    cout << "\x1b[93;96mPrice: \x10 \x1b[35;1m" << price << "\x1b[0;m" << endl;
    cout << "\x1b[93;96mDescription: \x10 \x1b[35;1m" << "\x1b[0;m" << endl;
    string* desc = getdescript();
    for (int i = 0; i < 10; i++)
    {
        cout<<"\x1b[95;91m  \x14  " << desc[i] <<endl;
    }

    cout << "\x1b[93;96mCategory: \x10 \x1b[35;1m" << getcategory() << "\x1b[0;m" << endl;

    cout << "\x1b[93;96mSeller name: \x10 \x1b[35;1m" << seller << "\x1b[0;m" << endl;


}

void product::input_productdata()
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
        id = 1;
        prod_id = 1;                          // if file is empty or "word" doesn't exist, set the prod_id to 1
    }
    else                                    // if latest prod_id_string was fetched then extract the number(prod_id) from the string
    {                                        //e.g prod_id_string is Product ID: 2, now we will erase Product ID to only get 2

        string::size_type i = prod_id_string.find(word);  //e.g calculating now size of "Product ID:" from "Product ID:2"
        if (i != string::npos)                           //if it is valid size
            prod_id_string.erase(i, word.length());      // then we erase "Product ID:" in order to get 2 only
        prod_id = stoi(prod_id_string) + 1;              // stoi converting from string to int //then we increment our prod_id by 1 that we required
        id = prod_id;
    }



    ofstream outfile;
    outfile.open("product.txt", ios_base::app);

    string i_name, i_size, i_seller, i_descrip[5], i_agegrp;  // input variables
    double i_price;
    string i_category;


    cout << "\n***Enter product details***";

    cout << "\nProduct ID: " << prod_id;
    cout << "\nEnter Name of your Product.Make it short yet descriptive and catchy to attract buyers!: ";
    cin.ignore();
    getline(cin, i_name);
    setprod_name(i_name);


    cout << "\nEnter Price: ";
    cin >> i_price;
    while (i_price < 0)
    {
        cout << "\nInvalid price, Enter again.";
        cout << "\nEnter Price: ";
        cin >> i_price;

    }
    setprice(i_price);

    setdescript();

    cout << "\nEnter Seller name: ";
    cin.ignore();
    getline(cin, i_seller);
    setseller(i_seller);
    outfile << "Seller Name: " << i_seller << endl;

    outfile << "Product ID: " << prod_id;

    outfile << "\nProduct Name: " << i_name << endl;
    outfile << "Price " << i_price << endl;
    outfile.close();
}

void product::read_file()
{
    cout << "\nReading from the file\n";
    //open a file in read mode.
    ifstream infile;
    infile.open("product.txt");
    string readfile;
    while (getline(infile, readfile))
    {
        cout << readfile << "\n";
    }
}


void clothes::input_productdata()
{
    string i_size;
    product::input_productdata();
    ofstream outfile;
    outfile.open("product.txt", ios_base::app);
    cout << "Enter Size: (small/S,medium/M,large/L)\n";
    cin >> i_size;
    while ((i_size != "small") && (i_size != "S") && (i_size != "medium") && (i_size != "M") && (i_size != "large") && (i_size != "L"))

    {
        cout << "Invalid size, Input again.";
        cout << "\nEnter Size: ";
        cin >> i_size;

    }
    setsize(i_size);
    outfile << "Size: " << i_size << endl;

}


void gadgets::set_usage(int  use)
{
    used = use;
}

int gadgets::get_usage()
{
    return used;
}


void gadgets::input_productdata()
{
    product::input_productdata();
    int use;
    cout << "\nEnter duration of usage (in months) : ";
    cin >> use;
    set_usage(use);

}

void gadgets::display_details()
{
    product::display_details();
    cout << "\x1b[93;96mDuration of usage:(In months) \x10 \x1b[35;1m" << get_usage() <<"\x1b[0;m" << endl;

}

void shoes::set_shoes_size(int shsize)
{
    shoe_size = shsize;
}
int shoes::get_shoes_size()
{
    return shoe_size;
}

void shoes::input_productdata()
{
    int sh_size;
    product::input_productdata();
    ofstream outfile;
    outfile.open("product.txt", ios_base::app);
    cout << "Enter Size: (6-11)";
    cin >> sh_size;
    while (sh_size > 11 || sh_size < 6)

    {
        cout << "Invalid size, Input again.";
        cout << "\nEnter Size: (6-11)";
        cin >> sh_size;

    }
    set_shoes_size(sh_size);
    outfile << "Size: " << sh_size << endl;
}

ostream& operator<<(ostream& os, const product& product)
{
    string::size_type length;
    os.write(reinterpret_cast<const char*>(&product.id), sizeof(product.id));

    length = product.prod_name.size();
    os.write(reinterpret_cast<char*>(&length), sizeof(length));
    os << product.prod_name;
    os.write(reinterpret_cast<const char*>(&product.price), sizeof(product.price));
    length = product.seller.size();
    os.write(reinterpret_cast<char*>(&length), sizeof(length));
    os << product.seller;
    for (int i = 0; i < 10; i++)
    {
        length = product.description[i].size();
        os.write(reinterpret_cast<char*>(&length), sizeof(length));
        os << product.description[i];
    }

    length = product.category.size();
    os.write(reinterpret_cast<char*>(&length), sizeof(length));
    os << product.category;
    return os;
}

istream& operator>>(istream& is, product& product)
{
    string::size_type length;
    is.read(reinterpret_cast<char*>(&product.id), sizeof(product.id));

    is.read(reinterpret_cast<char*>(&length), sizeof(length));
    product.prod_name.clear();
    for (string::size_type i = 0; i < length; i++)
    {
        char c = is.get();
        product.prod_name.push_back(c);
    }
    is.read(reinterpret_cast<char*>(&product.price), sizeof(product.price));

    is.read(reinterpret_cast<char*>(&length), sizeof(length));
    product.seller.clear();
    for (string::size_type i = 0; i < length; i++)
    {
        char c = is.get();
        product.seller.push_back(c);
    }
    for (int j = 0; j < 10; j++)
    {
        is.read(reinterpret_cast<char*>(&length), sizeof(length));
        product.description[j].clear();
        for (string::size_type i = 0; i < length; i++)
        {
            char c = is.get();
            product.description[j].push_back(c);
        }
    }
    is.read(reinterpret_cast<char*>(&length), sizeof(length));
    product.category.clear();
    for (string::size_type i = 0; i < length; i++)
    {
        char c = is.get();
        product.category.push_back(c);
    }
    return is;
}


//  OVERRIDING FOR SHOES

ostream& operator<<(ostream& os, const shoes& shoes)
{
    string::size_type length;
    os.write(reinterpret_cast<const char*>(&shoes.id), sizeof(shoes.id));
    length = shoes.prod_name.size();
    os.write(reinterpret_cast<char*>(&length), sizeof(length));
    os << shoes.prod_name;
    os.write(reinterpret_cast<const char*>(&shoes.price), sizeof(shoes.price));
    length = shoes.seller.size();
    os.write(reinterpret_cast<char*>(&length), sizeof(length));
    os << shoes.seller;
    for (int i = 0; i < 10; i++)
    {
        length = shoes.description[i].size();
        os.write(reinterpret_cast<char*>(&length), sizeof(length));
        os << shoes.description[i];
    }

    length = shoes.category.size();
    os.write(reinterpret_cast<char*>(&length), sizeof(length));
    os << shoes.category;
    os.write(reinterpret_cast<const char*>(&shoes.shoe_size), sizeof(shoes.shoe_size));
    return os;
}

istream& operator>>(istream& is, shoes& shoes)
{
    string::size_type length;

    is.read(reinterpret_cast<char*>(&shoes.id), sizeof(shoes.id));

    is.read(reinterpret_cast<char*>(&length), sizeof(length));
    shoes.prod_name.clear();
    for (string::size_type i = 0; i < length; i++)
    {
        char c = is.get();
        shoes.prod_name.push_back(c);
    }
    is.read(reinterpret_cast<char*>(&shoes.price), sizeof(shoes.price));

    is.read(reinterpret_cast<char*>(&length), sizeof(length));
    shoes.seller.clear();
    for (string::size_type i = 0; i < length; i++)
    {
        char c = is.get();
        shoes.seller.push_back(c);
    }

    for (int j = 0; j < 10; j++)
    {
        is.read(reinterpret_cast<char*>(&length), sizeof(length));
        shoes.description[j].clear();
        for (string::size_type i = 0; i < length; i++)
        {
            char c = is.get();
            shoes.description[j].push_back(c);
        }
    }

    is.read(reinterpret_cast<char*>(&length), sizeof(length));
    shoes.category.clear();
    for (string::size_type i = 0; i < length; i++)
    {
        char c = is.get();
        shoes.category.push_back(c);
    }

    is.read(reinterpret_cast<char*>(&shoes.shoe_size), sizeof(shoes.shoe_size));

    return is;
}



// Overriding the Operator Overloaders for clothes
ostream& operator<<(ostream& os, const clothes& clothes)
{
    string::size_type length;
    os.write(reinterpret_cast<const char*>(&clothes.id), sizeof(clothes.id));
    length = clothes.prod_name.size();
    os.write(reinterpret_cast<char*>(&length), sizeof(length));
    os << clothes.prod_name;
    os.write(reinterpret_cast<const char*>(&clothes.price), sizeof(clothes.price));
    length = clothes.seller.size();
    os.write(reinterpret_cast<char*>(&length), sizeof(length));
    os << clothes.seller;
    for (int i = 0; i < 10; i++)
    {
        length = clothes.description[i].size();
        os.write(reinterpret_cast<char*>(&length), sizeof(length));
        os << clothes.description[i];
    }

    length = clothes.category.size();
    os.write(reinterpret_cast<char*>(&length), sizeof(length));
    os << clothes.category;
    length = clothes.size.size();
    os.write(reinterpret_cast<char*>(&length), sizeof(length));
    os << clothes.size;

    return os;
}

istream& operator>>(istream& is, clothes& clothes)
{
    string::size_type length;

    is.read(reinterpret_cast<char*>(&clothes.id), sizeof(clothes.id));

    is.read(reinterpret_cast<char*>(&length), sizeof(length));
    clothes.prod_name.clear();
    for (string::size_type i = 0; i < length; i++)
    {
        char c = is.get();
        clothes.prod_name.push_back(c);
    }
    is.read(reinterpret_cast<char*>(&clothes.price), sizeof(clothes.price));

    is.read(reinterpret_cast<char*>(&length), sizeof(length));
    clothes.seller.clear();
    for (string::size_type i = 0; i < length; i++)
    {
        char c = is.get();
        clothes.seller.push_back(c);
    }

    for (int j = 0; j < 10; j++)
    {
        is.read(reinterpret_cast<char*>(&length), sizeof(length));
        clothes.description[j].clear();
        for (string::size_type i = 0; i < length; i++)
        {
            char c = is.get();
            clothes.description[j].push_back(c);
        }
    }

    is.read(reinterpret_cast<char*>(&length), sizeof(length));
    clothes.category.clear();
    for (string::size_type i = 0; i < length; i++)
    {
        char c = is.get();
        clothes.category.push_back(c);
    }

    is.read(reinterpret_cast<char*>(&length), sizeof(length));
    clothes.size.clear();
    for (string::size_type i = 0; i < length; i++)
    {
        char c = is.get();
        clothes.size.push_back(c);
    }

    return is;
}










































// Overriding the Operator Overloaders for gadgets
ostream& operator<<(ostream& os, const gadgets& gadgets)
{
    string::size_type length;
    os.write(reinterpret_cast<const char*>(&gadgets.id), sizeof(gadgets.id));
    length = gadgets.prod_name.size();
    os.write(reinterpret_cast<char*>(&length), sizeof(length));
    os << gadgets.prod_name;
    os.write(reinterpret_cast<const char*>(&gadgets.price), sizeof(gadgets.price));
    length = gadgets.seller.size();
    os.write(reinterpret_cast<char*>(&length), sizeof(length));
    os << gadgets.seller;
    for (int i = 0; i < 10; i++)
    {
        length = gadgets.description[i].size();
        os.write(reinterpret_cast<char*>(&length), sizeof(length));
        os << gadgets.description[i];
    }

    length = gadgets.category.size();
    os.write(reinterpret_cast<char*>(&length), sizeof(length));
    os << gadgets.category;
    os.write(reinterpret_cast<const char*>(&gadgets.used), sizeof(gadgets.used));
    return os;
}

istream& operator>>(istream& is, gadgets& gadgets)
{
    string::size_type length;

    is.read(reinterpret_cast<char*>(&gadgets.id), sizeof(gadgets.id));

    is.read(reinterpret_cast<char*>(&length), sizeof(length));
    gadgets.prod_name.clear();
    for (string::size_type i = 0; i < length; i++)
    {
        char c = is.get();
        gadgets.prod_name.push_back(c);
    }
    is.read(reinterpret_cast<char*>(&gadgets.price), sizeof(gadgets.price));

    is.read(reinterpret_cast<char*>(&length), sizeof(length));
    gadgets.seller.clear();
    for (string::size_type i = 0; i < length; i++)
    {
        char c = is.get();
        gadgets.seller.push_back(c);
    }

    for (int j = 0; j < 10; j++)
    {
        is.read(reinterpret_cast<char*>(&length), sizeof(length));
        gadgets.description[j].clear();
        for (string::size_type i = 0; i < length; i++)
        {
            char c = is.get();
            gadgets.description[j].push_back(c);
        }
    }

    is.read(reinterpret_cast<char*>(&length), sizeof(length));
    gadgets.category.clear();
    for (string::size_type i = 0; i < length; i++)
    {
        char c = is.get();
        gadgets.category.push_back(c);
    }

    is.read(reinterpret_cast<char*>(&gadgets.used), sizeof(gadgets.used));

    return is;
}