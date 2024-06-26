#include<bits/stdc++.h> 
#include<iostream>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; 
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set1;
typedef tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set2;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_s;
typedef tree<pair<int,int>,null_type,less_equal<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_s2;
typedef long long int ll; 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi      2*acos(0.0) 
#define vll     vector<ll> 
#define pq_      priority_queue 
#define pq_min  <int,vector<int>,greater<int>> 
#define vi      vector<int> 
#define vii     vector<pair<int, int>> 
#define pii     pair<int, int> 
#define sp      ' ' 
#define sz(n)   (int)n.size() 
#define all(n)  n.begin(),n.end() 
#define rall(n) n.rbegin(), n.rend()
#define bye     return 0; 
const double    eps = 1e-9;
const int       MAX = 1e5+7; 
const int 		mod = 1000000007; 
bool isEqual(double a,double b) {return abs(a-b)<eps;}
bool isGreater(double a,double b) {return a>=b+eps;} 
bool isGreaterEqual(double a,double b) {return a>b-eps;}
#define tc int t;cin >> t;while (t--) 
#define mset(n, v) memset(n, v, sizeof(n))
#define ff(i,n) for(int i = 0; i < n; i++)
#define lcm(a, b) (((a) * (b)) / __gcd(a, b))
int dx[8] = {1,-1, 0, 0, 1, -1, -1, 1}; 
int dy[8] = {0, 0, 1,-1, 1, -1, 1, -1};
///pbds header
/*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
*/

#define MOD 1000000007
#define pb push_back
#define LIM 100010
#define left st,(st+en)/2,n+n
#define right (st+en)/2+1,en,n+n+1
#define foreach(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define pii pair<int,int>
#define pi acos(-1.0)
#define all(v) v.begin(),v.end()
#define mp make_pair
#define eps 1e-8
#define ff first
#define ss second
#define mset(a,b) memset(a,b,sizeof(a))
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
#define CASE(a) printf("Case %d: ",a)



///Activate it for pbds set
/// *x.find_by_order(pos) ----> returns the value at "pos" index in the set 0-based
/// x.order_of_key(value)     ----> returns the position of "value" in the set 0-based

///Activate it for pbds trie
/*
typedef trie<
string,
null_type,
trie_string_access_traits<>,
pat_trie_tag,
trie_prefix_search_node_update>
pref_trie; */


//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};
ll fact[LIM],invFact[LIM];

ll phi(ll n);
ll RP(ll a,ll b,ll M);
ll bMwithRP(ll x, ll y, ll mod);
ll gcd(ll a,ll b);
ll bigMOD(ll num,ll n,ll m);
ll modInv(ll num,ll m,bool modPrime);
ll po(ll a,ll b);
ll nCr(ll n,ll r);


ll phi(ll n)
{
    ll res = n;
    for(ll p=2; p*p<=n; p++)
    {
        if(n%p==0)
        {
            while(n%p==0)
                n/=p;
            res-=res/p;
        }
    }
    if(n>1)
        res-=res/n;
    return res;
}

ll RP(ll a,ll b,ll M)
{
    ll r = 0;
    while(b>0)
    {
        if(b&1)
            r=(r+a)%M;
        a = a << 1;
        a = a % M;
        b = b >> 1;
    }
    return r%M;
}

ll bMwithRP(ll a, ll b, ll M)
{
    ll r = 1LL;
    while (b)
    {
        if (b&1)
            r = RP(r, a, M);
        b >>= 1, a = RP(a, a, M);
    }
    return r%M;
}

ll gcd(ll a,ll b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

ll bigMOD(ll a,ll b,ll M)
{
    if(!b)
        return 1LL;

    if(b%2==0)
    {
        ll t = bigMOD(a,b/2,M)%M;
        return (t*t)%M;
    }
    return (a*(bigMOD(a,b-1,M)))%M;
}

ll modInv(ll a,ll b,ll M,bool modPrime)
{
    if(!modPrime)
        return (a*bigMOD(b,phi(M)-1,M))%M;
    return (a*bigMOD(b,M-2,M))%M;
}

ll fast_modInv(ll a,ll m)
{
    int x = 0,y = 1,u = 1,v = 0;
    int e = m,f = a;
    int c,d,q,r;
    while(f != 1)
    {
        q = e/f;
        r = e%f;
        c = x-q*u;
        d = y-q*v;
        x = u;
        y = v;
        u = c;
        v = d;
        e = f;
        f = r;
    }
    u = (u+m)%m;
    return u;
}


void preprocess(int N)
{
    fact[0] = 1;
    for(int x=1 ; x<=N ; x++)
        fact[x] = (fact[x-1]*x)%MOD;
    invFact[N] = modInv(1,fact[N],MOD,1);

    for(int x = N-1; x>=0; x--)
        invFact[x] = (invFact[x+1]*(x+1) )%MOD;
}


// bit manipulations

//bool checkbit(int mask,int bit){return mask & (1<<bit);}

//int setbit(int mask,int bit){ return mask  (1<<bit) ; }

//int clearbit(int mask,int bit){return mask & ~(1<<bit);}

//int togglebit(int mask,int bit){return mask ^ (1<<bit);} 386819


/// CATALAN numbers:
/// 1) Cn = (2n,n)/(n+1)
/// 2) Cn = ((4n-2)*C(n-1))/(n+1)

/// Stirling numbers:
/// 2nd Kind : S(n,k) = k*S(n-1,k) + S(n-1,k-1) ; S(i,0) = S(0,i) = 0 ; S(0,0) = 1

/// MODULAR arithmetic:
/// a^b % m = a^(phi(m) + b%phi(m))%m
/// a^b % m = (a%m)^b % m
#define ll long long
#define pr 26
#define type 'a'
#define NUM_OF_HASH 2
#define MAX (int)1e6

ll Hash[NUM_OF_HASH][MAX+5];
ll power[NUM_OF_HASH][MAX+5];
ll mod[] = {1000000007, 1000000009, 998244353, 1000000037,1000000021,1000000003,1000005133};
int main()
{
    

}
