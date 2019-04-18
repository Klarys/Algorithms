#include <iostream>
using namespace std;

void uzupelnianie(int ile, int *tab)
{
    cout<<"Podawaj nominaly od najwiekszego do najmniejszego: \n";
    for(int i=0;i<ile;i++)
    {
        cout<<"Podaj "<<i+1<<" nominal: ";
        cin>>tab[i];
    }
}

bool reszta(int kwota, int kwotag,int ilen, int ileg, int *nominaly, int *nominalyg)
{
    int pom=0;
    if(kwota<nominaly[ilen-1]) return 0; //jesli kwota jest mniejsza niz najmniejszy nominal rozlozenie jej nie jest mozliwe
    if(kwotag<nominalyg[ileg-1]) return 0;
    cout<<"\n Kwota:";
    while(kwota>=nominaly[ilen-1] && pom<=(ilen-1))
    {
        if(kwota>=nominaly[pom])
        {
            cout<<nominaly[pom]<<" ";
            kwota=kwota-nominaly[pom];
        }
        else pom++;
    }
    pom=0;
    cout<<"\n Kwota (czesc po przecinku):";
    while(kwotag>=nominalyg[ileg-1] && pom<=(ileg-1))
    {
        if(kwotag>=nominalyg[pom])
        {
            cout<<nominalyg[pom]<<" ";
            kwotag=kwotag-nominalyg[pom];
        }
        else pom++;
    }
    if(kwota==0 && kwotag==0) return 1;
    else
    {
        cout<<"W kwocie pozostaje "<<kwota<<" a w czesci po przecinku "<<kwotag;
        return 0;
    }
}

main()
{
    //Podawanie nominalow
    int ilen, ileg;
    cout<<"Podaj ile bedzie kwot w walucie (nie liczac tych po przecinku): ";
    cin>>ilen;
    cout<<"Podaj ile bedzie kwot w walucie po przecinku (nominaly groszowe): ";
    cin>>ileg;
    int nominaly[ilen];
    int nominalyg[ileg];
    cout<<"Podaj nominaly (nie liczac tych po przecinku)";
    uzupelnianie(ilen, nominaly);
    cout<<"Podaj nominaly (nominaly groszowe):";
    uzupelnianie(ileg, nominalyg);
    //obliczanie reszty
    int kwota, kwotag;
    cout<<"Podaj kwotê (bez czêsci po przecinku): ";
    cin>>kwota;
    cout<<"Podaj kwotê po przecinku: ";
    cin>>kwotag;
    if(reszta(kwota, kwotag, ilen, ileg, nominaly, nominalyg)) cout<<"Da sie rozlozyc te kwote przy pomocy tych nominalow";
    else cout<<"Nie da sie rozlozyc tej kwoty przy pomocy tych nominalow";
}

