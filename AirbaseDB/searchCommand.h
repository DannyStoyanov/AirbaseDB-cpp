#pragma once
#include "ICommand.h"
class searchCommand :public ICommand{
public:
	searchCommand();
	void execute();
	~searchCommand();
};

