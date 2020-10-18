#include "truck.h"
// numbers based on uhaul truck
// 1,682 cu. ft. about 560 boxes if 1x1x3 boxes
// Holds up to 13,009 pounds

//default const
Truck::Truck() {
  maxBoxes = 10;
  maxWeight = 1500;
  numBoxes = 0;
  currentWeight = 0;
}

//manual const
Truck::Truck(unsigned int maxBoxes, unsigned int maxWeight) {
  this->maxBoxes=maxBoxes;
  this->maxWeight=maxWeight;
  numBoxes=0;
  currentWeight=0;
}
 // Adds weight to the Truck and increases the number of boxes
  //
  // If this->currentWeight + weight > this->maxWeight, returns false
  // Else if this->currentWeight + weight <= this->maxWeight:
  //   adds weight to this->currentWeight
  //   increments this->numBoxes
  //   returns true
//loading funct
bool Truck::loadBox(unsigned int weight) {
  if (this->currentWeight + weight > this->maxWeight || numBoxes+1 > maxBoxes){
    return false;
  } 
  else if (this-> currentWeight + weight <= this -> maxWeight) {
    this-> currentWeight += weight;
    //this-> numBoxes += 1;
    this-> numBoxes ++;
    return true;
  }
  return 0;
}
//deliver makes weight and boxes 0's
void Truck::deliver() {
  this->currentWeight = 0;
  this->numBoxes = 0;
}


//print out truck info 
string Truck::toString() {
  ostringstream out;

  out << "Truck -> " << numBoxes << "/" << maxBoxes <<" boxes "<< currentWeight <<"/"<< maxWeight<<" pounds\n";

  // EX: Truck -> NUM_BOXES/MAX_BOXES items, CURRENT_WEIGHT/MAX_WEIGHT weight
  //     Box -> 1/10 boxes, 750/1000 weight
  
  return out.str();
} 
