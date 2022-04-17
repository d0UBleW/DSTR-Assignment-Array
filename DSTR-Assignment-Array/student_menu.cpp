#include <iostream>
#include <string>
#include "validate.h"
#include "student_menu.h"
#include "tutor.h"
#include "display.h"


using namespace std;



void studentRatingMenu(vector<Tutor> arr)
{
	while (true)
	{
		cout << "Welcome student what you want to do?" << endl;
		cout << "1) Rate a tutor" << endl;
		cout << "2) Display list of tutor" << endl;
		cout << "0) Log Out" << endl;
		string sentence = "Enter your choice: ";
		int choice = checkIntInput(sentence);
		if (isChoiceInMenuRange(choice, 2))
		{
			switch (choice)
			{
			case 0:
				return;

			case 1:
				//code here
				break;
			case 2:
				DisplayTutor(arr, false);
				break;
			}

		}
	}
	
	
}