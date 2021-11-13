#include "NumberTestThread.h"

NumberTestThread::NumberTestThread(int dividend, int start, int end)
{
	this->dividend = dividend;
	this->divisorStart = start;
	this->divisorEnd = end;
}

NumberTestThread::~NumberTestThread()
{
}

void NumberTestThread::run()
{
	for (int i = this->divisorStart; i < this->divisorEnd; i++)
	{
		int remainder = dividend % i;
		if(remainder == 0)
		{
			prime = false;
		}
		float result = dividend / i;
	}
	done = true;
}
