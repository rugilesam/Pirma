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
using namespace std;

struct Duomenys {
    std::string vard, pav;
    int egz;
    double galvid, galmed;
    std::vector<int> nd;
};

double skaiciuotiGalutiniVid(const Duomenys& studentas);
double skaiciuotiGalutiniMed(const Duomenys& studentas);

#endif // STUDENTAI_H
