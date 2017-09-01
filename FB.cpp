#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <conio.h>

using namespace std;

//global variable

    float cash = 100;
    int day = 1;
    float networth = 100;

struct Fruit
{
    string name;
    float price;
    float wastage;
    float amount;
    char lastPrices[6];
    float months[12];
};



//print fruits' price
void printPrice(Fruit fruit[], int n);

//print everything in inventory, fruits, cash,...
void printInventory(Fruit *fruit, int array_size);

//buy fruit
bool buy(Fruit* fruit, int array_size);

//sell fruit
bool sell(Fruit* fruit, int array_size);

//print a question and get a character as answer
char getChar(string question);

//print a question and get an integer as answer
int getInt(string question);

float getFloat(string question);

//update information after a day
void update(Fruit *fruit, int array_size);

//get a random number
float getRandom();

//these functions are to print screen correctly
string getMonthString(int month_as_number);
void printScreen(Fruit *fruit, int array_size);

void printResult();

int main()
{
    Fruit fruit[5] = {
     { "Apple",      4.5, 1.0, 0.0, ".....", {7, 6, 5, 4, 3, 2, 3, 4, 5, 6, 7, 8} },
     { "Banana",     2.5, 1.8, 0.0, ".....", {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5} },
     { "Grape",      9.0, 2.0, 0.0, ".....", {6, 8, 8, 7, 6, 5, 5, 4, 3, 2, 2, 6} },
     { "Orange",     4.0, 1.0, 0.0, ".....", {5, 5, 5, 2, 2, 2, 5, 5, 8, 8, 8, 5} },
     { "Watermelon", 1.0, 1.2, 0.0, ".....", {1, 2, 3, 7, 8, 9, 8, 7, 5, 5, 3, 2} },
    };

    bool quit = false;

    while (!quit)
    {
        printScreen(fruit, 5);

        char cmd = ' ';
        while (cmd != 'c' && cmd != 'C')
        {
            cmd = getChar("Enter B to buy, S to sell, C to continue: ");
            if (cmd == 'B' || cmd == 'b')
            {
                buy(fruit, 5);
            }
            else if (cmd == 'S' || cmd == 's')
            {
                sell(fruit, 5);
            }

            //print again
            printScreen(fruit, 5);

        }
        update(fruit, 5);

        if (day >= 36)
        {
            printResult();
            quit = true;
        }
    }

    getch();

    return 0;
}


void printScreen(Fruit *fruit, int array_size)
{
    cout << string(50, '\n');
    cout << "Fruit Businessman\n";
    cout << "Month: " << day << endl;
    cout << getMonthString(day % 12) << ", " << (day - 1) / 12 + 1 << endl;
    printInventory(fruit, 5);
    cout << "------------------------------------\n";
    printPrice(fruit, 5);

}

void printResult()
{
    cout << string(50, '\n');
    cout << "FRUIT BUSINESSMAN\n";
    cout << "After 5 years, you have : " << networth << "\n";
}

void printPrice (Fruit fruit[],int n)
{
		cout <<right<<setw(14)<<"Prices\n";
		for(int i=0;i<n;i++)
	{
		cout << i + 1 << ". " << left<<setw(15) <<fruit[i].name<<"$"<<left<<setw(10)<<fruit[i].price
        << "last 5 months: " << fruit[i].lastPrices <<"\n";
	}
}

void printInventory (Fruit *fruit, int array_size)
{
//	cout <<right<<setw(15)<<"Inventory\n";
//	cout <<left<<setw(15)<<"Apples: "<<left<<setw(10)<<inv_apple<<"\n"
//		 <<left<<setw(15)<<"Bananas: "<<left<<setw(10)<<inv_banana<<"\n"
//	 	 <<left<<setw(15)<<"Grapes: "<<left<<setw(10)<<inv_grape<<"\n"
//	 	 <<left<<setw(15)<<"Oranges: "<<left<<setw(10)<<inv_orange<<"\n"
//	 	 <<left<<setw(15)<<"Watermelons: "<<inv_watermelon<<"\n"
//		 <<left<<setw(15)<<"Cash: " <<cash<<"\n"
//		 <<left<<setw(15)<<"Days: "<<day<<"\n"
//		 <<left<<setw(15)<<"Networth: "<<networth<<"\n";

    cout << right << setw(15) << "Inventory\n";
    cout << setprecision(2) << fixed;
    for (int i = 0; i < array_size; i++)
    {
        cout << i + 1 << ". " << left << setw(15) << fruit[i].name << right << setw(3) << fruit[i].amount << " kg" << endl;
    }
    cout << "------------------------------------\n";
    cout << left << setw(15) << "Cash" << "$" << cash << "\n";
    cout << left << setw(15) << "Networth" << "$" << networth << "\n";

}

bool buy(Fruit* fruit, int array_size)
{
    int fruit_type = -1;

    do {
        fruit_type = getInt("Which one do you want to buy (1-5): ");
        fruit_type--;
    } while (fruit_type < 0 || fruit_type > 4);

    float fruit_amount = -1.0f;

    do {
        fruit_amount = getFloat("How much do you want to buy: ");
    } while (fruit_amount <= 0);

    float deal_value = fruit[fruit_type].price * fruit_amount;
    if (cash < deal_value)
    {
        cout << "Transaction Failed\n";
        return false;
    }

    cash -= deal_value;
    fruit[fruit_type].amount += fruit_amount;
    cout << "Transaction Completed\n";
    return true;

}

bool sell(Fruit* fruit, int array_size)
{
    int fruit_type = -1;

    do {
        fruit_type = getInt("Which one do you want to sell (1-5): ");
        fruit_type--;
    } while (fruit_type < 0 || fruit_type > 4);

    float fruit_amount = -1.0f;

    do {
        fruit_amount = getFloat("How much do you want to sell: ");
    } while (fruit_amount <= 0);

    if (fruit[fruit_type].amount < fruit_amount)
    {
        fruit_amount = fruit[fruit_type].amount;
    }

    float deal_value = fruit[fruit_type].price * fruit_amount;

    cash += deal_value;
    fruit[fruit_type].amount -= fruit_amount;
    cout << "Transaction Completed\n";
    return true;
}

char getChar(string question)
{
    char c;
    cout << question;
    cin >> c;
    cin.clear();
    cin.ignore(1000, '\n');
    return c;
}

int getInt(string question)
{
	cout << question;
	int num;
	while (!(cin >> num))
	{
		cout << question;
		cin.clear();
		cin.ignore(9999, '\n');
	}
	return num;
}

float getFloat(string question)
{
    cout << question;
	float num;
	while (!(cin >> num))
	{
		cout << question;
		cin.clear();
		cin.ignore(9999, '\n');
	}
	return num;
}

void update(Fruit *fruit, int array_size)
{
	day++;
	networth = 0;
	networth += cash;
	for (int i = 0; i < array_size; i++)
	{
        //update depend on month
		//fruit[i].price += fruit[i].price * 0.05 * getRandom();
		float rate = fruit[i].months[day % 12];
		float deltaPrice = fruit[i].price * (0.05 * getRandom() - 0.05 + rate / 100.0f);

        //update price in the last 5 months
        for (int j = 0; j < 4; j++)
            fruit[i].lastPrices[j] = fruit[i].lastPrices[j + 1];
        fruit[i].lastPrices[4] = deltaPrice > 0? '+' : '-';

		fruit[i].price += deltaPrice;

        fruit[i].amount = fruit[i].amount * (100.0 - fruit[i].wastage) / 100.0f;

		networth +=  fruit[i].price *fruit[i].amount;
	}
}


float getRandom()
{
    int a = rand();
    return float(( a % 201) - 100 ) / 100;
}

string getMonthString(int month_as_number)
{
    string result;
    switch (month_as_number)
    {
    case 1:
        return "Junuary";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 0:
        return "December";
    }
}

