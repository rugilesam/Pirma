#include "studentai.h"

double skaiciuotiGalutiniVid(const Duomenys& studentas) {
    int ndSum = accumulate(studentas.nd.begin(), studentas.nd.end(), 0);
    return 0.4 * (ndSum / static_cast<double>(studentas.nd.size())) + 0.6 * studentas.egz;
}
