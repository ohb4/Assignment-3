#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <fstream>
#include "Person.h"
#include "Mechanic.h"
#include "Customer.h"
#include "Queue.h"

using namespace std;


int main()
{
    int numMechanics;
    int numCustomers;
    int id;
    int age;
    string name;
    int hrs;
    int mins;

    ofstream write;
    write.open("mechanics.txt");

    if(write.fail())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    
    cout << "Enter the number of mechanics: ";
    cin >> numMechanics;
    cout << "===============================" << endl;

    Mechanic *mechanics = new Mechanic[numMechanics];

    write << "Number of mechanics: " << numMechanics;
    write << endl << endl;
    write << "Name\t\tAge\t\tID" << endl;

    for(int i = 0; i < numMechanics; i++)
    {
        cout << "Enter mechanic " << i + 1 << "'s name: ";
        cin >> name;

        srand((unsigned) time(NULL));
        age = rand() % 50 + 18;

        id = i+1;

        write << name << "\t\t" << age  << "\t\t" << id << endl;

        mechanics[i].setName(name);
        mechanics[i].setId(id);
        mechanics[i].setAge(age);
    }

    write << endl << endl;
    write.close();
    cout << endl;

    ofstream input;
    input.open("customers.txt");
        
    if(input.fail())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }


    cout << "Enter the number of customers: ";
    cin >> numCustomers;
    cout << "===============================" << endl;

    Customer *customers = new Customer[numCustomers];

    input << "Number of Customers: "<< numCustomers << endl;
    input << "Name\t\tID\t\tAppointment Time" << endl;

    for(int i = 0; i < numCustomers; i++)
    {
        cout << "\nEnter customer " << i + 1 << "'s name: ";
        cin >> name;
        cout << "Enter customer " << i + 1 << "'s appointment time (hrs mins): \n";
        cout << "Hours: ";
        cin >> hrs;
        cout << "Minutes: ";
        cin >> mins;

        id = i+100;

        input << name << "\t\t" << id << "\t\t" << hrs << " : " << mins << endl;

        customers[i].setName(name);
        customers[i].setId(id);
        customers[i].setAppointment(hrs, mins);
    }

    input << endl << endl;
    input.close();
    cout << endl << endl << endl;

    Queue<Customer> q(numCustomers);
    for(int i = 0; i < numCustomers; i++)
    {
        q.push(customers[i]);
    }
    cout << "==============================================================" << endl;
    for(int i = 0; i < numCustomers; i++)
    {
        for(int j = 0; j < numMechanics; j++)
        {
            if(mechanics[j].isAvailable(q.getFront().getAppointment().hrs, q.getFront().getAppointment().mins))
            {
                mechanics[j].setAppointment(q.getFront().getAppointment().hrs, q.getFront().getAppointment().mins);
                
                cout << "The customer " << q.getFront().getName() << " is assigned to the mechanic " << mechanics[j].getName() << " at ";
                cout << q.getFront().getAppointment().hrs << ":" << q.getFront().getAppointment().mins << endl;
                cout << "Mechanic's information: " << endl;
                mechanics[j].printInfo();
                cout << "==============================================================\n";
                q.pop();
                break;
            }
            else if(j == numMechanics - 1)
            {
                cout << "No mechanics available for customer " << q.getFront().getName() << "!!"<< endl;
                cout << "==============================================================\n";
                q.pop();
            }
        }
    }

    return 0;
}