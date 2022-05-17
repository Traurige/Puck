#import "ShutdownAction.h"

static PuckShutdownListener* listener = nil;

@implementation PuckShutdownListener

- (void)activator:(LAActivator *)activator receiveEvent:(LAEvent *)event {

	CFNotificationCenterPostNotification(CFNotificationCenterGetDarwinNotifyCenter(), (CFStringRef)PuckActivatorShutdown, nil, nil, true);

}

@end

%ctor {

    listener = [[PuckShutdownListener alloc] init];
	[[LAActivator sharedInstance] registerListener:listener forName:@"love.litten.puck.shutdownlistener"];

}