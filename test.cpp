#include <cmath>
#include <iostream>

#include "auto_timer.h"

int main()
{
    // Default constructor
    AutoTimer timer0;

    {
        // Using 9 decimals when printing the result
        AutoTimer timer1(9);

        for (double i = 0; i < 100000000; ++i)
        {
            double root = sqrt(i);
            root *= root;
        }
    } // << timer1 will be destroyed here

    {
        // Explicit reference to std::cout, and 4 decimals
        AutoTimer timer2(std::cout, 4);

        for (int i = 0; i < 100000000; ++i)
        {
            if (i == 50000000)
            {
                // Report the time passed halfway through the loop
                timer2.report();
            }
            int root = sqrt(i);
            root *= root;
        }
    } // << This destroys timer2
} // Finally, timer0 is destroyed
