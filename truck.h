// Truck
//
// Aaron Del Monte
// 10/9/20
#pragma once

#include <sstream>
#include <string>
using std::ostringstream;
using std::string;

class Truck {
public:
  // Default constructor
  //
  // maxBoxes, maxWeight set to reasonable defaults
  // numBoxes=0, currentWeight=0
  Truck();

  // Overloaded constructor
  //
  // this->maxBoxes=maxBoxes, this->maxWeight=maxWeight
  // numBoxes=0, currentWeight=0
  Truck(unsigned int maxBoxes, unsigned int maxWeight);

  // Adds weight to the Truck and increases the number of boxes
  //
  // If this->currentWeight + weight > this->maxWeight, returns false
  // Else if this->currentWeight + weight <= this->maxWeight:
  //   adds weight to this->currentWeight
  //   increments this->numBoxes
  //   returns true
  bool loadBox(unsigned int weight);

  // Resets the current weight and number of boxes in this Truck to 0
  void deliver();

  // Returns a string representation of this Truck
  //
  // EX: Truck -> NUM_BOXES/MAX_BOXES items, CURRENT_WEIGHT/MAX_WEIGHT weight
  //     Box -> 1/10 boxes, 750/1000 weight
  string toString();

private:
  unsigned int maxBoxes;
  unsigned int numBoxes;
  unsigned int maxWeight;
  unsigned int currentWeight;
};