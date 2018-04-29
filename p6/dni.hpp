#ifndef DNI_HPP
#define DNI_HPP
#include <vector>
#include <iostream>
#include <time.h>
#include <random>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include <deque>
#include <queue>

#pragma once

using namespace std;


class dni {

    unsigned long int dni_;


 public:

    dni();
    dni(unsigned long int dnii);
    ~dni(void);
    unsigned long int get_dni(void);
    void set_dni(unsigned long int dnii);
    void set_random(void);

    bool operator<(dni& dni_n);
    bool operator>(dni& dni_n);
    bool operator==(dni& dni_n);
    bool operator!=(dni& dni_n);
    bool operator<=(dni& dni_n);
    explicit operator unsigned long int() const;

    friend ostream& operator<<(ostream& os, const dni& dni_s);

};


#endif // DNI_HPP
