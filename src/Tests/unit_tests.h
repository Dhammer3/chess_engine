#include "piece_factory.h"

class unit_tests
{
    
    #define IS_TRUE(x) { if (!(x)) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }

    unit_tests(){};
    void run_all_tests();
    void init();
};