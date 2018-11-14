
#import <Foundation/Foundation.h>
#import <objc/runtime.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTIvar : NSObject

+ (id)ivarWithObjCIvar: (Ivar)ivar;
+ (id)ivarWithName: (NSString *)name typeEncoding: (NSString *)typeEncoding;
+ (id)ivarWithName: (NSString *)name encode: (const char *)encodeStr;

- (id)initWithObjCIvar: (Ivar)ivar;
- (id)initWithName: (NSString *)name typeEncoding: (NSString *)typeEncoding;

@property (readonly) NSString *name;
@property (readonly) NSString *typeEncoding;
@property (readonly) ptrdiff_t offset;

@end

NS_ASSUME_NONNULL_END
