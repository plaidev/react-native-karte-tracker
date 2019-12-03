//
//  KarteTrackerConfig.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KarteTrackerConfigBuilder.h"
#import "KarteIDFADelegate.h"

NS_ASSUME_NONNULL_BEGIN


@interface KarteTrackerConfig : NSObject
@property (nonatomic, class, strong, readonly) KarteTrackerConfig *configure;

@property (nonatomic, copy, readonly) NSString *trackEndpoint;
@property (nonatomic, copy, readonly) NSString *overlayEndpoint;

@property (nonatomic, assign, readonly, getter=isEnabledTrackingAppLifecycle) BOOL enabledTrackingAppLifecycle NS_SWIFT_NAME(isEnabledTrackingAppLifecycle);
@property (nonatomic, assign, readonly, getter=isEnabledTrackingAppOpen) BOOL enabledTrackingAppOpen NS_SWIFT_NAME(isEnabledTrackingAppOpen);
@property (nonatomic, assign, readonly, getter=isEnabledTrackingIdfa) BOOL enabledTrackingIdfa NS_SWIFT_NAME(isEnabledTrackingIdfa) __attribute__((deprecated("Use -[KarteTrackerConfig IDFADelegate]. since v1.5.5")));
@property (nonatomic, assign, readonly, getter=isEnabledTrackingCrashError) BOOL enabledTrackingCrashError NS_SWIFT_NAME(isEnabledTrackingCrashError);
@property (nonatomic, assign, readonly, getter=isEnabledFCMTokenResend) BOOL enabledFCMTokenResend NS_SWIFT_NAME(isEnabledFCMTokenResend);
@property (nonatomic, assign, readonly, getter=isEnabledOptOutDefault) BOOL enabledOptOutDefault NS_SWIFT_NAME(isEnabledOptOutDefault);
@property (nonatomic, assign, readonly, getter=isDryRun) BOOL dryRun NS_SWIFT_NAME(isDryRun);
@property (nonatomic, assign, readonly, getter=isEnabledVisualTracking) BOOL enabledVisualTracking NS_SWIFT_NAME(isEnabledVisualTracking);
@property (nonatomic, weak, readonly) id<KarteIDFADelegate> IDFADelegate;

- (instancetype)initWithBuilder:(KarteTrackerConfigBuilder *)builder NS_SWIFT_NAME(init(_:));
+ (instancetype)configureWithBuilder:(void (^)(KarteTrackerConfigBuilder *builder))closure NS_SWIFT_NAME(configure(_:));

@end

NS_ASSUME_NONNULL_END
