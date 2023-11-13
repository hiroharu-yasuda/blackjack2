#pragma once


#include "CardCheckr.h"

class Card {
public:
    Card();
    Card(Mark mark, CardCheckr number);
    void operator=(const Card& other);

public:
    Mark get_mark() const {
        return _mark;
    }
    CardCheckr get_Number() const {
        return _number;
    }

protected:
    Mark _mark;
    CardCheckr _number;
}; 
