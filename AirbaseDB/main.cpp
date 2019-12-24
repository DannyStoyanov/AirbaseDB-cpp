#include<iostream>
#include "ICommand.h"
#include "createCommand.h"
#include "deleteCommand.h"
#include "updateCommand.h"
#include "showCommand.h"
#include "optimizeCommand.h"
#include "searchCommand.h"
#include "exitCommand.h"
#include "Dispatcher.h"
#include "AirbaseSystem.h"
int main() {
	AirbaseSystem airbase;
	airbase.run();
	return 0;
}