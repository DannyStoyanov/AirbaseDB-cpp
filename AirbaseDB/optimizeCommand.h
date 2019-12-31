#pragma once
#include "ICommand.h"
extern bool isOptimizeOn;
class optimizeCommand :public ICommand {
public:
	optimizeCommand();
	void execute();
	~optimizeCommand();
};

