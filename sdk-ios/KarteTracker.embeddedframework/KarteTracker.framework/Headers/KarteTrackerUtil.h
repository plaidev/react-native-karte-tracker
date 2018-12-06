//
//  KarteTrackerUtil.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

void KarteTrackerShowLog(BOOL showLog) __attribute__((deprecated("Use -[KarteLogger setLogLevel:]")));
void KarteTrackerLog(NSString *format, ...) __attribute__((deprecated("Use NSLog")));
