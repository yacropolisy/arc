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

const int MAX_Q = 100000;
int Q;
ll A[MAX_Q], B[MAX_Q];

int main(){
  cin >> Q;
  REP(i, Q) cin >> A[i] >> B[i];
  REP(i, Q) {
    ll a = A[i], b = B[i];
    if (a > b) swap(a, b);
    if(a == b || a == b - 1) {
      cout << (a - 1) * 2 << endl;
    } else {
      ll c = ll(sqrt(a * b));
      if (c * (c + 1) < a * b) {
        cout << c * 2 - 1 << endl;
      } else if(c * c < a * b) {
        cout << (c - 1) * 2 << endl;
      } else {
        cout << (c - 1) * 2 - 1 << endl;
      }
    }
  }

  return 0;
}
