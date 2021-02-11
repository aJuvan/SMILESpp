#include <elements.hpp>

namespace SMILESpp
{
	Element::Element(std::string symbol, int electrons, int max_electrons)
	{
		this->symbol = symbol;
		this->electrons = electrons;
		this->max_electrons = max_electrons;
	}
	
	std::map<std::string, Element> Element::element_map =
	{
		{"B",  Element("B",  3, 8)},
		{"C",  Element("C",  4, 8)},
		{"N",  Element("N",  5, 8)},
		{"O",  Element("O",  6, 8)},
		{"F",  Element("F",  7, 8)},
		{"S",  Element("S",  6, 8)},
		{"Cl", Element("Cl", 7, 8)},
		{"Br", Element("Br", 7, 8)},
		{"I",  Element("I",  7, 8)},
	};
};
