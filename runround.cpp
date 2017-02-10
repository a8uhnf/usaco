
/*
ID: hanifbo1
PROG: runround
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
ll number;
int mark[20];
string s;

bool checkTheNumber(int pos) {
    // cout<<s<<endl;
    int it = s[pos] - '0';

    if (mark[it]) {
        int cnt = 0;
        for(int i = 1; i<10; i++) {
            // cout<<mark[i]<<" ";
            if (mark[i]) {
                cnt++;
            }
        }
        // cout<<endl;
        if (cnt == s.length() && pos == 0) {
            return true;
        }
        return false;
    }
    pos = (pos + it)%s.length();
    mark[it]++;
    return checkTheNumber(pos);
    // return true;
}

int main()
{
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");

    fin>>number;
    ll i;
    for(i = number + 1; ; i++) {
        // cout<<i<<endl;
        mem(mark, 0);
        stringstream ss;
        ss<<i;
        ss>>s;

        if(checkTheNumber(0)) {
            break;
        }
    }
    stringstream ss;
    ss<<147;
    ss>>s;
    // cout<<checkTheNumber(0)<<endl;
    fout<<i<<endl;
    return 0;
}


