#include <iostream>
using namespace std;

int fibb(int x)
{
    if(x==0) return 0;
    if(x==1) return 1;
    if(x%2!=0) return fibb(x/2)*fibb(x/2) + fibb((x/2)+1)*fibb((x/2)+1); //+1 i -1 wynikaj¹ z dzielenia ca³kowitego
    if(x%2==0) return 2*fibb((x/2)-1)*fibb(x/2)  + fibb(x/2)*fibb(x/2);
}

main()
{
    int n=0;
    while(n<2)
    {
        cout<<"Podaj n>1: ";
        cin>>n;
    }
    cout<<n<<". wyraz ciagu fibonacciego to: "<<fibb(n);
return 0;
}
