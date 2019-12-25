#include<iostream>
//#include "ICommand.h" // abstract class for commands
//#include "createCommand.h"
//#include "deleteCommand.h"
//#include "updateCommand.h"
//#include "showCommand.h"
//#include "optimizeCommand.h"
//#include "searchCommand.h"
//#include "exitCommand.h"
//#include "Dispatcher.h" // Invoker
#include "AirbaseSystem.h" // Invoker wrapper

int main() {
	AirbaseSystem airbase;
	airbase.run();
	return 0;
}