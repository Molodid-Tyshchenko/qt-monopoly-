#include "Player.h"


void Player::changePos(int id_t,int t_pos)
{
    emit signal_changePos(id_t,t_pos);
}
