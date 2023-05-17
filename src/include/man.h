// Copyright (c). 2023. All rights reserved.
// Author: kaluosifa
// Date: 2023-05-15

#ifndef SRC_INCLUDE_MAN_H_
#define SRC_INCLUDE_MAN_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "map.h"
#include "box.h"
#include "target.h"

extern struct Point g_man;
extern struct Map g_maps[MAP_NUBMER];
extern struct Map g_current_map;

void ManTopMove();
void ManDownMove();
void ManLeftMove();
void ManRightMove();

#ifdef __cplusplus
}
#endif

#endif  // SRC_INCLUDE_MAN_H_
