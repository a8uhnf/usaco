
/*
ID: hanifbo1
PROG: skidesign
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
#define mx          35000
#define ssc         sscanf
#define FOR(val,n)  for(long i=val;i<=n;i++)
#define FORL(val,n) for(long i=val;i<n;i++)
#define PQ          priority_queue
#define sr(v)       sort(v.begin(),v.end())

vector<int>v;

int solve(int lo, int hi) {
    if (hi - lo < 0 && hi - lo > 17) {
        return 1000000000;
    }
    int ret = 0;
    for(int i = 0; i<v.size(); i++) {
        if (v[i] < lo) {
            ret += ((lo - v[i]) * (lo - v[i]));
        } else if (v[i] > hi) {
            ret += ((v[i] - hi) * (v[i] - hi));
        }
    }
    return ret;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    int n;
    fin>>n;
    for(int i = 0; i < n; i++) {
        int a;
        fin>>a;
        v.pb(a);
    }
    sr(v);
    int ans = 1000000000;
    int lo = v[0],hi = v[v.size() - 1];
    for (int i = lo; i<=hi; i++) {
        for(int j = hi; j>=lo; j--) {
            int tmpLo = i, tmpHi = j;
            if (tmpHi - tmpLo > 0 && tmpHi - tmpLo <= 17) {
                ans = min(ans, solve(tmpLo, tmpHi));
//                ans = min(ans, solve(tmpLo + 1, tmpHi));
//                ans = min(ans, solve(tmpLo, tmpHi - 1));
            }
        }
    }
    fout<<ans<<endl;
    return 0;
}
