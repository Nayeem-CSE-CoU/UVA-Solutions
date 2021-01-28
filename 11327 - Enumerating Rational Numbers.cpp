#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll phi[2000006],mark[2000006];
void eTotient(int n)
{
    int i,j;
    for(i=1; i<=n; i++)
        phi[i]=i;

    mark[1]=1;
    for(i=2; i<=n; i++)
        {
            if(!mark[i])
            {
                for(j=i;j<=n;j+=i)
                {
                    mark[j]=1;
                    phi[j]=phi[j]/i*(i-1);
                }
            }
        }
    phi[1]=2;
    for(i=2;i<=n;i++)
        phi[i]+=phi[i-1];
}
int main()
{
    eTotient(200001);

    ll k;
    while(cin>>k && k!=0)
    {
        if(k==1)
            {cout<<0<<"/"<<1<<endl;continue;}
        if(k==2)
            {cout<<1<<"/"<<1<<endl;continue;}

        int denominator=lower_bound(phi,phi+200001,k)-phi;

        int n=phi[denominator]-phi[denominator-1];
        int d=phi[denominator]-k;

        int count=0;
        for(int i=1;i<=denominator;i++)
        {
            if(__gcd(i,denominator)==1)
                count++;
            if(count+d==n)
            {
                cout<<i<<"/"<<denominator<<endl;
                break;
            }
        }

    }

    return 0;
}
