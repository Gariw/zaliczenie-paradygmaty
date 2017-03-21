#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Osoba
{
    //atrybuty
    string nazwisko;
    int wiek;
    Osoba *next;

public:
    //metody
    Osoba *przydziel()
    {
        next = new Osoba;
        return next;

    }
    void dodaj()
    {
        cout<<"Podaj nazwisko: ";
        cin>>nazwisko;
        cout<<"Podaj wiek: ";
        cin>>wiek;
    }
    string z_naz()
    {
        return nazwisko;

    }
    int z_wiek()
    {
        return wiek;
    }

    friend void wyswietl (Osoba *pierwszy, Osoba *ostatni);
    friend void zapisz(Osoba *pierwszy, Osoba *ostatni);
    friend Osoba *odczyt(Osoba *pierwszy, Osoba *ostatni);
    friend Osoba *usun(Osoba *pierwszy, Osoba *ostatni,int rekord);
};
/*
void wyswietl(Osoba *pierwszy, Osoba *ostatni);
void zapis(Osoba *pierwszy, Osoba *ostatni);
Osoba *odczyt(Osoba *pierwszy, Osoba *ostatni);
*/

int main()
{
    Osoba *nowy;
    nowy = new Osoba;
    Osoba *nast = nowy;

    char wyb;
    while(1)
    {
        cout<<"MENIU"<<endl;
        cout<<"1: Dodaj."<<endl;
        cout<<"2. Wyswietl."<<endl;
        cout<<"3. Zapisz."<<endl;
        cout<<"4: Odczytaj."<<endl;
        cout<<"5: Usun."<<endl;
        cout<<"6: Wyjdz."<<endl;
        cout<<endl<<"Opcja: "<<endl;
        cin.clear();
        int r = 0;
        wyb = getch();

        switch(wyb)
        {
        case '1':
            nast->dodaj();
            nast = nast->przydziel();
            break;
        case '2':
            wyswietl(nowy, nast);
            break;
        case '3':
            zapisz(nowy, nast);
            break;
        case '4':
            nast = odczyt(nowy, nast);
            break;
        case '5':
           cout<<"podaj rekord: ";
            cin>>r;
            nowy = usun(nowy, nast,r);
            break;
        case '6':
            exit(0);
        }
        cout<<endl;
        system("pause");
        system("cls");
    }
}
//procedura wyswietlajaca dane
void wyswietl(Osoba *pierwszy, Osoba *ostatni)
{
    Osoba *spr = pierwszy;
    if(pierwszy == ostatni)
    {
        cout<<"Brak danych!";

    }
    else
    {
        int licznik = 1;
        cout<<"==========================="<<endl;
        do
        {
            cout<<licznik++<<"."<<endl;
            cout<<"Nazwisko :"<<spr->z_naz()<<endl;
            cout<<"Wiek     :"<<spr->z_wiek()<<endl;
            spr = spr->next;
            cout<<"==========================="<<endl;
        }while(spr->next != ostatni->next);
    }
}
void zapisz(Osoba *pierwszy, Osoba *ostatni)
{
    Osoba *spr = pierwszy;
    if(pierwszy == ostatni)
    {
        cout<<"Brak danych!";

    }
    else
    {
        string nazwa;
        cout<<"Podaj nazwe pliku"<<endl;
        cin>>nazwa;
        nazwa.insert(nazwa.length(),".txt");

        fstream plik;
        plik.open(nazwa.c_str(),ios::out);

        do
        {
            plik<<spr->nazwisko<<endl;
            plik<<spr->wiek<<endl;

            spr = spr->next;
        }while(spr->next != ostatni->next);

        plik.close();

    }
}
Osoba *odczyt(Osoba *pierwszy, Osoba *ostatni)
{
    string nazwa,linia;
    ostatni = pierwszy;
    cout<<"Podaj nazwe pliku"<<endl;
    cin>>nazwa;
    nazwa.insert(nazwa.length(),".txt");

    fstream plik;
    plik.open(nazwa.c_str(),ios::in);

    if(plik.good()==false) cout<<"Nie mozna otworzyc pliku!";

    while (getline(plik, linia))
    {
        ostatni->nazwisko = linia;
        getline(plik, linia);


        istringstream iss(linia);
        iss >> ostatni->wiek;
        //cout<<ostatni->nazwisko<<" "<<ostatni->wiek<<endl;
        ostatni = ostatni->przydziel();
    }
    plik.close();
    return ostatni;
}
Osoba *usun(Osoba *pierwszy, Osoba *ostatni,int rekord)
{
    Osoba *pom;
    if(pierwszy == ostatni)
    {
        cout<<"Brak danych!";

    }
    else if(rekord == 1)
    {
        if(pierwszy->next == ostatni)
        {
            pierwszy = ostatni;
        }
        else
        {
            pom = pierwszy;
            pierwszy = pierwszy->next;
            delete pom;
        }

    }
    else
    {

        Osoba *spr = pierwszy;
        int licznik = 1;
        do
        {
            if(licznik == rekord)
            {

                pom->next = spr->next;
                delete spr;
                break;
            }
            else
            {
                pom = spr;
                spr = spr->next;
                ++licznik;
            }
        }while(spr->next != ostatni->next);
    }
    return pierwszy;
}












