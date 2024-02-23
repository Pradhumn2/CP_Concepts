#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define inf LLONG_MAX
#define endl '\n'
#define mod 1000000007
#define all(x) (x).begin(), (x).end()

struct Node{
    Node* links[26];
    bool flag;
    
    bool present(char ch, Node* root){
        return root->links[ch - 'a'] != NULL;
    }
    
    bool isEnd(){
        return flag;
    }
    
    void setEnd(){
        flag = true;
    }
};

class Trie {
    Node* root;
public:
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        
        for(int i = 0;i < word.size(); i++){
            if(!(node->present(word[i], node))){
                node->links[word[i] - 'a'] = new Node();
            }
            node = node->links[word[i] - 'a'];
        }
        
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0;i < word.size(); i++){
            if((!node->present(word[i], node))) return false;
            node = node->links[word[i] - 'a'];
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        Node* node = root;
        for(int i = 0;i < word.size(); i++){
            if((!node->present(word[i], node))) return false;
            node = node->links[word[i] - 'a'];
        }
        
        return true;
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