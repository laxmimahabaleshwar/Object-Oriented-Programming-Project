#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class hostel
{
public:
    int trippleroomSpace;
    int doubleroomSpace;
    int singleroomSpace;
    hostel(int x, int y, int z)
    {
        trippleroomSpace = x;
        doubleroomSpace = y;
        singleroomSpace = z;
    }
};

class student
{
public:
    time_t entryTime;
    string usn;
    string Name;

    virtual void getInfo() = 0;
    virtual void Leaving() = 0;
};

class trippleroom : public student
{
public:
    void getInfo()
    {
        cout << "Enter Student's Name\n";
        cin >> Name;
        cout << "Enter Usn\n";
        cin >> usn;
        entryTime = time(NULL);
    }
    void Leaving()
    {
        long Fee = (time(NULL) - entryTime) * 10;
        cout << "Students Details:\n";
        cout << "Name: " << Name << '\n';
        cout << "USN: " << usn<< '\n';
        cout << "Hostel fees: " << Fee << '\n';
    }
};

class doubleroom : public student
{
public:
    void getInfo()
    {
        cout << "Enter Student's Name\n";
        cin >> Name;
        cout << "Enter USN\n";
        cin >> usn;
        entryTime = time(NULL);
    }
    void Leaving()
    {
        long Fee = (time(NULL) - entryTime)*20;
        cout << "Students Details:\n";
        cout << "Name: " << Name << '\n';
        cout << "USN: " << usn<< '\n';
        cout << "Hostel fees: " << Fee << '\n';
    }
};

class singleroom : public student
{
public:
    void getInfo()
    {
        cout << "Enter Student's Name\n";
        cin >> Name;
        cout << "Enter USN\n";
        cin >> usn;
        entryTime = time(NULL);
    }
    void Leaving()
    {
        long Fee = (time(NULL) - entryTime) * 40;
        cout << "Students Details:\n";
        cout << "Name: " << Name << '\n';
        cout << "USN: " << usn<< '\n';
        cout << "Hostel fees: " << Fee << '\n';
    }
};

void printMenu()
{
    cout << "-----Main menu-----\n";
    cout << "\t1.Want room in hostel\n";
    cout << "\t2.See available rooms\n";
    cout << "\t3.Find your details\n";
    cout << "\t4.Leave the hostel\n";
    cout << "\t5.Exit\n";
}

int main()
{
    int ch1,ch2;
    int i2=0,i3=0;
    string USN;
    char choice;
    hostel s(150, 100, 50);
    vector<student *> room;
    vector<student *>::iterator it;
    do
    {
        printMenu();
        cout << "\tEnter your choice\n";
        cin >> ch1;
        switch (ch1)
        {
        case 1:
            cout << "\t1. Tripple-room\n";
            cout << "\t2. Double-room\n";
            cout << "\t3. Single-room\n";
            cin >> ch2;
            switch (ch2)
            {
            case 1:
                if (s.trippleroomSpace == 0)
                {
                    cout << "No Tripple-room Available\n";
                }
                else
                {
                    room.push_back(new trippleroom());
                    room.back()->getInfo();
                    i3++;
                    if(i3==3)
                    {
                        s.trippleroomSpace--;
                        i3=0;
                    }
                }
                break;
            case 2:
                if (s.doubleroomSpace == 0)
                {
                    cout << "No Double-room Available\n";
                }
                else
                {
                    room.push_back(new doubleroom());
                    room.back()->getInfo();
                    i2++;
                    if(i2==2)
                    {
                        s.doubleroomSpace--;
                        i2=0;
                    }
                }
                break;
            case 3:
                if (s.singleroomSpace == 0)
                {
                    cout << "No Single-room Available\n";
                }
                else
                {
                    room.push_back(new singleroom());
                    room.back()->getInfo();
                    s.singleroomSpace--;
                }
                break;
            }
            break;
        case 2:
            cout << "Available space \n";
            cout << "Tripple Room : " << s.trippleroomSpace << '\n';
            cout << "Double Room : " << s.doubleroomSpace<< '\n';
            cout << "Single Room : " << s.singleroomSpace<< '\n';
            break;
        case 3:
            cout << "Enter your USN\n";
            cin >> USN;
            for (it = room.begin(); it != room.end(); it++)
            {
                if ((*it)->usn == USN)
                {
                    cout << "Student Details:\n";
                    cout << "Student Name: " << (*it)->Name << '\n';
                    cout << "USN: " << (*it)->usn << '\n';
                    cout << "Room no.: " << it - room.begin() << '\n';
                    break;
                }
            }
            if (it == room.end())
            {
                cout << "Student not found\n";
            }
            break;
        case 4:
            cout << "Enter your USN\n";
            cin >> USN;
            for (it = room.begin(); it != room.end(); it++)
            {
                if ((*it)->usn == USN)
                {
                    (*it)->Leaving();
                    delete *it;
                    break;
                }
            }

            if (it == room.end())
            {
                cout << "Student not found\n";
            }
            else
            {
                room.erase(it);
            }
            break;
        case 5:
            exit(0);
        default:
            cout << "Enter valid choice\n";
            exit(0);
            break;
        }
        cout << "Do you want to continue(y/n)\n";
        cin >> choice;
    } while (choice == 'y');

    return 0;
}
