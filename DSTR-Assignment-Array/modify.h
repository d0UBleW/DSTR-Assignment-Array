#pragma once

#include <iostream>
#include <vector>

#include "center.h"
#include "subject.h"
#include "tutor.h"

using namespace std;

void modifyTutor(std::vector<Tutor *> &tutorV, bool isAdmin = true);
