//
//  KarteTracker.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KarteConstants.h"
#import "KarteLogger.h"
#import "KarteRemoteNotificationHandler.h"
#import "KarteTrackerConfig.h"
#import "KarteTrackerConfigBuilder.h"
#import "KarteTrackerJsUtil.h"
#import "KarteTrackerUtil.h"
#import "KarteVariable.h"
#import "KarteVariables.h"


@protocol KarteTrackerDelegate;
@class KarteTrackerUserProfile;
@class KarteTrackerAppProfile;
@class KarteUIWindow;


@interface KarteTracker : NSObject
@property (nonatomic, class, strong, readonly, nonnull) KarteTracker *sharedTracker;

@property (nonatomic, weak) id<KarteTrackerDelegate> delegate;
@property (nonatomic, copy, readonly) NSString *appKey;
@property (nonatomic, strong, readonly) KarteTrackerConfig *config;
@property (nonatomic, strong, readonly) KarteUIWindow *overlayWindow;
@property (nonatomic, strong, readonly) KarteTrackerUserProfile *userProfile;
@property (nonatomic, strong, readonly) KarteTrackerAppProfile *appProfile;
@property (nonatomic) NSUncaughtExceptionHandler *exceptionHandler;
@property (nonatomic, copy, readonly, nonnull) NSString *visitorId;

+ (nonnull instancetype)sharedTrackerWithAppKey:(nonnull NSString *)appKey NS_SWIFT_NAME(shared(appKey:));
+ (nonnull instancetype)setupWithAppKey:(nonnull NSString *)appKey NS_SWIFT_NAME(setup(appKey:));
+ (nonnull instancetype)setupWithAppKey:(nonnull NSString *)appKey config:(nullable NSDictionary *)config __attribute__((deprecated("Use +[KarteTracker setupWithAppKey:withConfig]")));
+ (nonnull instancetype)setupWithAppKey:(nonnull NSString *)appKey withConfig:(nonnull KarteTrackerConfig *)config NS_SWIFT_NAME(setup(appKey:config:));

- (nonnull instancetype)initWithAppKey:(nonnull NSString *)appKey NS_SWIFT_NAME(init(appKey:));
- (nonnull instancetype)initWithAppKey:(nonnull NSString *)appKey config:(nullable NSDictionary *)config __attribute__((deprecated("Use -[KarteTracker initWithAppKey:withConfig]")));
- (nonnull instancetype)initWithAppKey:(nonnull NSString *)appKey withConfig:(nonnull KarteTrackerConfig *)config NS_SWIFT_NAME(init(appKey:config:));

- (void)track:(nonnull NSString *)eventName values:(nullable NSDictionary *)values;
- (void)trackNotification:(nonnull NSDictionary *)userInfo;
- (void)trackUncaughtException:(nonnull NSDictionary *)values;
- (void)identify:(nonnull NSDictionary *)values;
- (void)view:(nonnull NSString *)viewName;
- (void)view:(nonnull NSString *)viewName title:(nonnull NSString *)title;
- (void)view:(nonnull NSString *)viewName title:(nonnull NSString *)title values:(nullable NSDictionary *)values;
- (void)view:(nonnull NSString *)viewName values:(nullable NSDictionary *)values;
- (void)registerFCMToken:(nonnull NSString *)token;
- (void)flush;
@end

#pragma mark - Delegate
@protocol KarteTrackerDelegate <NSObject>
@required
- (void)karteTracker:(KarteTracker *)tracker receivedResponse:(NSDictionary *)responseBody;
- (void)karteTrackerDidPresentNewPage:(KarteTracker *)tracker;
@end
