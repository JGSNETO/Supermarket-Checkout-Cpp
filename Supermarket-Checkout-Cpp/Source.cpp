#include <iostream>
#include "Checkout.h"
#include <gtest/gtest.h>


int main(int argc, char* argv[])
{
	std::cout << "Hello world" << std::endl;
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	system("PAUSE");
	return 0;
}