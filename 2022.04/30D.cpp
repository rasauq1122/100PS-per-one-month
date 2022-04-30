////////////////////////////////////////
//   Today : Sat Apr 30 09:35:48 2022 //
//  Author : rasauq1122               //
// Problem : BOJ2942                  //
////////////////////////////////////////

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

#ifdef LOCAL
    #define print(x) cout << x
    #define BLS ' ' <<
    #define BLK << ' ' <<
    #define BLE << ' '
    #define NLE << '\n'
#else
    #define print(x)
    #define BLS
    #define BLK
    #define BLE
    #define NLE
#endif

#define sz(a) (int)((a).size())
#define all(v) (v).begin(), (v).end()
#define uniq(v) (sort((v).begin(), (v).end()), (v).erase(unique((v).begin(),(v).end()),(v).end()))
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
template <typename T> vector<T> vec(int n) {return vector<T>(n);}
template <typename T, typename... Types> auto vec(int n, Types... sz) {auto nvec = vec<T>(sz...); return vector<decltype(nvec)>(n, nvec);}

typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
typedef tuple<int,int,int,int> tII;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<pii> vp;
typedef vector<vp> wp;
typedef vector<tiii> vt;
typedef vector<vt> wt;
typedef long long lli;
typedef pair<lli,lli> pll;
typedef tuple<lli,lli,lli> tlll;
typedef tuple<lli,lli,lli,lli> tLL;
typedef vector<lli> vl;
typedef vector<vl> wl;
typedef vector<pll> vpl;
typedef vector<vpl> wpl;
typedef vector<tlll> vtl;
typedef vector<vtl> wtl;

int pow(int a, int b, int c) {if (!b) return 1; int rtn = pow(a, b/2, c); rtn = rtn * rtn % c; if (b%2) {rtn = rtn * a % c;} return rtn;}
int safe(int x, int y, int Mx, int My, int mx = 0, int my = 0) {return mx <= x && x < Mx && my <= y && y < My;}
int mivs(int a, int m) {int u = 0, v = 1, k = m; while (a != 0) {int t = k / a; k -= t * a; swap(a, k); u -= t * v; swap(u, v);} return (u+m)%m;}

int f[500001];
int n, c, d;
lli a, b;

bool np[711];
vi p;

int vis[500001];
int cyc[500001];

int dfs(int idx, int len) {
    if (vis[idx]) return len;
    vis[idx] = true;
    return cyc[idx] = dfs(f[idx], len+1);
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> a >> b >> c >> d;
    repe(i, 1, n) cin >> f[i];

    repe(i, 2, 710) if (!np[i]) {
        p.pb(i);
        for (int j = 2*i ; j <= 710 ; j += i) np[i] = true;
    }

    vi now(sz(p));
    vi rem;
    int k = sz(p);
    repe(i, c+1, n-d) if (!vis[i]) {
        int len = dfs(i, 0);      
        rep(j, 0, k) {
            int cnt = 0;
            while (len%p[j] == 0) {
                now[j] = max(now[j], ++cnt);
                len /= p[j];
            }
        }

        rem.pb(len);
    }

    lli lcm = 1;
    rep(i, 0, k) {
        while (now[i]--) {
            if (lcm >= 1e12) break;
            lcm *= p[i];
        }
        if (lcm >= 1e12) break;
    }

    uniq(rem);
    each(rem, q) {
        lcm *= q;
        if (lcm >= 1e12) break;
    }

    lli s = (a-1)/lcm, e = (b-1)/lcm;
    cout << e - s + ((a-1)%lcm == 0) << endl;
}