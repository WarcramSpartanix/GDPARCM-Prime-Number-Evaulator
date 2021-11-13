#include "HelloWorldThread.h"

HelloWorldThread::HelloWorldThread(int i)
{
	id = i;
}

HelloWorldThread::~HelloWorldThread()
{
}

void HelloWorldThread::run()
{
	std::cout << "Hello World: " << id << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 4000 + 1000));
	this->run();
}

