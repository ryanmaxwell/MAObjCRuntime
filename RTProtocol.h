
#import <Foundation/Foundation.h>
#import <objc/runtime.h>

@class RTMethod;

@interface RTProtocol : NSObject

+ (NSArray<Protocol *> *)allProtocols;

+ (id)protocolWithObjCProtocol: (Protocol *)protocol;
+ (id)protocolWithName: (NSString *)name;

- (id)initWithObjCProtocol: (Protocol *)protocol;
- (id)initWithName: (NSString *)name;

@property (readonly) Protocol *objCProtocol;
@property (readonly) NSString *name;
@property (readonly) NSArray<Protocol *> *incorporatedProtocols;

- (NSArray<RTMethod *> *)methodsRequired: (BOOL)isRequiredMethod instance: (BOOL)isInstanceMethod;

@end
