#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void maxmin_rek(int * t, int p, int k, int &mi, int &ma) //p - poczatek przedzialu, k - koniec przedzialu
{
    if(p==k)
    {
        mi=p;
        ma=p;
    }
    if(p==(k-1))
    {
        if(t[p]<t[k])
        {
            mi=p;
            ma=k;
        }
        else
        {
            mi=k;
            ma=p;
        }
    }
    if(p<k-1)
    {
        int pivot=(k+p)/2;
        int mi1, mi2, ma1, ma2;
        maxmin_rek(t, p, pivot, mi1, ma1);
        maxmin_rek(t, (pivot+1), k, mi2, ma2);
        if(t[mi1]>t[mi2]) mi=mi2;
        else mi=mi1;
        if(t[ma1]<t[ma2]) ma=ma2;
        else ma=ma1;
    }
}


main()
{
    srand(time(NULL));
    int tab[10];
    for(int i=0;i<10;i++)
    {
        tab[i]=rand()%11;
        cout<<tab[i]<<" ";
    }
    int mi;
    int ma=0;
    maxmin_rek(tab, 0, 10, mi , ma);
    cout<<"Max to: "<<tab[ma]<<"\n";
    cout<<"Min to: "<<tab[mi]<<"\n";
return 0;
}

