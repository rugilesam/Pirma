#include "studentai.h"


int main() {
    string gen;
    string struktura;
    string ats;
    string rus_index;


    cout << "Norite atlikti veiksmus su vector<studentas> (v) ar list <studentas> (l)" << endl;
    cin >> struktura;
    
    if (struktura == "v")
    {
        vector<Duomenys> grupe;


        while (true) {
                    string failas;
                    cout << "Iveskite failo, kuri norite nuskaityti pavadinima (formatas: pavadinimas.txt): ";
                    cin >> failas;
                    cout << "Pagal ka noresite rusiuoti rezultatus: p - pavardes, v - vardus, g - galutini bala?\n";
                    cin >> rus_index;

                    int kiekis = kiek_sk(failas);

                    for (int i = 0; i < 5; i++) {

                        cout << endl << endl;
                        cout << i + 1 << " nuskaitymas" << endl;

                        auto Nuskaitymo_start = chrono::high_resolution_clock::now();
                        nuskaitymas(failas, grupe);
                        auto Nuskaitymo_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Nuskaitymo_laikas = Nuskaitymo_end - Nuskaitymo_start;
                        cout << kiekis << " irasu nuskaitymas uztruko: " << Nuskaitymo_laikas.count() << " s;" << endl;

                        
                        auto Rusiavimas_start = chrono::high_resolution_clock::now();
                        pal_pav(grupe, rus_index);
                        auto Rusiavimas_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Rusiavimas_laikas = Rusiavimas_end - Rusiavimas_start;
                        cout << kiekis << " irasu rusiavimas pagal " << rus_index << " uztruko: " << Rusiavimas_laikas.count() << " s;" << endl;
                        

                        auto Padalinimo_start = chrono::high_resolution_clock::now();
                        vector<Duomenys> vargsiukai;
                        vector<Duomenys> kietiakai;
                        padalinimas(grupe, vargsiukai);
                        kietiakai = grupe;
                        auto Padalinimo_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Padalinimo_laikas = Padalinimo_end - Padalinimo_start;
                        cout <<kiekis << " irasu surusiavimas i dvi grupes uztruko: " << Padalinimo_laikas.count() << " s;"  << endl;


                        pal_pav(kietiakai, rus_index);
                        pal_pav(vargsiukai, rus_index);


                        auto Kietiaku_sp_start = chrono::high_resolution_clock::now();
                        padalinto_spausdinimas(kietiakai, "kietiakai.txt");
                        auto Kietiaku_sp_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Kietiaku_sp_laikas = Kietiaku_sp_end - Kietiaku_sp_start;
                        cout << kiekis << " irasu kietiaku irasymas i faila uztruko: " << Kietiaku_sp_laikas.count() << " s;" << endl;


                        auto Vargsiuku_sp_start = chrono::high_resolution_clock::now();
                        padalinto_spausdinimas(vargsiukai, "vargsiukai.txt");
                        auto Vargsiuku_sp_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Vargsiuku_sp_laikas = Vargsiuku_sp_end - Vargsiuku_sp_start;
                        cout << kiekis << " irasu vargsiuku irasymas i faila uztruko: " << Vargsiuku_sp_laikas.count() << " s;" << endl;
                        double visas_laikas = Nuskaitymo_laikas.count() + Rusiavimas_laikas.count() + Padalinimo_laikas.count() + Kietiaku_sp_laikas.count() + Vargsiuku_sp_laikas.count();
                        cout << kiekis << " irasu testo laikas: " << visas_laikas << " s;" << endl;

                        grupe.clear();

                    }
        }
        return 0;
    }



    else if (struktura == "l")
    {
        list<Duomenys> grupe;


        while (true) {
                    string failas;
                    cout << "Iveskite failo, kuri norite nuskaityti pavadinima (formatas: pavadinimas.txt): ";
                    cin >> failas;

                    cout << "Pagal ka noresite rusiuoti rezultatus: p - pavardes, v - vardus, g - galutini bala?\n";
                    cin >> rus_index;

                    int kiekis = kiek_sk(failas);

                    for (int i = 0; i < 5; i++) {
                        cout << endl << endl;
                        cout << i + 1 << " nuskaitymas" << endl;

                        auto Nuskaitymo_start = chrono::high_resolution_clock::now();
                        nuskaitymas(failas, grupe);
                        auto Nuskaitymo_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Nuskaitymo_laikas = Nuskaitymo_end - Nuskaitymo_start;
                        cout << kiekis << " irasu nuskaitymas uztruko: " << Nuskaitymo_laikas.count() << " s;" << endl;


                        auto Rusiavimas_start = chrono::high_resolution_clock::now();
                        pal_pav_list(grupe, rus_index);
                        auto Rusiavimas_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Rusiavimas_laikas = Rusiavimas_end - Rusiavimas_start;
                        cout << kiekis << " irasu rusiavimas pagal " << rus_index << " uztruko: " << Rusiavimas_laikas.count() << " s;" << endl;
                        

                        
                        auto Padalinimo_start = chrono::high_resolution_clock::now();
                        list<Duomenys> vargsiukai;
                        list<Duomenys> kietiakai;
                        padalinimas(grupe, vargsiukai);
                        kietiakai = grupe;
                        auto Padalinimo_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Padalinimo_laikas = Padalinimo_end - Padalinimo_start;
                        cout << kiekis << " irasu surusiavimas i dvi grupes uztruko: " << Padalinimo_laikas.count()  << " s;"  << endl;

                        pal_pav_list(kietiakai, rus_index);
                        pal_pav_list(vargsiukai, rus_index);

                        auto Kietiaku_sp_start = chrono::high_resolution_clock::now();
                        padalinto_spausdinimas(kietiakai, "kietiakai.txt");
                        auto Kietiaku_sp_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Kietiaku_sp_laikas = Kietiaku_sp_end - Kietiaku_sp_start;
                        cout << kiekis << " irasu kietiaku irasymas i faila uztruko: " << Kietiaku_sp_laikas.count() << " s;" << endl;


                        auto Vargsiuku_sp_start = chrono::high_resolution_clock::now();
                        padalinto_spausdinimas(vargsiukai, "vargsiukai.txt");
                        auto Vargsiuku_sp_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Vargsiuku_sp_laikas = Vargsiuku_sp_end - Vargsiuku_sp_start;
                        cout << kiekis << " irasu vargsiuku irasymas i faila uztruko: " << Vargsiuku_sp_laikas.count() << " s;" << endl;
                        double visas_laikas = Nuskaitymo_laikas.count() + Rusiavimas_laikas.count() + Padalinimo_laikas.count()  + Kietiaku_sp_laikas.count() + Vargsiuku_sp_laikas.count();
                        cout << kiekis << " irasu testo laikas: " << visas_laikas << " s;" << endl;

                        grupe.clear();

                    }
        }
        return 0;

    }


}
