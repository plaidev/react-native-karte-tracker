//
//  KarteTrackerJsUtil.h
//  Pods
//
//  Created by 中間亮彬 on 2018/05/20.
//

#import <Foundation/Foundation.h>


@interface KarteTrackerJsUtil : NSObject
+ (nonnull NSString *)stringByAppendingUserSyncQueryParameter:(nonnull NSString *)appKey withURLString:(nonnull NSString *)url NS_SWIFT_NAME(stringByAppendingUserSyncQueryParameter(appKey:url:));
+ (nonnull NSURL *)URLByAppendingUserSyncQueryParameter:(nonnull NSString *)appKey withURL:(nonnull NSURL *)url NS_SWIFT_NAME(URLByAppendingUserSyncQueryParameter(appKey:url:));
+ (nullable NSString *)userSyncQueryParameter:(nonnull NSString *)appKey;
@end
