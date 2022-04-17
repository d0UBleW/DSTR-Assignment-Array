#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "student.h"
#include "admin.h"
#include "date.h"
#include "tutor.h"
#include "subject.h"
#include "center.h"
#include "file2struct.h"

std::vector<Tutor> fileToTutor(const std::string filename) {
    std::vector<Tutor> tutorV;
    std::fstream fileHandler(filename, std::ios::in);
    std::string line = "";
    std::string delim = "|";

    while (!getline(fileHandler, line).eof()) {
        std::vector<std::string> data = splitString(line, delim);
        Tutor t;
        t.ID = data.at(0);
        t.name = data.at(1);
        t.payRate = std::stof(data.at(2));
        t.rating = std::stof(data.at(3));
        t.phone = data.at(4);
        t.joinDate = Date(data.at(5));
        t.terminateDate = Date(data.at(6));
        t.center = getCenterByID(_CENTER, data.at(7));
        t.subject = getSubjectByID(_SUBJECT, data.at(8));
        t.countRate = std::stoul(data.at(9));
        tutorV.push_back(t);
    }
    fileHandler.close();
    return tutorV;
}

std::vector<Subject> fileToSubject(const std::string filename) {
    std::vector<Subject> subjectV;
    std::fstream fileHandler(filename, std::ios::in);
    std::string line = "";
    std::string delim = "|";

    while (!getline(fileHandler, line).eof()) {
        std::vector<std::string> data = splitString(line, delim);
        Subject s;
        s.ID = data.at(0);
        s.name = data.at(1);
        subjectV.push_back(s);
    }
    fileHandler.close();
    return subjectV;
}

std::vector<Center> fileToCenter(const std::string filename) {
    std::vector<Center> centerV;
    std::fstream fileHandler(filename, std::ios::in);
    std::string line = "";
    std::string delim = "|";

    while (!getline(fileHandler, line).eof()) {
        std::vector<std::string> data = splitString(line, delim);
        Center c;
        c.ID = data.at(0);
        c.name = data.at(1);
        centerV.push_back(c);
    }
    fileHandler.close();
    return centerV;
}

void tutorToFile(std::vector<Tutor> &tutorV, std::string filename) {
    std::fstream fileHandler(filename, std::ios::out);
    std::string delim = "|";
    std::vector<Tutor>::iterator it;

    for (it = tutorV.begin(); it != tutorV.end(); it++) {
        Tutor t = *it;
        std::string ID = t.ID; 
        std::string name = t.name; 
        std::string payRate = float_to_str_prec(t.payRate);
        std::string rating = float_to_str_prec(t.rating);
        std::string phone = t.phone; 
        std::string joinDate = t.joinDate.ToString();
        std::string terminateDate = t.terminateDate.ToString();
        std::string center = t.center->ID;
        std::string subject = t.subject->ID; 
        std::string countRate = std::to_string(t.countRate);
        std::string line = ID + delim + name + delim + payRate + delim +
            rating + delim + phone + delim + joinDate + delim + terminateDate +
            delim + center + delim + subject + delim + countRate;
        fileHandler << line << '\n';
    }
    fileHandler.close();
    
}

std::vector<Student> fileToStudent(std::string filename) {
    std::vector<Student> studentV;
    std::fstream fileHandler(filename, std::ios::in);
    std::string line = "";
    std::string delim = "|";

    while (!getline(fileHandler, line).eof()) {
        std::vector<std::string> data = splitString(line, delim);
        Student stu;
        stu.username = data.at(0);
        stu.password = std::stoul(data.at(1));
        studentV.push_back(stu);
    }
    fileHandler.close();
    return studentV;
}

void studentToFile(std::vector<Student> &studentV, std::string filename) {
    std::fstream fileHandler(filename, std::ios::out);
    std::string delim = "|";
    std::vector<Student>::iterator it;

    for (it = studentV.begin(); it != studentV.end(); it++) {
        Student stu = *it;
        std::string username = stu.username;
        std::string password = std::to_string(stu.password);
        fileHandler << username << delim << password << '\n';
    }
    fileHandler.close();
}

std::vector<Admin> fileToAdmin(std::string filename) {
    std::vector<Admin> adminV;
    std::fstream fileHandler(filename, std::ios::in);
    std::string line = "";
    std::string delim = "|";

    while (!getline(fileHandler, line).eof()) {
        std::vector<std::string> data = splitString(line, delim);
        Admin stu;
        stu.username = data.at(0);
        stu.password = std::stoul(data.at(1));
        adminV.push_back(stu);
    }
    fileHandler.close();
    return adminV;
}

void adminToFile(std::vector<Admin> &adminV, std::string filename) {
    std::fstream fileHandler(filename, std::ios::out);
    std::string delim = "|";
    std::vector<Admin>::iterator it;

    for (it = adminV.begin(); it != adminV.end(); it++) {
        Admin stu = *it;
        std::string username = stu.username;
        std::string password = std::to_string(stu.password);
        fileHandler << username << delim << password << '\n';
    }
    fileHandler.close();
}

std::vector<std::string> splitString(std::string str, std::string delim) {
    std::vector<std::string> data;
    size_t start = 0;
    size_t end = str.find(delim);
    while (end != std::string::npos) {
        data.push_back(str.substr(start, end-start));
        start = end + delim.length();
        end = str.find(delim, start);
    }
    data.push_back(str.substr(start));
    return data;
}

std::string float_to_str_prec(float f, int n) {
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << f;
    return out.str();
}
