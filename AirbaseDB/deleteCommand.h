#pragma once
#include "ICommand.h"
class deleteCommand :public ICommand {
public:
	deleteCommand();
	void execute();
	~deleteCommand();
};

