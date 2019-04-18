#include <iostream>
using namespace std;

void scal(int *A,int p, int q, int r)
{
    int n=q-p+1;
    int wynik[n];
    int granicap=r;
    int i=0;
    for(i=0;i<n;i++)
    {
        if(i<p) wynik[i]=A[i];
          if(p>granicap)
          {
              wynik[i]=A[r+1];
              r++;
          }
          else
          {
            if(A[p]<A[r+1])
            {
                wynik[i]=A[p];
                p++;
            }
            else
            {
                wynik[i]=A[r+1];
                r++;
            }
          }
    }
    for(i=0;i<n;i++)
    {
        A[i]=wynik[i];
    }
}


main()
{
    int tab[8]={1,2,3,6,1,2,5,7};
    int i;
    for(i=0;i<8;i++)
    {
            cout<<tab[i]<<" ";
    }
    scal(tab,0,7,3);
    cout<<"\n";
    for(i=0;i<8;i++)
    {
            cout<<tab[i]<<" ";
    }
}

