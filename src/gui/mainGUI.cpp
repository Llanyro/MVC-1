/*
 * mainGUI.cpp
 *
 *  Created on: Apr 15, 2023
 *      Author: llanyro
 */

#include "mainGUI.hpp"
#include "../core/MainControllerSingelton.hpp"

// Call the main controller to execute this main when necesary
bool guiInit = llcpp::core::MainControllerSingelton::getInstance()->setMainThread(mainGUI);

#pragma region MultiThreadExample
#include "../example/example.hpp"
#include <iostream>
#include <mutex>
#pragma endregion

extern std::mutex coutMutex;

int mainGUI(int argc, char** argv) {
	coutMutex.lock();
	std::cout << "GUI thread " << std::this_thread::get_id() << std::endl;
	coutMutex.unlock();
	thread::zzzThread();
	return 0;
}
