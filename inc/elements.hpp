/**
	\file elements.hpp
	\brief Static data for chemical elements.
	This file defined basic information about chemical elements.
 */

#ifndef _SMILESpp_elements_hpp_
#define _SMILESpp_elements_hpp_

#include<string>
#include<map>

namespace SMILESpp
{
	/**
		\brief Struct representing a chemical element.
		A struct representing a chemical element and all of it's metadata.
	 */
	struct Element
	{
		std::string symbol; ///< The elements symbol.
		int electrons;      ///< The number of electrons in the last electron shell.
		int max_electrons;  ///< The total number of electrons in the last electron shell.

		/**
			\brief Simple mapping constructor.
		 */
		Element(std::string symbol, int electrons, int max_electrons);

		/**
			\brief static map from an element's symbol to an element.
		*/
		static std::map<std::string, Element> element_map;
	};
}

#endif
