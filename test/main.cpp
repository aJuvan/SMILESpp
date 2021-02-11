#include<iostream>
#include<exception>
#include<SMILESpp.hpp>

#include "elements.hpp"
#include"unit/elements.cpp"

namespace SMILESpp
{
	namespace Test
	{
		// Define all tests
		std::map<std::string, std::vector<std::function<void()>>> tests
		{
			{"Element", SMILESpp::Test::Element::tests}
		};

		// Run single test
		bool run_test(std::string location, int index, std::function<void()> test)
		{
			try
			{
				test();
			}
			catch(const char* msg)
			{
				std::cout
					<< "\t\t" << "Exception raised while running test "
					<< location << " " << index << ": " << std::endl
					<< "\t\t" << msg;
				return false;
			}
			catch(std::exception &e)
			{
				std::cout
					<< "\t\t" << "Exception raised while running test "
					<< location << " " << index << ": " << std::endl
					<< "\t\t" << e.what();
				return false;
			}

			return true;
		}

		// Run tests
		void run()
		{
			int all_tests = 0;
			int successful_tests = 0;

			std::cout
				<< "Running tests"
				<< std::endl;
			
			for (auto test_part : tests)
			{
				int index = 1;
				std::cout << "\t" << "Running tests segment: " << test_part.first << std::endl;
				
				for (auto test : test_part.second)
				{
					bool result = run_test(test_part.first, index, test);
					if (result)
						successful_tests++;
					all_tests++;
				}

				index++;
			}

			std::cout
				<< std::endl
				<< "Done "
				<< successful_tests << "/" << all_tests
				<< std::endl;
		}
	}
}

int main()
{
	SMILESpp::Test::run();
	return 0;
}
