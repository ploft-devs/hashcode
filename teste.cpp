#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    ifstream arquivo("a_example.txt");
    string myText;
    string data[4];
    getline(arquivo, myText);
    for (int i = 0; i < 4; i++)
    {
        data->push_back(myText[i * 2]);
    }
}