#include <iostream>
#include <vector>
using namespace std;


bool sprawdzanie(vector <int> tab)
{
    int n=tab.size();
    bool spr;
    for(int i=0; i<n-2; i++)
    {

        for(int j=i+1; j<n-1; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                spr=1;
                if(tab[i]+tab[j]<=tab[k] || tab[j]+tab[k]<=tab[i] || tab[i]+tab[k]<=tab[j]) spr=0;
                if(spr==1)
                {
                    cout<<tab[i]<<" "<<tab[j]<<" "<<tab[k]<<endl;
                    return 1;
                }
            }
        }
    }
    if(spr==0) return 0;
}


main()
{
    int temp;
    vector <int> tab;
    while(tab.size()<=45)
    {
        cin>>temp;
        if(temp==0) break;
        tab.push_back(temp);
    }
    if(!sprawdzanie(tab)) cout<<"NIE"<<endl;

return 0;
}
