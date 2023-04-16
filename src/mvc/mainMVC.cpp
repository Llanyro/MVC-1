/*
 * mainMVC.cpp
 *
 *  Created on: Apr 15, 2023
 *      Author: llanyro
 */

#include "mainMVC.hpp"
#include "../core/MainControllerSingelton.hpp"

// Call the main controller to execute this main when necesary
ll_bool_t mvcInit = llcpp::core::MainControllerSingelton::getInstance()->addMainToExec(mainMVC);

#pragma region MultiThreadExample
#include "../example/example.hpp"
#pragma endregion

int mainMVC(int argc, char** argv) {
	thread::zzzThread();
	return 0;
}
