#pragma once
#include "ICommand.h"
class showCommand :public ICommand{
public:
	showCommand();
	void execute();
	~showCommand();
};

