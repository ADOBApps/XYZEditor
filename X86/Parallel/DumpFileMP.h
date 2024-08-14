/***************************************************************
 * Name:      CppGlue.cpp
 * Purpose:   Code for JSON usign test
 * Author:    Acxel Orozco (acxelorozco@gmail.com)
 * Created:   2023-07-10
 * Copyright: Acxel Orozco ()
 * License:
 **************************************************************/

#ifndef DUMPFILEMP_H
#define DUMPFILEMP_H

#include <fstream>
#include <iostream>
#include <exception>
#include <string>
using namespace std;

class DumpFileMP{
	public:
		void SerialReplace(
		    std::string& s,
    		std::string const& toReplace,
    		std::string const& replaceWith
    	);
    	void ParallelReplace(std::string file_path);
};

#endif