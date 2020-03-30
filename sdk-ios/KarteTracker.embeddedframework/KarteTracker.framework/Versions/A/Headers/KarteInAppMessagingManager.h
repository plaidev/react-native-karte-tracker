//
//  KarteInAppMessagingManager.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol KarteInAppMessagingManagerDelegate;


@interface KarteInAppMessagingManager : NSObject
@property (class, nonatomic, strong, readonly) KarteInAppMessagingManager *sharedManager;
@property (nonatomic, assign, readonly, getter=isPresenting) BOOL presenting;
@property (nonatomic, weak) id<KarteInAppMessagingManagerDelegate> delegate;
- (void)dismiss;
- (void)suppress;
- (void)unsuppress;
@end

@protocol KarteInAppMessagingManagerDelegate <NSObject>
@optional
- (BOOL)inAppMessagingManager:(KarteInAppMessagingManager *)manager shouldOpenURL:(nullable NSURL *)url;
@end

NS_ASSUME_NONNULL_END
