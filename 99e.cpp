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

const int MAX_N = 700;
const int MAX_M = 700 * 699 / 2;

int N, M;
int A[MAX_M];
int B[MAX_M];
bool e[MAX_N][MAX_N];
bool used[MAX_N];


int black;
int white;
int color[MAX_N];

bool dfs(int v, int c) {
  used[v] = true;
  color[v] = c;
  if(c == 0) white++;
  else black++;
  REP(u, N) {
    if(e[v][u]) {
      if(used[u]) {
        if(color[u] != 1 - c) return false;
      } else {
        if(!dfs(u, 1 - c)) return false;
      }
    }
  }
  return true;
}

int main(){
  cin >> N >> M;

  REP(i, N) REP(j, N) e[i][j] = true;
  REP(i, N) e[i][i] = false;

  REP(i, M) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
    e[A[i]][B[i]] = false;
    e[B[i]][A[i]] = false;
  }

  REP(i, N) used[i] = false;

  vi s, t;
  REP(i, N) {
    if(!used[i]) {
      white = 0;
      black = 0;
      if(!dfs(i, 0)) {
        cout << -1 << endl;
        return 0;
      }
      s.push_back(white);
      t.push_back(black);
    }
  }

  int num = s.size();
  bool dp[num + 1][2 * MAX_N];
  REP(i, num + 1) REP(j, 2 * MAX_N) dp[i][j] = false;
  dp[0][0] = true;
  REP(i, num) {
    REP(j, N) {
      if(dp[i][j]) {
        dp[i + 1][j + s[i]] = true;
        dp[i + 1][j + t[i]] = true;
      }
    }
  }

  int ans = N * (N - 1) / 2;
  REP(j, N + 1) {
    if(dp[num][j]) {
      ans = min(ans, (j * (j - 1) / 2) + ((N - j) * (N - j - 1) / 2));
    }
  }

  cout << ans << endl;


  return 0;
}
