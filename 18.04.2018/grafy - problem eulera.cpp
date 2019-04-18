#include <iostream>
using namespace std;

main()
{
    int n,m, i, j; //n- ilosc wierzcholkow, m - ilosc krawedzi
    cout<<"Podaj ilosc wierzcholkow ilosc krawedzi: ";
    cin>>n>>m;
    int graf[n][n];
    //zerujemy graf
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            graf[i][j]=0;
        }
    }
    //wpisanie jedynek na odpowiednie miejsca
    while(m>0)
    {
        cout<<"Podaj krawedzie: ";
        cin>>i>>j;
        graf[i][j]=1;
        graf[j][i]=1; //bo nie jest to graf skierowany
        m--;
    }
    //wypisanie grafu:
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cout<<graf[i][j]<<" ";
        }
        cout<<"\n";
    }

return 0;
}
