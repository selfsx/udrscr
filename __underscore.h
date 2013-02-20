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

#if !__has_extension(attribute_overloadable)
#  error "__underscore requires attribute_overloadable support"
#endif

#ifndef __UNDERSCORE_OFF__
#  if defined(DEBUG) || defined(__UNDERSCORE_ON__)
#    define __U_LOG(...) NSLog(__VA_ARGS__);
#
#    // Shortcut macros to print simple text message without using of quotes
#    define __um(msg, type) printf("%s: ", #msg); __u(type);
#  else
#    define __U_LOG(...) /* */
#    define __um(...) /* */
#  endif
#else
#  define __U_LOG(...) /* */
#  define __um(...) /* */
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Print function/method name
static inline void __attribute__((overloadable)) __u(void) {
  NSArray *sym = [NSThread callStackSymbols];
  __U_LOG(@"__: %@", (2 > [sym count]) ? @"__null" : [sym objectAtIndex:1]);
}

// Print string
static inline void __attribute__((overloadable)) __u(NSString *str) {
  __U_LOG(@"__: L:%d %@", [str length], str);
}

// Print object's description
static inline void __attribute__((overloadable)) __u(id obj) {
  __U_LOG(@"__: %@", [obj description]);
}

// Print char string
static inline void __attribute__((overloadable)) __u(const char *c) {
  __U_LOG(@"__: L:%zu %s", strlen(c), c);
}

// Print integer
static inline void __attribute__((overloadable)) __u(int i) {
  __U_LOG(@"__: %d", i);
}

// Print float
static inline void __attribute__((overloadable)) __u(float f) {
  __U_LOG(@"__: %f", f);
}

// Print double
static inline void __attribute__((overloadable)) __u(double d) {
  __U_LOG(@"__: %f", d);
}

static inline void __attribute__((overloadable)) __u(CGPoint p) {
  __U_LOG(@"__: {x: %f, y: %f}", p.x, p.y);
}

static inline void __attribute__((overloadable)) __u(CGSize s) {
  __U_LOG(@"__: {width: %f, height: %f}", s.width, s.height);
}

static inline void __attribute__((overloadable)) __u(CGRect r) {
  __U_LOG(@"__: {x: %f, y: %f, width: %f, height: %f}",
          r.origin.x,
          r.origin.y,
          r.size.width,
          r.size.height);
}

// Print caller's name
static inline void __u_clr(void) {
  NSArray *sym = [NSThread callStackSymbols];
  __U_LOG(@"__: %@", (3 > [sym count]) ? @"__null" : [sym objectAtIndex:2]);
}

// Print stack frame
static inline void __u_stk(void) {
  __U_LOG(@"__: %@", [[NSThread callStackSymbols] description]);
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __UNDERSCORE_H */
