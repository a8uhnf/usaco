
/*
ID: hanifbo1
PROG: preface
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

int main()
{
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
    int n;
    fin>>n;
    map<string, int>cToi;
    map<int, string>iToc;
    map<int, string>::reverse_iterator it;
    map<string, int>::iterator it1;
    vector<int>divider;

    iToc[1] = "I";
    iToc[4] = "IV";
    iToc[5] = "V";
    iToc[9] = "IX";
    iToc[10] = "X";
    iToc[40] = "XL";
    iToc[50] = "L";
    iToc[90] = "XC";
    iToc[100] = "C";
    iToc[400] = "CD";
    // iToc[400] = "CD";
    iToc[500] = "D";
    iToc[900] = "CM";
    iToc[1000] = "M";
    for(it = iToc.rbegin(); it != iToc.rend(); it++) {
        divider.pb(it->first);
    }

    for(int k = 1; k<=n; k++) {
        int idx = 0;
        string ans = "";
        int exp = k;
        cout<<"``````````````` "<<k<<endl;
        while(exp != 0) {
            if (exp < divider[idx]) {
                idx++;
                continue;
            }
            int tmp = exp/divider[idx];
            if (tmp != 0) {
                exp = exp - (tmp*divider[idx]);
            } else {
                tmp = exp;
            }
            string ch = iToc[divider[idx]];
            cout<< (ch) <<" "<<tmp<<endl;
            for(int i = 0; i<ch.length(); i++) {
                stringstream ss;
                char c = ch[i];
                string s1;
                ss<<c;
                ss>>s1;
                cToi[s1] += tmp;
            }
            idx++;
        }
        // cout<<ans<<endl;
//        for(int i = 0; i<ans.length(); i++) {
//            char tmp = ans[i];
//            cToi[tmp] += 1;
//        }
    }
    vector<string>mapToRoman;
    mapToRoman.pb("I");
    mapToRoman.pb("V");
    mapToRoman.pb("X");
    mapToRoman.pb("L");
    mapToRoman.pb("C");
    mapToRoman.pb("D");
    mapToRoman.pb("M");
    for(int i = 0; i<mapToRoman.size(); i++) {
        string tmp = mapToRoman[i];
        if (cToi[tmp] != 0) {
            fout<<tmp<<" "<<cToi[tmp]<<endl;
        }
    }

    return 0;
}

