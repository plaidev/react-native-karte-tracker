//
//  KarteLogger.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, KarteLogLevel) {
    KarteLogLevelOff = 0,
    KarteLogLevelError = 1 << 0,
    KarteLogLevelWarn = 1 << 1,
    KarteLogLevelInfo = 1 << 2,
    KarteLogLevelDebug = 1 << 3,
    KarteLogLevelVerbose = 1 << 4
};


@interface KarteLogger : NSObject <NSCopying>
@property (class, strong, readonly) KarteLogger *sharedLogger;
@property (nonatomic, assign) KarteLogLevel logLevel;

@end

NS_ASSUME_NONNULL_END
