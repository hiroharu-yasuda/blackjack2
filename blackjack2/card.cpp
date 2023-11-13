#include "CardCheckr.h"
#include "Card.h"

//コンストラクタ
Card::Card() {
    _mark = spade;
    _number = ace;
}
//random用のコンストラクタ
Card::Card(Mark mark, CardCheckr number) {
    _mark = mark;
    _number = number;
}

void Card::operator=(const Card& other) {
    _mark = other._mark;
    _number = other._number;
}