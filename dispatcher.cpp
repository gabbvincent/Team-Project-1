#include "dispatcher.h"

Dispatcher::Dispatcher() {

  deliveries = 0;
  box = Box(5, 150);
  truck = Truck(10, 1500);

}

void Dispatcher::placeOrder(unsigned int weight) {
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


if (!box.packItem(weight)) {
   if (!truck.loadBox(box.getCurrentWeight())) {
      truck.deliver();
      deliveries++;
      box.packItem(weight);
} else {
  box.emptyBox();
  box.packItem(weight);
}
}
}


string Dispatcher::toString() {

  ostringstream out;

  out << "Dispatched a total of " << deliveries << " deliveries\n";
  out << box.toString();
  out << truck.toString() << "\n";

  return out.str();
}