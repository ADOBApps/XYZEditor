/***************************************************************
 * Name:      DumpFile.cpp
 * Purpose:   DUMP file manage
 * Description: Edit dump/xyz files to replace molecule openmd molecule type by openbabel type.
 * Author:    Acxel Orozco (acxelorozco@gmail.com)
 * Created:   2023-07-10
 * Last Modification: 2024-03-26
 * Copyright: Acxel Orozco ()
 * License:
 **************************************************************/

#include "DumpFile.h"
#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#if defined (_OPENMP)
#include <omp.h>
#endif // defined

using namespace std;

// Find and replace
void DumpFile::SerialReplace(
    std::string& s,
    std::string const& toReplace,
    std::string const& replaceWith
) {
    std::string buf;
    std::size_t pos = 0;
    std::size_t prevPos;
    //std::size_t prevPos = 0;

    // Reserves rough estimate of final size of string.
    buf.reserve(s.size());
    while (true) {
        prevPos = pos;
        pos = s.find(toReplace, pos);
        if (pos == std::string::npos){
            break;
        }
        buf.append(s, prevPos, pos - prevPos);
        buf += replaceWith;
        pos += toReplace.size();
    }

    buf.append(s, prevPos, s.size() - prevPos);
    s.swap(buf);
}
