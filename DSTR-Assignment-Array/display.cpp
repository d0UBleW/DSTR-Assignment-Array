#include <iostream>
#include <vector>

#include "admin_menu.h"
#include "center.h"
#include "date.h"
#include "display.h"
#include "subject.h"
#include "tutor.h"
#include "validate.h"

using namespace std;

// displaying tutor
void DisplayTutor(vector<Tutor *> &arr, bool isAdmin)
{
    size_t size = arr.size();
    if (size == 0)
    {
        std::cout << "No tutor record to be displayed\n";
        Enter();
        return;
    }
    size_t step = 5; // how many tutor being display per page

    if (isAdmin) step = 3; // set tutor display only 3 per page

    int choice = 0;
    size_t start = 0;  // start of each page display
    size_t end = step; // end of each page display

    while (true)
    {
        clearScreen();
        for (size_t i = start; i < end && i < size; i++)
        {
            cout << "Tutor ID: " << arr.at(i)->ID << endl;
            cout << "Tutor Name: " << arr.at(i)->name << endl;
            // if its not admin then only show
            // tutor id and name
            if (!isAdmin)
            {
                cout << endl;
                continue;
            }

            cout << "Pay Rate: " << arr.at(i)->payRate << endl;
            cout << "Rating: " << arr.at(i)->rating << endl;
            cout << "Phone Number: " << arr.at(i)->phone << endl;
            cout << "Address: " << arr.at(i)->address << endl;
            cout << "Joined Date: " << arr.at(i)->joinDate.ToString() << endl;
            cout << "Termination Date: " << arr.at(i)->terminateDate.ToString() << endl;
            cout << "Center ID: " << arr.at(i)->center->ID << endl;
            cout << "Center Name: " << arr.at(i)->center->name << endl;
            cout << "Subject ID: " << arr.at(i)->subject->ID << endl;
            cout << "Subject Name: " << arr.at(i)->subject->name << endl;
            cout << endl;
        }

        string sentence = "Prev or Next (1 to Prev 2 to Next 0 to Exit): ";
        choice = getIntInput(sentence);
        // the statement to move forward and back
        if (choice == 2)
        {
            if (end < size)
            {
                start += step;
                end += step;
            }
        }
        else if (choice == 1)
        {
            if (start >= step)
            {
                start -= step;
                end -= step;
            }
        }
        else if (choice == 0)
        {
            break;
        }
    }
}

// displaying subject in a list
void DisplaySubject()
{
    vector<Subject> arr = _SUBJECT;
    size_t size = arr.size();
    cout << "List of Subject's Information" << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << "Subject ID: " << arr[i].ID << endl;
        cout << "Subject Name: " << arr[i].name << endl;
        cout << endl;
    }
}

// displaying center in a list
void DisplayCenter()
{
    vector<Center> arr = _CENTER;
    size_t size = arr.size();
    cout << "List of Center's Information" << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << "Center ID: " << arr[i].ID << endl;
        cout << "Center Name: " << arr[i].name << endl;
        cout << endl;
    }
}

void DisplayOneTutor(Tutor *tutor, bool isAdmin)
{
    cout << "Tutor ID: " << tutor->ID << endl;
    cout << "Tutor Name: " << tutor->name << endl;

    if (isAdmin)
    {
        cout << "Pay Rate: " << tutor->payRate << endl;
        cout << "Rating: " << tutor->rating << endl;
        cout << "Phone Number: " << tutor->phone << endl;
        cout << "Address: " << tutor->address << endl;
        cout << "Joined Date: " << tutor->joinDate.ToString() << endl;
        cout << "Termination Date: " << tutor->terminateDate.ToString() << endl;
        cout << "Center ID: " << tutor->center->ID << endl;
        cout << "Center Name: " << tutor->center->name << endl;
        cout << "Subject ID: " << tutor->subject->ID << endl;
        cout << "Subject Name: " << tutor->subject->name << endl;
    }
}
