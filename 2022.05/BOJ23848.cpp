////////////////////////////////////////
//   Today : Mon May  2 13:17:20 2022 //
//  Author : rasauq1122               //
// Problem : BOJ23848                 //
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

#define int long long

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

lli pow(int a, int b, lli c) {if (!b) return 1; lli rtn = pow(a, b/2, c); rtn = (1LL * rtn * rtn) % c; if (b%2) {rtn = 1LL * rtn * a % c;} return rtn;}
int safe(int x, int y, int Mx, int My, int mx = 0, int my = 0) {return mx <= x && x < Mx && my <= y && y < My;}
int mivs(int a, int m) {int u = 0, v = 1, k = m; while (a != 0) {int t = k / a; k -= t * a; swap(a, k); u -= t * v; swap(u, v);} return (u+m)%m;}

vl v(1000001);
lli n;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n;

    repe(i, 2, 1000000) {
        lli now = 1 + i + 1LL*i*i;
        v[i] = now;
    }

    int len = sz(v);
    int cnt = 3;
    repe(cnt, 3, 40) {
        repe(i, 2, 1000000) {
            if (n < v[i]) break;
            if (n%v[i]) {
                lli now = pow(i, cnt, LINF);
                if (now > n || now + v[i] > n) continue;
                v[i] += now;
            }
            else {
                cout << cnt << endl;
                lli k = n/v[i];
                rep(j, 0, cnt) {
                    cout << k << ' ';
                    k *= i;
                }
                return 0;
            }
        }
    }

    cout << -1 << endl;
}