/*
ID: hanifbo1
PROG: wormhole
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
struct point{
    ll a,b;
};
int ans, cnt;
bool mark[20];
bool markNode[20];
vector<int>graph[20];
vector<point>v;
bool dic;
bool connectivityCheck[20][20];

void printGraph() {
    ofstream fout ("wormhole.out");
    cnt++;
    cout<<"````````````````````````` = "<<cnt<<endl;
    for (int k = 0; k<v.size(); k++) {
        for (int l = 0; l<graph[k].size(); l++) {
            cout<<"hello graph`````"<<k<<" > "<<graph[k][l]<<endl;
        }
    }
}

void graphVisit(int n) {
    if (markNode[n]) {
        ans++;
        // printGraph();
        dic = true;
        return;
    }
    markNode[n] = 1;
    for(int i = 0; i<v.size(); i++) {
        if (n == i) {
            continue;
        }
        if (v[n].b == v[i].b && (v[n].a - v[i].a) < 0) {
            graphVisit(graph[i][0]);
            break;
        }
    }
}

void generateGraph(int n, int nxt) {
    if (n >= v.size()/2) {
        dic = false;
        for(int i = 0;i<v.size();i++) {
            mem(markNode, 0);
            graphVisit(i);
            if (dic) {
                break;
            }
        }
        // printGraph();
        // cout<<cnt++<<endl;
        return;
    }
    // for(int ii = nxt;ii<v.size(); ii++) {
    int nnxt = nxt;
        if (mark[nxt]) {
            // continue;
            // nnxt = nxt + 1;
            generateGraph(n, nxt+1);
            return;
        }
        for(int jj = nnxt+1; jj<v.size(); jj++) {
            if (mark[jj]) {
                continue;
            }
            // if (!connectivityCheck[ii][jj]) {
                // connectivityCheck[nxt][jj] = 1;
                mark[nnxt] = mark[jj] = 1;
                graph[nnxt].pb(jj);
                graph[jj].pb(nnxt);
                generateGraph(n+1, nnxt+1);
                // connectivityCheck[ii][jj] = 0;
                graph[nnxt].clear();
                graph[jj].clear();
                mark[nnxt] = mark[jj] = 0;
            // }
        }
    // }
}

bool comp(point x, point y) {
    if (x.a < y.a)return true;
    return false;
}
void printVector() {
    for(int i = 0; i<v.size(); i++) {
        cout<<v[i].a<<" "<<v[i].b<<endl;
    }
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");
    cnt = 0;
    int n;
    fin>>n;
    ans = 0;
    dic = false;
    while(n--)
    {
        point a;
        fin>>a.a>>a.b;
        v.pb(a);
    }
    sort(v.begin(),v.end(), comp);
    // printVector();
    mem(mark, 0);
    for(int i = 0; i< 20; i++) {
        graph[i].clear();
    }

    for(int i = 1; i<v.size();i++) {
        mark[0] = mark[i] = 1;
        graph[0].pb(i);
        graph[i].pb(0);
        mem(connectivityCheck, 0);
        connectivityCheck[0][i] = 1;
        connectivityCheck[i][0] = 1;
        generateGraph(1, 1);
        graph[0].clear();
        graph[i].clear();
        connectivityCheck[0][i] = 0;
        connectivityCheck[i][0] = 0;
        mark[0] = mark[i] = 0;
    }
    // fout<<cnt<<endl;
    fout<<ans<<endl;
    return 0;
}

