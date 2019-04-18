#include <iostream>
using namespace std;

int f(int n,int  Tab[], int &mini, int &maks)
{

    for(int i=0;i<n;i++)
    {
        if(Tab[i]>Tab[i+1]) swap(Tab[i],Tab[i+1]);

    }
    maks=Tab[0];
    mini=Tab[1];
    int j=1;
    for(int i=0;i<n;i+=2)
    {
        if(Tab[j]>maks) maks=Tab[j];
        if(Tab[i]<mini) mini=Tab[i];
        j=j+2;
    }
}
int main()
{
    int n, mini,maks;
    cin>>n;
    int Tab[n];
    for(int i=0;i<n;i++)
    {
        cin>>Tab[i];
    }
    f(n,Tab,mini,maks);
    cout<<" Minimum wynosi: "<<mini<<" \n "<< "Maksimum wynosi: "<<maks<<endl;
}
