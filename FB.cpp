#include <iostream>

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

//buy an amount of fruit
bool buy(Fruit fruit, int amount);

//sell an amount of fruit
bool sell(Fruit fruit, int amount);

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
 

}
