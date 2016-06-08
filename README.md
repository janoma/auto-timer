# C++ Auto Timer
A C++ timer that automatically measures wall time and prints the output upon destruction.

It is based on [`auto_cpu_timer`](http://www.boost.org/doc/libs/1_58_0/libs/timer/doc/cpu_timers.html#Class-auto_cpu_timer) from [`boost::timer`](http://www.boost.org/doc/libs/1_58_0/libs/timer/doc/index.html), but it doesn't require Boost (doh), and it only shows the wall time.

## Usage
Initialize when you want to start measuring. A report is given to `std::cout` when the timer object is destroyed.

```cpp
{
    AutoTimer timer;
    
    // You will be measuring all these lines...
    
    timer.report(); // Reports the time up to this line
    
    // These lines are still being measured
} // The timer object is destroyed and report() is called one last time
```

To measure functions you can either integrate the timer to the function itself...

```cpp
void my_function() {
    AutoTimer timer; //will report once the function finishes or returns
    // function code...
}
```

... or call it from outside:

```cpp
std::cout << "Measuring function call ... took " << std::flush;
{
    AutoTimer timer;
    my_function();
}
```

Sample output:

```
Measuring function call ... took 3.141592s
```
