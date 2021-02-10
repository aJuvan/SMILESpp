/**
	\file SMILESpp.hpp
	\brief Main header file for SMILESpp.
	The main header file for the SMILESpp project.
 */

#ifndef _SMILESpp_SMILESpp_hpp_
#define _SMILESpp_SMILESpp_hpp_

#include <iostream>
#include <string>
#include <vector>

namespace SMILESpp
{
	/**
		Molecule structure.
		A structure representing a single molecule in a graph.
	*/
	class Molecule
	{
		private:

			//* A molecule symbol (i.e H for hydrogen)
			std::string symbol;

			//* 
			std::vector<Molecule> neighbors;

		public:

			/**
				Molecule symbol getter.
			*/
			std::string get_symbol();

			/**
				
			*/
			std::vector<Molecule> get_neighbors();
	};

	class Graph
	{
		public:
			void test();
	};
}

#endif
