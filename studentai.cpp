#include "studentai.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <algorithm>

using namespace std;

double skaiciuotiGalutiniVid(const Duomenys& studentas) {
    int ndSum = accumulate(studentas.nd.begin(), studentas.nd.end(), 0);
    return 0.4 * (ndSum / static_cast<double>(studentas.nd.size())) + 0.6 * studentas.egz;
}

double skaiciuotiGalutiniMed(const Duomenys& studentas) {
    vector<int> pazymiai = studentas.nd;
    pazymiai.push_back(studentas.egz);

    sort(pazymiai.begin(), pazymiai.end());

    vector<int>::size_type n = pazymiai.size();
    if (n % 2 == 0) {
        int vidurinisKairys = pazymiai[(n - 1) / 2];
        int vidurinisDesinys = pazymiai[n / 2];
        return (vidurinisKairys + vidurinisDesinys) / 2.0;
    } else {
        return pazymiai[n / 2];
    }
}
