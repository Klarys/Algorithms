#include <iostream>
using namespace std;

int rozwiazanie(int * siatka, int x, int y)
{

}



main()
{
 int x,y;
 cout<<"Podaj wspolrzedne x i y ostatniego punktu: ";
 cin>>x>>y;
 int siatka[x][y][2];

 //uzupelnianie siatki
 for(int i=0; i<=x; i++)
 {
     for(int j=0; j<=y; j++)
     {
            if(j!=0)
            {
                cout<<"Podaj dlugosc od lewej dla punktu ("<<i<<","<<j<<"): ";
                cin>>siatka[i][j][0];
            }
            if(i!=0)
            {
                 cout<<"Podaj dlugosc od dolu dla punktu ("<<i<<","<<j<<"): ";
                 cin>>siatka[i][j][1];
            }
     }
 }
 //
 rozwiazanie(siatka, x, y);

return 0;
}
