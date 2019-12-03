//
//  KarteTrackerConfigBuilder.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KarteLogger.h"
#import "KarteIDFADelegate.h"

NS_ASSUME_NONNULL_BEGIN


@interface KarteTrackerConfigBuilder : NSObject
@property (nonatomic, copy) NSString *trackEndpoint;
@property (nonatomic, copy) NSString *overlayEndpoint;

@property (nonatomic, assign, getter=isEnabledTrackingAppLifecycle) BOOL enabledTrackingAppLifecycle;
@property (nonatomic, assign, getter=isEnabledTrackingAppOpen) BOOL enabledTrackingAppOpen;
@property (nonatomic, assign, getter=isEnabledTrackingIdfa) BOOL enabledTrackingIdfa __attribute__((deprecated("Use -[KarteTrackerConfigBuilder IDFADelegate]. since v1.5.5")));
@property (nonatomic, assign, getter=isEnabledTrackingCrashError) BOOL enabledTrackingCrashError;
@property (nonatomic, assign, getter=isEnabledFCMTokenResend) BOOL enabledFCMTokenResend;
@property (nonatomic, assign, getter=isEnabledVisualTracking) BOOL enabledVisualTracking;
@property (nonatomic, assign, getter=isEnabledOptOutDefault) BOOL enabledOptOutDefault;
@property (nonatomic, assign, getter=isDryRun) BOOL dryRun;
@property (nonatomic, weak) id<KarteIDFADelegate> IDFADelegate;
@end

NS_ASSUME_NONNULL_END
