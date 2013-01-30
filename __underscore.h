/* __underscore.h
 *
 * Copyright (c) Sergey Ivonchik, 2013
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, 
 * this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are 
 * those of the authors and should not be interpreted as representing official 
 * policies, either expressed or implied, of the FreeBSD Project.
 */

#ifndef __UNDERSCORE_H
#define __UNDERSCORE_H

#import <Foundation/Foundation.h>

// Simple shortcut
#ifdef DEBUG
#  define __U_LOG(...) NSLog(__VA_ARGS__);
#else
#  define __U_LOG(...) /* */
#endif

// [p]rint [m]essage
#ifdef DEBUG
#  define __pm(...) NSLog(@"__: %s", #__VA_ARGS__);
#else
#  define __pm(...) /* */
#endif

#ifdef __cplusplus
extern "C" {
#endif

// [p]rint function/method name
static inline void __p(void) {
  NSArray *sym = [NSThread callStackSymbols];
  __U_LOG(@"__: %@", (2 > [sym count]) ? @"__null" : [sym objectAtIndex:1]);
}

// [p]rint [s]tring
static inline void __ps(NSString *str) {
  __U_LOG(@"__: %@", str);
}

// [p]rint [o]bject
static inline void __po(id obj) {
  __U_LOG(@"__: %@", [obj description]);
}

// [p]rint [c]har string
static inline void __pc(char *c) {
  __U_LOG(@"__: %s", c);
}

// [p]rint [i]nteger
static inline void __pi(int i) {
  __U_LOG(@"__: %d", i);
}

// [p]rint [f]loat
static inline void __pf(float f) {
  __U_LOG(@"__: %f", f);
}

// [p]rint [d]ouble
static inline void __pd(double d) {
  __U_LOG(@"__: %f", d);
}

// print caller's name
static inline void __clr(void) {
  NSArray *sym = [NSThread callStackSymbols];
  __U_LOG(@"__: %@", (3 > [sym count]) ? @"__null" : [sym objectAtIndex:2]);
}

// print stack frame
static inline void __stk(void) {
  __U_LOG(@"__: %@", [[NSThread callStackSymbols] description]);
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __UNDERSCORE_H */
