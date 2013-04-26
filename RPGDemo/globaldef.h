#pragma once

#include <Windows.h>
#include "hge\include\hge.h"
#include "hge\include\hgesprite.h"
#include <vector>

#include "engine\SceneEngine.h"
#include "engine\InputEngine.h"

extern HGE* hge;
extern SceneEngine* SceneEngine_;
extern InputEngine* InputEngine_;

enum DIR_ENUM
{
    DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT
};