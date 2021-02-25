#include <iostream>
#include "files.hpp"
#include <fstream>
#include <string>
#include <queue>

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
   queue<street> path;
public:
    car(/* args */);
};

car::car()
{
    
}

class street
{
private:
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




bool readSetup(){
    ifstream arq;
    arq.open("arquivo.txt");
    char linha [100];
    if(!arq.is_open()){
        cout<<"Could not read setup file";
        return false;
    }
    else{
        while(!arq.eof()){
            arq.getline(linha,100);
            string numBuffer = "";
            int pos =0;
            while(linha[pos]!=' '){
                numBuffer +=linha[pos];
                pos++;
            }
            N_TIME = stoi(numBuffer);
            numBuffer = "";
            pos++;
            while(linha[pos]!=' '){
                numBuffer +=linha[pos];
                pos++;
            }
            N_INTERSECTIONS = stoi(numBuffer);
            pos++;
            numBuffer = "";
            while(linha[pos]!=' '){
                numBuffer +=linha[pos];
                pos++;
            }
            N_STREETS = stoi(numBuffer);
            pos++;
            numBuffer = "";
            while(linha[pos]!=' '){
                numBuffer +=linha[pos];
                pos++;
            }
            N_CARS = stoi(numBuffer);
            pos++;
            numBuffer = "";
            while(linha[pos]!=' '){
                numBuffer +=linha[pos];
                pos++;
            }
            POINTS_PER_CAR = stoi(numBuffer);
            pos++;
            numBuffer = "";
            return true;
            
            
        }
    }
}

int main()
{
    //Exemplo de mexer em arquivo
    readSetup();
    if(DEBUG_MODE){
        cout<<"\nN_TIME: "<<N_TIME;
        cout<<"\nN_INTERSECTIONS: "<<N_INTERSECTIONS;
        cout<<"\nN_STREETS: "<<N_STREETS;
        cout<<"\nN_CARS: "<<N_CARS;
        cout<<"\nPOINTS_PER_CAR "<<POINTS_PER_CAR;
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