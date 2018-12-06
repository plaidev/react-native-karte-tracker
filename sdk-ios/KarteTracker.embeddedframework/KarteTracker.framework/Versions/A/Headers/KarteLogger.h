//
//  KarteLogger.h
//  KarteTracker
//
//  Created by tomoki.koga on 2018/08/23.
//

typedef NS_ENUM(NSUInteger, KarteLogLevel) {
    KarteLogLevelOff = 0,
    KarteLogLevelError = 1 << 0,
    KarteLogLevelWarn = 1 << 1,
    KarteLogLevelInfo = 1 << 2,
    KarteLogLevelDebug = 1 << 3,
    KarteLogLevelVerbose = 1 << 4
};


@interface KarteLogger : NSObject <NSCopying>
@property (class, strong, readonly, nonnull) KarteLogger *sharedLogger;
@property (nonatomic, assign) KarteLogLevel logLevel;

@end
