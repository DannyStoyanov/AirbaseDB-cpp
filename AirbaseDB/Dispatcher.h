#pragma once
#include "createCommand.h"
#include "deleteCommand.h"
#include "updateCommand.h"
#include "showCommand.h"
#include "optimizeCommand.h"
#include "searchCommand.h"
#include "exitCommand.h"

class Dispatcher {
private:
	createCommand create_command;
	deleteCommand delete_command;
	updateCommand update_command;
	showCommand show_command;
	optimizeCommand optimize_command;
	searchCommand search_command;
	exitCommand exit_command;
public:
	Dispatcher();
	Dispatcher(createCommand, deleteCommand, updateCommand, showCommand, optimizeCommand, searchCommand, exitCommand);
	void createAttribute();
	void deleteAttribute();
	void updateAttribute();
	void showAttribute();
	void opitmizeAttribute();
	void exitProgram();
};

