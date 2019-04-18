#include <iostream>
#include <vector>
using namespace std;

main()
{
    int n, m, i, w1, w2 ; //n- ilosc wierzcholkow, m - ilosc krawedzi
    cout<<"Podaj ilosc wierzcholkow ilosc krawedzi: ";
    cin>>n>>m;
    vector<int> graf[n];

    //wpisanie jedynek na odpowiednie miejsca
    for(i=0; i<m; i++)
    {
        cout<<"Podaj krawedzie: ";
        cin>>w1>>w2;
        graf[w1].push_back(w2);
        graf[w2].push_back(w1);
    }

    //wypisanie grafu:
    for(int i=0;i<n;i++)
    {
        for (int j=0; j<graf[i].size(); j++)
        {
            cout <<graf[i][j]<<" ";
        }
        cout<<endl;
    }
    //sprawdzanie czy graf ma cykl eulera
    for(int i=0;i<n;i++)
    {
        if(graf[i].size()%2!=0)
        {
            cout<<"Graf nie ma cyklu Eulera";
            return 0;
        }
    }
    cout<<"Graf ma cykl Eulera";

return 0;
}
