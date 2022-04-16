#include <iostream>
#include <vector>
#include "tutor.h"
#include "center.h"
#include "subject.h"
#include "date.h"
#include "display.h"

using namespace std;


void DisplayTutor(vector<Tutor> arr, bool isAdmin)
{

    int size = arr.size();
    int end;

    if (isAdmin)
    {
        end = 3;
    }
    else
    {
        end = 5;
    }
    
    int choice = 0;
    int start = 0;
   



    while (true)
    {
        system("cls");
        
        
        for (int i = start; i < end; i++)
        {
            if (i < size)
            {
                if (isAdmin)
                {
                    cout << "TutorID: " << arr.at(i).ID << endl;
                    cout << "Tutur Name: " << arr.at(i).name << endl;
                    cout << "PayRate: " << arr.at(i).payRate << endl;
                    cout << "Rating: " << arr.at(i).rating << endl;
                    cout << "Phoe Number: " << arr.at(i).phone << endl;
                    cout << "Joined Date: " << arr.at(i).joinDate.ToString() << endl;
                    cout << "Termination Date: " << arr.at(i).terminateDate.ToString() << endl;
                    cout << "Center ID: " << arr.at(i).center->ID << endl;
                    cout << "Center Name: " << arr.at(i).center->name << endl;
                    cout << "Subject ID: " << arr.at(i).subject->ID << endl;
                    cout << "Subject Name: " << arr.at(i).subject->name << endl;
                    
                }
                else
                {
                    cout << "TutorID: " << arr.at(i).ID << endl;
                    cout << "Tutur Name: " << arr.at(i).name << endl;
                }
                cout << endl;
                
            }
            else
            {
                break;
            }
        }


        while (std::cout << "Prev or Next (0 to Prev 1 to Next 2 to Exit): " && !(std::cin >> choice)) {
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
            std::cout << "Invalid input; please re-enter.\n";
        }
        if (choice == 1)
        {
            if (end <= size)
            {
                start += (end-start);
                end += (end - start);
            }
            continue;
        }
        else if (choice == 0)
        {
            
            if (start >= 2)
            {
                
                
                start -= (end - start);
                end -= (end - start);
            }
            continue;


        }
        else if (choice == 2)
        {
            break;
        }
        else
        {
            continue;
        }



    }


}