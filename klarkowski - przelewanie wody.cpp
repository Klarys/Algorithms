#include <iostream>
#include <cmath>
using namespace std;

int nwd(int m, int n)
{
    do
    {
        if(m>n) m=m-n;
        else n=n-m;
    }while(m!=n);

return m;
}

void sprawdzanie(int m, int n,int k)
{

    int a=n, a_=m, x=0,x_=1,y=1,y_=0,q,z,pom,pom2;
    pom=0;

        while(a_!=0)
        {

            q=a/a_;

            z=a_;
            a_=a-(q*a_);
            a=z;

            z=x_;
            x_=x-(q*x_);
            x=z;

            z=y_;
            y_=y-(q*y_);
            y=z;
        }

        pom2=k/(nwd(m,n));
        cout<< "pierwszego pojemnika nalezy uzyc: "<<x*pom2<<" razy \n";
        cout<< "drugiegio pojemnika nalezy uzyc: "<<y*pom2<<" razy \n";
}

int main()
{
    int k,m,n;
    while(k%nwd(m,n)!=0)
    {
        cout<< "pojemnosc pierwszego zbiornika: \n";
        cin>>m;
        cout<< "pojemnosc drugiego zbiornika: \n";
        cin>>n;
        cout<<"ilosc wody: \n";
        cin>>k;
    }
    sprawdzanie(m,n,k);

return 0;
}
