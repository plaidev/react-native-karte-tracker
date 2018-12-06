//
//  KarteTrackerConfigBuilder.h
//  KarteTracker
//
//  Created by tomoki.koga on 2018/08/18.
//

#import <Foundation/Foundation.h>

#import "KarteLogger.h"


@interface KarteTrackerConfigBuilder : NSObject
@property (nonatomic, copy, nonnull) NSString *trackEndpoint;
@property (nonatomic, copy, nonnull) NSString *overlayEndpoint;

@property (nonatomic, assign, getter=isEnabledTrackingAppLifecycle) BOOL enabledTrackingAppLifecycle;
@property (nonatomic, assign, getter=isEnabledTrackingAppOpen) BOOL enabledTrackingAppOpen;
@property (nonatomic, assign, getter=isEnabledTrackingIdfa) BOOL enabledTrackingIdfa;
@property (nonatomic, assign, getter=isEnabledTrackingCrashError) BOOL enabledTrackingCrashError;
@property (nonatomic, assign, getter=isEnabledFCMTokenResend) BOOL enabledFCMTokenResend;
@property (nonatomic, assign, getter=isDryRun) BOOL dryRun;
@end
