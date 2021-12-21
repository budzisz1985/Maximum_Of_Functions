#include "count.h"
#include <iostream>
#include <random>
#include <cmath>

using namespace std;

void Data::enter_data()
{
    cout << "Podaj wspolczynniki funkcji F(x)= ax^3+bx^2+cx+d" << endl;
    for (int i = 0; i < 4; i++) {
        cout << (char)character << " = ";
        cin >> data[i];
        ++character;
    }
    cout << "Podaj wspolczynik krzyzowania od 0 do 100:" << endl;
    cin >> crossing;
    cout << "Podaj wspolczynik mutacji od 0 do 100:" << endl;
    cin >> mutation;
    cout << "Podaj ilosc wystapien najwyzszego wyniku:" << endl;
    cin >> reapeting;

    cout << "Postac funkcji F(x)=" << data[0] << "x^3+" << data[1] << "x^2+" << data[2] << "x+" << data[3] << endl;
}

void Gene::chromo()
{
    for (int i = 0; i < 6; i++) {
        sum[i] = (int)0;
    }

    for (int j = 0; j < 6; j++) {
        cout << "Ch" << (j + 1) << ": ";
        for (int i = 0; i < 5; i++) {
            chromosom[j][i] = (rand() % 2);
            if (chromosom[j][i] == 1) {
                sum[j] = sum[j] + pow(2, 5 - 1 - i);
            }
            cout << chromosom[j][i];
        }
        cout << "=" << sum[j] << endl;
    }
}

void Function::firstFunction()
{
    first = 0;
    cout << "Funkcja przystosowania: " << endl;
    for (int i = 0; i < 6; i++) {
        function[i] = (Data::data[0] * (Gene::sum[i] * Gene::sum[i] * Gene::sum[i])) + (Data::data[1] * (Gene::sum[i] * Gene::sum[i])) + (Data::data[2] * Gene::sum[i]) + Data::data[3];
        cout << "Ch" << (i + 1) << "=" << function[i] << endl;
        first = (first + function[i]);
    }
    cout << "Suma wartosci wszystkich funkcji przystosowania: " << first << endl;
    cout << "Procentowy udzial kazdego z chromosomow: " << endl;

    for (int i = 0; i < 6; i++) {
        part[i] = (function[i] / first) * 100;
        cout << "Ch" << (i + 1) << "=" << part[i] << endl;
    }

}

void Roulette::count()
{
    for (int z = 0; end < Data::reapeting; z++) {
        for (int j = 0; j < 6; j++) {
            wheel = rand() % 101;
            for (int i = 0; i < 5; i++) {
                if (wheel > 0 && wheel < Function::part[0]) {
                    Gene::chromosom[j][i] = Gene::chromosom[0][i];
                }
                else if (wheel > Function::part[0] && wheel < (Function::part[0] + Function::part[1])) {
                    chromosom[j][i] = chromosom[1][i];
                }
                else if (wheel > (Function::part[0] + Function::part[1]) && wheel < Function::part[0] + Function::part[1] + Function::part[2]) {
                    chromosom[j][i] = chromosom[2][i];
                }
                else if (wheel > (Function::part[0] + Function::part[1] + Function::part[2]) && wheel < (Function::part[0] + Function::part[1] + Function::part[2] + Function::part[3])) {
                    chromosom[j][i] = chromosom[3][i];
                }
                else if (wheel > (Function::part[0] + Function::part[1] + Function::part[2] + Function::part[3]) && wheel < (Function::part[0] + Function::part[1] + Function::part[2] + Function::part[3] + Function::part[4])) {
                    chromosom[j][i] = chromosom[4][i];
                }
                else if (wheel > (Function::part[0] + Function::part[1] + Function::part[2] + Function::part[3] + Function::part[4]) && wheel < 100) {
                    chromosom[j][i] = chromosom[5][i];
                }
            }
        }
        lokus = rand() % 5;
        cp = rand() % 101;
        for (int i = lokus; i < 5; i++) {
            if (cp < crossing) {
                temp[0][i] = Gene::chromosom[0][i];
                Gene::chromosom[0][i] = Gene::chromosom[1][i];
                Gene::chromosom[1][i] = temp[0][i];
            }
        }
        lokus = rand() % 5;
        cp = rand() % 101;
        for (int i = lokus; i < 5; i++) {
            if (cp < crossing) {
                temp[1][i] = Gene::chromosom[2][i];
                Gene::chromosom[2][i] = Gene::chromosom[3][i];
                Gene::chromosom[3][i] = temp[1][i];
            }
        }
        lokus = rand() % 5;
        cp = rand() % 101;
        for (int i = lokus; i < 5; i++) {
            if (cp < crossing) {
                temp[2][i] = Gene::chromosom[4][i];
                Gene::chromosom[4][i] = Gene::chromosom[5][i];
                Gene::chromosom[5][i] = temp[2][i];
            }
        }
        lokus = rand() % 6;
        mp = rand() % 101;
        for (int i = 0; i < 1; i++) {
            if (mp < mutation) {
                if (chromosom[0][lokus] == 0) {
                    chromosom[0][lokus] = 1;
                }
                else if
                    (chromosom[0][lokus] == 1) {
                    chromosom[0][lokus] = 0;
                }
            }
        }
        lokus = rand() % 6;
        mp = rand() % 101;
        for (int i = 0; i < 1; i++) {
            if (mp < mutation) {
                if (Gene::chromosom[1][lokus] == 0) {
                    Gene::chromosom[1][lokus] = 1;
                }
                else if
                    (Gene::chromosom[1][lokus] == 1) {
                    Gene::chromosom[1][lokus] = 0;
                }
            }
        }
        lokus = rand() % 6;
        mp = rand() % 101;
        for (int i = 0; i < 1; i++) {
            if (mp < mutation) {
                if (Gene::chromosom[2][lokus] == 0) {
                    Gene::chromosom[2][lokus] = 1;
                }
                else if
                    (Gene::chromosom[2][lokus] == 1) {
                    Gene::chromosom[2][lokus] = 0;
                }
            }
        }
        lokus = rand() % 6;
        mp = rand() % 101;
        for (int i = 0; i < 1; i++) {
            if (mp < mutation) {
                if (Gene::chromosom[3][lokus] == 0) {
                    Gene::chromosom[3][lokus] = 1;
                }
                else if
                    (Gene::chromosom[3][lokus] == 1) {
                    Gene::chromosom[3][lokus] = 0;
                }
            }
        }
        lokus = rand() % 5;
        mp = rand() % 100;
        for (int i = 0; i < 1; i++) {
            if (mp < mutation) {
                if (Gene::chromosom[4][lokus] == 0) {
                    Gene::chromosom[4][lokus] = 1;
                }
                else if
                    (Gene::chromosom[4][lokus] == 1) {
                    Gene::chromosom[4][lokus] = 0;
                }
            }
        }
        lokus = rand() % 5;;
        mp = rand() % 100;
        for (int i = 0; i < 1; i++) {
            if (mp < mutation) {
                if (Gene::chromosom[5][lokus] == 0) {
                    Gene::chromosom[5][lokus] = 1;
                }
                else if
                    (Gene::chromosom[5][lokus] == 1) {
                    Gene::chromosom[5][lokus] = 0;
                }
            }
        }
        cout << "Chromosomy po losowaniu, krzyzowaniu, mutacji oraz ich wartosc: " << endl;
        for (int j = 0; j < 6; j++) {
            cout << "Ch" << (j + 1) << ": ";
            Gene::sum[j] = 0.0;
            for (int i = 0; i < 5; i++) {
                if (chromosom[j][i] == 1) {
                    Gene::sum[j] = Gene::sum[j] + pow(2, 5 - 1 - i);
                }
                cout << chromosom[j][i];
            }
            cout << "=" << Gene::sum[j] << endl;
        }
        Function::first = 0.0;

        cout << "Funkcja przystosowania:" << endl;
        for (int i = 0; i < 6; i++) {
            Function::function[i] = 0.0;
            Function::function[i] = Data::data[0] * (Gene::sum[i] * Gene::sum[i] * Gene::sum[i]) + Data::data[1] * (Gene::sum[i] * Gene::sum[i]) + Data::data[2] * Gene::sum[i] + Data::data[3];
            cout << "Ch" << (i + 1) << "=" << Function::function[i] << endl;
            Function::first = Function::first + Function::function[i];
        }
        max = Function::first;
        if
            (maximum < max) {
            maximum = max;
            end = 0;
        }
        else if (maximum == max) {
            end = end + 1;
        }
        counter = counter + 1;
        cout << "Procentowy udzial kazdego z chromosomow: " << endl;
        for (int i = 0; i < 6; i++) {
            Function::part[i] = ((Function::function[i] / Function::first) * 100);
            cout << "Ch" << (i + 1) << "=" << Function::part[i] << endl;
        }
        cout << "Suma wartoœci najlepszych funkcji przystosowania: " << Function::first << endl;
        cout << "Wykonano " << counter << " iteacji" << endl << endl;

    }
}



