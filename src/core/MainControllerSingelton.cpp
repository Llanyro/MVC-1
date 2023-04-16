/*
 * MainControllerSingelton.hpp
 *
 *  Created on: ??? ??, ????
 *      Author: llanyro
 */

#include "MainControllerSingelton.hpp"

#include "Subsciber.hpp"

#include <vector>
#include <list>
#include <algorithm>
#include <thread>

namespace llcpp {
namespace core {

MainControllerSingelton::MainControllerSingelton() {
	//this->mainList = new std::list<MainFunction>();
}
MainControllerSingelton::~MainControllerSingelton() {
	//if (this->mainList) delete this->mainList;
	//this->mainList = nullptr;
}
ll_bool_t MainControllerSingelton::add(Subscriber* sub) {
	ll_bool_t result = true;
	std::list<Subscriber*>::iterator it =
		//std::find(this->mainList->begin(), this->mainList->end(), function);
		std::find(this->mainList.begin(), this->mainList.end(), sub);
	//if ((result = (it != this->mainList->end())))
	if (!(result = (it != this->mainList.end())))
		//this->mainList->push_back(function);
		this->mainList.push_back(sub);
	return result;
}
void MainControllerSingelton::run(int argc, char** argv) const {
	std::vector<std::thread> threads;

	//for (MainFunction main : *this->mainList)
	for (Subscriber* sub : this->mainList) {
		threads.emplace_back(std::thread(&Subscriber::run, sub, argc, argv));
		//main(argc, argv);
	}
	for (auto& t : threads)
		t.join();
}

} /* namespace core */
} /* namespace llcpp */
