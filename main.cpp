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
#include <list>

using namespace std;

struct Duomenys {
    string vard, pav;
    int egz;
    double galvid, galmed;
    vector<int> nd;
};
struct Duomenys1 {
    string vard, pav;
    int egz;
    double galvid, galmed;
    list<int> nd;
};
#include "Timer.h"

int generateRandomGrade() {
    return rand() % 10 + 1;
}

double skaiciuotiGalutiniVid(const Duomenys& studentas) {
    int ndSum = accumulate(studentas.nd.begin(), studentas.nd.end(), 0);
    return 0.4 * (ndSum / static_cast<double>(studentas.nd.size())) + 0.6 * studentas.egz;
}

double skaiciuotiGalutiniVid1(const Duomenys1& studentas) {
    int ndSum = accumulate(studentas.nd.begin(), studentas.nd.end(), 0);
    return 0.4 * (ndSum / static_cast<double>(studentas.nd.size())) + 0.6 * studentas.egz;
}

void strategija1(const vector<Duomenys>& studentai, vector<Duomenys>& vargsiukai, vector<Duomenys>& kietiakai) {
    for (const auto& studentas : studentai) {
        if (skaiciuotiGalutiniVid(studentas) < 5.0) {
            vargsiukai.push_back(studentas);
        } else {
            kietiakai.push_back(studentas);
        }
    }
}

void strategija2(list<Duomenys1>& studentai, list<Duomenys1>& vargsiukai) {
    auto it = studentai.begin();
    while (it != studentai.end()) {
        if (skaiciuotiGalutiniVid1(*it) < 5.0) {
            vargsiukai.push_back(*it);
            it = studentai.erase(it);
        } else {
            ++it;
        }
    }
}

int main() {
  
    srand(time(0));

  
    string fileNames[] = {"studentai1000.txt", "studentai10000.txt", "studentai100000.txt", "studentai1000000.txt", "studentai10000000.txt"};
    
    for (const std::string &fileName : fileNames) {
        ifstream failas(fileName);

        if (!failas.is_open()) {
            cerr << "Nepavyko atidaryti failo." << endl;
            return 1;
        }

        int pas;
        cout << "Jei norite tirti strategija 1 (1), jei strategija 2 (2): ";
        cin >> pas;

        Timer t;

        if (pas == 1) {
            vector<Duomenys> studentai;
            vector<Duomenys> vargsiukai;
            vector<Duomenys> kietiakai;

            string line;
            while (getline(failas, line)) {
                Duomenys studentas;
                istringstream iss(line);
                iss >> studentas.vard >> studentas.pav;
                int pazymys;
                for (int i = 0; i < 5; i++) {
                    iss >> pazymys;
                    studentas.nd.push_back(pazymys);
                }
                iss >> studentas.egz;
                studentas.galvid = skaiciuotiGalutiniVid(studentas);
                studentai.push_back(studentas);
            }

            t.reset();
            strategija1(studentai, vargsiukai, kietiakai);
            cout << fileName << " Studentų rūšiavimas strategija 1 užtruko: " << t.elapsed() << " s\n";

            
            ofstream vargsiukaiFile("vargsiukai_strategija1_" + fileName);
            ofstream kietiakaiFile("kietiakiai_strategija1_" + fileName);

            for (const auto& vargsiukas : vargsiukai) {
                vargsiukaiFile << vargsiukas.vard << " " << vargsiukas.pav << " " << vargsiukas.galvid << endl;
            }

            for (const auto& kietiakas : kietiakai) {
                kietiakaiFile << kietiakas.vard << " " << kietiakas.pav << " " << kietiakas.galvid << endl;
            }

            vargsiukaiFile.close();
            kietiakaiFile.close();
        } else if (pas == 2) {
            list<Duomenys1> studentai;
            list<Duomenys1> vargsiukai;

            string line;
            while (getline(failas, line)) {
                Duomenys1 studentas;
                istringstream iss(line);
                iss >> studentas.vard >> studentas.pav;
                int pazymys;
                for (int i = 0; i < 5; i++) {
                    iss >> pazymys;
                    studentas.nd.push_back(pazymys);
                }
                iss >> studentas.egz;
                studentas.galvid = skaiciuotiGalutiniVid1(studentas);
                studentai.push_back(studentas);
            }

            t.reset();
            strategija2(studentai, vargsiukai);
            cout << fileName << " Studentų rūšiavimas strategija 2 užtruko: " << t.elapsed() << " s\n";

            
            ofstream vargsiukaiFile("vargsiukai_strategija2_" + fileName);
            for (const auto& vargsiukas : vargsiukai) {
                vargsiukaiFile << vargsiukas.vard << " " << vargsiukas.pav << " " << vargsiukas.galvid << endl;
            }

            vargsiukaiFile.close();
        }

        failas.close();
    }

    return 0;
}
