#pragma once
#include <thread>
#include <iostream>

class IETThread
{
public:
	IETThread();
	~IETThread();

	void Start();

protected:
	virtual void run();
};

