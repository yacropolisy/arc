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

const int MAX_N = 18;

int N;
ll A[1 << MAX_N];

pll B[1 << MAX_N];

pll max2(pll a, pll b) {
  ll t[4] = {a.first, a.second, b.first, b.second};
  sort(t, t + 4, greater<ll>());
  return pll(t[0], t[1]);
}

int main(){
  cin >> N;
  REP(i, 1 << N) {
    cin >> A[i];
    B[i] = pll(A[i], 0);
  }

  REP(i, N) REP(j, 1 << N) {
    if(j & (1 << i)) {
      B[j] = max2(B[j], B[j ^ (1 << i)]);

    }
  }

  ll ma = 0;

  // REP(i, 1 << N) {
  //   cout << B[i].first + B[i].second << endl;
  // }

  for(int i = 1; i < 1 << N; i++) {
    ma = max(ma, B[i].first + B[i].second);
    cout << ma << endl;
  }

  // REP(i, 1 << N) {
    // cout << B[i].first << ", " << B[i].second << endl;
  // }

  return 0;
}
