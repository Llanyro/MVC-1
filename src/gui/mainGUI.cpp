/*
 * mainGUI.cpp
 *
 *  Created on: Apr 15, 2023
 *      Author: llanyro
 */

#include "mainGUI.hpp"
#include "../core/MainControllerSingelton.hpp"

// Call the main controller to execute this main when necesary
ll_bool_t guiInit = llcpp::core::MainControllerSingelton::getInstance()->setMainThread(mainGUI);

#pragma region MultiThreadExample
#include "../example/example.hpp"
#pragma endregion

int mainGUI(int argc, char** argv) {
	thread::zzzThread();
	return 0;
}
