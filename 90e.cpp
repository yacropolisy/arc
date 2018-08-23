#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

const int MAX_N = 100000;
const int MAX_M = 200000;

int N, M;
int S, T;
// int U[MAX_M], V[MAX_M];
// ll D[MAX_M];

// set V in main
// d[MAX_V] shows the answer

const int MAX_V = 100000;

struct edge{int to; ll cost;};
typedef pair<ll, int> P;

int V;
vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(int s){
  priority_queue<P, vector<P>, greater<P>  > que;
  fill(d, d + V, INFll);
  d[s] = 0;
  que.push(P(0,s));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(int i = 0; i < G[v].size(); i++){
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

ll dp1[MAX_V], dp2[MAX_V];
// bool used1[MAX_V], used2[MAX_V];

ll dfs1(int v) {
  if(dp1[v] > 0) return dp1[v];
  // used1[v] = true;
  int res = 0;
  REP(i, G[v].size()) {
    int u = G[v][i].to;
    if(d[v] - d[u] == G[v][i].cost) res = (res + dfs1(u)) % MOD;
  }
  return dp1[v] = res;
}

ll dfs2(int v) {
  if(dp2[v] > 0) return dp2[v];
  // used2[v] = true;
  int res = 0;
  REP(i, G[v].size()) {
    int u = G[v][i].to;
    if(d[u] - d[v] == G[v][i].cost) res = (res + dfs2(u)) % MOD;
  }
  return dp2[v] = res;
}

int main(){
  cin >> N >> M;
  cin >> S >> T;
  S--; T--;
  int u, v;
  ll dd;
  REP(i, M) {
    cin >> u >> v >> dd;
    u--; v--;
    G[u].push_back((edge){v, dd});
    G[v].push_back((edge){u, dd});
  }
  V = N;
  dijkstra(S);
  REP(i, N) {
    dp1[i] = 0;
    dp2[i] = 0;
  }
  dp1[S] = 1;
  dp2[T] = 1;

  // REP(i, N) {
  //   used1[i] = false;
  //   used2[i] = false;
  // }

  // REP(i, N) {
  //   if(!used1[i]) dfs1(i);
  //   if(!used2[i]) dfs2(i);
  // }
  dfs1(T); dfs2(S);

  ll ans = 0;
  ans += dp1[T] * dp1[T] % MOD;
  ll mid = d[T] / 2;
  REP(v, N) {
    if(d[v] == mid) ans = (ans - dp1[v] * dp1[v] % MOD * dp2[v] % MOD * dp2[v] % MOD + MOD) % MOD;
    else {
      REP(i, G[v].size()) {
        int u = G[v][i].to;
        if(d[u] > mid && d[v] < mid && d[u] - d[v] == G[v][i].cost) {
          ans = (ans - dp1[v] % MOD * dp1[v] % MOD * dp2[u] % MOD * dp2[u] % MOD + MOD) % MOD;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
