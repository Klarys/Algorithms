#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<int> *tab, int *L, int *F, int v, int skladowa)
{
    int p, u;
    queue <int> Q; //kolejka
    Q.push(v); //wstawianie na koniec kolejki przetwarzanego wierzcho³ka
    L[v]=skladowa; //wierzcho³ek s jest odwiedzony
    while(Q.size()!=0) //dopóki koljeka nie jest pusta
    {
        p=Q.front(); //pobranie wierzcho³ka z poczatku kolejki
        Q.pop();//usunięcie pobranego wierzcho³ka z pocz¹tku kolejki
        for(int j=0; j<tab[p].size(); j++) //dla wszystkich sasiadów wierzcho³ka s
        {
            u=tab[p][j];
            if(L[u]==false) //jeœli s¹siad nie by³ odwiedzony
            {
                Q.push(u); //wstawienie sasiada na koniec kolejki
                L[u]=skladowa; //sąsiad uzyskuje status odwiedzonego
                F[u]=p;
            }
        }
    }
}
int main()
{
    int n,m,x,y;
    int nr_skladowej=1;//n-liczba wierzcholkow, m-liczba krawedzi
    int i=0;
    cin>>n;
    cin>>m;
    int l[n]; //tablica odwiedzen
    int f[n]; //tablica ojców
    for (int i=0; i<n; i++)
      { l[i]=0;
        f[i]=-1;
       }//zerowanie tablicy odwiedzen, ustalenie poczatkowych wartoœci tablicy ojców na -1
    vector <int> tab[n]; //tablica n pustych wektorów
    for(i=0;i<m;i++)
    {
        cin>>x;//pierwszy wierzcho³ek krawêdzi
        cin>>y;//drugi wierzcho³ek krawedzi
        tab[x].push_back(y);
        tab[y].push_back(x);
    }
    for(i=0;i<n;i++)
    {
        if(l[i]==0)
        {
            bfs(tab,l,f,i,nr_skladowej);//jesli graf nie by³ spójny trzeba zacz¹c od nastepnych nieodwiedzonych wierzcho³ków
            nr_skladowej++;
        }
    }
    for(i=0; i<n; i++) cout<<f[i]<<" ";
    //skladowe
    int skladowe[nr_skladowej]; //tablica zliczajaca elementy w kazdej skladowej
    for(i=0; i<nr_skladowej; i++)
    {
        skladowe[i]=0;
    }
    for(i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        if(l[i]==j)
        {
            skladowe[j]++;
        }
    }
    cout<<"\nIlosc skladowych: "<<nr_skladowej<<"\n";
    for(i=1; i<nr_skladowej; i++)
    {
        cout<<"skladowa "<<i<<" ma "<<skladowe[i]<<" wierzcholkow. Wierzcholki w tej skladowej to: \n";
        {
            for(int j=0; j<n; j++)
            {
                if(l[j]==i) cout<<"\t - "<<j<<"\n";
            }
        }
    }
return 0;
}
/*
cztery skladowe
10 10
0 1
2 0
1 2
2 3
3 4
4 1
1 3
4 2
5 7
6 9
*/
