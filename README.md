__underscore.h
======

__underscore.h - Simple shortcuts for NSLog messages ;)

**Exapmles:**
    
    NSLog(@"%s", __PRETTY_FUNCTION__);     =>     __p()
    NSLog(@"%@", @"Hello World!");         =>     __pm(Hello World!)

**Shortcuts:**

    // [p]rint [m]essage
    __pm(...)
    
    // [p]rint function/method name
    __p(void)
    
    // [p]rint [s]tring
    __ps(NSString *str)
    
    // [p]rint [o]bject
    __po(id obj)
    
    // [p]rint [c]har string
    __pc(char *c)
    
    // [p]rint [i]nteger
    __pi(int i)
    
    // [p]rint [f]loat
    __pf(float f)
    
    // [p]rint [d]ouble
    __pd(double d)
    
    // print caller's name
    __clr(void)
    
    // print stack frame
    __stk(void)
    