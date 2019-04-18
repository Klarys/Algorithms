#include <iostream>
using namespace std;

long long int potit(long long int x, int n)
{
    int pom=1;
    int mnoz=0;
    if(n==1) return x;
    if(n==0) return 1;
    while(n>0)
    {
       if(n%2==0)
       {
           x=x*x;
       }
       else
       {
           pom=pom*x;
           x=x*x;
       }
       n=n/2;
       mnoz++;
    }
    cout<<"liczba mnozen: "<<mnoz<<"\n";
    return pom;
}

main()
{
    long int n;
    int x;
    cout<<"Podaj do ktorej potegi chcesz podniesc liczbe: ";
    cin>>n;
    cout<<"Podaj liczbe ktora chcesz podniesc do potegi: ";
    cin>>x;
    cout<<"Wynik potegowania to: "<<potit(x, n);
    return 0;
}
