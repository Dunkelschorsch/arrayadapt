/*
 * Copyright (c) 2009 Armin C. Schmidt
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */
 
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
