#include <iostream>
#include <string>

using namespace std;

struct Fruit
{
    string name;
    float price;
    float wastage;
};

int main()
{
    Fruit apple = { "apple", 2.50, 1.20 };
    cout << apple.name << " " << apple.price << " " << apple.wastage << endl;
}
