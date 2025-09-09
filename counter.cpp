#include <iostream>

#include "counter.h"

Counter::Counter() = default;
Counter::Counter(int setVal) : value{ setVal } {};
void Counter::incrementValue() { value++; };
void Counter::decrementValue() { value--; };
void Counter::showCurrentValue() { std::cout << value << std::endl; };
