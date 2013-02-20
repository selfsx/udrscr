__underscore.h
======

__underscore.h - Simple header file with shortcuts for NSLog messages. It simply defines single function ```__u()``` with which you can log different types of data, also it defines simple macros ```__um(msg, type)``` for prepending type log with message.

Log messages are ON in debug mode and OFF in release mode. But you can manually enable and disable messages by defining ```__UNDERSCORE_ON__``` and ```__UNDERSCORE_OFF__``` macroses in different modes.

__underscore.h uses [function overloading](http://clang.llvm.org/docs/LanguageExtensions.html#function-overloading-in-c) extension and requires Clang 3.3 and above.

### Exapmles:


```objective-c

// Will be __u()
NSLog(@"%s", __PRETTY_FUNCTION__); 

// Will be __u(p)
CGPoint p = CGPointMake(74, 23);
NSLog(@"{x: %f, y: %f}", p.x, p.y);

// Will be __um(My Rect, r);
CGRect r = CGRectMake(23, 34, 345, 453);
NSLog(@"My Rect: {x: %f, y: %f, width: %f, height: %f}", 
        r.origin.x, 
        r.origin.y,
        r.size.width,
        r.size.height);
```

### Shortcuts:


```objective-c
    
__u(void) // Print function/method name
__u(NSString *str) // Print string with length
__u(id obj)
__u(const char *c) // Print char string with length
__u(int i)
__u(float f)
__u(double d)
__u(CGPoint p)
__u(CGSize s)
__u(CGRect r)

__u_clr(void) // Print caller's name
__u_stk(void) // Print stack frame
    
```   

Enjoy. Hope compilers won't be angry for double underscore ;)