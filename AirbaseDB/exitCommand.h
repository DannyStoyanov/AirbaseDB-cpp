#pragma once
#include "ICommand.h"
class exitCommand:public ICommand{
public:
	exitCommand();
	void execute();
	~exitCommand();
};

