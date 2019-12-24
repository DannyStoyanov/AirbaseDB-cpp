#pragma once
#include "ICommand.h"
class optimizeCommand :public ICommand{
public:
	optimizeCommand();
	void execute();
	~optimizeCommand();
};

