#include <iostream>


	int funCalls = 0;

	void fun()
	
	{
		funCalls++;
		std::cout << "I am fun1 and I have been called" << funCalls << " times" << endl;
	}

	void fun2()
	{
		static int funCalls = 0;
		funCalls++;
		std::cout << "I am fun2 and I have been called" << funCalls << " times" << endl;

	}

	int main() 
	{
		for (int i = 0; i < 10; i++)
			fun1();

		std::cout << endl;
		for (int i = 0; i < 10; i++)
			fun2()
	}
