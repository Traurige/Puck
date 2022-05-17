#import "WakeAction.h"

static PuckWakeListener* listener = nil;

@implementation PuckWakeListener

- (void)activator:(LAActivator *)activator receiveEvent:(LAEvent *)event {

	CFNotificationCenterPostNotification(CFNotificationCenterGetDarwinNotifyCenter(), (CFStringRef)PuckActivatorWake, nil, nil, true);

}

@end

%ctor {

    listener = [[PuckWakeListener alloc] init];
	[[LAActivator sharedInstance] registerListener:listener forName:@"love.litten.puck.wakelistener"];

}