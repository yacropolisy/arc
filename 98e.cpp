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

int N, K, Q;
int A[MAX_N];

int main(){
  cin >> N >> K >> Q;

  REP(i, N) cin >> A[i];

  int ans = INFi;

  REP(i, N) {
    int X = A[i];
    vvi vec;
    vi tmp;
    REP(j, N) {
      if(A[j] >= X) {
        tmp.push_back(A[j]);
      } else {
        vec.push_back(tmp);
        tmp.clear();
      }
      if(j == N - 1 && !tmp.empty()) vec.push_back(tmp);
    }

    vi rms;
    REP(j, vec.size()) {
      sort(ALL(vec[j]));
      if(vec[j].size() >= K) {
        REP(k, vec[j].size() - K + 1) {
          rms.push_back(vec[j][k]);
        }
      }
    }
    sort(ALL(rms));
    if(rms.size() >= Q) ans = min(ans, rms[Q - 1] - X);
  }

  cout << ans << endl;


  return 0;
}
