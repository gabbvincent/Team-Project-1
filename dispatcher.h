// dispatcher
//
// Madelynn Kim
// 10/17/2020
#pragma once

#include "box.h"
#include "truck.h"

#include <sstream>
#include <string>
using std::ostringstream;
using std::string;
//using namespace std;

class Dispatcher {
public:
  // Default constructor.
  //
  // deliveries=0
  // box=Box(5, 150)
  // truck=Truck(10, 1000)
  Dispatcher();

  // Handles an order. Most complex algorithm in this program.
  //
  // Try to add the weight to the Box:
  //   If the weight cannot be added to the Box:
  //      Try to add a Box to the Truck:
  //        If a Box cannot be added to the Truck:
  //          Send the truck out for a delivery
  //          Increment deliveries
  //          Load a Box onto the now empty Truck
  //          Add the incoming weight to the now empty Box
  //        Else -- empty the Box and add the incoming weight
  void placeOrder(unsigned int weight);

  // Returns a string representation of the state of the Dispatcher.
  //
  // EX: Dispatched a total of DELIVERIES deliveries
  //     box.toString()
  //     truck.toString()
  //
  //     Dispatched a total of 1 deliveries
  //     Box -> 1/5 items, 100/150 weight
  //     Truck -> 1/10 boxes, 100/1000 weight
  string toString();

private:
  unsigned int deliveries;
  Box box;
  Truck truck;
};