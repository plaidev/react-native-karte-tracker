//
//  KarteConstants.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - PushNotification
extern NSString *const KarteNotificationKey;
extern NSString *const KarteMassPushNotificationKey;
extern NSString *const KarteCampaignIdKey;
extern NSString *const KarteShortenIdKey;
extern NSString *const KarteMassPushIdKey;

#pragma mark - EventName
extern NSString *const KarteEventMessageOpen;
extern NSString *const KarteEventMessageClose;
extern NSString *const KarteEventMessageClick;

#pragma mark - Notification
extern NSString *const KarteInAppMessagingWillAppear;
extern NSString *const KarteInAppMessagingDidAppear;
extern NSString *const KarteInAppMessagingWillDisappear;
extern NSString *const KarteInAppMessagingDidDisappear;
