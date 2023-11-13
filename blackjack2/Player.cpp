#include "Player.h"

void Player::PlayerScoreCalculation()
{
    for (int i = 0; i < _outwardlyNum; ++i) {
        if (_pcard[i].get_Number() == ace) {
            if (_score + 11 > 21) {
                set_score(_pcard[i].get_Number());
            }
            else {
                set_score(jack);
            }
        }
        else if (two <= _pcard[i].get_Number() && _pcard[i].get_Number() <= ten) {
            set_score(_pcard[i].get_Number());
        }
        else if (jack <= _pcard[i].get_Number() && _pcard[i].get_Number() <= king) {
            set_score(ten);
        }
    }
}