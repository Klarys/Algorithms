#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


main()
{
    int * wska;
    wska = new int;
    *wska=10;
    int tab[4];
    tab[0]=0;
    cout<<"Adres: "<<wska<<" wartosc: "<<*wska<<"\n";
    cout<<"Adres: "<<tab<<" wartosc: "<<tab[0]<<" adres z &: "<<&tab[0];

    //po tablicy mo�na porusza� si� wska�nikiem, jest to szybsze od odwo�ywania si� do indeksu po zmiennej i, gdy� w takim wypadku w ka�dym obiegu p�tli przechodzimy po ka�dym adresie od pocz�tkowego do docelowego
    wska=tab;
    cout<<*wska<<"\n";
    for(int i=0; i<4; i++)
    {
        *wska= rand()%10;
        wska++;
        cout<<*wska<<"\n";
    }


return 0;
}
