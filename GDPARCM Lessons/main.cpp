#include <iostream>
#include <thread>
#include "NumberTestThread.h"
#include <vector>
#include <cmath>

using namespace std;

void Hi()
{
	std::cout << "hi" << std::endl;
	
}

void PrimeTestThreaded(int number, int threadCount)
{
	bool finished = true;
	bool prime = true;
	vector<NumberTestThread*> testThreadList;
	for (int i = 0; i < threadCount; i++) {
		int start = floor((number) / threadCount) * i + 2;
		//int end = (i != threadCount-1) ? floor((number / 2.0) / threadCount) * (i+1) + 1 : floor(number/2.0f);
		int end = (i != threadCount - 1) ? floor((number) / threadCount) * (i + 1) + 1 : number - 1;
		NumberTestThread* temp = new NumberTestThread(number, start , end);

		cout << "Thread: " << i << " , Start: " << start << " , End: " << end << endl;
	testThreadList.push_back(temp);
	}
	
	do
	{
		finished = true;
		for (int i = 0; i < testThreadList.size(); i++)
		{
			if (!testThreadList[i]->done)
			{
				finished = false;
				break;
			}
		}
	} while (!finished);

	for (int i = 0; i < testThreadList.size(); i++)
	{
		//cout << "Thread: " << i << " , Result: " << testThreadList[i]->prime << endl;
		if (!testThreadList[i]->prime)
		{
			prime = false;
			break;
		}
	}
	
	if (prime)
	{
		cout << "The Number " << number << " is a Prime Number" << endl;
	}
	else
	{
		cout << "The Number " << number << " is not a Prime Number" << endl;
	}
}

void Test(int divisorStart, int divisorEnd, int dividend)
{
	bool prime = true;
	for (float i = divisorStart; i <= divisorEnd; i++)
	{
		
		float result = dividend / i;
		
		result = remainder(result, 1);
		if(result != 0.f)
		{
			prime = false;
		}
	}
	if (prime)
	{
		cout << "The Number " << dividend << " is a Prime Number" << endl;
	}
	else
	{
		cout << "The Number " << dividend << " is not a Prime Number" << endl;
	}
}

int main()
{
	int number = 2147483647;
	//2147483647
	// get test number value
	/*std::cout << "Enter Number: ";
	std::cin >> number;*/
	
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	
	PrimeTestThreaded(number, 128);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
	return 0;
}