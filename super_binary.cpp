ll tr[SIZE];
ll lz[SIZE];
bool upd[SIZE];

void push(ll k, ll l, ll r){
    if(!upd[k])return;
    ll mid = (l+r)/2;
    tr[k*2] += lz[k] * (mid-l+1);
    tr[k*2+1] += lz[k] * (r-mid);
    
    lz[k*2] += lz[k];
    lz[k*2+1] += lz[k];
    
    upd[k*2] = 1;
    upd[k*2+1] = 1;
    
    upd[k] = 0;
    lz[k] = 0;
}


void add(ll a, ll b, ll x, ll l, ll r, ll k){
    if(r < a or l > b)return;
    if(a <= l and r <= b){
        tr[k] += x * (r-l+1);
        lz[k] += x;
        upd[k] = 1;
        return;}
    push(k, l, r);
    ll mid = (l+r)/2;
    add(ind, x, l, mid, k*2);
    add(ind, x, mid+1, r, k*2+1);
    tr[k] = tr[k*2] + tr[k*2+1];
}

ll sum(ll a, ll b, ll l, ll r, ll k){
    if(b < l or r < a)return 0;
    if(a <= l and r <= b)return tr[k];
    push(k, l, r);
    ll mid = (l+r)/2;
    return sum(a, b, l, mid, k*2) + sum(a, b, mid+1, r, k*2+1);
}

