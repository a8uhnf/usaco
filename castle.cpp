
/*
ID: hanifbo1
PROG: castle
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
bool visit[55][55], wallChk[10];
vector<int>x[20], y[20], wall, tmp;
int compass[5][5];
int input[55][55];
int xD[4] = {-1, +1, 0, 0};
int yD[4] = {0, 0, -1, +1};
void printVector() {
    int xP = 1, yP = 1;
    int sum = 0;
    FORL(0, tmp.size()) {
        sum += tmp[i];
    }
    // cout<<sum<<endl;
    for(int i = 0;i<4; i++) {
        int xT = xP + xD[i], yT = yP + yD[i];
        bool dic = true;
        for (int j = 0; j<tmp.size(); j++) {
            if (compass[xT][yT] == tmp[j]) {
                // cout<<"::::"<<tmp[j]<<endl;
                dic = false;
                // x[sum].pb(0);
                // y[sum].pb(0);
            } else {
                // cout<<compass[xT][yT]<<endl;
            }
        }
        if (dic) {
            x[sum].pb(xD[i]);
            y[sum].pb(yD[i]);
        }
    }
}

void permuteWall(int len, int position) {
    if (tmp.size() == len) {
        printVector();
        return;
    }
    for(int i = position; i<4; i++) {
        tmp.pb(wall[i]);
        permuteWall(len, i+1);
        tmp.erase(tmp.begin() + tmp.size() - 1);
    }
}
void preProcess() {
    mem(visit, 0);
    wall.pb(1);
    wall.pb(2);
    wall.pb(4);
    wall.pb(8);
    compass[0][1] = 2;
    compass[1][0] = 1;
    compass[1][2] = 4;
    compass[2][1] = 8;
    for(int i = 0; i<4; i++) {
        permuteWall(i+1, 0);
    }
}
void printMatrix(int n, int m) {
    for(int i = 0;i<m;i++) {
        for(int j = 0; j< n; j++) {
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    preProcess();
//    for(int i = 0; i<=15; i++) {
//        if (x[i].size() && y[i].size()) {
//            for(int j = 0; j<x[i].size(); j++) {
//                cout<<x[i][j]<<" "<<y[i][j]<<endl;
//            }
//            cout<<"==================="<<endl;;
//        }
//    }
    int n,m;
    fin>>n>>m;
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {
            fin>>input[i][j];
        }
    }
    return 0;
}
