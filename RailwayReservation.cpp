#include <iostream>
#include <cstring>
using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

public:
    static int trainCount;

    Train()
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    Train(int number, char name[], char src[], char dest[], char time[])
    {
        trainNumber = number;
        trainCount++;

        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
    }

    void setTrainNumber(int number)
    {
        trainNumber = number;
    }

    void setTrainName(char name[])
    {
        strcpy(trainName, name);
    }

    void setsource(char src[])
    {
        strcpy(source, src);
    }

    void setdestination(char dest[])
    {
        strcpy(destination, dest);
    }
    void settrainTime(char time[])
    {
        strcpy(trainTime, time);
    }

    int getTrainNumber()
    {
        return trainNumber;
    }
    char *getTrainName()
    {
        return trainName;
    }

    char *getsource()
    {
        return source;
    }

    char *getdestination()
    {
        return destination;
    }

    char *gettrainTime()
    {
        return trainTime;
    }
    void inputTrainDetails()
    {
        int number;
        cout << "Enter Train Number: ";
        cin >> number;
        setTrainNumber(number);

        char name[50];
        cout << "Enter Train Name: ";
        cin >> name;
        setTrainName(name);

        char src[50];
        cout << "Enter Source: ";
        cin >> src;
        setsource(src);

        char dest[50];
        cout << "Enter Destination: ";
        cin >> dest;
        setdestination(dest);

        char time[10];
        cout << "Enter Train Time: ";
        cin >> time;
        settrainTime(time);
    }

    void displayTrainDetails()
    {
        cout << "Train Number: " << getTrainNumber() << endl;
        cout << "Train Name: " << getTrainName() << endl;
        cout << "Source: " << getsource() << endl;
        cout << "Destination: " << getdestination() << endl;
        cout << "Train Time: " << gettrainTime() << endl;
    }

    ~Train()
    {
        trainCount--;
    }
};

int Train::trainCount = 0;

class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem()
    {
        totalTrains = 3;

        Train train1(101, (char *)"Rajdhani", (char *)"Delhi", (char *)"Mumbai", (char *)"10:00");
        Train train2(102, (char *)"Shatabdi", (char *)"Delhi", (char *)"Bhopal", (char *)"12:00");
        Train train3(103, (char *)"Duronto", (char *)"Mumbai", (char *)"Pune", (char *)"15:00");

        trains[0] = train1;
        trains[1] = train2;
        trains[2] = train3;
    }

    void addTrain()
    {
        trains[totalTrains].inputTrainDetails();
        totalTrains++;
    }

    void displayAllTrains()
    {
        for (int i = 0; i < totalTrains; i++)
        {
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number)
    {
        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                trains[i].displayTrainDetails();
                return;
            }
        }

        cout << "Train not found." << endl;
    }
};
int main()
{
    RailwaySystem railway;
    int choice;

    do
    {
        cout << "\n1. Add New Train Record" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            railway.addTrain();
            break;

        case 2:
            railway.displayAllTrains();
            break;

        case 3:
        {
            int number;
            cout << "Enter Train Number to Search: ";
            cin >> number;
            railway.searchTrainByNumber(number);
            break;
        }

        case 4:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 4);

    return 0;
}