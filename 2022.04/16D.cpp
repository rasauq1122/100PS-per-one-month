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

string s, k;
int slen, klen;
vi par;
vi idx;
vp word;

wi edge;
vs node;

int n = 1;

int dp[333334][20][2];

int foo(int now, int p, bool aft) {
    int& ret = dp[now][p][aft];

    if (ret != -1) return ret;
    
    int len = sz(node[now]);
    if (aft) {
        rep(i, 0, min(klen-p, len)) if (node[now][i] != k[i+p]) return ret = 0;
        if (klen-p <= len) return ret = 1;
        
        each(edge[now], nxt) {
            if (foo(nxt, p+len, 1)) return ret = 1;
        }
        
        return ret = 0;
    }
    
    rep(st, 0, len) {

        bool okay = true;
        rep(i, 0, min(klen, len - st)) {
            if (node[now][i+st] != k[i]) {
                okay = false;
                break;
            }
        }

        if (!okay) continue;

        if (klen <= len-st) return ret = 1;
        each(edge[now], nxt) {
            if (foo(nxt, len-st, 1)) return ret = 1;
        }
    }

    return ret = 0;
}

void dfs(int i) {
    if (!foo(i, 0, 0)) {
        cout << '[' << node[i];
        each(edge[i], nxt) dfs(nxt);
        cout << ']';
    }
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> s;
    cin >> k;

    slen = sz(s);
    klen = sz(k);

    par = vi(slen+1, -1);
    idx = vi(slen+1, -1);
    word = vp(slen+1);
    stack <pii> stk;
    stk.push({0, 1});

    idx[0] = 0;
    repe(i, 1, slen) {
        if (s[i-1] == '[') {
            idx[i] = n++;
            auto [p, w] = stk.top();
            if (!w) {
                stk.pop();
                stk.push({p, 1});
                word[p] = {p, i-2};
            }    
            stk.push({i, 0});
            par[i] = p;
        }
        else if (s[i-1] == ']') {
            auto [p, w] = stk.top();
            if (!w) word[p] = {p, i-2};
            stk.pop();
        }
    }

    edge = wi(n);
    node = vs(n);
    repe(i, 1, slen) {
        if (par[i] == -1) continue;
        
        edge[idx[par[i]]].pb(idx[i]);
        node[idx[i]] = s.substr(word[i].ff, word[i].ss-word[i].ff+1);
    }

    mset(dp, -1);
    bool okay = false;
    each(edge[0], nxt) if (!foo(nxt, 0, 0)) {
        okay = true;
        dfs(nxt);
    }
    if (!okay) cout << "torie!";
    cout << endl;
}