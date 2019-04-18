#include <iostream>
using namespace std;
long int fib(long int n)
{
    cout<<n<<" ";
    if(n==1 || n==2) return 1;
        return fib(n-1)+fib(n-2);
}

long int fibit(long int n)
{
    long int wynik=0;
    long int pom1=1;
    long int pom2=1;
    if(n==1 || n==2) return 1;
    for(int i=3;i<=n;i++)
    {
        wynik=pom1+pom2;
        pom2=pom1;
        pom1=wynik;
    }
    return wynik;
}
long long int potega(long long int x, int n)
{
    if(n==1) return x;
    if(n==0) return 1;
    if(n%2==0) return potega(x, n/2)*potega(x, n/2);
    else return potega(x, n/2)*potega(x, n/2)*x;
}

long long int potit(long long int x, int n)
{
    int pom=1;
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
    }
    return pom;
}

main()
{
    long int n;
    int x;
    cin>>n;
    cin>>x;
    cout<<potit(x, n);
    return 0;
}
