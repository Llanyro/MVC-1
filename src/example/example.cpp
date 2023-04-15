/*
 * example.cpp
 *
 *  Created on: Apr 15, 2023
 *      Author: llanyro
 */

#include "example.hpp"

#include <iostream>
#include <thread>
#include <chrono>

namespace thread {

void exampleThread() {
	//std::thread t(zzzThread);
	//t.join();
	zzzThread();
}
void zzzThread() {
	int i = 10;
	std::cout << "Thread " << std::this_thread::get_id() << " is going to sleep " << i << " seconds" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(i));
}

} /* namespace thread */
