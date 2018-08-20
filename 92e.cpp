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

const int MAX_N = 1000;
int N;
int a[MAX_N];


int main(){
  cin >> N;
  ll odd = 0, even = 0;
  int oddmax = -INFi, evenmax = -INFi;
  int oddmaxi, evenmaxi;

  REP(i, N) {
    cin >> a[i];
    if(a[i] > 0) {
      if (i % 2 == 0) even += a[i];
      else odd += a[i];
    } else {
      if(i % 2 == 0) {
        if(evenmax < a[i]) {
          evenmaxi = i;
          evenmax = a[i];
        }
      } else {
        if(oddmax < a[i]) {
          oddmaxi = i;
          oddmax = a[i];
        }
      }
    }
  }


  if(even == 0 && odd == 0) {
    if(oddmax > evenmax) {
      cout << oddmax << endl;
      cout << N - 1 << endl;
      for(int i = N; i > oddmaxi + 1; i--) {
        cout << i << endl;
      }
      REP(i, oddmaxi) {
        cout << 1 << endl;
      }
    } else {
      cout << evenmax << endl;
      cout << N - 1 << endl;
      for(int i = N; i > evenmaxi + 1; i--) {
        cout << i << endl;
      }
      REP(i, evenmaxi) {
        cout << 1 << endl;
      }
    }
  } else {
    int crt;
    int ct = 0;
    // count

    if(odd > even) {

      ct ++;
      crt = 1;
    } else {

      crt = 0;
    }
    while(a[crt] <= 0) {
      ct += 2;
      crt += 2;
    }
    crt += 2;
    while(crt < N) {
      if(a[crt] < 0){
        ct ++;
        if(crt == N - 1 || crt == N - 2) ct++;
      } else {
        ct ++;
        if(crt == N - 2) ct ++;
      }
      crt += 2;
    }

    // output

    if(odd > even) {
      cout << odd << endl;
      cout << ct << endl;
      cout << 1 << endl;  // +1
      crt = 1;
    } else {
      cout << even << endl;
      cout << ct << endl;
      crt = 0;
    }
    while(a[crt] <= 0) {
      cout << 1 << endl << 1 << endl;
      crt += 2;
    }
    crt += 2;
    while(crt < N) {
      if(a[crt] < 0){
        cout << 3 << endl;
        if(crt == N - 1 || crt == N - 2) cout << 2 << endl;
      } else {
        cout << 2 << endl;
        if(crt == N - 2) cout << 2 << endl;
      }
      crt += 2;
    }

  }


  return 0;
}
