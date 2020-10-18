#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
    // define COMPILING_LIB when building a .dll library
    #ifdef COMPILING_LIB
        #define DLLEXPORT __declspec(dllexport)
    #else
        #define DLLEXPORT __declspec(dllimport)
    #endif
#else
    #define DLLEXPORT
#endif

DLLEXPORT int compute(int val);

#ifdef __cplusplus
}
#endif
