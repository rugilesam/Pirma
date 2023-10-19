#ifndef STUDENTAI_H
#define STUDENTAI_H

#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

struct Duomenys {
    string vard, pav;
    int egz;
    double galvid, galmed;
    vector<int> nd;
};

double skaiciuotiGalutiniVid(const Duomenys& studentas);

#endif // STUDENTAI_H
