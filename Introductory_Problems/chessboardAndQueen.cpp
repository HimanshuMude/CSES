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

    bool isSafe(ll row,ll col,vector<string>&board)
    {
        if(board[row][col]=='*') return false;
        //check row
        for(int i=col;i>=0;i--)
        {
            if(board[row][i]=='Q') return false;
        }

        //check col

        for(int i=row;i>=0;i--)
        {
            if(board[i][col]=='Q') return false;
        }
        ll trow=row,tcol=col;

        while(row>=0 and col>=0)
        {
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        row=trow;
        col=tcol;
        while(row<8 and col>=0)
        {
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }

        return true;
    }

    ll nqueen(vector<string>&board,ll row,ll col)
    {
        if(col==8)
        {
            return 1;
        }
        ll ans=0;
        for(int r=0;r<8;r++)
        {
            char before=board[r][col];
            if(isSafe(r,col,board)){

                board[r][col]='Q';
                ans+=nqueen(board,r,col+1);
                board[r][col]=before;
            } 
        }
        return ans;
    }
    
    
    void solve(){
        vector<string>board(8);
        for(auto &i:board) cin>>i;
        cout<<nqueen(board,0,0)<<"\n";
    }




    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
        freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
        #endif
        fastio;
        long long int t=1;
        // cin>>t;
        while(t--)
        {
            solve();
        }
        return 0;
    }
