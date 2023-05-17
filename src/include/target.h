// Copyright (c). 2023. All rights reserved.
// Author: kaluosifa
// Date: 2023-05-17

#ifndef SRC_INCLUDE_TARGET_H_
#define SRC_INCLUDE_TARGET_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "map.h"

extern struct Point g_man;
extern struct Map g_current_map;

// 判断人物在哪个目标点上
int WhichTarget();

// 判断箱子是否在目标点上
bool BoxOnTarget();

// 判断人物是否在目标点上
bool ManOnTarget();

#ifdef __cplusplus
}
#endif

#endif  // SRC_INCLUDE_TARGET_H_