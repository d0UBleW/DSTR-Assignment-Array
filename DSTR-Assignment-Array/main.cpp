#include <iostream>
#include <vector>

#include "add.h"
#include "admin_menu.h"
#include "display.h"
#include "file2struct.h"
#include "sort.h"
#include "tutor.h"

const std::string TUTOR_FILE = "./data/tutor.txt";
const std::string SUBJECT_FILE = "./data/subject.txt";
const std::string CENTER_FILE = "./data/center.txt";
std::vector<Subject> _SUBJECT = fileToSubject(SUBJECT_FILE);
std::vector<Center> _CENTER = fileToCenter(CENTER_FILE);

int main() {
    std::vector<Tutor> tutorV = fileToTutor(TUTOR_FILE);
    startMenu(tutorV);

    /* Tutor tutor = addingInterface(tutorV); */
    /* addToBack(tutorV, tutor); */
    /* std::cout << tutorV.size() << '\n'; */
    /* std::cout << tutorV.back().ID << '\n'; */
    /* tutorToFile(tutorV, TUTOR_FILE); */
    /* DisplayTutor(tutorV); */

    return 0;
}

