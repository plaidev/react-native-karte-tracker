//
//  KarteTrackerConfig.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KarteTrackerConfigBuilder.h"


@interface KarteTrackerConfig : NSObject
@property (nonatomic, class, strong, readonly, nonnull) KarteTrackerConfig *configure;

@property (nonatomic, copy, readonly, nonnull) NSString *trackEndpoint;
@property (nonatomic, copy, readonly, nonnull) NSString *overlayEndpoint;

@property (nonatomic, assign, readonly, getter=isEnabledTrackingAppLifecycle) BOOL enabledTrackingAppLifecycle NS_SWIFT_NAME(isEnabledTrackingAppLifecycle);
@property (nonatomic, assign, readonly, getter=isEnabledTrackingAppOpen) BOOL enabledTrackingAppOpen NS_SWIFT_NAME(isEnabledTrackingAppOpen);
@property (nonatomic, assign, readonly, getter=isEnabledTrackingIdfa) BOOL enabledTrackingIdfa NS_SWIFT_NAME(isEnabledTrackingIdfa);
@property (nonatomic, assign, readonly, getter=isEnabledTrackingCrashError) BOOL enabledTrackingCrashError NS_SWIFT_NAME(isEnabledTrackingCrashError);
@property (nonatomic, assign, readonly, getter=isEnabledFCMTokenResend) BOOL enabledFCMTokenResend NS_SWIFT_NAME(isEnabledFCMTokenResend);
@property (nonatomic, assign, readonly, getter=isDryRun) BOOL dryRun NS_SWIFT_NAME(isDryRun);

- (nonnull instancetype)initWithConfig:(NSDictionary *)config NS_SWIFT_NAME(init(_:)) __attribute__((deprecated("Use +[KarteTrackerConfig configureWithBuilder:] or -[KarteTrackerConfig initWithBuilder:]")));
- (nonnull instancetype)initWithBuilder:(KarteTrackerConfigBuilder *)builder NS_SWIFT_NAME(init(_:));
+ (nonnull instancetype)configureWithBuilder:(void (^)(KarteTrackerConfigBuilder *_Nonnull builder))closure NS_SWIFT_NAME(configure(_:));

@end
