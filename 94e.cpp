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
int N;
int A[MAX_N], B[MAX_N];

int main(){
  cin >> N;
  int mi = INFi;
  ll su = 0;

  REP(i, N) {
    cin >> A[i] >> B[i];
    if(A[i] > B[i]) mi = min(B[i], mi);
    su = su + A[i];
  }
  if (mi == INFi) cout << 0 << endl;
  else cout << su - mi << endl;


  return 0;
}
