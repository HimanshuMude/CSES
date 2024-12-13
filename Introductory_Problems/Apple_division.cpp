   /*
           Author: Himanshu M. Mude

           Date: 
   */


    #include<bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #include <ext/pb_ds/detail/standard_policies.hpp>
    #include <functional>
    using namespace std;
    using namespace __gnu_pbds;
    #define ll long long
    #define gcj "Case #"    
    #define pb push_back
    #define all(_obj) _obj.begin(), _obj.end()
    #define F first
    #define S second
    #define pll pair<ll, ll>
    #define vll vector<ll>
    #define yes cout<<"YES\n"
    #define no cout<<"NO\n"
    ll INF = 1e18;
    const int mod = 1e9 + 7;
    #define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    /*------------------Macros end here------------------*/

    /*-----------------Debugger------------------*/
    void __print(int x) {cerr << x;}
    void __print(long x) {cerr << x;}
    void __print(long long x) {cerr << x;}
    void __print(unsigned x) {cerr << x;}
    void __print(unsigned long x) {cerr << x;}
    void __print(unsigned long long x) {cerr << x;}
    void __print(float x) {cerr << x;}
    void __print(double x) {cerr << x;}
    void __print(long double x) {cerr << x;}
    void __print(char x) {cerr << '\'' << x << '\'';}
    void __print(const char *x) {cerr << '\"' << x << '\"';}
    void __print(const string &x) {cerr << '\"' << x << '\"';}
    void __print(bool x) {cerr << (x ? "true" : "false");}

    template <class T> using multi_ordered_set = tree<T, null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

    template <class T> using ordered_set = tree<T, null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

    template<typename T, typename V>
    void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
    template<typename T>
    void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
    void _print() {cerr << "]\n";}
    template <typename T, typename... V>
    void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
    #ifndef ONLINE_JUDGE
    #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    #else
    #define debug(x...)
    #endif
    /*----------------------Debugger ends here-------------------*/

    /*----------------------Imp Functions-----------------------*/

    const ll N = 1050;
    ll f_[N], _f[N];
     
    ll pow(ll a, ll b, ll m)
    {
        ll ans = 1;
        while (b)
        {
            if (b & 1)
                ans = (ans * a) % m;
            b /= 2;
            a = (a * a) % m;
        }
        return ans;
    }
     
    ll modinv(ll k)
    {
        return pow(k, mod - 2, mod);
    }
     
    void _fp()
    {
        f_[0] = f_[1] = 1;
        for (int i = 2; i < N; i++)
        {
            f_[i] = f_[i - 1] * i;
            f_[i] %= mod;
        }
        _f[N - 1] = modinv(f_[N - 1]);
        for (int i = N - 2; i >= 0; i--)
        {
            _f[i] = _f[i + 1] * (i + 1);
            _f[i] %= mod;
        }
    }
     
    ll _nr_(ll x, ll y)
    {
        if (y > x)
            return 0ll;
        ll _n = f_[x];
        _n *= _f[y];
        _n %= mod;
        _n *= _f[x - y];
        _n %= mod;
        return _n;
    }
     
    ll gcd(ll a, ll b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
     
    ll fastpower(ll a, ll b)
    {
        ll res = 1;
        while (b > 0)
        {
            if (b & 1 == 1)
                res *= a;
            a *= a;
            b = b >> 1;
        }
        return res;
    }
     
    ll SieveOfEratosthenes(int n)
    {
        ll cnt = 0;
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
     
        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        for (int p = 2; p <= n; p++)
            if (prime[p])
                cnt++;
        return cnt;
    }

    template <typename T>
    vector<T> inputvec(size_t size) {
        vector<T> vec(size);
        for (size_t i = 0; i < size; ++i) {
            cin >> vec[i];
        }
        return vec;
    }
     
    ll binpowmod(ll a, ll b)
    {
        ll ans = 1;
        while (b > 0)
        {
            if ((b & 1) == 1)
            {
                ans *= a;
                ans %= mod;
            }
            a *= a;
            a %= mod;
            b = b >> 1;
        }
        return ans;
    }

    /*----------------------Imp Functions ends-------------------*/



    /*------------------- Code Starts Here --------------------*/

    ll dif(ll i,vll &v,ll n,ll lsum,ll rsum)
    {
        if(i==0)
        {
            return min(abs(lsum-rsum-v[0]),abs(lsum+v[0]-rsum));
        }

        ll num=v[i];
        ll d1=dif(i-1,v,n,lsum+num,rsum);
        ll d2=dif(i-1,v,n,lsum,rsum+num);
        return min(d1,d2);
    }
    
    void solve(){
        ll n;
        cin>>n;
        vll v=inputvec<ll>(n);
        cout<<dif(n-1,v,n,0,0)<<"\n";
    }




    int main()
    {
        // #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
        // freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
        // #endif
        fastio;
        long long int t=1;
        // cin>>t;
        while(t--)
        {
            solve();
        }
        return 0;
    }
