#include <elements.hpp>
#include <exception>
#include <vector>
#include <functional>

namespace SMILESpp
{
	namespace Test
	{
		namespace Element
		{

			// Test definitions
			void test_struct_element()
			{
				SMILESpp::Element element("S", 4, 8);

				if (element.symbol != "S")
					throw "Symbols in element don't match";
				if (element.electrons != 4)
					throw "Electrons in element don't match";
				if (element.max_electrons != 8)
					throw "Max electrons in element don't match";
			}

			// Save tests
			std::vector<std::function<void()>> tests
			{
				test_struct_element,
			};

		}
	}
}
