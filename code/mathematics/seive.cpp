    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define pb push_back
    const ll MAX =1e9+1;
    

    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        ll t;
        cin>>t;
        ll n=MAX;
       
        while(t--){
            ll a,b;
            cin>>a>>b;
            
             vector<char> is_prime(b+1, true);
            is_prime[0] = is_prime[1] = false;
            for (int i = 2; i * i <= b; i++) {
                if (is_prime[i]) {
                    for (int j = i * i; j <= b; j += i)
                        is_prime[j] = false;
                }
            }
            
            for(ll i=a;i<=b;i++){
                if(is_prime[i])
                    cout<<i<<"\n";
            }
            cout<<"\n";


        }
        
       

    
    return 0;
    }