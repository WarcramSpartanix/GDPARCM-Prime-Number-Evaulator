#include "IETThread.h"

IETThread::IETThread()
{
	Start();
}

IETThread::~IETThread()
{
}

void IETThread::Start()
{
	std::thread(&IETThread::run, this).detach();
}

void IETThread::run()
{
	
}
