#pragma once
#include "ICommand.h"
class updateCommand :public ICommand{
public:
	updateCommand();
	void execute();
	~updateCommand();
};

