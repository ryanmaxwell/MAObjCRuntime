
#import <Foundation/Foundation.h>


@class RTProtocol;
@class RTIvar;
@class RTProperty;
@class RTMethod;
@class RTUnregisteredClass;

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (MARuntime)

// includes the receiver
+ (NSArray<Class> *)rt_subclasses;

+ (RTUnregisteredClass *)rt_createUnregisteredSubclassNamed: (NSString *)name;
+ (Class)rt_createSubclassNamed: (NSString *)name;
+ (void)rt_destroyClass;

+ (BOOL)rt_isMetaClass;
+ (Class)rt_setSuperclass: (Class)newSuperclass;
+ (size_t)rt_instanceSize;

+ (NSArray<RTProtocol *> *)rt_protocols;

+ (NSArray<RTMethod *> *)rt_methods;
+ (nullable RTMethod *)rt_methodForSelector: (SEL)sel;

+ (void)rt_addMethod: (RTMethod *)method;

+ (NSArray *)rt_ivars;
+ (nullable RTIvar *)rt_ivarForName: (NSString *)name;

+ (NSArray<RTProperty *> *)rt_properties;
+ (nullable RTProperty *)rt_propertyForName: (NSString *)name;
#if __MAC_OS_X_VERSION_MIN_REQUIRED >= 1070
+ (BOOL)rt_addProperty: (RTProperty *)property;
#endif

// Apple likes to fiddle with -class to hide their dynamic subclasses
// e.g. KVO subclasses, so [obj class] can lie to you
// rt_class is a direct call to object_getClass (which in turn
// directly hits up the isa) so it will always tell the truth
- (Class)rt_class;
- (Class)rt_setClass: (Class)newClass;

@end

NS_ASSUME_NONNULL_END

