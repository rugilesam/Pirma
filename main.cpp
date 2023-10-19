
#include "studentai.h"


int main() {
  char p;
  cout << "Ar norite vesti duomenys patys(t) ar nuskaityti iš failo(n)?";
  cin >> p;
  if (p == 't') {
    vector<Duomenys> studentai;
    int pasirinkimas;
    cout << "Pasirinkite, ar norite vesti rezultatus (0) ar generuoti atsitiktinai (1): ";
    cin >> pasirinkimas;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char pasirinkimasgalut;
    cout << "Pasirinkite, ar norite naudoti vidurkį ('v') ar medianą ('m'): ";
    cin >> pasirinkimasgalut;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        Duomenys studentas;
        cout << "Įveskite studento pavardę (Enter norint baigti): ";
        getline(cin, studentas.pav);

        if (studentas.pav.empty()) {
            break;
        }

        cout << "Įveskite studento vardą: ";
        getline(cin, studentas.vard);

        if (pasirinkimas == 0) {
            cout << "Įveskite studento namų darbų rezultatus (įveskite -1, kad baigtumėte): ";
            int pazymys;
            while (true) {
                cin >> pazymys;
                if (pazymys == -1) {
                    break; // baigti namu darbų ivedimą jei ivestas -1
                }
                studentas.nd.push_back(pazymys);
            }

            cout << "Įveskite studento egzamino rezultatą: ";
            cin >> studentas.egz;
        } else if (pasirinkimas == 1){
            int s;
            cout << "Įveskite namų darbų skaičiu: ";
            cin >> s;
            // sugeneruoti atsitiktinius namu darbu rezultatus
            for (int j = 0; j < s; j++) {
                int atsitiktinisPazymys = rand() % 10 + 1; // generuojame nuo 1 iki 10
                studentas.nd.push_back(atsitiktinisPazymys);
            }
            studentas.egz = rand() % 10 + 1;
        }else{    cout << "Įvedete neteisingą pirmo klausimo simbolį" <<endl;
        }

        if (pasirinkimasgalut == 'v') {
            studentas.galvid = skaiciuotiGalutiniVid(studentas);
        } else if (pasirinkimasgalut == 'm') {
            studentas.galmed = skaiciuotiGalutiniMed(studentas);
        } else {
            cout << "Įvedete neteisingą antro klausimo simbolį" << endl;
        }

        studentai.push_back(studentas);

        // isvalyti cin buferi po namu darbu ivedimo
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << left << setw(15) << "Pavardė" << left << setw(15) << "Vardas" << left << setw(10) << "Galutinis (" << pasirinkimasgalut << ".)" << endl;
    cout << "-------------------------------------------------" << endl;


    for (const Duomenys& studentas : studentai) {
        cout << left << setw(15) << studentas.pav
        << left << setw(15) << studentas.vard;

        if (pasirinkimasgalut == 'v' && studentas.galvid > 0) {
            cout << left << setw(20) << fixed << setprecision(2) << studentas.galvid;
        } else if (pasirinkimasgalut == 'm' && studentas.galmed > 0) {
            cout << left << setw(20) << fixed << setprecision(2) << studentas.galmed;
        }

        cout << endl;
    }
  } else if (p == 'n'){
    vector<Duomenys> studentai;

        ifstream failas("studentai.txt");

        if (!failas) {
                cerr << "Nepavyko atidaryti failo." << endl;
                return 1;
        }

        string eilute;
        while (getline(failas, eilute)) {
            Duomenys studentas;
            istringstream iss(eilute);
            iss >> studentas.pav >> studentas.vard;
                    int pazymys;
                    while (iss >> pazymys) {
                        studentas.nd.push_back(pazymys);
                    }
                    iss.clear();
                    iss >> studentas.egz;


                    studentas.galvid = skaiciuotiGalutiniVid(studentas);
                        studentas.galmed = skaiciuotiGalutiniMed(studentas);
                    studentai.push_back(studentas);
                }

                failas.close();

            sort(studentai.begin(), studentai.end(), [](const Duomenys& a, const Duomenys& b) {
                    return a.vard < b.vard;
                });

    cout << left << setw(15) << "Pavardė" << left << setw(15) << "Vardas" << left << setw(15) << "Galutinis (vid.)" << left << setw(15) << "Galutinis (med.)" << endl;
    cout << "-------------------------------------------------" << endl;


    for (const Duomenys& studentas : studentai) {
            cout << left << setw(15) << studentas.pav
            << left << setw(15) << studentas.vard << left << setw(20) <<     fixed << setprecision(2) << studentas.galvid << left << setw(20) << fixed << setprecision(2) << studentas.galmed <<endl;
        }
  } else {
    cout << "Reikia ivesti simboli t arba n";
  }
    return 0;
} 

