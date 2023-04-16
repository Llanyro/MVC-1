/*
 * Subscriber.hpp
 *
 *  Created on: Apr 15, 2023
 *      Author: llanyro
 */

#ifndef LLCPP_CORE_SUBSCRIBER_HPP_
#define LLCPP_CORE_SUBSCRIBER_HPP_

namespace llcpp {
namespace core {

class Subscriber {
	public:
		Subscriber();
		~Subscriber();
		virtual int run(int argc, char** argv) const = 0;
};

} /* namespace core */
} /* namespace llcpp */

#endif // !LLCPP_CORE_SUBSCRIBER_HPP_
