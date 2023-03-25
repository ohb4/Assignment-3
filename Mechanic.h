#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Mechanic: public Person
{
    private:
        int counter;
        Appointment appointments[10];
    public:
        Mechanic()
        {
            counter = 0;
        }
        bool isAvailable(int h, int m)
        {
            bool unavailable = false;
            bool available = true;
            for(int i = 0; i < counter; i++)
            {
                // If the hour and minute of an existing appointment matches the given hour and minute then there is a conflict therefore return unavailable.
                if(appointments[i].hrs == h && appointments[i].mins == m)
                {
                    return unavailable;
                }
                else if(appointments[i].hrs == h && appointments[i].mins < m && (h*60+m)-(appointments[i].hrs*60+appointments[i].mins) < 60)
                {
                    // If the hour of an appointment matches the hour and the minute is earlier than the given minute,
                    // and the time difference between the existing appointment and the given time is less than 60 minutes there is a conflict 
                    // therefore we return unavailable.
                    return unavailable;
                }
                
                else if(appointments[i].hrs == h && appointments[i].mins > m && (appointments[i].hrs*60+appointments[i].mins)-(h*60+m) < 60)
                {
                    // If the hour of an existing appointment matches the given hour and the minute is later than the given minute,
                    // and the time difference between the existing appointment and the given time is less than 60 minutes them there is a conflict
                    // therefore we return unavailable. 
                    return unavailable;
                }
            }
            return available;
        }
        void setAppointment(int h, int m)
        {
            appointments[counter].hrs = h;
            appointments[counter].mins = m;
            counter++;
        }
        int getCounter()
        {
            return counter;
        }
        Appointment getAppointment(int i)
        {
            return appointments[i];
        }
};