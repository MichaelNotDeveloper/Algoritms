struct Hash{
    ll n, mod, k;
    vector<ll> p = {1}, h = {0};
    void init(string str, ll _mod, ll _k){n = str.size();k = _k;mod = _mod;
        for(auto u : str){
            p.push_back(p.back()*k%mod);
            h.push_back((h.back()*k%mod + (u-'a'))%mod);
        }
    }
    ll hashof(ll l, ll r){
        return (mod + h[r+1] - h[l]*p[r-l+1]%mod)%mod;
    }
};
