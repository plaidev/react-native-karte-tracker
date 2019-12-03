//
//  KarteVariables.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KarteVariable.h"

NS_ASSUME_NONNULL_BEGIN


@interface KarteVariables : NSObject
@property (class, strong, readonly) KarteVariables *variables;

- (instancetype)initWithAppKey:(NSString *)appKey NS_SWIFT_NAME(init(appKey:));
+ (instancetype)variablesWithAppKey:(NSString *)appKey NS_SWIFT_NAME(variables(appKey:));

- (void)fetch;
+ (void)fetch;
- (void)fetchWithCompletionBlock:(void (^)(BOOL isSuccessful))completion NS_SWIFT_NAME(fetch(_:));
+ (void)fetchWithCompletionBlock:(void (^)(BOOL isSuccessful))completion NS_SWIFT_NAME(fetch(_:));

- (KarteVariable *)variableForKey:(NSString *)key NS_SWIFT_NAME(variable(forKey:));
+ (KarteVariable *)variableForKey:(NSString *)key NS_SWIFT_NAME(variable(forKey:));

- (void)trackWithVariables:(NSArray *)variables withEventName:(NSString *)eventName NS_SWIFT_NAME(track(variables:eventName:));
- (void)trackWithVariables:(NSArray *)variables withEventName:(NSString *)eventName withValues:(nullable NSDictionary *)values NS_SWIFT_NAME(track(variables:eventName:values:));

+ (void)trackWithVariables:(NSArray *)variables withEventName:(NSString *)eventName NS_SWIFT_NAME(track(variables:eventName:));
+ (void)trackWithVariables:(NSArray *)variables withEventName:(NSString *)eventName withValues:(nullable NSDictionary *)values NS_SWIFT_NAME(track(variables:eventName:values:));

@end

NS_ASSUME_NONNULL_END
