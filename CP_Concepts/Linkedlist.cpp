#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define inf LLONG_MAX
#define endl '\n'
#define mod 1000000007
#define all(x) (x).begin(), (x).end()

class Node{
    public:
        int data;
        Node* next;
        Node(){
            data = 0;
            next = NULL;
        }
        Node(int data){
            this->data = 0;
            this->next = NULL;
        }
};

class ListNode{
    Node *head;
public:
    ListNode(){
        head = NULL;
    }
};

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