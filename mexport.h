#ifndef MEXPORT_H
#define MEXPORT_H

#if defined __GNUC__
    #include <stdint.h>
    #define DSO_EXPORT __attribute__((visibility("default"))) __attribute__((externally_visible))
#elif defined _WIN32
    #include "pstdint.h"
    #define DSO_EXPORT
#else
    #error "Sorry, only GNU and Windows are supported."
#endif

#ifdef __cplusplus
    #define EXPORT_MEXFUNCTION extern "C" void mexFunction(int, mxArray*[], int, const mxArray*[]) DSO_EXPORT;
#else
    #define EXPORT_MEXFUNCTION mexFunction(int, mxArray*[], int, const mxArray*[]) DSO_EXPORT;
#endif
    
#endif
