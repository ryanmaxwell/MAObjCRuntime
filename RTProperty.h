
#import <Foundation/Foundation.h>
#import <objc/runtime.h>

typedef NS_ENUM(NSInteger, RTPropertySetterSemantics) {
    RTPropertySetterSemanticsAssign,
    RTPropertySetterSemanticsRetain,
    RTPropertySetterSemanticsCopy
};

@interface RTProperty : NSObject

+ (id)propertyWithObjCProperty: (objc_property_t)property;
+ (id)propertyWithName: (NSString *)name attributes:(NSDictionary *)attributes;

- (id)initWithObjCProperty: (objc_property_t)property;
- (id)initWithName: (NSString *)name attributes:(NSDictionary *)attributes;

- (NSDictionary *)attributes;
#if __MAC_OS_X_VERSION_MIN_REQUIRED >= 1070
- (BOOL)addToClass:(Class)classToAddTo;
#endif

@property (readonly) NSString *attributeEncodings;
@property (readonly) BOOL isReadOnly;
@property (readonly) RTPropertySetterSemantics setterSemantics;
@property (readonly) BOOL isNonAtomic;
@property (readonly) BOOL isDynamic;
@property (readonly) BOOL isWeakReference;
@property (readonly) BOOL isEligibleForGarbageCollection;
@property (readonly) SEL customGetter;
@property (readonly) SEL customSetter;
@property (readonly) NSString *name;
@property (readonly) NSString *typeEncoding;
@property (readonly) NSString *oldTypeEncoding;
@property (readonly) NSString *ivarName;

@end

extern NSString * const RTPropertyTypeEncodingAttribute;
extern NSString * const RTPropertyBackingIVarNameAttribute;

extern NSString * const RTPropertyCopyAttribute;
extern NSString * const RTPropertyRetainAttribute;
extern NSString * const RTPropertyCustomGetterAttribute;
extern NSString * const RTPropertyCustomSetterAttribute;
extern NSString * const RTPropertyDynamicAttribute;
extern NSString * const RTPropertyEligibleForGarbageCollectionAttribute;
extern NSString * const RTPropertyNonAtomicAttribute;
extern NSString * const RTPropertyOldTypeEncodingAttribute;
extern NSString * const RTPropertyReadOnlyAttribute;
extern NSString * const RTPropertyWeakReferenceAttribute;
