#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;


main()
{
    int n, m, i, j, w1, w2 ; //n- ilosc wierzcholkow, m - ilosc krawedzi
    cout<<"Podaj ilosc wierzcholkow ilosc krawedzi: ";
    cin>>n>>m;
    int stopien[n];    vector<int> graf[n]; //deklaracja grafu w postaci listy sasiadow i tablicy ze stopniami wierzcholkow
    queue <int> kolejka;
    for(i=0; i<n; i++) //zerowanie talicy stopni
    {
        stopien[i]=0;
    }

    for(i=0; i<m; i++) //uzupelnienie wektora i tablicy stopni
    {
        cout<<"Podaj krawedzie: ";
        cin>>w1>>w2;
        graf[w1].push_back(w2);
        graf[w2].push_back(w1);
        stopien[w2]++;
    }

    for(i=0; i<n; i++) //pcczatkowe wyrazy do kolejki
    {
        if(stopien[i]==0)
        {
            kolejka.push(i);
        }
    }
    while(!kolejka.empty())
    {
        cout<<kolejka.front()<<" ";
        for(i=0; i<graf[kolejka.front()].size(); i++)
        {
            stopien[graf[kolejka.front()][i]]--;

            if(stopien[graf[kolejka.front()][i]]==0)
            {
                kolejka.push(graf[kolejka.front()][i]);
            }
        }
        kolejka.pop();

    }
return 0;
}
