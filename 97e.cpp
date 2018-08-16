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

const int MAX_N = 2000;

int N;
char c[MAX_N * 2];
int a[MAX_N * 2];

int cnt[2][MAX_N * 2][MAX_N + 1];
int plc[2][MAX_N + 1];

void count(){
  int cw[N + 1];
  int cb[N + 1];
  REP(i, N + 1) {
    cw[i] = 0;
    cb[i] = 0;
  }

  REP(i, N * 2) {
    REP(j, N + 1) {
      if(c[i] == 'W' && a[i] > j) cw[j]++;
      if(c[i] == 'B' && a[i] > j) cb[j]++;
      cnt[0][i][j] = cw[j];
      cnt[1][i][j] = cb[j];
    }
  }
}



int main(){
  cin >> N;
  REP(i, N * 2) cin >> c[i] >> a[i];

  count();

  REP(i, N * 2) {
    if(c[i] == 'W') plc[0][a[i]] = i;
    if(c[i] == 'B') plc[1][a[i]] = i;
  }

  int dp[N + 1][N + 1];
  dp[0][0] = 0;

  REP(i, N + 1) {
    REP(j, N + 1) {
      if (i == 0 && j == 0) continue;
      else if(i == 0) {
        dp[i][j] = dp[i][j - 1] + cnt[1][plc[1][j]][j] + cnt[0][plc[1][j]][i];
      } else if (j == 0) {
        dp[i][j] = dp[i - 1][j] + cnt[0][plc[0][i]][i] + cnt[1][plc[0][i]][j];

      } else {
        dp[i][j] = min(dp[i - 1][j] + cnt[0][plc[0][i]][i] + cnt[1][plc[0][i]][j], dp[i][j - 1] + cnt[1][plc[1][j]][j] + cnt[0][plc[1][j]][i]);
      }
    }
  }

  cout << dp[N][N] << endl;;


  return 0;
}
