#import <UIKit/UIKit.h>
#import <dlfcn.h>
#import <Cephei/HBPreferences.h>

#define SYSTEM_VERSION_LESS_THAN(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)

HBPreferences* preferences = nil;

BOOL enabled = NO;

BOOL isPuckActive = NO;
BOOL recentlyWoke = NO;
BOOL recentlyWarned = NO;
BOOL isInCall = NO;
NSTimer* timer = nil;
int volumeUpPresses = 0;
BOOL deviceHasFlashlight = NO;
BOOL flashLightAvailable = NO;
int previousLowPowerModeState = 0;

// behavior
NSString* shutdownPercentageValue = @"7";
NSString* wakePercentageValue = @"10";
BOOL wakeWithVolumeButtonSwitch = YES;
BOOL wakeWhenPluggedInSwitch = YES;
BOOL toggleWarningSwitch = NO;

// warning notification
BOOL warningNotificationSwitch = YES;
NSString* warningPercentageValue = @"10";
BOOL hideLowPowerAlertSwitch = YES;

// airplane
BOOL toggleAirplaneModeSwitch = YES;

// apps
BOOL killAllAppsSwitch = YES;
BOOL ignoreNowPlayingAppSwitch = NO;

// music
BOOL allowMusicPlaybackSwitch = YES;
BOOL allowVolumeChangesSwitch = YES;

// calls
BOOL allowCallsSwitch = YES;
BOOL shutdownAfterCallEndedSwitch = YES;

// alarms
BOOL wakeWhenAlarmFiresSwitch = YES;

// flashlight
BOOL turnFlashlightOffSwitch = YES;

// other gestures
BOOL toggleFlashlightSwitch = NO;
BOOL playPauseMediaSwitch = NO;

@interface SpringBoard : UIApplication
- (void)_simulateLockButtonPress;
- (void)_simulateHomeButtonPress;
- (void)receivePuckNotification:(NSNotification *)notification;
- (void)puckShutdown;
- (void)puckWake;
- (void)puckLightWake;
@end

@interface SBAirplaneModeController : NSObject
+ (id)sharedInstance;
- (void)setInAirplaneMode:(BOOL)arg1;
@end

@interface _CDBatterySaver : NSObject
+ (id)sharedInstance;
- (long long)getPowerMode;
- (BOOL)setPowerMode:(long long)arg1 error:(id *)arg2;
@end

@interface DNDModeAssertionService : NSObject
+ (id)serviceForClientIdentifier:(id)arg1;
- (id)takeModeAssertionWithDetails:(id)arg1 error:(id *)arg2;
- (BOOL)invalidateAllActiveModeAssertionsWithError:(id *)arg1;
@end

@interface DNDModeAssertionDetails : NSObject
+ (id)userRequestedAssertionDetailsWithIdentifier:(id)arg1 modeIdentifier:(id)arg2 lifetime:(id)arg3;
@end

@interface SBDisplayItem : NSObject
@property(nonatomic, copy, readonly)NSString* bundleIdentifier;
@end

@interface SBMainSwitcherViewController : UIViewController
+ (id)sharedInstance;
- (id)recentAppLayouts;
- (void)_deleteAppLayout:(id)arg1 forReason:(long long)arg2;
- (void)_deleteAppLayoutsMatchingBundleIdentifier:(id)arg1;
@end

@interface SBAppLayout : NSObject
- (id)allItems;
- (BOOL)containsItemWithBundleIdentifier:(id)arg1;
@end

@interface AVFlashlight : NSObject
- (float)flashlightLevel;
- (BOOL)setFlashlightLevel:(float)arg1 withError:(id *)arg2;
@end

@interface SBApplication : NSObject
@property(nonatomic, readonly)NSString* bundleIdentifier;
@end

@interface SBMediaController : NSObject
+ (id)sharedInstance;
- (BOOL)togglePlayPauseForEventSource:(long long)arg1;
- (SBApplication *)nowPlayingApplication;
@end

@interface SBUIController : NSObject
+ (id)sharedInstance;
- (int)batteryCapacityAsPercentage;
- (BOOL)isOnAC;
@end

@interface NSTask : NSObject
@property(copy)NSArray* arguments;
@property(copy)NSString* launchPath;
- (void)launch;
@end

@interface BBAction : NSObject
+ (id)actionWithLaunchBundleID:(id)arg1 callblock:(id)arg2;
@end

@interface BBBulletin : NSObject
@property(nonatomic, copy)NSString* sectionID;
@property(nonatomic, copy)NSString* recordID;
@property(nonatomic, copy)NSString* publisherBulletinID;
@property(nonatomic, copy)NSString* title;
@property(nonatomic, copy)NSString* message;
@property(nonatomic, retain)NSDate* date;
@property(assign, nonatomic)BOOL clearable;
@property(nonatomic)BOOL showsMessagePreview;
@property(nonatomic, copy)BBAction* defaultAction;
@property(nonatomic, copy)NSString* bulletinID;
@property(nonatomic, retain)NSDate* lastInterruptDate;
@property(nonatomic, retain)NSDate* publicationDate;
@end

@interface BBServer : NSObject
- (void)publishBulletin:(BBBulletin *)arg1 destinations:(NSUInteger)arg2 alwaysToLockScreen:(BOOL)arg3;
- (void)publishBulletin:(id)arg1 destinations:(unsigned long long)arg2;
@end

@interface BBObserver : NSObject
@end

@interface NCBulletinNotificationSource : NSObject
- (BBObserver *)observer;
@end

@interface SBNCNotificationDispatcher : NSObject
- (NCBulletinNotificationSource *)notificationSource;
@end