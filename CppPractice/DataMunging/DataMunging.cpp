//
//  DataMunging.cpp
//  CppPractice
//
//  Created by Stewart Bracken on 12/15/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <gtest/gtest.h>

#include "Split.h"

template <class T>
T str_to_num(std::string& s){
    T out;
    std::stringstream convert(s);
    if(!(convert>>out))
        out=0;
    return out;
}

TEST(DataMunging, weather_read){
    std::string line;
    std::ifstream weather_dat ("weather.dat");
    int skip_n_lines = 8;
    int num_days = 30;
    if (weather_dat.is_open())
    {
        for(int i=0;i<skip_n_lines;getline(weather_dat,line),++i);
        std::vector<std::string> split_line;
        int min_day = 0, min_temp_spread = 1000;
        for(int i = 0; i < num_days; ++i){
            getline (weather_dat,line);
            split_line = split(line, ' ');
            
            int spread = str_to_num<int>(split_line[1]) - //daily max
                         str_to_num<int>(split_line[2]); //daily min
            if(spread < min_temp_spread){
                min_temp_spread = spread;
                min_day = str_to_num<int>(split_line[0]);
            }
        }
        std::cout << "Minimum temperature spread. Day: " << min_day << ", Spread: "<< min_temp_spread << std::endl;
        weather_dat.close();
    }
    
    else std::cout << "Unable to open file";
}