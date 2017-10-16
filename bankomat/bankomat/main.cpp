#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

char wybor;

string PIN;
string pin = "1234";
string linia;
int saldo, x = 0;
int kwotaout, kwotain;
int nr_linii=1;
int test_linii=0;

int main()
{
    cout << "Witaj w bankomacie" << endl;
    Sleep(500);
    system("cls");

    while(true)  //funkcja petla do calego bankomatu zeby podac PIN, 3 szanse

    {
    system("cls");
    cout<<"Podaj PIN:";
    cin>>PIN;
    system("cls");
    if(PIN==pin)    // jezli PIN ok to wybor opcji
    {
    cout<<"Wybierz opcje"<<endl;
    cout<<"1. Wplac pieniadze:"<<endl;
    cout<<"2. Wyplac pieniadze:"<<endl;
    cout<<"3. Sprawdz saldo 5 ostatnich transakcji:"<<endl;
    cout<<"4. Wyjscie:"<<endl;

    fstream plik;

    plik.open ("dane.txt", ios::in);   //laduje plik lub tworze

    if(plik.good()==false)  // jezeli pliku nie ma to tworzy
    {
        plik.open ("dane.txt", ios::out);
    }

    while(getline(plik,linia))  // zliczam iloc linii
    {
                        test_linii++;
    }
    plik.close();

    int wykaz[test_linii]; // zmienna dla celow wyswietlenia transakcji

    plik.open ("dane.txt", ios::in);   //laduje plik

    while(getline(plik,linia))  //wczytuje dane z pliku
    {

            wykaz[nr_linii] = atoi(linia.c_str());
            saldo = atoi(linia.c_str());
            nr_linii++;
    }


    plik.close();

    wybor = getch();   //wybor opcji

    switch(wybor)

    {
        case '1': //obliczanie nowego salda i dopisywanie dla wplat
            {
                system("cls");
                cout<<"Jaka kwote chcesz wplacic?"<<endl;
                cin>>kwotain;
                saldo = saldo+kwotain;

                plik.open("dane.txt", ios::out | ios::app);

                plik<<endl;
                plik<<saldo;

                plik.close();
                Sleep(1000);

                system("cls");
                cout<<"Dziekujemy za wspolprace. Do widzenia"<<endl;
                cout<<"Twoje pieniazki: "<<saldo<<endl;
               system("pause");
            }
        break;

        case '2':  // obliczanie nowego salda i nadpisywanie dla wyplat
            {
                system("cls");
                cout<<"Jaka kwote chcesz wyplacic?"<<endl;
                cin>>kwotaout;

                if(kwotaout<=saldo)
                {
                saldo = saldo-kwotaout;
                cout<<"Twoje saldo:"<<saldo<<endl;


                plik.open("dane.txt", ios::out | ios::app);
                plik<<endl;
                plik<<saldo;

                plik.close();
                Sleep(2000);

                system("cls");
                cout<<"Dziekujemy za wspolprace. Do widzenia"<<endl;
                system("pause");
                }
                else
                {
                    system("cls");
                    cout<<"Masz za malo srodkow na koncie.";
                    system("pause");
                }
            }

        break;

        case '3':
            {
                system("cls");
                int trans[5];

                trans[0] = wykaz[nr_linii-1]-wykaz[nr_linii-2];
                trans[1] = wykaz[nr_linii-2]-wykaz[nr_linii-3];
                trans[2] = wykaz[nr_linii-3]-wykaz[nr_linii-4];
                trans[3] = wykaz[nr_linii-4]-wykaz[nr_linii-5];
                trans[4] = wykaz[nr_linii-5]-wykaz[nr_linii-6];

                cout<<"5 ostatnich transakcji:"<<endl;
                cout<<trans[0]<<endl;
                cout<<trans[1]<<endl;
                cout<<trans[2]<<endl;
                cout<<trans[3]<<endl;
                cout<<trans[4]<<endl;

                system("pause");

            }

        break;

        case '4':
            {
                system("cls");
                cout<<"Do widzenia"<<endl;
                Sleep(3000);
                system("pause");
            }

        break;

        default:
            {
                cout<<"Nie ma takiej opcji:"<<endl;
                Sleep(3000);
                system("cls");
            }
        break;

    }


    }

    else

    {
        x++;


        if (x==3)
        {
            cout<<"Zablokowano konto!!! Zglos sie do oddzialu w banku."<<endl;
            Sleep(5000);
            exit(0);
        }

        cout<<"Zly PIN, pozostalo "<<3-x<<" prob."<<endl;
        Sleep(3000);
        system("cls");
    }

    }


    return 0;
}
