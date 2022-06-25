#include "Bot.h"

void Bot::changePos(int id_t,int t_pos)
{
    emit signal_changePos(id_t,t_pos);
}
