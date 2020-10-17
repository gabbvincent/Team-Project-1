// User Interface
//
// Roberto Viramontes
// 10/06/2020

#pragma once

// Recommend you use CinReader to handle user input.
#include "cinreader.hpp"

#include "dispatcher.h"

#include <iostream>
using std::cout;
using std::endl;

class UserInterface {
public:
  // Runs the main menu loop and dispatches events to appropriate handlers
  //
  // EX: 1. Order an item
  //     2. View system status
  //     0. Exit program
  //
  //     choice=0, break loop and exit program
  //     choice=1, dispatch to orderItem()
  //     choice=2, dispatch to report()
  void run();

private:
  CinReader reader;
  Dispatcher dispatcher;

  // Prompts user for weight of item being ordered, reads in value,
  // then uses dispatcher to place the order of the given weight
  void orderItem();

  // dispatcher.toString()
  void report();

  // Clears the terminal screen. Useful for improving the quality of
  // the program's output.
  void clearScreen();
};