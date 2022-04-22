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



signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    wi v(n, vi(n, -1));
    vi x(n), y(n), d(n);

    int dy[8] = {1, 1, 1, 0, -1, -1,- 1, 0};
    int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    rep(i, 0, n) {
        cin >> x[i] >> y[i] >> d[i];
        d[i]--;
    }

    rep(i, 0, n) rep(j, i+1, n) {
        // x[i] + d[i]*k == x[j] + d[j]*k
        // y[i] + d[i]*k == y[j] + d[j]*k

        int di = d[i], dj = d[j];
        int xk, yk;
        
        if (dx[dj] == dx[di] && x[i] == x[j]) xk = 0;
        else if (dx[dj]-dx[di] && !((x[i]-x[j])%(dx[dj]-dx[di]))) 
            xk = (x[i]-x[j])/(dx[dj]-dx[di]);
        else continue;

        if (dy[dj] == dy[di] && y[i] == y[j]) yk = 0;
        else if (dy[dj]-dy[di] && !((y[i]-y[j])%(dy[dj]-dy[di]))) 
            yk = (y[i]-y[j])/(dy[dj]-dy[di]);
        else continue;

        if (xk < 0 || yk < 0) continue;

        if (!xk) v[i][j] = v[j][i] = yk;
        else if (!yk || xk == yk) v[i][j] = v[j][i] = xk;
    }

    pii ans = {0, INF};
    rep(i, 0, n) {
        sort(all(v[i]));
        
        int idx = upper_bound(all(v[i]), -1) - v[i].begin();
        
        if (idx == n) continue;

        pii nax = {0, INF};
        int cnt = 1, now = v[i][idx];
        rep(j, idx, n-1) {
            if (v[i][j] == v[i][j+1]) cnt++;
            else {
                nax = max(nax, {cnt, -now});
                cnt = 1, now = v[i][j+1];
            }
        }

        ans = max({ans, nax, {cnt, -now}});
    }

    cout << ans.ff+1 << endl << -ans.ss << endl;
}