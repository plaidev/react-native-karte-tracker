//
//  RNKarteTrackerModule.m
//  react-native-karte-tracker
//
//  Created by tomoki.koga on 2018/12/03.
//

#import "RNKarteTrackerModule.h"

#import <KarteTracker/KarteTracker.h>

@interface KarteVariable ()
@property (nonatomic, copy, nullable, readwrite) NSString *campaignId;
@property (nonatomic, copy, nullable, readwrite) NSString *shortenId;
@end

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

#pragma mark - KarteVariables
RCT_EXPORT_METHOD(fetch:(RCTResponseSenderBlock)callback)
{
    [KarteVariables fetchWithCompletionBlock:^(BOOL isSuccessful) {
        callback(@[@(isSuccessful)]);
    }];
}

RCT_EXPORT_METHOD(variable:(NSString *)key callback:(RCTResponseSenderBlock)callback)
{
    KarteVariable *variable = [KarteVariables variableForKey:key];
    
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    [dict setObject:key forKey:@"key"];
    
    if (variable.campaignId) {
        [dict setObject:variable.campaignId forKey:@"campaign_id"];
    }
    if (variable.shortenId) {
        [dict setObject:variable.shortenId forKey:@"shorten_id"];
    }
    if (variable.string) {
        [dict setObject:variable.string forKey:@"string"];
    }
    
    callback(@[dict]);
}

RCT_EXPORT_METHOD(trackVariables:(NSArray *)vals eventName:(NSString *)eventName values:(NSDictionary *)values)
{
    NSMutableArray *variables = [NSMutableArray array];
    for (NSDictionary *val in vals) {
        KarteVariable *variable = [[KarteVariable alloc] init];
        variable.campaignId = val[@"campaign_id"];
        variable.shortenId = val[@"shorten_id"];
        [variables addObject:variable];
    }
    [KarteVariables trackWithVariables:variables withEventName:eventName withValues:values];
}

#pragma mark - KarteVariable
RCT_EXPORT_METHOD(stringForKey:(NSString *)key defaultValue:(NSString *)defaultValue callback:(RCTResponseSenderBlock)callback)
{
    KarteVariable *variable = [KarteVariables variableForKey:key];
    NSString *value = [variable stringWithDefaultValue:defaultValue];
    
    NSMutableArray *returns = [NSMutableArray array];
    if (value) {
        [returns addObject:value];
    }
    
    callback(returns);
}

RCT_EXPORT_METHOD(integerForKey:(NSString *)key defaultValue:(NSInteger)defaultValue callback:(RCTResponseSenderBlock)callback)
{
    KarteVariable *variable = [KarteVariables variableForKey:key];
    NSInteger value = [variable integerWithDefaultValue:defaultValue];
    callback(@[@(value)]);
}

RCT_EXPORT_METHOD(doubleForKey:(NSString *)key defaultValue:(double)defaultValue callback:(RCTResponseSenderBlock)callback)
{
    KarteVariable *variable = [KarteVariables variableForKey:key];
    double value = [variable doubleWithDefaultValue:defaultValue];
    callback(@[@(value)]);
}

RCT_EXPORT_METHOD(boolForKey:(NSString *)key defaultValue:(BOOL)defaultValue callback:(RCTResponseSenderBlock)callback)
{
    KarteVariable *variable = [KarteVariables variableForKey:key];
    bool value = [variable boolWithDefaultValue:defaultValue];
    callback(@[@(value)]);
}

RCT_EXPORT_METHOD(arrayForKey:(NSString *)key defaultValue:(NSArray *)defaultValue callback:(RCTResponseSenderBlock)callback)
{
    KarteVariable *variable = [KarteVariables variableForKey:key];
    NSArray *value = [variable arrayWithDefaultValue:defaultValue];
    
    NSMutableArray *returns = [NSMutableArray array];
    if (value) {
        [returns addObject:value];
    }
    
    callback(returns);
}

RCT_EXPORT_METHOD(objectForKey:(NSString *)key defaultValue:(NSDictionary *)defaultValue callback:(RCTResponseSenderBlock)callback)
{
    KarteVariable *variable = [KarteVariables variableForKey:key];
    NSDictionary *value = [variable dictionaryWithDefaultValue:defaultValue];
    
    NSMutableArray *returns = [NSMutableArray array];
    if (value) {
        [returns addObject:value];
    }
    
    callback(returns);
}

@end

