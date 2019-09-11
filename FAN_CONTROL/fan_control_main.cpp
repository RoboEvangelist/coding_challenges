#include <iostream>
#include "fan_control/fan_control.hpp"

int main()
{
    bool secondary_is_idle = true;  // keeps track of the current state
                                    // of secondary module

    int main_counter = 0;           // main module's counter
    int sec_counter = 0;            // secondary module's counter

    bool init_sec_counter = false;  // keeps track of whether the
                                    // secondary module's counter has
                                    // been initialized already

    while (main_counter <= 3)
    {
        if (secondary_is_idle){
            std::cout << "Main: " << main_counter << std::endl;
            ++main_counter;
            secondary_is_idle = false;
            init_sec_counter = false;
        }
        else{
            if (!init_sec_counter){
                sec_counter = main_counter - 1;
                init_sec_counter = true;
            }
            // increment by doing circular addition 
            // (e.g., 0, 1, 2, 0, 1...)
            sec_counter = (++sec_counter)%3;
            if (sec_counter == main_counter - 1)
                secondary_is_idle = true;
            // 3%3 gives 0, so we need to convert here
            if (!sec_counter)
                sec_counter = 3;
            std::cout << "   Secondary: " << sec_counter
                << std::endl;
        }         
    }
    std::cout << "Bye!" << std::endl;
}






//int main()
//{
//    int state;                   // keeps track of the current state
//
//    int main_counter = 0;        // main module's counter
//    int prev_main_value = main_counter;
//    int sec_counter = 0;   // secondary module's counter
//    int prev_sec_value = sec_counter;
//
//    while (main_counter <= 3)
//    {
//        if (prev_main_value != main_counter){
//
//            // update state
//            prev_main_value = main_counter;
//
//            sec_counter = main_counter;
//            for (int j = 0; j < 3; ++j)
//            {
//                std::cout << "   Secondary: " << sec_counter
//                    << std::endl;
//                // increment by doing circular addition 
//                // (e.g., 0, 1, 2, 3, 0, 1...)
//                sec_counter = (++sec_counter)%4;
//                if (!sec_counter)
//                    sec_counter++;
//            }
//        }         
//        std::cout << "Main: " << main_counter << std::endl;
//        ++main_counter;
//    }
//    std::cout << "Bye!" << std::endl;
//}
