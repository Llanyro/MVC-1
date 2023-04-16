/*
 * main.cpp
 *
 *  Created on: ??? ??, ????
 *      Author: llanyro
 */

#include "MainControllerSingelton.hpp"

#include <iostream>
#include <thread>
#include <chrono>

int main(int argc, char** argv) {
	std::cout << "Main " << std::this_thread::get_id() << std::endl;
	llcpp::core::MainControllerSingelton::getInstance()->runMains(argc, argv);
	int i = 11;
	std::cout << "Main thread hash finished loading threads mains, now will go to sleep for " << i << " seconds." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(i));
	return 0;
}

/*
	Thread core control ???

*/