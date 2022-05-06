////////////////////////////////////////
//   Today : Fri May  6 09:53:46 2022 //
//  Author : rasauq1122               //
// Problem : BOJ2237                  //
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

int n, t;
int a[101];

bool dp[101][20001];
int btk[101][20001];

bool foo(int idx, int val) {
    bool &ret = dp[idx][val];
    int &vis = btk[idx][val];

    if (vis) return ret;
    if (idx == n) return ret = val == 10000+t;    

    if (foo(idx+1, val+a[idx])) return vis = 1, ret = true;
    if (foo(idx+1, val-a[idx])) return vis = -1, ret = true;

    return vis = 2, ret = false;
}

int sign[100];

void setup(int idx, int val) {
    if (idx == n) return;
    
    sign[idx] = btk[idx][val];
    if (sign[idx] == 1) setup(idx+1, val+a[idx]);
    else setup(idx+1, val-a[idx]);
}

int ans[100];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n >> t;
    rep(i, 0, n) cin >> a[i];

    if (n <= 2) {
        if (n == 2) cout << 1 << endl;
        return 0;
    }

    btk[0][10000] = 1;
    btk[1][10000+a[0]] = -1;

    foo(2, 10000+a[0]-a[1]);
    setup(0, 10000);

    queue <int> q;

    int cnt = 0;
    int flag = -1;

    rep(i, 1, n) {
        if (sign[i] == -1) {
            if (i+1 < n && sign[i+1] == 1) flag = i;
            else ans[++cnt] = i;
        }
        if (sign[i] == 1) {
            q.push(i);
            if (i == n-1 || sign[i+1] == -1) {
                while (!q.empty()) {
                    ans[++cnt] = q.front();
                    q.pop();
                }
                ans[++cnt] = flag;
                flag = -1;
            }
        }
    }

    rep(i, 1, n) {
        int now = ans[i];
        rep(j, 1, i) if (ans[j] < ans[i]) now--;
        cout << now << endl;
    }
}