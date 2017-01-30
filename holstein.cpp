
/*
ID: hanifbo1
PROG: holstein
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

vector<int>vRequirement, feedType[27], tmpV;
int v, g;
int vSum[27];
void testing() {
    cout<<"hello"<<endl;
    int mx = 15;
    int nCr = 0;
    int sum = 0;
    for (int i = 1; i<= 15; i++) {
        int d1 = i, d2 = 15 - i;
        int maxi = max(d1, d2);
        int mini = min(d1, d2);
        vector<int>vNcr;
        for(int j = 15; j>maxi; j--) {
            // nCr *= j;
            vNcr.pb(j);
        }
        for(int j = 2; j<=mini; j++) {
            for(int k = 0; k<vNcr.size();k++) {
                if (vNcr[k]%j == 0) {
                    vNcr[k] /= j;
                }
            }
        }
        nCr = 1;
        for(int k = 0; k<vNcr.size();k++) {
            nCr *= vNcr[k];
        }
        cout<<"============== "<<nCr<<endl;
        sum += nCr;
    }
    cout<<sum<<endl;
}

bool printVector() {
    mem(vSum, 0);
    for(int i = 0; i<tmpV.size(); i++) {
        int type = tmpV[i];
        for(int j = 0; j<feedType[type].size(); j++) {
            int val = feedType[type][j];
            vSum[j] += val;
        }
    }
    for (int i = 0; i<vRequirement.size(); i++) {
        if (vRequirement[i] > vSum[i]) {
            return false;
        }
    }
    return true;
}
bool dic;
void printSolution() {
    ofstream fout ("holstein.out");
    fout<<tmpV.size();
    for(int k = 0; k<tmpV.size();k++) {
        fout<<" "<<tmpV[k] + 1;
    }
    fout<<endl;
}
void combination(int n, int start) {
    // cout<<"asfasf "<<tmpV.size()<<endl;
    if (n <= tmpV.size()) {
        if (printVector()) {
            printSolution();
            dic = true;
        }
        return;
    }
    for(int i = start; i<g; i++) {
        if(dic) {
            return;
        }
        tmpV.pb(i);
        combination(n, i + 1);
        tmpV.erase(tmpV.begin() + tmpV.size() - 1);
    }
}
int main()
{
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
    fin>>v;
    for(int i = 0; i<v; i++) {
        int a;
        fin>>a;
        vRequirement.pb(a);
    }

    fin>>g;

    for(int i = 0; i<g; i++) {
        for (int j = 0; j<v; j++) {
            int a;
            fin>>a;
            feedType[i].pb(a);
        }
    }
    dic = false;

    for(int i = 0; i<g;i++) {
        if(dic) {
            break;
        }
        tmpV.clear();
        combination(i+1, 0);
    }

    return 0;
}


