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
    callback(@[[NSNull null], appKey]);
}

RCT_EXPORT_METHOD(getVisitorId:(RCTResponseSenderBlock)callback)
{
    NSString *visitorId = [[KarteTracker sharedTracker] visitorId];
    callback(@[[NSNull null], visitorId]);
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

#pragma mark - KarteTrackerJsUtil
RCT_EXPORT_METHOD(appendUserSyncQueryParameter:(NSString *)url callback:(RCTResponseSenderBlock)callback)
{
    NSString *appKey = [[KarteTracker sharedTracker] appKey];
    NSString *newURL = [KarteTrackerJsUtil stringByAppendingUserSyncQueryParameter:appKey withURLString:url];
    callback(@[[NSNull null], newURL]);
}

@end
