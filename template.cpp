/**       
*    author:  aditya_raj      *use  jj to enter into normal mode
* 
**/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, K, N)                          for (int i = K; i < N; ++i)
#define repd(i,a, b)                          for (int i = (a); i >= b; --i)
#define lower(v, i)                           *lower_bound((v).begin(), (v).end(), i)
#define upper(v, i)                           *upper_bound((v).begin(), (v).end(), i)
#define lower_count(v, i)                     lower_bound((v).begin(), (v).end(), i) - (v).begin()
#define fcout(n)                              cout << fixed << setprecision(n)
using ll                                      = long long;
const ll mod                                  = 1000000007;
#define mset(arr, v)                          memset(arr, v, sizeof(arr))
#define set_allbit(n)                         (1 << (n + 1)) - 1
#define set_bit(i, S)                         (S) |= (1 << (i))
#define unset_bit(i, S)                       (S) &= ~(1 << (i))
#define bitcnt                                __builtin_popcount
#define ceil(a, b)                            (a + (b - 1)) / b
#define floor(a, b)                           a / b
#define toggle(a)                             a ^= 1
#define lcm(a, b)                             a / __gcd(a, b) * b
#define sz(x)                                 (int)(x).size()
#define pb                                    push_back
#define pi                                    pair<int, int>
#define vi                                    vector<int>
#define vpi                                   vector<pi>
#define F                                     first
#define nl                                    endl
#define S                                     second
#define mp                                    make_pair
#define all(a)                                (a).begin(), (a).end()
using vvi =                                   vector<vector<int> >;
const ll infinity =                           1e+18;
const double eps =                            1e-15;
const int dx[4] =                             {1, 0, -1, 0};
const int dy[4] =                             {0, 1, 0, -1};
#define getunique(v)                          {sort(all(v)); v.resize(unique(all(v)) - v.end());}
template <class T, class C>                   void self_max(T &a, C b) { a > b ?: a = b; }
template <class T, class C>                   void self_min(T &a, C b) { a < b ?: a = b; }

template<typename T> istream &operator>>(istream &is, vector<T> &vec)
{ for (auto &v : vec) is >> v; return is; }

template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec)
{ os << "[ "; for (auto v : vec) os << v << ", "; os <<']';  return os; }

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) {
return cout << "(" << p.F << ", " << p.S << ")"; }


template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
cin >> p.first;
return cin >> p.second;
}

template<typename T_vector>
void print_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
if (start < 0) start = 0;
if (end < 0) end = int(v.size());

for (int i = start; i < end; i++)
    cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}



/* Debug Begins */ 
# define trace(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

string to_string(char c) { return "'" + string(1, c) + "'";}
string to_string(string s) { return '"' + s + '"';}
string to_string(bool f) { if(f) return "True"; else return "False";}
string to_string(const char* s) { return to_string((string) s);}

template<typename A> string to_string(A);
template<typename A, typename B> string to_string(pair<A, B> p){
return "(" + to_string(p.first) + ": " + to_string(p.second) + ")";}

template<typename A> string to_string(A v) 
{bool f = false; string r = "{"; 
for (auto x: v) {if (f) r += ", "; r += to_string(x); f = true;} return r += "}";}
template<typename A> string to_string(vector<vector<A>> v) 
{string r;   for (auto x: v) r += "\n" + to_string(x); return r;}

int Nerr;
template<typename A> string to_string(A *p) {return to_string(vector<A>(p, p + Nerr));}
void err(istream_iterator<string>) { cerr << endl; }
template<typename T,typename... Args> void err(istream_iterator<string> it, T a, Args... args) {
cerr << *it << " = " << to_string(a) << "; "; err(++it, args...); }
template<typename T> void kek(T ans) {cout << ans << endl; exit(0);}

#define Lu(...) [&] (auto &&u) { return __VA_ARGS__; }
#define Luv(...) [&] (auto &&u, auto &&v) { return __VA_ARGS__; }
/***************************************************************/








vector<pair<int, int>> compress_with_freq(vi &a){ 
  vector<pi > v;  v.pb({a[0],1});
  rep(i,1,sz(a)) { if(a[i]==a[i-1]) v.back().S++;    else v.pb({a[i],1}); }  return v;}

vector<int> coordinate_compression_using_set(vi &v){
  set<int> se(all(v));   map<int,int> mp;   int id=0;
  for(auto &x :se) mp[x] =id++;     rep(i ,0 ,sz(v)) v[i] = mp[v[i]];   return v;}

vector<int> coordinate_compression_1_based(vi &v){
    vi z= v;  sort(all(z));
    z.resize(unique(all(z)) -z.begin());
    rep(i ,0 ,sz(v)) v[i] = 1 + lower_bound(all(z), v[i])- z.begin(); return v;}

auto rotate = [](string S[]) -> void{
int N = 10;
for(int i = 0; i < N; i++)
    for(int j = i + 1; j < N; j++)
            swap(S[i][j], S[j][i]);

for(int i = 0; i < N; i++)
    for(int j = 0; j < N / 2; j++)
        swap(S[i][j], S[i][N - j -1]); 
};   


    void MxH_pyramid(int test){
// consider yes/no qs => are we good enough to reach to next no with the diminishing value of N

  int N; cin >> N;
  int next = 1;
  while(N >= next){
      N -= next;
      next += 1;
  }
  cout << next - 1 << '\n';
}

auto rotate_right = [](int l, int r) {
  vi a(10);
    for(int i = r - 1; i >= l; i--)swap(a[i], a[i + 1]);
    //cyclic shift to right by an offset 1  = to left by an offset (r - l)
};

auto rotate_left = [](int l, int r) {
  vi a(10);
    for(int i = l; i < r; i++)swap(a[i], a[i + 1]);
    //cyclic shift to left by an offset 1
};




// ll no_of_factors[1000005];
//  for(int i = 1;i <= n; i++){
//         for(int j = i; j <= n; j += i)no_of_factors[j]++;   //array stores no of factors of no int i.
//     }
//   vector<vector<ll>> dp(A , vector<ll>(B));


ll calc_xor_upto_N(ll N){
// XOR value of nos in range [1, N] repeats in cycle of 4 => it's enough to calculate in [N/4 * 4, N]
ll res = 0;
for( ll i = N / 4 * 4; i <= N; i++){ res ^= i;}return res;}




ll binexp1(ll a, ll b, ll md = mod){
ll res = 1;  while(b){ if(b & 1) {res = (a * res) % md;} 
    a=(a * a) % md; b >>= 1;}       return res;}

ll multiply(ll a, ll b, ll m= mod){
ll res = 0;  while(b>0){ if(b & 1){ res = res + a;  res %= m;}
     a <<= 1;  a %= m;  b >>= 1;} return res;}

ll binexp2(ll a, ll b, ll m= mod){
ll res = 1;while(b>0){ if(b & 1){ res = multiply(res, a, m);}
    a = multiply(a, a, m);  b >>= 1;}  return res;}



int setBits(int N) {          //__builtin_popcount(N)
    if(N == 0)return 0;
    int ans = 0;    if(N)ans++;
    return ans + setBits(N & (N - 1));   // N & (N - 1) gives removed last set bit of N, N - (N & -N) can also be used
}



struct point
{
      ll x, y;
      void read(){
           cin >> x >> y;}
      
      point operator -(point &b){
           return {x - b.x, y - b.y};}
      

      void operator -= (const point &b){
          x -= b.x;
          y -= b.y;
      }
      ll operator *(const point& b){
          return x * b.y - y * b.x;}
     

      ll cross_product(const point &b) const{
         return x * b.y - y * b.x;
      }
};



struct String{
    string T;

    vector<int> get_freq()
    {
        vector<int> ct(26);
        for(auto ch : T)
            ct[ch - 'a']++; 
        return ct;
    }
};

namespace number_theory {
ll gcd(ll x, ll y) {
 if (x == 0) return y;
 if (y == 0) return x;
 return gcd(y, x % y);
}
bool isprime(ll n) { 
 if (n <= 1) return false; 
 if (n <= 3) return true; 
 if (n % 2 == 0 || n % 3 == 0) return false; 
 
 for (ll i = 5; i * i <= n; i += 6) 
  if (n % i == 0 || n % (i+2) == 0) 
    return false; 
 
 return true; 
} 

bool prime[15000105]; 
void sieve(int n) 
{ 
 for (ll i = 0; i <= n; i++) {if(i and i != 1)prime[i] = 1;}
 for (ll p = 2; p * p <= n; p++) { 
  if (prime[p]) { 
    for (ll i = p * p; i <= n; i += p)//sum of all N / p, no of primes = N / lnN and kth prime = k * lnk
     prime[i] = false; 
  } 
 } 
} 

vector<ll> primelist;
bool __primes_generated__ = 0;

void genprimes(int n) {
 __primes_generated__ = 1;
 sieve(n + 1);
 for (ll i = 2; i <= n; i++) if (prime[i]) primelist.push_back(i);
}

vector<ll> factors(ll n) {
 if (!__primes_generated__) {
  cerr << "Call genprimes " << endl;
  exit(1);
 }
 vector<ll> facs;

 for (ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
  if (n % primelist[i] == 0) {
    while (n % primelist[i] == 0) {
     n /= primelist[i];
     facs.push_back(primelist[i]);
    }
  }
 }
 if (n > 1) {
  facs.push_back(n);
 }
 sort(facs.begin(), facs.end());
 return facs;
}

vector<ll> get_divs(ll n) {
vector<ll> divs;
for (ll i = 1; i * i <= n; i++) {
  if (n % i == 0) {
    divs.push_back(i);
    if(i != n / i)divs.push_back(n / i);
  }
}
return divs;
}

// N = p1^a1 * p2^a2 * p3^a3 * ... * pn^an  has (a1 + 1)*(a2 + 1)*...*(an + 1) divisors
int no_of_div(int N = 100){
        ll ans = 1;   
        for (ll p = 2; p * p <= N; p++) {
        ll e = 0;
        while (N % p == 0) {
            N /= p;
            e++;
          }
          ans *= e+1;
        }
        if (N > 1) {
          ans *= 2;
        }
        return ans;
}

const int MAXN = 1e5+10; int spf[MAXN];
void sieve1()//sieve
{
spf[1] = 1;
for (int i = 2; i < MAXN; i++)
    spf[i] = i;
for (int i = 4; i < MAXN; i += 2)
    spf[i] = 2; 
for (int i = 3; i * i < MAXN; i++)
{ 
    if (spf[i] == i)
    {
        for (int j = i * i; j < MAXN; j += i)
            if (spf[j] == j)
                spf[j] = i;
    }
}
}//sieve ends
map<int,int> getfactor(int a)//factor prime
{
  sieve1();
  map<int,int> m;
    while(a > 1)
    {
        m[spf[a]]++;
        a /= spf[a];
    }
    return m;
    }

    int inverse(ll a, ll p ){
    return binexp1(a, p-2, p);}

    ll nCr(ll n, ll r, ll p = mod){
    if (n < r) return 0;
    if (r == 0) return 1;


    ll fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * inverse(fac[r], p) % p * inverse(fac[n - r], p) % p) % p;
    }
}
using namespace number_theory;



vector<int> computeLPS (string T){
      int N = sz(T);
      vector<int> lps(N);
      int i = 1, j = 0;
      while(i < N)
      {
      if(T[i] == T[j]){
        lps[i] = j + 1;
        i++;  j++;
      }
      else{
        if(j > 0){
          j = lps[j - 1];
        }
        else{
          lps[i] = 0;
          i++;
        }
      }
  }
  return lps;
}

// N - 1 flips all bits after and including rightmost set bit;  (n & (n-1)), unsets the rightmost set bit.
template <typename T>
struct binary_indexed_tree{
      int N;
      vector<T> BIT;                    //BIT[i] =  stores sum of range [j + 1, i], j = removed last set bit of i  =  i - i & -i (last set bit of i) 
      binary_indexed_tree(int n){
              N = 1;
              while(N < n){
                  N *= 2;
              }
              BIT = vector<T> (N + 1, 0);
      }
      void add(int i, T x){             // to add x at ind i we need to add x to all those ind whose last set bit removed has ind i in range
              i++;
              while(i <= N){
                  BIT[i] += x;
                  i += i & -i;
              }
      }

      T sum(int i){                   // gives sum of array in range [0, i - 1]  if i = 1101, we need BIT[13] {13, 13} + BIT[12] {9, 12} + BIT[8] {1, 8}
              T ans = 0;              // BIT[5] = a[0] + a[1] + ... + a[4]   generally  BIT[N] = a[0] + a[1] + ... + a[N - 1]
              while(i > 0){
                  ans += BIT[i];
                  i -= i & -i;
              }
              return ans;
      }

      T query(int L, int R){
              return sum(R) - sum(L);
      }
      T get_id_val(int i){
              return BIT[i];
      }
        /*    // to count no of inv we take every element of array as index of bit
        vi a = {4, 5, 1, 2, 3};
        binary_indexed_tree<ll> BIT(10); // size greater than max element in the array , if size exceeds 1e5, do coordinate compression.
          int count_inv = 0;
       
        for(int i = 0; i < 5; i++){
              count_inv += BIT.sum(9) - BIT.sum(a[i]);
              BIT.add(a[i], 1);
        }
        //count_inv => 6
        
          vi a = {4, 5, 1, 2, 3};
         binary_indexed_tree<ll> bit(6);
         for(int i = 0; i < 5; i++){
           bit.add(i, a[i]);
         }
         rep(i, 0, 6)
         cout << bit.query(0, i) << ' ';    // 0 4 9 10 12 15
         */
};

void Kahns_Algo(){
  int m, n;                   // n = no of nodes , m = no of edges
  cin >> m >> n;
  vector<vector<int>> G(n);

  vector<int> in_degree(n);
  for(int i = 0; i < m; i++)
  {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      in_degree[y] += 1;
  }
vector<int> ans;  // returns one of the possible topo sort solution for the given DAG
queue<int> q;
  rep(i, 0, n)
  if(in_degree[i] == 0)q.push(i);

int count = 0;
    while(!q.empty())
    {
          int v = q.front();
          q.pop();
          count++;
          ans.push_back(v);

          for(auto &vv : G[v]){
          in_degree[vv] -= 1;
          if(in_degree[vv] == 0)q.push(vv);
    }
}
//count should be equal to n
}





signed main()
{
ios::sync_with_stdio(false); cin.tie(nullptr);




}
