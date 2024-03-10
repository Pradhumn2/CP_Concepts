
/********************* Factory Pattern *******************
-> Library should be responsible to decide 
   which obj type to create based on input.

-> Client just call library's factory and pass type without worrying 
   about implementation of creation of object.
 */

#include <bits/stdc++.h>
using namespace std;

class Vehicle{
public:
  virtual void createVehicle() = 0;
};

class Car : public Vehicle {
public:
  void createVehicle(){
    cout<<"Vehicle of Car type is created."<<endl;
  }
};

class Bike : public Vehicle {
public:
  void createVehicle(){
    cout<<"Vehicle of Bike type is created."<<endl;
  }
};

class Factory {
public:
  static Vehicle* new_vehicle(string vehicleType){
      Vehicle *vehicle;

      if(vehicleType == "Car"){
        vehicle = new Car();
      }
      else if(vehicleType == "Bike"){
        vehicle = new Bike();
      }

      return vehicle;
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
  string vehicle;
  cin>>vehicle;

  Vehicle *new_vehicle = Factory::new_vehicle(vehicle);
  new_vehicle->createVehicle();

  return 0;
}