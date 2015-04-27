#include <cmath>

#include "auto_timer.h"

int main()
{
    AutoTimer timer;

    for (double i = 0; i < 100000; ++i)
    {
        double root = sqrt(i);
        root *= root;
    }
}
