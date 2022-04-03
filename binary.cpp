ll tr[SIZE];

void add(ll ind, ll x, ll l, ll r, ll k){
    if(r < ind or l > ind)return;
    if(l == r){tr[k] += x;return;}
    ll mid = (l+r)/2;
    add(ind, x, l, mid, k*2);
    add(ind, x, mid+1, r, k*2+1);
    tr[k] = tr[k*2] + tr[k*2+1];
}

ll sum(ll a, ll b, ll l, ll r, ll k){
    if(b < l or r < a)return 0;
    if(a <= l and r <= b)return tr[k];
    ll mid = (l+r)/2;
    return sum(a, b, l, mid, k*2) + sum(a, b, mid+1, r, k*2+1);
}

