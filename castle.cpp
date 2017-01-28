
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
int numberOfRomms;
int searchNumberOfRooms(int xx, int yy) {
    if (visit[xx][yy]) {
        return 0;
    }
    // cout<<xx<<"   "<<yy<<endl;
    int ret = -1;
    int sum = input[xx][yy];
    visit[xx][yy] = 1;
    for(int i = 0; i<x[sum].size(); i++) {
        ret = max(1 + searchNumberOfRooms(xx + x[sum][i], yy + y[sum][i]), ret);
    }
    // cout<<ret<<endl;
    return ret;
}
int space;
int n,m;
int countSpace(int xx,int yy) {
    if (xx < 0 || yy < 0 || xx >=m || yy >= n){
        return 0;
    }
    if (visit[xx][yy]) {
        return 0;
    }
    space++;
    // cout<<xx<<"   "<<yy<<"  # "<<space<<endl;
    int ret = +1;
    int sum = input[xx][yy];
    visit[xx][yy] = 1;
    for(int i = 0; i<x[sum].size(); i++) {
        countSpace(xx + x[sum][i], yy + y[sum][i]);
    }
    return ret;
}
struct wallBreakPoint {
    int x,y;
    string direction;
} pointOn;
int mxSizewithBreakWall;
int breakWall(int xx, int yy) {
    int sum = input[xx][yy];
    for(int i = 0; i<4;i++) {
        bool skip = false;
        int nxtX = xx + xD[i], nxtY = yy + yD[i];
        for(int j = 0; j<x[sum].size(); j++) {
            if (x[sum][j] == xD[i] && y[sum][j] == yD[i]) {
                skip = true;
            }
        }
        for(int j = 0; j<y[sum].size(); j++) {
            if (y[sum][j] == yD[i] && yD[i] != 0) {
                skip = true;
            }
        }
        if (nxtX < 0 || nxtY < 0 || nxtX >= m || nxtY >= n) {
            skip = true;
        }
        if (skip) {
            continue;
        }
        // if (x[sum])
        // x[sum].pb(xD[i]);
        // y[sum].pb(yD[i]);
        mem(visit, 0);
        cout<<xx<<" "<<yy<<endl;
        cout<<"````````````````\n";
        space = 0;
        if (xx == 2 && yy == 3) {
            for(int l = 0; l<x[sum].size(); l++) {
                cout<<"X: "<<x[sum][l]<<" Y: "<<y[sum][l]<<endl;
            }
        }
        countSpace(xx, yy);
        countSpace(nxtX, nxtY);
        cout<<"space = "<<space<<endl;
        if (space > mxSizewithBreakWall) {
            cout<<xx<<" "<<yy<<endl;
            mxSizewithBreakWall = space;
            pointOn.x = xx;
            pointOn.y = yy;
            if (xD[i] == -1) {
                pointOn.direction = "N";
            } else if (xD[i] == +1) {
                pointOn.direction = "S";
            } else if (yD[i] == -1) {
                pointOn.direction = "W";
            } else if(yD[i] == +1) {
                pointOn.direction = "E";
            }
        }

        // printVector();
        for(int l = 0; l<x[sum].size(); l++) {
            // cout<<"X: "<<x[sum][l]<<" Y: "<<y[sum][l]<<endl;
        }
        cout<<"'''''''''''''''''''\n";
        // x[sum].erase(x[sum].begin() + x[sum].size() - 1);
        // y[sum].erase(y[sum].begin() + y[sum].size() - 1);
        // cout<<"===="<<ret<<endl;
    }
    return mxSizewithBreakWall;
}
int main()
{
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    preProcess();
    numberOfRomms = 0;
//    for(int i = 0; i<=15; i++) {
//        if (x[i].size() && y[i].size()) {
//            for(int j = 0; j<x[i].size(); j++) {
//                cout<<x[i][j]<<" "<<y[i][j]<<endl;
//            }
//            cout<<"==================="<<endl;;
//        }
//    }
    fin>>n>>m;
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {
            fin>>input[i][j];
        }
    }
    x[0].pb(-1);
    x[0].pb(+1);
    y[0].pb(+0);
    y[0].pb(+0);

    x[0].pb(+0);
    x[0].pb(+0);
    y[0].pb(-1);
    y[0].pb(+1);

    int largestRoom = -1;
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {
            // fin>>input[i][j];
            if (!visit[i][j]) {
                numberOfRomms++;
                // largestRoom = max(1 + searchNumberOfRooms(i,j), largestRoom);
                space = 0;
                countSpace(i,j);
                largestRoom = max(largestRoom, space);
            }
        }
    }
    fout<<numberOfRomms<<endl;
    fout<<largestRoom<<endl;
    int roomAreaAfterBreak = largestRoom;
    mxSizewithBreakWall = -1;
    for (int j = 0; j<n; j++) {
        for(int i = m - 1; i >= 0; i--) {
            roomAreaAfterBreak = max(breakWall(i,j), roomAreaAfterBreak);
        }
    }
    fout<<roomAreaAfterBreak<<endl;
    fout<<pointOn.x + 1<<" "<<pointOn.y + 1<<" "<<pointOn.direction<<endl;
    return 0;
}
