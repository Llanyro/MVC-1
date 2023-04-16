/*
 * MainControllerSingelton.hpp
 *
 *  Created on: ??? ??, ????
 *      Author: llanyro
 */

#include "MainControllerSingelton.hpp"

#include <vector>
#include <list>
#include <algorithm>
#include <thread>

namespace llcpp {
namespace core {

MainControllerSingelton::MainControllerSingelton() {
	this->main = nullptr;
	//this->mainList = new std::list<MainFunction>();
}
MainControllerSingelton::~MainControllerSingelton() {
	//if (this->mainList) delete this->mainList;
	//this->mainList = nullptr;
}
ll_bool_t MainControllerSingelton::addMainToExec(MainFunction function) {
	ll_bool_t result = true;
	std::list<MainFunction>::iterator it = 
		//std::find(this->mainList->begin(), this->mainList->end(), function);
		std::find(this->mainList.begin(), this->mainList.end(), function);
	//if ((result = (it != this->mainList->end())))
	if (!(result = (it != this->mainList.end())))
		//this->mainList->push_back(function);
		this->mainList.push_back(function);
	return result;
}
ll_bool_t MainControllerSingelton::setMainThread(MainFunction function) {
	ll_bool_t result = true;
	if (!this->main)
		this->main = function;
	else
		result = false;
	return result;
}
void MainControllerSingelton::runMains(int argc, char** argv) const {
	std::vector<std::thread> threads;

	//for (MainFunction main : *this->mainList)
	for (MainFunction main : this->mainList) {
		threads.emplace_back(std::thread(main, argc, argv));
		//main(argc, argv);
	}
	if (this->main) this->main(argc, argv);
	for (auto& t : threads)
		t.join();
}

} /* namespace core */
} /* namespace llcpp */
