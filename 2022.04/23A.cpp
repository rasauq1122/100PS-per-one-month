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
    
    int h, m;
    char tmp;
    
    cin >> h >> tmp >> m;

    tuple <int, string, string> nin = {INF, "", ""};

    int x[10] = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};
    int y[10] = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};

    rep(i, 0, 5) {
        rep(j, 0, 2) {
            int H = h + 24*i;
            int M = m + 60*j;

            if (H > 99 || M > 99) continue; 

            vi v = {H/10, H%10, M/10, M%10};
            int eff = 0;
            rep(i, 1, 4) eff += abs(x[v[i]] - x[v[i-1]]) + abs(y[v[i]] - y[v[i-1]]);
            
            nin = min(nin, {eff, itos(v[0])+itos(v[1]), itos(v[2])+itos(v[3])});
        }
    }

    cout << get<1>(nin) << ":" << get<2>(nin) << endl;
}