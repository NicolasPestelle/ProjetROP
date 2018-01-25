/**
 * @file main.cpp
 * See the AUTHORS or Authors.txt file
 */

/*
 * Copyright (C) 2017-2018 ULCO http://www.univ-litoral.fr
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <graph_manager.hpp>
#include <models.hpp>

#include <artis-star/common/RootCoordinator.hpp>

#include <solution.hpp>
#include <evalCC.hpp>

#include <chrono>
#include <fstream>
#include <iostream>
#include <time.h>
#include <RandomSearch.hpp>
#include <RandomWalk.hpp>


using namespace cc;
using namespace artis::common;


int main()
{ 
    srand(time(NULL));
 
    const unsigned int n_stack = 5;
    const unsigned int n_destination = 8;
    const unsigned int solution_size = n_destination + n_stack * n_destination * (n_destination - 1);

	
   
	/*RandomSearch rs(solution_size);
	rs.run();

	Solution result; 
	result = rs.getSolution();*/

	RandomWalk rw(solution_size);
	rw.run();

	//Solution result; 
	//result = rw.getSolution();

	

//	std::cout << result.to_string() << std::endl;

    return 0;
}
