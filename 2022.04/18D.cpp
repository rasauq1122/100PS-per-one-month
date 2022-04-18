#include <bits/stdc++.h>

#define int long long

#define INF ((1LL<<31)-1)
#define LINF ((1LL<<61)-1)
#define MOD 1000000007
#define MOD2 998244353

#define TC() int CASE_N;cin>>CASE_N;for(int CASE_I=1;CASE_I<=CASE_N;CASE_I++)
#define FIX(a) cout<<fixed;cout.precision(a);

#define rep(i,j,k) for(int i=(j);i<(k);i++)
#define repe(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(k)-1;i>=(j);i--)
#define pere(i,j,k) for(int i=(k);i>=(j);i--)
#define each(v,n) for(auto n:v)

#define yesif(x) cout<<((x)?"YES":"NO")<<'\n'
#define impif(x) if(x){cout<<-1<<'\n';continue;}

#define ff first
#define ss second
#define pb push_back
#define bp pop_back
#define mp make_pair
#define mt make_tuple
#define itos to_string
#define endl '\n'

#define sz(a) (int)((a).size())
#define all(v) (v).begin(), (v).end()
#define uniq(v) sort((v).begin(), (v).end()); (v).erase(unique((v).begin(),(v).end()),(v).end()) 
#define mset(arr, n) memset(arr, n, sizeof(arr));

#define BIT(a,b) (((a)>>(b))&1)
#define dxdy(dx,dy) int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1}

#define fsi(f) freopen(f, "r", stdin) 
#define fso(f) freopen(f, "w", stdout)

#define RANDOM()         random_device rand;mt19937 seed(rand())
// int-random-value    : uniform_int_distribution<int> gen(min,max);
// double-random-value : uniform_real_distribution<double> gen(min,max);
// how-to-get-value    : gen(seed)

using namespace std;

template <typename T1, typename T2> ostream& operator<<(ostream& out, pair<T1, T2>& p) {out << '{' << p.first << ", " << p.second << '}'; return out;}
template <typename T> ostream& operator<<(ostream& out, vector<T>& v) {int len = v.size(); for (int i = 0 ; i < len ; i++) out << v[i] << (i+1 == len ? '\n' : ' '); return out;}
template <typename T> ostream& operator<<(ostream& out, vector<vector<T>>& v) {int len = v.size(); for (int i = 0 ; i < len ; i++) out << v[i]; return out;}

typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
typedef tuple<int,int,int,int> tII;
typedef vector<int> vi;
typedef vector<pair<int,int>> vp;
typedef vector<tuple<int,int,int>> vt;
typedef vector<string> vs;
typedef vector<vector<int>> wi;
typedef vector<vector<pair<int,int>>> wp;
typedef vector<vector<tuple<int,int,int>>> wt;

int pow(int a, int b, int c) {if (!b) return 1; int rtn = pow(a, b/2, c); rtn = rtn * rtn % c; if (b%2) {rtn = rtn * a % c;} return rtn;}
int safe(int x, int y, int Mx, int My, int mx = 0, int my = 0) {return mx <= x && x < Mx && my <= y && y < My;}
int mivs(int a, int m) {int u = 0, v = 1, k = m; while (a != 0) {int t = k / a; k -= t * a; swap(a, k); u -= t * v; swap(u, v);} return (u+m)%m;}

int n, m;
string s[100];

int dp, cc;
int num[100][100];
pii nxt[10001][4][2];
char f[10001];

tII info[10001][4][2];

dxdy(dx, dy);

void bfs(int ix, int iy, int p) {
    num[ix][iy] = p;
    queue <pii> q;
    q.push({ix, iy});

    int xmin = n, xmax = 0, ymin = m, ymax = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        xmin = min(x, xmin);
        xmax = max(x, xmax);
        ymin = min(y, ymin);
        ymax = max(y, ymax);

        for (int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!safe(nx, ny, n, m)) continue;
            if (s[nx][ny] != f[p]) continue;
            if (num[nx][ny]) continue;

            num[nx][ny] = p;
            q.push({nx, ny});
        }
    }

    // dp : left / cp : down 
    repe(i, xmin, xmax) {
        if (num[i][ymin] == p) {
            nxt[p][2][1] = {i, ymin-1};
            break;
        }
    }

    // dp : left / cp : up
    pere(i, xmin, xmax) {
        if (num[i][ymin] == p) {
            nxt[p][2][0] = {i, ymin-1};
            break;
        }
    }

    // dp : right / cp : down
    repe(i, xmin, xmax) {
        if (num[i][ymax] == p) {
            nxt[p][0][0] = {i, ymax+1};
            break;
        }
    }
    
    // dp : right / cp : up
    pere(i, xmin, xmax) {
        if (num[i][ymax] == p) {
            nxt[p][0][1] = {i, ymax+1};
            break;
        }
    }
    
    // dp : up / cp : left;
    repe(i, ymin, ymax) {
        if (num[xmin][i] == p) {
            nxt[p][3][0] = {xmin-1, i};
            break;
        }
    }

    // dp : up / cp : right
    pere(i, ymin, ymax) {
        if (num[xmin][i] == p) {
            nxt[p][3][1] = {xmin-1, i};
            break;
        }
    }

    // dp : down / cp : left
    repe(i, ymin, ymax) {
        if (num[xmax][i] == p) {
            nxt[p][1][1] = {xmax+1, i};
            break;
        }
    }
    
    // dp : down / cp : right
    pere(i, ymin, ymax) {
        if (num[xmax][i] == p) {
            nxt[p][1][0] = {xmax+1, i};
            break;
        }
    }

    // cout << "<" << ix << " " << iy << ">" << " " << p << endl;
    // cout << "x : " << xmin << " ~ " << xmax << endl;
    // cout << "y : " << ymin << " ~ " << ymax << endl;
    // rep(i, 0, 4) rep(j, 0, 2) {
    //     cout << i << " " << j << " : " << nxt[p][i][j] << endl;
    // } 
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n >> m;
    rep(i, 0, n) cin >> s[i];

    int cnt = 0;
    rep(i, 0, n) rep(j, 0, m) {
        if (!num[i][j] && s[i][j] != 'X') {
            f[++cnt] = s[i][j];
            bfs(i, j, cnt);
        }
    }
    
    repe(i, 1, cnt) rep(k, 0, 4) rep(l, 0, 2) {
        info[i][k][l] = {-1, -1, -1, -1};
        int dp = k, cc = l;
        rep(t, 0, 8) {
            auto [nx, ny] = nxt[i][dp][cc];
            if (safe(nx, ny, n, m) && s[nx][ny] != 'X') {
                info[i][k][l] = {nx, ny, dp, cc};
                break;
            }

            if (t%2) dp = (dp+1)%4;
            else cc = !cc;
        }
    }

    int x = 0, y = 0;
    int clock = 0;
    // queue <char> q;
    while (true) {
        int now = num[x][y];
        // clock++;
        cout << f[now];
        // cout << "<" << x << " " << y << ">" << endl;

        tie(x, y, dp, cc) = info[num[x][y]][dp][cc];
        if (x == -1 && y == -1) break;
        if (clock == 10) break;
    }
    
    // for(; !q.empty() ; q.pop()) cout << q.front();
    cout << endl;
}

/*
5 5
ABBBA
BCCCB
BCCCB
BCCCB
ABBBA
*/