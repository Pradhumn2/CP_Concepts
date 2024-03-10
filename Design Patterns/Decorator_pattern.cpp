
/************************ DECORATOR PATTERN ****************************

-> Used to avoid class explosion
-> CLASS EXPLOSION : creation of multiple classes for performing particular task.
-> eg: Pizza base class and adding toppings in it for diff pizza's.


*/
#include <bits/stdc++.h>
using namespace std;

class BasePizza{
public:
    virtual int cost() = 0;
};

class Margherita : public BasePizza{
public:
    int cost(){
      return 120;
    }
};

class Farmhouse : public BasePizza{
public:
    int cost(){
      return 100;
    }
};

class toppingDecorator : public BasePizza {};

class extraCheese : public toppingDecorator {
  BasePizza *basepizza;
public:
  extraCheese(BasePizza* pizza){
    this->basepizza = pizza;
  }

  int cost(){
    return basepizza->cost() + 50;
  }
};

class extracorn : public toppingDecorator {
  BasePizza *basepizza;
public:
  extracorn(BasePizza* pizza){
    this->basepizza = pizza;
  }

  int cost(){
    return basepizza->cost() + 30;
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
  // BasePizza *new_pizza = new extraCheese(new Margherita());
  // cout<<"Cost of extra cheese matgerita pizza is "new_pizza->cost()<<endl;

  BasePizza *new_pizza = new extracorn(new extraCheese(new Farmhouse()));
  cout<<"Cost of extra corn & cheese farmhouse pizza is "<<new_pizza->cost()<<endl;
  return 0;
}