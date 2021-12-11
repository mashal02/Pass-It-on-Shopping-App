#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

static double bill = 0;
extern class personprofile
{
public:
	string name, password;
	string  country, bank_acc;
	int  age;
	long long phone_no;
};

inline int countDigit(long long n)   // to count digits of phone number
{
	int count = 0;
	while (n != 0)
	{
		n = n / 10;
		++count;
	}
	return count;
}

inline void Signup()
{
	personprofile user;


	cout << "\x1b[96;32m\n\n\n\n\n\t *  Get Started, to have the most amazing Shopping Experience. *\n\n";
	cout << "\tEnter username. Use the same format as Instagram \n\t(Don't use spaces. Use underscores,numbers etc.)\x1b[96;31m\n";
	ofstream outAccounts("User.txt", ios::out);
	cin >> user.name;
	cout << "\n\x1b[96;32mEnter Password\n\x1b[96;31m";
	cin >> user.password;

	cout << "\n\x1b[96;32mEnter age: \n\x1b[96;31m";
	cin >> user.age;
	cout << "\n\x1b[96;32mEnter Country: \n\x1b[96;32m";
	cin >> user.country;
	cout << "\n\x1b[96;32mEnter Phone number: \x1b[96;31m 0";
	cin >> user.phone_no;

	int a = countDigit(user.phone_no);
	while (a != 10)
	{
		cout << "Invalid value.";
		cout << "\n\x1b[96;32mEnter Phone number: \x1b[96;31m 0";
		cin >> user.phone_no;
		a = countDigit(user.phone_no);
	}
	cout << "\n\x1b[96;32mEnter Bank Account Title: \n\x1b[96;31m";
	cin >> user.bank_acc;
	outAccounts << user.name << "  " << user.password << " " << user.age << " 0" << user.country << "  " << user.phone_no << " " << user.bank_acc;


}
inline personprofile Login()
{
	system("cls");
	cout << "\n\n\n\t\t\t\x1b[96;7m      LOGIN  SCREEN     \x1b[0m\n";
	ifstream inAccounts("User.txt", ios::in);
	personprofile person;
	inAccounts >> person.name >> person.password;     //The username and password in file has been saved in variables 'user' and 'pass'
	string loginname; string loginpass;
	cout << "\n\n\x1b[96;32mEnter Username.\n\x1b[96;33m";
	cin >> loginname;
	cout << "\n\x1b[96;32mEnter Password.\n\x1b[95;33m";
	cin >> loginpass;


	while (loginname.compare(person.name) != 0 || loginpass.compare(person.password) != 0)
	{

		if (loginname.compare(person.name) != 0)
			cout << "\nIncorrect username.\n";
		if (loginpass.compare(person.password) != 0)
			cout << "\nIncorrect password.\n";

		cout << "\n\n\x1b[96;32mEnter Username.\n\x1b[96;33m";
		cin >> loginname;
		cout << "\n\x1b[96;32mEnter Password.\n\x1b[96;33m";
		cin >> loginpass;


	}
	cout << "\n\n\n\t\t\t\x1b[96;7m Welcome back! " << person.name;
	inAccounts >> person.age >> person.country >> person.phone_no >> person.bank_acc;
	//cout <<"\n "<< AGE << " " << countr << " " << phone_num << " " << bankAcc;
	return person;
}
inline int fetch_total_objects_cnt()
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


	if (prod_id_string == "a")
		prod_id = 1;                          // if file is empty or "word" doesn't exist, set the prod_id to 1

	else                                    // if latest prod_id_string was fetched then extract the number(prod_id) from the string
	{                                        //e.g prod_id_string is Product ID: 2, now we will erase Product ID to only get 2

		string::size_type i = prod_id_string.find(word);  //e.g calculating now size of "Product ID:" from "Product ID:2"
		if (i != string::npos)                           //if it is valid size
			prod_id_string.erase(i, word.length());      // then we erase "Product ID:" in order to get 2 only
		prod_id = stoi(prod_id_string);              // stoi converting from string to int

	}
	return prod_id;


}

inline void lowercase(string& str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')    //checking for uppercase characters
			str[i] = str[i] + 32;         //converting uppercase to lowercase
	}
}
inline void uppercase(string& str)
{
	str[0] = str[0] - 32;
	
}



inline double addtocart(double x)
{
	bill = bill + x;
	return bill;
}
inline void placeorder(double BILL, int f, personprofile obj)
{
	cin.ignore();
	string name;

	
	string bank_acc;
	cout << "\n\x1b[96;36m1-Cash on Delivery.\n2-Online Payment.";
	int mode; cin >> mode;
	if (mode == 2)
	{
		cin.ignore();
	
		cout << "\nEnter Bank Account Title: ";
		getline(cin, bank_acc);
	}
	if (f == 1) {

		long long phone_no;  string  address;
		cout << "Enter name."; getline(cin, name);
		cout << "Enter Address";
		getline(cin, address);

		cout << "\nEnter Phone number: 0";
		cin >> phone_no;

		int a = countDigit(phone_no);
		while (a != 10)
		{
			cout << "Invalid value.";
			cout << "\nEnter Phone number: ";
			cin >> phone_no;
			a = countDigit(phone_no);
		}
	}

	else if (f == 2)
	{
		cout << "\nFetching your Data.\nName: " << obj.name << "\nAge: " << obj.age << "\nCountry: " << obj.country << "\nPhone Number: 0" << obj.phone_no << "\nBank Account: " << obj.bank_acc << "\x1b[0m";
	}
	addtocart(-1 * bill);
}
inline void checkout()
{
	cin.ignore();

	cout << "\n\x1b[96;92mTotal Bill:  \x1b[96;91m \x12 \x1b[96;92m" << bill;
	
	cout << "\n\x1b[92;93m\x1  \x1b[94;7m 1 \x1b[0m \x1b[92;96m Continue as Guest.\x1b[0m\n\x1b[92;93m\x1  \x1b[94;7m 2 \x1b[0m \x1b[92;96mSign up and create a free account.\x1b[0m\n\x1b[92;93m\x1  \x1b[94;7m 3 \x1b[0m \x1b[92;96m Already have an account? \x1b[94;47m Login.\x1b[0m";
	int q;
	cin >> q;
	while (q > 3 || q < 1)
	{
		cout << "\n\t\x1b[96;31mInvalid.\x1b[0m\n";
		cout << "\n\x1b[92;93m\x1  \x1b[94;7m 1 \x1b[0m \x1b[92;96m Continue as Guest.\x1b[0m\n\x1b[92;93m\x1  \x1b[94;7m 2 \x1b[0m \x1b[92;96mSign up and create a free account.\x1b[0m\n\x1b[92;93m\x1  \x1b[94;7m 3 \x1b[0m \x1b[92;96m Already have an account? \x1b[94;47m Login.\x1b[0m"; cin >> q;
	}
	system("cls");
	if (q == 1)
	{
		personprofile p;
		placeorder(bill, 1, p);

	}
	if (q == 2)
	{
		Signup();
		personprofile obj = Login();
		placeorder(bill, 2, obj);

	}
	else if (q == 3)
	{
		personprofile obj = Login();
		placeorder(bill, 2, obj);
	}
	cout << "\nOrder successfully placed.\n";
}
inline bool comparing(string s1, string s2)
{
	int sizeofs2 = s2.size()/2;
	int a = 0;
	char* char_arr;
	char_arr = &s1[0];
	char* char2;
	char2 = &s2[0];
	for (int i = 0; i < sizeofs2; i++) {
		if (char_arr[i] == char2[i])
		{
			a++;
		}
	}
	if (a >= sizeofs2)
		return true;
	else return false;
}
inline void search(string searchword, int choice)
{
	lowercase(searchword);
	//choice 1== checking on the basis of description
	// choice 2== means checking on the basis of Category
	// to MAINTAIN SEARCH HISTORY, WE ARE STORING THAT SEARCHWORD IN THIS FILE.
	

	double prices[30] = { 0 };
	string s = "Shoes"; string c = "Clothes";  string g = "Gadget";
	int flag = 0;
	int temp = fetch_total_objects_cnt();  //how many objects to read

	if (choice == 1)
	{
		ofstream outfile;
		outfile.open("searchhistory.txt", ios_base::out);
		outfile << searchword << "\n";
		outfile.close();

		ifstream f2("txt.txt", ios::in);   //opening inventory
		for (int cnt = 0; cnt < temp; cnt++)
		{

			string cat = "Shoes";
			getline(f2, cat);

			if (s == cat)
			{
				shoes p;
				f2 >> p;
				shoes q = p;

				for (int i = 0; i < 10; i++)
				{


					if (comparing(q.description[i], searchword) == true)
					{
						q.display_details();
						prices[q.id] = q.price;

						flag++;
						break;
					}
				}

			}
			else if (c == cat)
			{
				clothes p;
				f2 >> p;
				clothes q = p;
				for (int i = 0; i < 10; i++)
				{

					if (comparing(q.description[i], searchword) == true)
					{
						q.display_details();
						prices[q.id] = q.price;
						flag++;
						break;
					}
				}
			}

			else if (cat == g)
			{
				gadgets p;
				f2 >> p;
				gadgets q = p;

				for (int i = 0; i < 10; i++)
				{

					if (comparing(q.description[i], searchword) == true)
					{
						q.display_details();
						prices[q.id] = q.price;
						flag++;
						break;
					}
				}
			}
			else
			{
				product p;
				f2 >> p;
				product q;
				for (int i = 0; i < 10; i++)
				{
					if (comparing(q.description[i], searchword) == true)
					{
						q.display_details(); prices[q.id] = q.price;
						flag++;
						break;
					}
				}
			}
		}
		if (flag == 0)
		{
			cout << "None Found";
		}
		else
		{
			int buy; cout << "\n\x1b[96;33mPress relevant ID Number to add product to ID. To go back to home page, Press -2. ";
			cin >> buy;

			while (buy >= 1 && buy <= 30)
			{
				addtocart(prices[buy]);
				cout << "\n\n\x1b[96;33m \x2  \x1b[96;36mItem Added to cart.\nCurren Bill: " << bill << "\n\x1b[96;38m Press Relevant ID  to continue Shopping from same page.\nPress \x1b[94;7m -1 \x1b[0m \x1b[96;38m to Checkout.Press any other number to go back";
				cin >> buy;

			}
			if (buy == -1)
			{
				checkout();
			}
		}
	}

	else if (choice == 2)
	{
	uppercase(searchword);
	    ifstream f2("txt.txt", ios::in);   //opening inventory
	    for (int cnt = 0; cnt < temp; cnt++)
	    {

		string cat = "Shoes";
		getline(f2, cat);
		product p;
		f2 >> p;
		product q=p;
		if (comparing(q.category, searchword) == true)
		{
			q.display_details(); prices[q.id] = q.price;
			flag++;
			
		}
		
	}

		if (flag == 0)
		{
			cout << "None Found";
		}
		else
		{
			int buy; cout << "Press relevant ID Number to add product to ID. To go back to home page, Press -2. ";
			cin >> buy;

			while (buy >= 1 && buy <= 30)
			{
				addtocart(prices[buy]);
				cout << "\nItem Added to cart.\nCurren Bill: " << bill << "\nPress Relevant ID  to continue Shopping from same page.\nPress -1to Checkout.Press -2 to go back";
				cin >> buy;

			}
			if (buy == -1)
			{
				checkout();
			}
		}
	}
}
	


inline void search_acc_to_history()
{
	cout << "\n\nBased on your search history, we think you might be interested in the following items:\n";

	ifstream ifs("searchhistory.txt");    //reading line by line
	string line;
	ifs >>line;
	int temp = fetch_total_objects_cnt(); double prices[30] = { 0 }; int flag = 0;
	string s = "Shoes"; string c = "Clothes";  string g = "Gadget";
	ifstream f2("txt.txt", ios::in);   //opening inventory
	for (int cnt = 0; cnt < temp; cnt++)
	{

		string cat = "Shoes";
		getline(f2, cat);

		if (s == cat)
		{
			shoes p;
			f2 >> p;
			shoes q = p;

			for (int i = 0; i < 10; i++)
			{


				if (comparing(q.description[i], line) == true)
				{
					q.display_details();
					prices[q.id] = q.price;

					flag++;
					break;
				}
			}

		}
		else if (c == cat)
		{
			clothes p;
			f2 >> p;
			clothes q = p;
			for (int i = 0; i < 10; i++)
			{


				if (comparing(q.description[i], line) == true)
				{
					q.display_details(); prices[q.id] = q.price;

					flag++;
					break;
				}
			}
		}

		else if (cat == g)
		{
			gadgets p;
			f2 >> p;
			gadgets q = p;

			for (int i = 0; i < 10; i++)
			{

				

				if (comparing(q.description[i],line) == true)
				{
					q.display_details(); prices[q.id] = q.price;

					flag++;
					break;
				}
			}
		}
		else
		{
			product p;
			f2 >> p;
			product q;
			for (int i = 0; i < 10; i++)
			{
				if (comparing(q.description[i], line) == true)
				{
					q.display_details(); prices[q.id] = q.price;

					flag++;
					break;
				}
			}
		}
	}


	if (flag == 0)
	{
		cout << "None Found";
	}
	else
	{
		int buy; cout << "Press relevant ID Number to add product to ID. To go back to home page, Press -2. ";
		cin >> buy;

		while (buy >= 1 && buy <= 30)
		{
			addtocart(prices[buy]);
			cout << "\nItem Added to cart.\nCurren Bill: " << bill << "\nPress Relevant ID  to continue Shopping from same page.\nPress -1to Checkout.Press any other number to go back";
			cin >> buy;

		}
		if (buy == -1)
		{
			checkout();
		}
	}

}
















inline void border()
{
	for (int i = 0; i < 40; i++)
	{
		Sleep(2);
		cout << "\t \x1b[63;95m\x3";
	}
	for (int i = 0; i < 40; i++)
	{
		Sleep(2);
		cout << "\t\x1b[61;96m\x4\t";
	}
	for (int i = 0; i < 40; i++)
	{
		Sleep(2);
		cout << "\t \x1b[61;91m\x6";
	}
	for (int i = 0; i < 40; i++)
	{
		Sleep(2);
		cout << "\t\x1b[61;92m\x5\t";
	}
	for (int i = 0; i < 40; i++)
	{
		Sleep(2);
		cout << "\t \x1b[61;93m\x3";
	}
	for (int i = 0; i < 40; i++)
	{
		Sleep(2);
		cout << "\t\x1b[63;95m\x4\t";
	}
	for (int i = 0; i < 40; i++)
	{
		Sleep(2);
		cout << "\t \x1b[63;95m\x6";
	}
	for (int i = 0; i < 40; i++)
	{
		Sleep(2);
		cout << "\t\x1b[61;96m\x5\t";
	}
	
}

inline void welcomescreen()
{
	border();
	//Initialising character arrays for an animation effect on starting screen
	char welcome1[] = "\n\n\n\n\t\t\t\t\t\t\t\t\t  \x1b[36;1mWELCOME\x1b[0m \x1b[36;36mTO\x1b[0m\n\n";
	char welcome2[] = "\t\t\t\t\t\t\t\t \x1b[35;1m   PASS\x1b[0m \x1b[35;40m     IT\x1b[0m\x1b[31m      ON\x1b[0m\n\n";
	char welcome3[] = "\t\t\t\t\t\t\t \x1b[33;50m\tA\x1b[0m \x1b[34;1mThrift\x1b[0m \x1b[33;35mShopping\x1b[0m \x1b[32;20mApplication\x1b[0m \x1b\n\n[33;5m\t\t\t\t\t  \t\t\t     \x3 Pre-loved items \x3\x1b[0m\n\n\n\n";
	//Loops to cause delay while printing characters.
	for (int a = 0; welcome1[a] != NULL; a++)
	{
		printf("%c", welcome1[a]);
		Sleep(10);
	}
	for (int a = 0; welcome2[a] != NULL; a++)
	{
		printf("%c", welcome2[a]);
		Sleep(10);
	}
	for (int a = 0; welcome3[a] != NULL; a++)
	{
		printf("%c", welcome3[a]);
		Sleep(10);
	}
	border();
	system("pause");
	system("cls");
}