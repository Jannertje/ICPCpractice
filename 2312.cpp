#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long
#define MX 100010
#define MOD 1000000007

vector<LL>missile;
LL L[MX];
LL LIS_n2()
{
    LL total_missile=missile.size();

    LL mx=1;
    for(LL i=0;i<total_missile;i++)
        L[i]=1;
    for(LL i=0;i<total_missile;i++)
    {
        for(LL j=i+1;j<total_missile;j++)
            if(missile[j]<=missile[i])
                L[j]=max(L[j], L[i]+1);
    }
    for(LL i=0;i<total_missile;i++)
        mx=max(mx,L[i]);
return mx;
}

int main()
{
    LL n,kk=1;
    while(cin>>n)
    {
        if(n==-1)   break;
        missile.clear();
        missile.PB(n);

        while(cin>>n)
        {
            if(n==-1)  break;
            missile.PB(n);
        }
        if(kk!=1)
        cout<<endl;

        cout<<"Test #"<<kk++<<":"<<endl<<"  maximum possible interceptions: "<<LIS_n2()<<endl;
    }
return 0;
}
