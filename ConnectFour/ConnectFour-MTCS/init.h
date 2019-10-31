#ifndef __INIT_H__
#define __INIT_H__

enum player {Player1, Player2};

using stone = _int8;

inline stone PTOS(player p) { return (p == Player1) ? 1 : -1; }
inline player SWITCHPLAYER(player p) { return (p == Player1) ? Player2 : Player1; }

const int SCORE_MAX = 1000000;
const int SCORE_MIN = -1000000;

const int depth = 5;

#endif