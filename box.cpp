#include "box.h"

Box::Box() {

  maxItems = 5;
  maxWeight = 150;
  numItems = 0;
  currentWeight = 0;

}

Box::Box(unsigned int maxItems, unsigned int maxWeight) {

  this-> maxItems = maxItems;
  this-> maxWeight = maxWeight;
  numItems = 0;
  currentWeight = 0;

}

unsigned int Box::getCurrentWeight() {

  return currentWeight;

}

// Adds weight to the Box and increases the number of items
  //
  // If this->currentWeight + weight > this->maxWeight, returns false
  // Else if this->currentWeight + weight <= this->maxWeight:
  //   adds weight to this->currentWeight
  //   increments this->numItems
  //   returns true
bool Box::packItem(unsigned int weight) {

  if (this-> currentWeight + weight > this-> maxWeight) {
    return false;
  } else if (this-> currentWeight + weight <= this-> maxWeight) {
    this-> currentWeight = this-> currentWeight + weight;
    this-> numItems++;
    
    return true;
  }
  return 0;
}


// Resets the current weight and number of items in this Box to 0
void Box::emptyBox() {

  this-> currentWeight = 0;
  this-> numItems = 0;

}

string Box::toString() {

  ostringstream out;

  out << "Box -> " << numItems << "/" << maxItems << " items, " << currentWeight << "/" << maxWeight << " weight\n";

  return out.str();
  
}