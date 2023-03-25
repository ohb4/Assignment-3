#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Person
{
    protected:
        string name;
        int id;
        int age;
    public:
        Person()
        {
            name = "";
            id = 0;
            age = 0;
        }
        void setName(string n)
        {
            name = n;
        }
        void setId(int x)
        {
            id = x;
        }
        void setAge(int a)
        {
            age = a;
        }
        string getName()
        {
            return name;
        }
        int getId()
        {
            return id;
        }
        int getAge()
        {
            return age;
        }
        void printInfo()
        {
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Age: " << age << endl;
        }
};

struct Appointment
{
    int hrs;
    int mins;
    
    int getHrs()
    {
        return hrs;
    }
    int getMins()
    {
        return mins;
    }
};