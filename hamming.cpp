
/*
ID: hanifbo1
PROG: hamming
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

int n, b, d, mxLimit;
vector<int>ans;
void printAns() {
    ofstream fout ("hamming.out");
    for(int i = 0; i<ans.size(); i++) {
        if (i%10 == 0 && i != 0 ) {
            fout<<endl;
        } else if (i != 0)fout<<" ";
        fout<<ans[i];
    }
    fout<<endl;
}
string convertTobinary(int number) {
    string ret = "";
    while(number != 0) {
        ret += (number%2 + '0');
        number/=2;
    }
    for (int i = ret.length(); i < b; i++) {
        ret += '0';
    }
    return ret;
}
bool getTheDifferences(string s1, string s2) {
    int ret = 0;
    for(int i = 0; i<s1.length(); i++) {
        if(s1[i] != s2[i]) ret++;
    }
    if (ret >= d) {
        return true;
    }
    return false;
}

bool checkWhole(string s1) {
    for (int i = 0; i < ans.size(); i++ ) {
        string s2 = convertTobinary(ans[i]);
        if (!getTheDifferences(s1, s2)) {
            return false;
        }
    }
    return true;
}
void checkAns() {
    for(int i = 1; i<mxLimit; i++) {
        for (int j = i; j<mxLimit; j++) {
            string com1 = convertTobinary(j);
            if (ans.size() >= n) {
                printAns();
                return;
            }
            if (checkWhole(com1)) {
                ans.pb(j);
            }
        }
    }
    // return true;
}


int main()
{
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
    fin>>n>>b>>d;
    cout<<n<<b<<d<<endl;
    mxLimit = pow(2, b);
    ans.pb(0);
    checkAns();
    return 0;
}

