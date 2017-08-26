#include <iostream>
#include <ctime>
#include <string>

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

Fruit fruit[5] {
     { "Apple", 4.5, 1.0 },
     { "Banana", 2.5, 1.8 },
     { "Grape", 9.0, 2.0},
     { "Orange", 4.0, 1.0},
     { "Watermelon", 1.00, 1.2},
};

//print fruits' price
//assigned to Nhan
void printPrice();

//print everything in inventory, fruits, cash,...
//assigned to Nhan
void printInventory();

//buy fruit
bool buy();

//sell fruit
bool sell();

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
    bool quit = false;

    while (!quit)
    {
        cout << string(50, '\n');
        cout << "Fruit Businessman\n";
        cout << "Day: " << day << endl;
        printInventory();
        cout << "------------------------------------\n";
        printPrice();

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

void printPrice()
{

}

void printInventory()
{

}

bool buy()
{

}

bool sell()
{

}

char getChar(string question)
{
    char c;
    cout << question;
    cin >> c;
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

}
