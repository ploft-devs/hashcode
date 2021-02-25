#include <iostream>
#include "files.hpp"
#include <fstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

const bool DEBUG_MODE = true;

int N_TIME;
int N_INTERSECTIONS;
int N_STREETS;
int N_CARS;
int POINTS_PER_CAR;

class car
{
private:
    //queue<street> path;

public:
    car(/* args */);
};

car::car()
{
}

class street
{
private:
    string name;
    queue<car> cars;
    int time;
    int TrafficLightTime;
    bool TrafficLightStatus;

public:
    street(/* args */);
};

street::street(/* args */)
{
}

class intersection
{
private:
    vector<street> begin;
    vector<street> end;

public:
    intersection(/* args */);
};

intersection::intersection(/* args */)
{
}

bool readSetup()
{
    ifstream arq;
    arq.open("file.txt");
    char linha[100];
    if (!arq.is_open())
    {
        cout << "Could not read setup file";
        return false;
    }
    else
    {
        arq.getline(linha, 100);
        string numBuffer = "";
        int pos = 0;
        while (linha[pos] != ' ')
        {
            numBuffer += linha[pos];
            pos++;
        }
        N_TIME = stoi(numBuffer);
        numBuffer = "";
        pos++;
        while (linha[pos] != ' ')
        {
            numBuffer += linha[pos];
            pos++;
        }
        N_INTERSECTIONS = stoi(numBuffer);
        pos++;
        numBuffer = "";
        while (linha[pos] != ' ')
        {
            numBuffer += linha[pos];
            pos++;
        }
        N_STREETS = stoi(numBuffer);
        pos++;
        numBuffer = "";
        while (linha[pos] != ' ')
        {
            numBuffer += linha[pos];
            pos++;
        }
        N_CARS = stoi(numBuffer);
        pos++;
        numBuffer = "";
        while (linha[pos] != ' ')
        {
            numBuffer += linha[pos];
            pos++;
        }
        POINTS_PER_CAR = stoi(numBuffer);
        pos++;
        numBuffer = "";
        int no1 = 0, no2 = 0;
        for (int i = 0; i < N_STREETS; i++)
        {
            arq.getline(linha, 100);
            pos = 0;
            numBuffer = "";
            while (linha[pos] != ' ')
            {
                numBuffer += linha[pos];
                pos++;
            }
            no1 = stoi(numBuffer);
            numBuffer = "";
            pos++;
            while (linha[pos] != ' ')
            {
                numBuffer += linha[pos];
                pos++;
            }
            no2 = stoi(numBuffer);
            numBuffer = "";
            pos++;
            while (linha[pos] != ' ')
            {
                numBuffer += linha[pos];
                pos++;
            }
            string nome = numBuffer;
            numBuffer = "";
            pos++;
            while (linha[pos] != ' ')
            {
                numBuffer += linha[pos];
                pos++;
            }
            
        }

        return true;
    }
}

void solve()
{
    ifstream arq;
    arq.open("");
    while(N_TIME--){
        
    }
}   

int main()
{
    //Exemplo de mexer em arquivo
    readSetup();
    if (DEBUG_MODE)
    {
        cout << "\nN_TIME: " << N_TIME;
        cout << "\nN_INTERSECTIONS: " << N_INTERSECTIONS;
        cout << "\nN_STREETS: " << N_STREETS;
        cout << "\nN_CARS: " << N_CARS;
        cout << "\nPOINTS_PER_CAR " << POINTS_PER_CAR;
    }

    return 0;
}

/*
 * TODO: Geral fazer, geral ganhar programação maratona
 * 
 * 
 * 
 */

/*
    Class car:
    path

    Class street
    CarsQueue
    CrossingTime
    TrafficlightTime
    TrafficlightStatus
   
    
    
*/