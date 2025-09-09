#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
private:
    int value{ 1 };

public:

    Counter();
    Counter(int setVal);

    void incrementValue();

    void decrementValue();

    void showCurrentValue();
};

#endif
