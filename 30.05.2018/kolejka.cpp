#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// pk - poczatek kolejki kk - koniec kolejki
struct element
{
    int liczba;
    element *wsk;
};

void dodaj_elem(int x, element *&kk) //*&adres - dajemy *& bo
{
    element *temp;
    temp=kk;
    kk=new element;
    kk ->liczba=x;
    kk ->wsk=temp;
}

void usun_elem(element *&pk)
{
    element *temp;
    temp=w;
    w=w->wsk;
    delete temp;
}

void wypisz_kolejke(element *&pk, *&kk)
{
    while(w->wsk!=NULL)
    {
        cout<<"Element: "<<w->liczba<<"\n";
        usun_elem(w);
    }
    cout<<"Element: "<<w->liczba<<"\n";
}

main()
{
    element *kk=NULL;
    element *pk=NULL;
    int x;
    int tmp=1;
    while(tmp)
    {
        cout<<"Wybierz: 1 - dodaj element | 2 - usun element | 3 - wypisz element | 0 - wypisz caly stos i zakoncz \n";
        cin>>tmp;

        switch(tmp)
        {
            case 1:
                cout<<"Podaj liczbe: ";
                cin>>x;
                dodaj_elem(x,w);
                break;
            case 2:
                usun_elem(w);
                break;
            case 3:
                cout<<"Element: "<<w->liczba<<"\n";
                break;
            case 0:
                wypisz_stos(w);
                break;
        }
    }


return 0;
}

