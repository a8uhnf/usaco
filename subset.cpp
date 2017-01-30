
/*
ID: hanifbo1
PROG: subset
LANG: C++
*/
#include<bits/stdc++.h>

using namespace std;

#define DD          double
#define eps         0.000001
#define FastIO      ios_base::sync_with_stdio(0); cin.tie(0)
#define READ(f)     freopen(f,"r",stdin)
#define WRITE(f)    freopen(f,"w",stdout)
#define sc          scanf
#define pf          printf
#define mem(a,val)  memset(a,val,sizeof(a))
#define rep(s,n)    for(long i=s; i<=n;i++)
#define pb          push_back
#define ll          long long
#define pi          (2*acos(0.0))
// #define mx          35000
#define ssc         sscanf
#define FOR(val,n)  for(long i=val;i<=n;i++)
#define FORL(val,n) for(long i=val;i<n;i++)
#define PQ          priority_queue
#define sr(v)       sort(v.begin(),v.end())

int n;

ll dp[44][800];

ll call(int i, int sum) {
    // cout<<i<<" "<<sum<<endl;
    if(i>=n+1) {
        if (2 * sum == (n*(n+1))/2) {
        cout<<"Hello World!!!"<<endl;
            return 1;
        }
        return 0;
    }
    if (dp[i][sum] != -1) return dp[i][sum];
    ll ret = 0;
    ret = call(i+1, sum + i) + call(i+1, sum);
    return dp[i][sum] = ret;
}

int main()
{
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");

    fin>>n;
    mem(dp, -1);
    // cout<<n<<endl;

    fout<<call(1, 0)/2<<endl;;
    return 0;
}



