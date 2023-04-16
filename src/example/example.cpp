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
#include <mutex>

namespace thread {

std::mutex coutMutex;

void zzzThread() {
	coutMutex.lock();
	int i = 10;
	std::cout << "Thread " << std::this_thread::get_id() << " is going to sleep " << i << " seconds" << std::endl;
	coutMutex.unlock();
	std::this_thread::sleep_for(std::chrono::seconds(i));
}

} /* namespace thread */
