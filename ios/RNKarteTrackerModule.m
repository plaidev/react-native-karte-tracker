//
//  RNKarteTrackerModule.m
//  react-native-karte-tracker
//
//  Created by tomoki.koga on 2018/12/03.
//

#import "RNKarteTrackerModule.h"

#import <KarteTracker/KarteTracker.h>

@implementation RNKarteTrackerModule

RCT_EXPORT_MODULE()

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}

#pragma mark - KarteTracker
RCT_EXPORT_METHOD(getAppKey:(RCTResponseSenderBlock)callback)
{
    NSString *appKey = [[KarteTracker sharedTracker] appKey];
    callback(@[appKey]);
}

RCT_EXPORT_METHOD(getVisitorId:(RCTResponseSenderBlock)callback)
{
    NSString *visitorId = [[KarteTracker sharedTracker] visitorId];
    callback(@[visitorId]);
}

RCT_EXPORT_METHOD(track:(NSString *)eventName values:(NSDictionary *)values)
{
    [[KarteTracker sharedTracker] track:eventName values:values];
}

RCT_EXPORT_METHOD(identify:(NSDictionary *)values)
{
    [[KarteTracker sharedTracker] identify:values];
}

RCT_EXPORT_METHOD(view:(NSString *)viewName title:(NSString *)title values:(NSDictionary *)values)
{
    [[KarteTracker sharedTracker] view:viewName title:title values:values];
}

RCT_EXPORT_METHOD(registerFCMToken:(NSString *)fcmToken)
{
    [[KarteTracker sharedTracker] registerFCMToken:fcmToken];
}

RCT_EXPORT_METHOD(optIn)
{
    [[KarteTracker sharedTracker] optIn];
}

RCT_EXPORT_METHOD(optOut)
{
    [[KarteTracker sharedTracker] optOut];
}

RCT_EXPORT_METHOD(renewVisitorId)
{
    [[KarteTracker sharedTracker] renewVisitorId];
}

#pragma mark - KarteTrackerJsUtil
RCT_EXPORT_METHOD(appendUserSyncQueryParameter:(NSString *)url callback:(RCTResponseSenderBlock)callback)
{
    NSString *appKey = [[KarteTracker sharedTracker] appKey];
    NSString *newURL = [KarteTrackerJsUtil stringByAppendingUserSyncQueryParameter:appKey withURLString:url];
    callback(@[newURL]);
}

#pragma mark - KarteInAppMessagingManager
RCT_EXPORT_METHOD(isPresenting:(RCTResponseSenderBlock)callback)
{
    BOOL isPresenting = [[KarteInAppMessagingManager sharedManager] isPresenting];
    callback(@[@(isPresenting)]);
}

RCT_EXPORT_METHOD(dismiss)
{
    [[KarteInAppMessagingManager sharedManager] dismiss];
}

RCT_EXPORT_METHOD(suppress)
{
    [[KarteInAppMessagingManager sharedManager] suppress];
}

RCT_EXPORT_METHOD(unsuppress)
{
    [[KarteInAppMessagingManager sharedManager] unsuppress];
}

@end

