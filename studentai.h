#ifndef STUDENTAI_H_INCLUDED
#define STUDENTAI_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cctype>
#include <stdexcept>
#include <chrono>

using namespace std;
struct Duomenys
    {
        string vard, pav;
        vector <int> nd;
        int egz{};
        float vid{};
        //float med{};
        float galutinis{};
    };

// Aibūdiname ContainerTypeTrait šabloną
template <typename S>
struct ContainerTypeTrait;

// Specifikuojame atvejui vector<studentas>
template <>
struct ContainerTypeTrait<vector<Duomenys>> {
    using type = vector<int>;
};

// Specifikuojame atvejui list<studentas>
template <>
struct ContainerTypeTrait<list<Duomenys>> {
    using type = list<int>;
};




void isvedimas(vector<Duomenys> &grupe, string gen, string ats,string rus_index);
void isvedimas_list(list<Duomenys> &grupe, string gen, string ats,string rus_index);
bool palyginimas(Duomenys &a, Duomenys &b, string rus_index);
int kiek_sk(const string& failas);
void gen_failas(int stud_gen_sk, int stud_gen_nd);





template <typename S>
void skaiciavimas(S &grupe, Duomenys &temp) {
    double suma = 0;

    for (int i = 0; i < temp.nd.size(); i++) {
        suma += temp.nd[i];
    }

    temp.vid = 0.4 * (suma / temp.nd.size()) + 0.6 * temp.egz;

    // Nustatome, kokį konteinerio tipą imti
    typename ContainerTypeTrait<S>::type visipaz;

    for (int i : temp.nd) {
        visipaz.push_back(i);
    }

    visipaz.push_back(temp.egz);

}




template <class P>
void pal_pav(P &grupe, string rus_index) {
    sort(grupe.begin(), grupe.end(), [rus_index](Duomenys &a, Duomenys &b) {
        return palyginimas(a, b, rus_index);
    });
}
template <class P>
void pal_pav_list(P &grupe, string rus_index) {
    grupe.sort([rus_index](Duomenys &a, Duomenys &b) {
        return palyginimas(a, b, rus_index);
    });
}

template <class T>
void nuskaitymas(const string& failas, T& grupe) {
    std::ifstream in(failas);
    if (!in.is_open()) {
        std::cerr << "Klaida: Failas nerastas." << std::endl;
        return;
    }

    string pavadinimas, praleidziam;
    getline(in, pavadinimas);
    Duomenys temp;
    int laik_kint, suma = 0, m = 0;
    double nd_sk = 0;
    int raidziu_sk = 0;
    for (char ch : pavadinimas) {
        if (isalpha(ch)) {
            raidziu_sk++;
        }
    }

    nd_sk = (raidziu_sk - 6 - 7 - 3) / 2;


    while (in >> temp.vard >> temp.pav) {

        for (int i = 0; i < nd_sk; i++) {
        in >> laik_kint;
            temp.nd.push_back(laik_kint);
            suma+=laik_kint;
        }

    in >> temp.egz;
    getline(in, praleidziam);

        skaiciavimas_2(suma,nd_sk,temp,grupe);
        m++;
    }

    in.close();
}


template <class S>
void skaiciavimas_2(int &suma, int nd_sk, Duomenys &temp, S &grupe) {

    temp.vid = static_cast<float>(suma)/nd_sk;
    temp.galutinis = static_cast<float>(temp.vid*0.4 + temp.egz*0.6);


    grupe.push_back(temp);
    temp.nd.clear();
    suma = 0;
}





/*
//strategija 1
 template <class P, class K>
 void padalinimas(P& grupe, K& kietiakai, K& vargsiukai) {

     for (const auto &a: grupe) {
         if (a.galutinis >= 5) {
             kietiakai.push_back(a);
         }
         else {
             vargsiukai.push_back(a);
         }
     }
 }
 */
// strategija 2

 template <class P>
 void padalinimas(P& grupe, P& vargsiukai) {

     // Iš pradinio konteinerio perkeliami vargšiukai į naująjį "vargšiukai" konteinerį
     auto partitionPoint = std::partition(grupe.begin(), grupe.end(), [](const Duomenys& a) {
         return a.galutinis < 5;
     });

     vargsiukai.insert(vargsiukai.end(), partitionPoint, grupe.end());

     // Iš pradinio konteinerio ištrinami vargšiukai
     grupe.erase(partitionPoint, grupe.end());
}

//strategija 3
/*
template <class P>
void padalinimas(P& grupe, P& vargsiukai) {
    auto partitionPoint = std::partition(grupe.begin(), grupe.end(), [](const Duomenys& a) {
        return a.galutinis < 5;
        });

    // Visus studentus, kuriu galutinis < 5 dedame i vargsiukus
    vargsiukai.insert(vargsiukai.end(), grupe.begin(), partitionPoint);

    // Is grupes istriname studentus, kurie buvo ideti i vargsiukus
    grupe.erase(grupe.begin(), partitionPoint);
}
*/

//spausdinimo funkcija kietiakam ir vargsiukam
template <class P>
void padalinto_spausdinimas(const P& Duomenys, const string& failo_pav) {
    ofstream out(failo_pav);

    out << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis" << endl;
    out << endl;

    for (const auto& stud : Duomenys) {
        out << left << setw(20) << stud.pav << setw(20) << stud.vard << setw(20) << fixed << setprecision(2) << stud.galutinis << endl;


    }
    out.close();
}
#endif
