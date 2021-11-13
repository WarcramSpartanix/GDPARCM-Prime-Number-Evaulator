#pragma once
#include "IETThread.h"
class NumberTestThread : public IETThread
{
public:
	NumberTestThread(int dividend, int start, int end);
	~NumberTestThread();

	int dividend;
	int divisorStart;
	int divisorEnd;

	bool done = false;
	bool prime = true;
	
protected:
	void run() override;
};