//
//  KarteTracker.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KarteConstants.h"
#import "KarteIDFADelegate.h"
#import "KarteInAppMessagingManager.h"
#import "KarteLogger.h"
#import "KarteRemoteNotificationHandler.h"
#import "KarteTrackerConfig.h"
#import "KarteTrackerConfigBuilder.h"
#import "KarteTrackerJsUtil.h"
#import "KarteTrackerUtil.h"
#import "KarteVariable.h"
#import "KarteVariables.h"
#import "KarteUrlSchemeHandler.h"

NS_ASSUME_NONNULL_BEGIN

@protocol KarteTrackerDelegate;
@protocol KarteVisualTrackDelegate;
@class KarteTrackerAppProfile;
@class KarteTrackerUserProfile;


@interface KarteTracker : NSObject
@property (nonatomic, class, strong, readonly) KarteTracker *sharedTracker;

@property (nonatomic, copy, readonly) NSString *appKey;
@property (nonatomic, copy, readonly) NSString *visitorId;
@property (nonatomic, strong, readonly) KarteTrackerConfig *config;

+ (instancetype)sharedTrackerWithAppKey:(NSString *)appKey NS_SWIFT_NAME(shared(appKey:));
+ (instancetype)setupWithAppKey:(NSString *)appKey NS_SWIFT_NAME(setup(appKey:));
+ (instancetype)setupWithAppKey:(NSString *)appKey withConfig:(KarteTrackerConfig *)config NS_SWIFT_NAME(setup(appKey:config:));

- (instancetype)initWithAppKey:(NSString *)appKey NS_SWIFT_NAME(init(appKey:));
- (instancetype)initWithAppKey:(NSString *)appKey withConfig:(KarteTrackerConfig *)config NS_SWIFT_NAME(init(appKey:config:));

- (void)optOut;
- (void)optIn;

@end


@interface KarteTracker (Track)
- (void)track:(NSString *)eventName values:(nullable NSDictionary *)values;
- (void)trackNotification:(NSDictionary *)userInfo;
- (void)trackUncaughtException:(NSDictionary *)values;
- (void)identify:(NSDictionary *)values;
- (void)view:(NSString *)viewName;
- (void)view:(NSString *)viewName title:(NSString *)title;
- (void)view:(NSString *)viewName title:(NSString *)title values:(nullable NSDictionary *)values;
- (void)view:(NSString *)viewName values:(nullable NSDictionary *)values;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
- (void)logoutWithCompletionBlock:(void (^)(BOOL isSuccessful))completion NS_SWIFT_NAME(logout(_:)) __attribute__((deprecated("Use -[KarteTracker renewVisitorId]. since v1.5.3")));
;
#pragma clang diagnostic pop

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
- (void)logout __attribute__((deprecated("Use -[KarteTracker renewVisitorId]. since v1.5.9")));
#pragma clang diagnostic pop

- (void)renewVisitorId;
@end


@interface KarteTracker (FirebaseCloudMessaging)
- (void)registerFCMToken:(NSString *)token;
- (void)handleFCMRemoteMessage:(NSDictionary *)data;
@end

NS_ASSUME_NONNULL_END
