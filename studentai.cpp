#include "studentai.h"



int kiek_sk(const string& failas) {
    int kiekis = 0;
    string numberPart;
    bool rastas_sk = false;

    for (char c : failas) {
        if (rastas_sk) {
            if (std::isdigit(c)) {
                numberPart += c;
            }
            else {
                break;  // Sustoja kai suranda ne skaiciu
            }
        }
        else if (std::isdigit(c)) {
            rastas_sk = true;
            numberPart += c;
        }
    }

    if (!numberPart.empty()) {
        // Surinktas skaicius is eilutes paverciamas i sveikajo skaiciu
        std::istringstream(numberPart) >> kiekis;
    }

    return kiekis;
}


//failo generavimas
void gen_failas(int stud_gen_sk, int stud_gen_nd) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> rand_score(1, 10);



    ofstream out("Kursiokai" + to_string(stud_gen_sk) + ".txt");
    out << left << setw(20) << "Vardas" << setw(20) << "Pavarde";

    for (int m = 1; m <= stud_gen_nd; m++) {
        out << setw(7) << "ND" + to_string(m);
    }

    out << setw(7) << "Egz." << setw(15) << endl;
    out << endl;

    for (int i = 1; i <= stud_gen_sk; i++) {
        Duomenys stud;
        stud.vard = "Vardas" + to_string(i);
        stud.pav = "Pavarde" + to_string(i);
        out << left << setw(20) << stud.vard << setw(20) << stud.pav;
        stud.egz = rand_score(gen);

        double suma = 0;

        for (int j = 0; j < stud_gen_nd; j++) {
            int pazymys = rand_score(gen);
            stud.nd.push_back(pazymys);
            suma += pazymys;

            out << setw(7) << pazymys;
        }
        out << setw(7) << stud.egz << endl;
    }
    out.close();
}



//Palyginimas pagal P,V,G
bool palyginimas(Duomenys& a, Duomenys& b, string rus_index) {
    if (rus_index == "p") {
        return a.pav < b.pav;
    }
    else if (rus_index == "v") {
        return a.vard < b.vard;
    }
    else if (rus_index == "g") {
        return a.galutinis < b.galutinis;
    }
    else {
        // Automatinis nustatymas, kai rus_index neatpazintas
        return false;
    }
}
