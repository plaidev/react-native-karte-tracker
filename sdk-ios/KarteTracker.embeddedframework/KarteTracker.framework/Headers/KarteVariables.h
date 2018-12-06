//
//  Variables.h
//  KarteTracker
//
//  Created by rei.ishikawa on H30/08/20.
//

#import <Foundation/Foundation.h>
#import "KarteVariable.h"


@interface KarteVariables : NSObject
@property (class, strong, readonly) KarteVariables *variables;

- (nonnull instancetype)initWithAppKey:(nonnull NSString *)appKey NS_SWIFT_NAME(init(appKey:));
+ (nonnull instancetype)variablesWithAppKey:(nonnull NSString *)appKey NS_SWIFT_NAME(variables(appKey:));

- (void)fetch;
+ (void)fetch;
- (void)fetchWithCompletionBlock:(nonnull void (^)(BOOL isSuccessful))completion NS_SWIFT_NAME(fetch(_:));
+ (void)fetchWithCompletionBlock:(nonnull void (^)(BOOL isSuccessful))completion NS_SWIFT_NAME(fetch(_:));

- (nonnull KarteVariable *)variableForKey:(nonnull NSString *)key NS_SWIFT_NAME(variable(forKey:));
+ (nonnull KarteVariable *)variableForKey:(nonnull NSString *)key NS_SWIFT_NAME(variable(forKey:));

- (void)trackWithVariables:(NSArray *)variables withEventName:(NSString *)eventName NS_SWIFT_NAME(track(variables:eventName:));
- (void)trackWithVariables:(NSArray *)variables withEventName:(NSString *)eventName withValues:(nullable NSDictionary *)values NS_SWIFT_NAME(track(variables:eventName:values:));

+ (void)trackWithVariables:(NSArray *)variables withEventName:(NSString *)eventName NS_SWIFT_NAME(track(variables:eventName:));
+ (void)trackWithVariables:(NSArray *)variables withEventName:(NSString *)eventName withValues:(nullable NSDictionary *)values NS_SWIFT_NAME(track(variables:eventName:values:));

@end
