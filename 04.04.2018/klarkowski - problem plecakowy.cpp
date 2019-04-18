#include <iostream>
#include <algorithm>
using namespace std;


int rozwiazanie(int ilosc_p,int V_plecaka, int *wagi, int *wartosci)
{
    int P[ilosc_p+1][V_plecaka+1]; //tablica do szukania najlepszej kombinacji przedmiotow (+1 na kolumne i wiersz z zerami)
    int Q[ilosc_p+1][V_plecaka+1]; //tablica do zapisywania ilosci kazdego przedmiotu
    int i,j;
    for(j=0; j<=V_plecaka; j++) // uzupelnianie dodatkowego wiersza z zerami
    {
        P[0][j]=0;
        Q[0][j]=0;
    }
    for(i=0; i<=ilosc_p; i++) // uzupelnianie dodatkowej kolumny z zerami
    {
        P[i][0]=0;
        Q[i][0]=0;
    }
    for(i=1; i<=ilosc_p; i++)
    {
        for(j=1; j<=V_plecaka; j++)
        {
            if (j>=wagi[i-1] && P[i-1][j]<(P[i][j-wagi[i-1]]+wartosci[i-1]))
            {
                P[i][j]=P[i][j-wagi[i-1]]+wartosci[i-1];
                Q[i][j]=i;
            }
            else
            {
                P[i][j]=P[i-1][j];
                Q[i][j]=Q[i-1][j];
            }

        }
        cout<<endl;
    }
    //wypisanko
    for(i=0; i<=ilosc_p; i++)
    {
        for(j=0; j<=V_plecaka; j++)
        {
            cout<<P[i][j]<<" ";
        }
        cout<<endl;
    }
     for(i=0; i<=ilosc_p; i++)
    {
        for(j=0; j<=V_plecaka; j++)
        {
            cout<<Q[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<P[ilosc_p][V_plecaka]<<endl;
    cout<<"Numery przedmiotow w plecaku: ";
    j=V_plecaka;
        while(j>0)
        {
            cout<<Q[ilosc_p][j]<<" ";
            j=j-wagi[(Q[ilosc_p][j])-1];
        }
}

main()
{
    int ilosc_przedmiotow, V_plecaka;
    cout<<"Podaj ilosc przedmiotow: ";
    cin>>ilosc_przedmiotow;
    cout<<"Podaj pojemnosc plecaka: ";
    cin>>V_plecaka;
    int wartosci[ilosc_przedmiotow];
    int wagi[ilosc_przedmiotow];

    //uzupelnianie danych przedmiotow
    for(int i=0; i<ilosc_przedmiotow; i++)
    {
        cout<<"Podaj wartosc "<<i+1<<" przedmiotu: ";
        cin>>wartosci[i];
        cout<<"Podaj wage "<<i+1<<" przedmiotu: ";
        cin>>wagi[i];
    }
    int tab_Q[ilosc_przedmiotow][V_plecaka]; //tablica umozliwiajaca odczytanie rozwiazania
    rozwiazanie(ilosc_przedmiotow, V_plecaka, wagi, wartosci);


return 0;
}
