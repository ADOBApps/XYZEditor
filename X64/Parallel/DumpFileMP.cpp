/***************************************************************
 * Name:      CppGlue.cpp
 * Purpose:   Code for JSON usign test
 * Author:    Acxel Orozco (acxelorozco@gmail.com)
 * Created:   2023-07-10
 * Copyright: Acxel Orozco ()
 * License:
 **************************************************************/

#include "DumpFileMP.h"
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
void DumpFileMP::SerialReplace(
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


void DumpFileMP::ParallelReplaceOld(std::string file_path)
{
    int no_of_threads = omp_get_max_threads();
    int partition_size = 1000000000/no_of_threads;
    long double word_length_counter;
    string temp_word_holder;
    word_length_counter = 0;

    cout<<"\nno of threads "<<no_of_threads;
    #pragma omp parallel private(word_length_counter, temp_word_holder) shared(partition_size)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                ifstream main_file;
                ofstream temp_file_holder;
                main_file.open("generated.txt",ios::in);
                temp_file_holder.open("partition0.txt",ios::out);

                while(word_length_counter <= partition_size)
                {
                    main_file>>temp_word_holder;
                    word_length_counter += temp_word_holder.length();
                    temp_file_holder<<temp_word_holder<<endl;
                }
                main_file.close();
                temp_file_holder.close();
            }

            #pragma omp section
            {
                ifstream main_file1;
                ofstream temp_file_holder1;
                main_file1.open("generated.txt",ios::in);
                temp_file_holder1.open("partition1.txt",ios::out);
                main_file1.seekg(partition_size);
                while(word_length_counter <= partition_size)
                {
                    main_file1>>temp_word_holder;
                    word_length_counter += temp_word_holder.length();
                    temp_file_holder1<<temp_word_holder<<endl;
                }
                main_file1.close();
                temp_file_holder1.close();
            }

            #pragma omp section
            {
                ifstream main_file2;
                ofstream temp_file_holder2;
                main_file2.open("generated.txt",ios::in);
                temp_file_holder2.open("partition2.txt",ios::out);
                main_file2.seekg((partition_size*2));
                while(word_length_counter <= partition_size)
                {
                    main_file2>>temp_word_holder;
                    word_length_counter += temp_word_holder.length();
                    temp_file_holder2<<temp_word_holder<<endl;
                }
                main_file2.close();
                temp_file_holder2.close();
            }

            #pragma omp section
            {
                ifstream main_file3;
                ofstream temp_file_holder3;
                main_file3.open("generated.txt",ios::in);
                temp_file_holder3.open("partition3.txt",ios::out);
                main_file3.seekg((partition_size-1)*3);
                while(word_length_counter <= partition_size && !main_file3.eof())
                {
                    main_file3>>temp_word_holder;
                    word_length_counter += temp_word_holder.length();
                    temp_file_holder3<<temp_word_holder<<endl;
                }
                main_file3.close();
                temp_file_holder3.close();
            }
        }

    }
    #pragma omp barrier
    cout<<"\npartitions generated";
}

/*
* Main idea is divide replacement into threads
*/
void DumpFileMP::ParallelReplace(
    std::string& s,
    std::string const& toReplace,
    std::string const& replaceWith
) {
    std::string buf;
    std::size_t pos = 0;
    std::size_t prevPos = 0;
    std::size_t finalPos = 0;

    int no_of_threads = omp_get_max_threads();
    omp_set_num_threads(no_of_threads);
    std::size_t local_size = ((int)s.length())/no_of_threads;

    #pragma omp parallel private(buf,pos,prevPos) shared(local_size,finalPos)
    {
        // Reserves rough estimate of final size of string.
        buf.reserve(local_size);
        int th_id = omp_get_thread_num();
        while (true) {
            if(th_id == 0){
                prevPos = 0;
            } else{
                prevPos = finalPos;
            }
            pos = s.find(toReplace, pos);
            if (pos == std::string::npos){
                break;
            }
            buf.append(s, prevPos, pos - prevPos);
            buf += replaceWith;
            pos += toReplace.size();
            finalPos = pos;
        }

        buf.append(s, prevPos, s.size() - prevPos);
        s.swap(buf);
    }
}
