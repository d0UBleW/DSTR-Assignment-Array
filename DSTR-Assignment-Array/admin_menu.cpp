#include <iostream>
#include <string>
#include "admin_menu.h"
#include "validate.h"
#include "student_menu.h"
#include "display.h"
#include "tutor.h"
#include "file2struct.h"
#include "add.h"
#include "authentication.h"
#include "sort.h"

using namespace std;

void startMenu(vector<Tutor> &tutorV)
{
	
	while (true)
	{
        clearScreen();
		cout << "Welcome to eXcel Tuition Centre" << endl;
		cout << "Who are you?" << endl;
		cout << "1) Admin" << endl;
		cout << "2) Student" << endl;
		cout << "3) Student Register" << endl;
		cout << "0) Exit" << endl;
		string sentence = "Enter your choice: ";
		int choice = checkIntInput(sentence);
		if (isChoiceInMenuRange(choice, 3)) 
		{
			//code here
			switch (choice)
			{
			case 0:
				cout << "Thank you for using this system" << endl;
				return;

			case 1:
				if (adminLogin()) { adminMainMenu(tutorV); }
				else { continue; }
				break;
			case 2:
				if (studentLogin()) { studentRatingMenu(tutorV); }
				else { continue; }
				break;
			case 3:
				registerStudent();
				break;
			}

		}
	}
	
}


void adminMainMenu(vector<Tutor> &tutorV)

{
	
	while (true)
	{
        clearScreen();
		cout << "Welcome back admin, please select a function" << endl;
		cout << "1) Add Tutor" << endl;
		cout << "2) Display Tutor" << endl;
		cout << "3) Sort Tutor" << endl;
		cout << "4) Search Tutor" << endl;
		cout << "5) Modify Tutor" << endl;
		cout << "6) Termination or Delete Tutor" << endl;
		cout << "7) Register New Admin" << endl;
		cout << "0) Logout" << endl;
		string sentence = "Enter your choice: ";
		int choice = checkIntInput(sentence);
		if (isChoiceInMenuRange(choice, 7))
		{
			switch (choice)
			{
			case 0:
				return;
				
			case 1:
				addMenu(tutorV);
				break;
			case 2:
				DisplayTutor(tutorV);
				break;
			case 3:
				sortMenu(tutorV);
				break;
			case 4:
				searchMenu(tutorV);
				break;
			case 5:
				//Modify method call here
				// please delete this cout after implementing modify
				cout << "No yet impemented modify" << endl;
				break;
			case 6:
				deleteMenu(tutorV);
				break;

			case 7:
				registerAdmin();
				break;
			}
			
		}
	}
	
}


void addMenu(vector<Tutor> &tutorV)
{
	
	while (true)
	{
        clearScreen();
		Tutor tutor;
		cout << "Where you want to add?" << endl;
		cout << "1) Add to First" << endl;
		cout << "2) Add to Last" << endl;
		cout << "0) Previous Page" << endl;
		string sentence = "Enter your choice: ";
		int choice = checkIntInput(sentence);
		if (isChoiceInMenuRange(choice, 2))
		{
			//code here
			switch (choice)
			{
			case 0:
				return;

			case 1:
				//code here
				tutor = addingInterface(tutorV);
				addToFront(tutorV, tutor);
				tutorToFile(tutorV, TUTOR_FILE);
				cout << "Tutor Added to Front Succesfully!\n";
				break;
			case 2:
				//code here
				tutor = addingInterface(tutorV);
				addToBack(tutorV, tutor);
				tutorToFile(tutorV, TUTOR_FILE);
				cout << "Tutor Added to Back Succesfully!\n";
				break;
			}
			
		}
	}
	
}

void sortMenu(std::vector<Tutor> &tutorV)
{
	while (true)
	{
        clearScreen();
		cout << "How do you want to sort?" << endl;
		cout << "1) Sort by Tutors ID" << endl;
		cout << "2) Sort by Pay Rate " << endl;
		cout << "3) Sort by Overall Performance" << endl;
		cout << "0) Previous Page" << endl;
		string sentence = "Enter your choice: ";
		int choice = checkIntInput(sentence);
		if (isChoiceInMenuRange(choice, 3))
		{
            int (*CompareFn)(Tutor &, Tutor &) = nullptr;
            switch (choice) {
                case 1:
                    CompareFn = &CompareTutorID;
                    break;
                case 2:
                    CompareFn = &CompareTutorPay;
                    break;
                case 3:
                    CompareFn = &CompareTutorRating;
                    break;
                case 0:
                    return;
            }
            while (true) {
                cout << "Sort in:\n";
                cout << "1) Ascending order\n";
                cout << "2) Descending order\n";
                cout << "0) Back\n";
                int option = checkIntInput("Enter your choice: ");
                if (option == 0) break;

                char order = 'a';
                if (option == 2) order = 'd';
                std::vector<Tutor> sortedTutorV =
                    sortTutor(tutorV, (*CompareFn), order);
                DisplayTutor(sortedTutorV);
                clearScreen();
            }
		}
	}
	
}

void searchMenu(vector<Tutor> &tutorV)
{
	while (true)
	{
		cout << "How do you want to search?" << endl;
		cout << "1) Search by Tutor ID" << endl;
		cout << "2) Search by overall performance" << endl;
		cout << "0) Previous Page" << endl;
		string sentence = "Enter your choice: ";
		int choice = checkIntInput(sentence);
		if (isChoiceInMenuRange(choice, 2))
		{
			//code here
		}
	}
	
}

void deleteMenu(vector<Tutor> &tutorV)
{
	while (true)
	{
		cout << "Which function you need?" << endl;
		cout << "1) Terminate all expired tutors" << endl;
		cout << "2) Delete specific tutor data" << endl;
		cout << "0) Previous Page" << endl;
		string sentence = "Enter your choice: ";
		int choice = checkIntInput(sentence);
		if (isChoiceInMenuRange(choice, 2))
		{
			//code here
		}
	}
	
}

void clearScreen() {
    system("cls || clear");
}
