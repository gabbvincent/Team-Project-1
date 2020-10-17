#include "user_interface.h"

  // Runs the main menu loop and dispatches events to appropriate handlers
  //
  // EX: 1. Order an item
  //     2. View system status
  //     0. Exit program
  //
  //     choice=0, break loop and exit program
  //     choice=1, dispatch to orderItem()
  //     choice=2, dispatch to report()

void UserInterface::run() {
  clearScreen();
  bool active{ true };

    while(active) {
        //Menu with the actions
        cout << "Main menu, select one of the following options!\n";
        cout << "1. Order an item.\n";
        cout << "2. View system status \n";
        cout << "0. Exit program \n" << endl;

        //Construct of the user choice from our menu
        unsigned int menuChoice = reader.readInt(0, 2);//Range betweeen 0 and 3

          switch (menuChoice) {
            case 0: 
            active = false;//Breaks the while loop
              break;
            case 1: 
            orderItem();
            clearScreen();
              break;
            case 2:
            report();
              break;
          }
    }
}

// Prompts user for weight of item being ordered, reads in value,
// then uses dispatcher to place the order of the given weight
void UserInterface::orderItem() {
  clearScreen();//Cleans terminal for the orderItem

  cout << " ------------------- " << endl;
  cout << "| Order information |\n";
  cout << " ------------------- " << endl;

  //Ask user about the weight from the order
  cout << endl;
  cout << "What is the weight of the product: ";
  //Using cinReader to read the input from user (wiht a range from 1 to 100)
  //The range has grabed from the Box information ---> MAYBE: Change range by using the value from there instance
  int itemWeight = reader.readInt(1, 150);
  
  dispatcher.placeOrder(itemWeight);//Calling dispatch placeOrder function to continue....
}

// dispatcher.toString()
void UserInterface::report() {
  //Pulls the report from the item placed from our previous function
  clearScreen(); //Cleans terminal for the menu *removed for testing
  cout << dispatcher.toString();
}
// Clears the terminal screen. Useful for improving the quality of
// the program's output.
void UserInterface::clearScreen() {
  cout << "\033[2J\033[1;1H";
}