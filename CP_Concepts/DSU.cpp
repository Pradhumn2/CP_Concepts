#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define inf LLONG_MAX
#define endl '\n'
#define mod 1000000007
#define all(x) (x).begin(), (x).end()

vector<int> par(1e5), size(1e5);

void make(int node){
	par[node] = node;
	size[node] = 1;
}

void find(int node){
	if(par[node] == node) return node;
	return par[node] = find(par[node]);
}

//Sourav 

void Union(int a, int b){
	int a = find(a);
	int b = find(b);

	if(a != b){
		if(size[a] > size[b]){
           par[b] = a;
           size[a] += size[b];
		}
		else{
           par[a] = b;
           size[b] += size[a];
		}
	}
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("error.txt", "w", stderr);
  freopen("output.txt", "w", stdout);
#endif
  
  return 0;
}