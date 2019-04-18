#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct element
{
    int liczba;
    element *wsk;
};

void dodaj_elem(int x, element *&w) //*&adres - dajemy *& bo
{
    element *temp;
    temp=w;
    w=new element;
    w ->liczba=x;
    w ->wsk=temp;
}

void usun_elem(element *&w)
{
    element *temp;
    temp=w;
    w=w->wsk;
    delete temp;
}

void wypisz_stos(element *&w)
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
    element *w=NULL;
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
