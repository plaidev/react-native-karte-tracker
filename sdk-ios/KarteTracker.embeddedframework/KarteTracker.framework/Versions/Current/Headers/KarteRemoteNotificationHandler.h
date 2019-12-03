//
//  KarteRemoteNotificationHandler.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface KarteRemoteNotificationHandler : NSObject
+ (BOOL)handleRemoteNotification:(nullable NSDictionary *)userInfo;
+ (BOOL)canHandleRemoteNotification:(nullable NSDictionary *)userInfo;
+ (nullable NSURL *)retrieveURLFromUserInfo:(nullable NSDictionary *)userInfo NS_SWIFT_NAME(retrieveURL(userInfo:));
@end

NS_ASSUME_NONNULL_END
