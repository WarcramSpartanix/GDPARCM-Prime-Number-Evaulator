#pragma once
#include "IETThread.h"
#include <iostream>
class HelloWorldThread :
    public IETThread
{
public:
	HelloWorldThread(int);
	~HelloWorldThread();
	
	int id = 0;

protected:
	void run() override;
};

