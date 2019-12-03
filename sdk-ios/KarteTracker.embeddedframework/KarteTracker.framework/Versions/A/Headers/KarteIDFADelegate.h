//
//  KarteIDFADelegate.h
//  KarteTracker
//
//  Copyright (c) 2019 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol KarteIDFADelegate <NSObject>
- (nullable NSString *)advertisingIdentifierString;
- (BOOL)isAdvertisingTrackingEnabled;
@end

NS_ASSUME_NONNULL_END
