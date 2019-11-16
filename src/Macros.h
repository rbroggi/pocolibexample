//
// Created by rbroggi on 11/16/19.
//

#pragma once

#include <profiler/Timer.h>

//MACRO FOR ENABELING profiling in DEBUG MODE
#ifndef NDEBUG
#define PROFILE_SCOPE(name) pocolib_ex::profiler::InstrumentationTimer timer##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCTION__)
#else
#define PROFILE_SCOPE(name)
#define PROFILE_FUNCTION()
#endif
