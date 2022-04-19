#include <bits/stdc++.h>

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

#define print cout <<
#define BLK << ' ' <<
#define BLE << ' '
#define NLE << '\n'

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

int n, m, d;
string s[500];
wi dist(500, vi(500, INF));
wi vis(500, vi(500));
dxdy(dx, dy);

void dijk() {
    priority_queue < tiii, vt, greater<tiii>> pq;
    pq.push({0, 0, 0});
    vis[0][0] = true;

    while (!pq.empty()) {
        auto [cum, x, y] = pq.top();
        pq.pop();
        
        if (dist[x][y] != INF) continue;
        vis[x][y] = false;
        dist[x][y] = cum;
        
        if (dist[n-1][m-1] != INF) return;

        rep(i, 0, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (!safe(nx, ny, n, m)) continue;
            if (s[nx][ny] == '#') continue;
            if (dist[nx][ny] == INF) {
                pq.push({cum, nx, ny});
            }
        }

        // 0  0 1 -1
        // 1 -1 0  0
        rep(i, 0, 4) {
            repe(j, -(d-1), (d-1)) {
                int nx = x + (i/2 ? d*dx[i] : j);
                int ny = y + (i/2 ? j : d*dy[i]);

                if (nx >= n) nx = n-1;
                else if (nx < 0) nx = 0;

                if (ny >= m) ny = m-1;
                else if (ny < 0) ny = 0;

                if (!safe(nx, ny, n, m)) continue;
                if (dist[nx][ny] != INF) continue;
                if (vis[nx][ny]) continue;
                vis[nx][ny] = true;
                pq.push({cum+1, nx, ny});
            }
        }

        if (n - x <= d && m - y <= d) {
            if (vis[n-1][m-1]) continue;
            vis[n-1][m-1] = true;
            pq.push({cum+1, n-1, m-1});
        }
    }
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> m >> d;
    
    rep(i, 0, n) cin >> s[i];
    dist = wi(n, vi(m, INF));
    vis = wi(n, vi(m));
    dijk();

    cout << dist[n-1][m-1] << endl;
}