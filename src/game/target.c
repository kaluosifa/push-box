#include "../include/target.h"

int WhichTarget()
{
    int target_index = -1;
    for (int i = 0; i < g_current_map.box_number; ++i)
    {
        if (g_man.x == g_current_map.target[i].x && \
            g_man.y == g_current_map.target[i].y)
        {
            target_index = i;
            break;
        }
    }

    return target_index;
}

bool BoxOnTarget()
{
    bool box_on_target = false;
    int target_index = WhichTarget();

    for (int i = 0; i < g_current_map.box_number; ++i)
    {
        if (g_current_map.boxes[i].x == g_current_map.target[target_index].x && \
            g_current_map.boxes[i].y == g_current_map.target[target_index].y)
        {
            box_on_target = true;
            break;
        }
    }

    return box_on_target;
}

bool ManOnTarget()
{
    bool man_on_target = false;
    int target_index = WhichTarget();
    if (target_index == -1)
    {
        man_on_target = false;
    }
    else
    {
        man_on_target = true;
    }

    return man_on_target;
}