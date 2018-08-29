#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <string.h>
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

const int MAX_N = 100;

int N;
ll a[MAX_N + 1];

// ford-fulkerson O(FE) F:Flow
// maximum flow problem
// 1. init G[V] by add_edge
// 2. max_flow(s, t) return the max flow

const int MAX_V = MAX_N + 2;

struct edge{int to;ll cap; int rev;};

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, ll cap){
  G[from].push_back((edge){to, cap, int(G[to].size())});
  G[to].push_back((edge){from, 0, int(G[from].size() -1)});
}

ll dfs(int v, int t, ll f){
  if(v == t) return f;
  used[v] = true;
  for (int i = 0; i < G[v].size(); i++){
    edge &e = G[v][i];
    if(!used[e.to] && e.cap > 0){
      ll d = dfs(e.to, t, min(f, e.cap));
      if (d > 0){
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

ll max_flow(int s, int t){
  ll flow = 0;
  for(;;){
    memset(used, 0, sizeof(used));
    ll f = dfs(s, t, INFi);
    if(f == 0) return flow;
    flow += f;
  }
}

int main(){
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  ll ans = 0;

  int s = 0, t = N + 1;
  for(int i = 1; i <= N; i++) {
    if(a[i] < 0) {
      add_edge(s, i, -a[i]);
    } else {
      ans += a[i];
      add_edge(i, t, a[i]);
    }
    for(int j = 2; i * j <= N; j++) {
      add_edge(i, i * j, 1333333333333);
    }
  }

  ans -= max_flow(s, t);

  cout << ans << endl;


  return 0;
}
