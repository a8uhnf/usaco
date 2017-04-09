
/*
ID: hanifbo1
PROG: lamps
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

int n, c;
map<vector<int>, int>mp;
map<vector<int>, int>chkmp;

vector<int> firstOp(vector<int>v) {
    for (int i = 0; i<v.size();i++) {
        v[i] = 1- v[i];
    }
    return v;
}
vector<int> secondOp(vector<int> v) {
    for(int i = 0; i<v.size();i+= 2) {
        v[i] = 1 - v[i];
    }
    return v;
}
vector<int> thirdOp(vector<int> v) {
    for(int i = 1; i<v.size();i+=2) {
        v[i] = 1 - v[i];
    }
    return v;
}
vector<int> forthOp (vector<int> v) {
    for(int k = 0; k<v.size(); k++) {
        int tmp = 3*k+1;
        if (tmp > v.size())break;
        v[tmp-1] = 1- v[tmp-1];
    }
    return v;
}


void lamps(int cnt, vector<int> v) {
    if (cnt >= c) {
        mp[v] = 1;
        for(int i = 0; i<v.size();i++) {
            // cout<<v[i];
        }
        // cout<<endl;
        return;
    }
    vector<int>tmp = firstOp(v);
    if (chkmp.find(v) != chkmp.end()) {
        mp[v] = 1;
        return;
    }
    chkmp[v] = 1;
    lamps(cnt+1, tmp);

    tmp = secondOp(v);
    lamps(cnt+1, tmp);

    tmp = thirdOp(v);
    lamps(cnt + 1, tmp);

    tmp = forthOp(v);
    lamps(cnt+1, tmp);
}
int main()
{
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");

    fin>>n;
    fin>>c;
    vector<int>on, off;
    int a;
    while(fin>>a) {
        if(a == -1) break;
        on.pb(a);
    }
    while(fin>>a) {
        if (a == -1) break;
        off.pb(a);
    }
    vector<int>tmp;
    for(int i = 0; i<n;i++) {
        tmp.pb(1);
    }
    lamps(0, tmp);
    map<vector<int>, int>::iterator it;
    int ans = 0;

    for(it = mp.begin(); it != mp.end(); it++) {
        vector<int>firstV = it->first;
        bool dic = true;
        for(int i = 0; i<on.size();i++) {
            int tmp = on[i];
            if (firstV[tmp-1] == 0) {
                dic = false;
            }
        }
        for(int i = 0; i<off.size(); i++) {
            int tmp = off[i];
            if (firstV[tmp-1] == 1) {
                dic = false;
            }
        }
        if (dic) {
            ans ++;
            for(int i = 0; i<firstV.size();i++) {
                fout<<firstV[i];
            }
            fout<<endl;
        }
    }
    if(ans == 0) {
        fout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}


