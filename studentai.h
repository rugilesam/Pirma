#ifndef STUDENTAI_H
#define STUDENTAI_H

#include <string>
#include <vector>

struct Duomenys {
    std::string vard, pav;
    int egz;
    double galvid, galmed;
    std::vector<int> nd;
};

double skaiciuotiGalutiniVid(const Duomenys& studentas);
double skaiciuotiGalutiniMed(const Duomenys& studentas);

#endif // STUDENTAI_H
