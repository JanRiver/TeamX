#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

//global variable

//amount of fruits in inventory
float   inv_apple = 0,
        inv_banana = 0,
        inv_grape = 0,
        inv_orange = 0,
        inv_watermelon = 0;

    float cash = 11000;
    float day = 0;
    float networth = 11000;

struct Fruit
{
    string name;
    float price;
    float wastage;
};



//print fruits' price
//assigned to Nhan
void printPrice(Fruit fruit[], int n);

//print everything in inventory, fruits, cash,...
//assigned to Nhan
void printInventory();

//buy fruit
bool buy(Fruit[], int array_size);

//sell fruit
bool sell(Fruit[], int array_size);

//print a question and get a character as answer
//assigned to Vang Vang
char getChar(string question);

//print a question and get an integer as answer
int getInt(string question);

//update information after a day
void update();

//get a random number
//assigned to Vang Vang
float getRandom();


int main()
{
    Fruit fruit[5] {
     { "Apple", 4.5, 1.0 },
     { "Banana", 2.5, 1.8 },
     { "Grape", 9.0, 2.0},
     { "Orange", 4.0, 1.0},
     { "Watermelon", 1.00, 1.2},
    };

    bool quit = false;

    while (!quit)
    {
        cout << string(50, '\n');
        cout << "Fruit Businessman\n";
        cout << "Day: " << day << endl;
        printInventory();
        cout << "------------------------------------\n";
        printPrice(fruit, 5);

        char cmd = ' ';
        while (cmd != 'c' && cmd != 'C')
        {
            cmd = getChar("Enter B to buy, S to sell, C to continue: ");
            if (cmd == 'B' || cmd == 'b')
            {
                buy();
            }
            else if (cmd == 'S' || cmd == 's')
            {
                sell();
            }
        }
        update();
    }


    return 0;
}

void printPrice (Fruit fruit[],int n)
{
		cout <<right<<setw(14)<<"Prices\n";
		for(int i=0;i<n;i++)
	{
		cout <<left<<setw(15)<<fruit[i].name<<"$"<<left<<setw(30)<<fruit[i].price<<"\n";
	}
}

void printInventory ()
{
	cout <<right<<setw(15)<<"Inventory\n";
	cout <<left<<setw(15)<<"Apples: "<<left<<setw(10)<<inv_apple<<"\n"
		 <<left<<setw(15)<<"Bananas: "<<left<<setw(10)<<inv_banana<<"\n"
	 	 <<left<<setw(15)<<"Grapes: "<<left<<setw(10)<<inv_grape<<"\n"
	 	 <<left<<setw(15)<<"Oranges: "<<left<<setw(10)<<inv_orange<<"\n"
	 	 <<left<<setw(15)<<"Watermelons: "<<inv_watermelon<<"\n"
		 <<left<<setw(15)<<"Cash: " <<cash<<"\n"
		 <<left<<setw(15)<<"Days: "<<day<<"\n"
		 <<left<<setw(15)<<"Networth: "<<networth<<"\n";
}

bool buy()
{
    cout << "Bought" << endl;
}

bool sell()
{
    cout << "Sold" << endl;
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

}

void update()
{

}

float getRandom()
{
    int a = rand();
    return float(( a % 201) - 100 ) / 100;
}
