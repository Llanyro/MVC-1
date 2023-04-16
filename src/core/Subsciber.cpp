/*
 * Subscriber.cpp
 *
 *  Created on: Apr 15, 2023
 *      Author: llanyro
 */

#include "Subsciber.hpp"
#include "MainControllerSingelton.hpp"

namespace llcpp {
namespace core {

Subscriber::Subscriber(const bool& main) {
	if(main)
		MainControllerSingelton::getInstance()->setMainThread(this);
	else
		MainControllerSingelton::getInstance()->add(this);
}
Subscriber::~Subscriber() {}

} /* namespace core */
} /* namespace llcpp */
