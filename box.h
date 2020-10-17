// BOX
//
// Vincent Gabb
// 10/05/2020
#pragma once

#include <sstream>
#include <string>
using std::ostringstream;
using std::string;

class Box {
public:
  // Default constructor
  //
  // maxItems, maxWeight set to reasonable defaults
  // numItems=0, currentWeight=0
  Box();

  // Overloaded constructor
  //
  // this->maxItems=maxItems, this->maxWeight=maxWeight
  // numItems=0, currentWeight=0
  Box(unsigned int maxItems, unsigned int maxWeight);

  // Returns the current weight of the Box
  unsigned int getCurrentWeight();

  // Adds weight to the Box and increases the number of items
  //
  // If this->currentWeight + weight > this->maxWeight, returns false
  // Else if this->currentWeight + weight <= this->maxWeight:
  //   adds weight to this->currentWeight
  //   increments this->numItems
  //   returns true
  bool packItem(unsigned int weight);

  // Resets the current weight and number of items in this Box to 0
  void emptyBox();

  // Returns a string representation of this Box
  //
  // EX: Box -> NUM_ITEMS/MAX_ITEMS items, CURRENT_WEIGHT/MAX_WEIGHT weight
  //     Box -> 1/5 items, 50/100 weight
  string toString();

private:
  unsigned int maxItems;
  unsigned int numItems;
  unsigned int maxWeight;
  unsigned int currentWeight;
};