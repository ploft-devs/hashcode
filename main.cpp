#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <utility> 

using namespace std;

const bool DEBUG_MODE = true;

int N_TIME;
int N_INTERSECTIONS;
int N_STREETS;
int N_CARS;
int POINTS_PER_CAR;

int RES_INTERSECTIONS = 3;
int RES_IDSINTERSECTIONS[3] = {0,1,2};
int RES_STREETSCOUNT[3] = {1,2,1}; // Incoming streets
string RES_STREETNAMES[4] = {"rue-de-londres","rue-d-amsterdam","rue-d-athenes","rue-de-moscou"};
int RES_GREENTIME[4] = {1,1,1,1};

class car
{
public:
    queue<string> path;
    car() {}
    car(queue<string> path)
    {
        this->path = path;
    }
};

class street
{

public:
    string name;
    queue< pair<car, int> > cars;
    int time;
    int TrafficLightTime;
    bool TrafficLightStatus;

    street(string name, int time)
    {
        this->name = name;
        this->time = time;
        this->TrafficLightStatus = false;
    }

    void addCar(car car, int time = 0)
    {
        cars.push(make_pair(car, time));
    }
};

class intersection
{
public:
    vector<street> begin;
    vector<street> end;
    int timeRemaining;
    int greenLightStreet;

    intersection()
    {
    }

    void setupTrafficLight()
    {
        if (this->end.size() == 1){
            this->end.at(0).TrafficLightTime = -1;
            this->end.at(0).TrafficLightStatus = true;
            timeRemaining=-1;
            greenLightStreet=0;
        } else{
            for(auto street: end)
                street.TrafficLightTime = 1;
        }
    }
};

vector<street> streets;
vector<car> cars;
vector<intersection> intersections;

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
        string numBuffer = "";
        int pos = 0;
        //read parameters from first line
        {
            arq.getline(linha, 100);

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
        }

        intersections = vector<intersection>(N_INTERSECTIONS);

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
            int tam = stoi(numBuffer);
            street newStreet(nome, tam);
            intersections[no1].begin.push_back(newStreet);
            intersections[no2].end.push_back(newStreet);
            streets.push_back(newStreet);
        }
        for (int i = 0; i < N_CARS; i++)
        {
            arq.getline(linha, 100);
            car newCar;
            pos = 0;
            numBuffer = "";
            while (linha[pos] != ' ')
            {
                numBuffer += linha[pos];
                pos++;
            }
            int streetsNum = stoi(numBuffer);
            pos++;
            string path = "";
            for (int j = 0; j < streetsNum; j++)
            {
                while (linha[pos] != ' ')
                {
                    path += linha[pos];
                    pos++;
                }
                newCar.path.push(path);
            }
            cars.push_back(newCar);
        }

        return true;
    }
}

void solve()
{
    int time = N_TIME;
    for (int i = 0; i < time; i++)
    {
    }
}

void save()
{

    // auto arq = openFile("solve.txt");
    
    // arq << N_INTERSECTIONS; //the number of intersections for which you specify the schedule.

    // for (int i = 0; i < RES_INTERSECTIONS; i++)
    // {
    //     arq << RES_IDSINTERSECTIONS[i]; //the ID of the intersection
    //     arq << RES_STREETSCOUNT[i];        // the number of incoming streets

    //     for (int j = 0; j < RES_STREETSCOUNT[i]; j++) //indice do streetscount
    //     {
    //         arq << RES_STREETNAMES[j+i] + to_string(RES_GREENTIME[j+i]);
    //         // the street name, how long each street will have a green light
    //     }
    // }
    // arq.close();
    ofstream arq;
    arq.open("solve.txt");
    
    arq << N_INTERSECTIONS<<"\n"; //the number of intersections for which you specify the schedule.

    for (int i = 0; i < N_INTERSECTIONS; i++)
    {
        arq << i << "\n"; //the ID of the intersection
        arq << intersections[i].end.size() << "\n";        // the number of incoming streets

        for (int j = 0; j < intersections[i].end.size(); j++) //indice do streetscount
        {
            arq << intersections[i].end[j].name << " 1"  << "\n";
            // the street name, how long each street will have a green light
        }
    }
    arq.close();
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
        cout<<"\n\nIntersections: \n";
        for(int i =0;i<N_INTERSECTIONS;i++){
            cout<<"Intersection "<<i<<": \n";
            cout<<"Streers starting here: \n";
            for(street x: intersections[i].begin){
                cout<<x.name<<endl;
            }
            cout<<"Streets ending here: \n";
            for(street x: intersections[i].end){
                cout<<x.name<<endl;
            }
        }
    }
    save();

    return 0;
}

/*
    Class car:
    path

    Class street
    CarsQueue
    CrossingTime
    TrafficlightTime
    TrafficlightStatus
   
    
    
*/