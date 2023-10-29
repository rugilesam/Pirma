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


//#include "studentai.h"
#include "Timer.h"
// Funkcija generuoti atsitiktinį pažymį nuo 1 iki 10
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

int main() {
    // Inicializuojame atsitiktinių skaičių generatorių
    srand(time(0));

    // Penki failų pavadinimai
    string fileNames[] = {"studentai1000.txt", "studentai10000.txt", "studentai100000.txt", "studentai1000000.txt", "studentai10000000.txt"};

    // Penki skirtingų įrašų kiekiai
    int recordCounts[] = {1000, 10000, 100000, 1000000, 10000000};

    Timer t;
  
    for (int i = 0; i < 5; i++) {
        string fileName = fileNames[i];
        int numRecords = recordCounts[i];

        // Atidarome failą rašymui
        ofstream file(fileName);

        if (!file.is_open()) {
            cerr << "Nepavyko atidaryti failo: " << fileName << endl;
            return 1;
        }

    
        // Generuojame studentų įrašus ir rašome į failą
        for (int j = 1; j <= numRecords; j++) {
            file << "Vardas" << j << " Pavarde" << j << " ";
            for (int k = 0; k < 5; k++) {
                file << generateRandomGrade() << " ";
            }
            file << generateRandomGrade() << endl;

        }

        file.close();
        //cout << "Sugeneruotas failas: " << fileName << " su " << numRecords << " įrašais." << endl;
        cout << "Studentai failas su " << numRecords << " elementų užpildymas užtruko: " << t.elapsed() << " s\n";

    }
    for (const std::string &fileName : fileNames) {
    //vector<Duomenys> studentai;
      
        ifstream failas(fileName);

        if (!failas.is_open()) {
            cerr << "Nepavyko atidaryti failo." << endl;
            return 1;
        }

        int pas;
        cout << "Jei norite tirti vector (0), jei list (1): " ;
        cin >> pas;
        
        Timer t;
        
        ofstream vargsiukaiFile("vargsiukai.txt");
        ofstream kietiakiaiFile("kietiakiai.txt");


        string line;
        
        if (pas == 0){
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
                
                if (studentas.galvid < 5.0) {
                    vargsiukaiFile << studentas.vard << " " << studentas.pav << " " << studentas.galvid << endl;
                } else {
                    kietiakiaiFile << studentas.vard << " " << studentas.pav << " " << studentas.galvid << endl; //naudoti per vektoriu kazkaip???
                }
            }
        } else if(pas == 1){
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
                
                if (studentas.galvid < 5.0) {
                    vargsiukaiFile << studentas.vard << " " << studentas.pav << " " << studentas.galvid << endl;
                } else {
                    kietiakiaiFile << studentas.vard << " " << studentas.pav << " " << studentas.galvid << endl;
                }
            }
        }
        failas.close();
        vargsiukaiFile.close();
        cout << fileName <<" Vargsiukai.txt elementų užpildymas užtruko: " <<  t.elapsed() << " s\n";
        kietiakiaiFile.close();
        cout << fileName<<" Kietekai.txt elementų užpildymas užtruko: " << t.elapsed() << " s\n";
        }
  
    return 0;
}
