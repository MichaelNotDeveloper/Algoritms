ll d[SIZE], h[SIZE];
vector<ll> g[SIZE];

// bridges
void dfs(ll ind, ll p = -1){
    d[ind] = h[ind] = (p==-1)?1:d[p]+1;
    for(auto u : g[ind])if(u != p){
        if(d[u])h[ind] = min(h[ind], d[u]);
        else{
            dfs(u, ind);
            h[ind] = min(h[ind], h[u]);
            if(h[u] > d[ind]){
                // (ind -> u) is a bridge
            }
        }
    }
}

// dots

void dfs(ll ind, ll p = -1){
    d[ind] = h[ind] = (p==-1)?1:d[p]+1;
    // counter of ind's kids
    ll cnt = 0;
    for(auto u : g[ind])if(u != p){
        if(d[u])h[ind] = min(h[ind], d[u]);
        else{
            dfs(u, ind);
            h[ind] = min(h[ind], h[u]);
            if(h[u] >= d[ind] and p+1){
                // (ind) is a dot
            }
            cnt++;
        }
    }
    if(p == -1 and cnt > 1)
        //(ind) is a dot
}

