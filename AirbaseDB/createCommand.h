#pragma once
#include "ICommand.h"
class createCommand :public ICommand {
public:
	createCommand();
	void execute();
	~createCommand();
};

