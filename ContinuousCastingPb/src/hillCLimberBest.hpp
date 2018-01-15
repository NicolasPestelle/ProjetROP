//
// Created by cspecq1 on 15/01/18.
//

#ifndef CC_SIMULATOR_HILLCLIMBERBEST_HPP
#define CC_SIMULATOR_HILLCLIMBERBEST_HPP

#include "search.hpp"


class hillCLimberBest : public search {

public:
    hillCLimberBest();
    void run(Solution s);
};


#endif //CC_SIMULATOR_HILLCLIMBERBEST_HPP
