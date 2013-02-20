__underscore.h
======

__underscore.h - Simple header file with shortcuts for NSLog messages. It simply defines single function ```__u()``` with which you can log different types of data, also it defines simple macros ```__um(msg, type)``` for prepending type log with message.

Log messages are on in debug mode and off in release mode. But you can manually enable and disable messages using ```__UNDERSCORE_ON__``` and ```__UNDERSCORE_OFF__``` in different modes.


**Exapmles:**


```objective-c

// __u()
NSLog(@"%s", __PRETTY_FUNCTION__); 

// __u(p)
CGPoint p = CGPointMake(74, 23);
NSLog(@"{x: %f, y: %f}", p.x, p.y);=

// __um(My Rect, r);
CGRect r = CGRectMake(23, 34, 345, 453);
NSLog(@"My Rect: {x: %f, y: %f, width: %f, height: %f}", 
        r.origin.x, 
        r.origin.y,
        r.size.width,
        r.size.height);
```

**Shortcuts:**


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