#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void maxmin(int * tab, int n, int &mi, int &ma)
{
    int temp;
    int i;
    for(i=0;i<n-1;i+=2)
    {
        if(tab[i]>tab[i+1])
        {
            temp=tab[i];
            tab[i]=tab[i+1];
            tab[i+1]=temp;
        }
    }
    ma=tab[1];
    mi=tab[0];
    for(i=2;i<n;i+=2)
    {
        if(tab[i]<mi)
        {
            mi=tab[i];
        }
    }
    for(i=3; i<n;i+=2)
    {
        if(tab[i]>ma)
        {
            ma=tab[i];
        }
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
    int ma;
    maxmin(tab, 10, mi, ma);
    cout<<"Max to: "<<ma<<"\n";
    cout<<"Min to: "<<mi<<"\n";
return 0;
}
