#import "PCKRootListController.h"

@implementation PCKAppearanceSettings

- (UIColor *)tintColor {

    return [UIColor colorWithRed: 0.24 green: 0.70 blue: 0.71 alpha: 1.00];

}

- (UIColor *)statusBarTintColor {

    return [UIColor whiteColor];

}

- (UIColor *)navigationBarTitleColor {

    return [UIColor whiteColor];

}

- (UIColor *)navigationBarTintColor {

    return [UIColor whiteColor];

}

- (UIColor *)tableViewCellSeparatorColor {

    return [UIColor colorWithWhite:0 alpha:0];

}

- (UIColor *)navigationBarBackgroundColor {

    return [UIColor colorWithRed: 0.24 green: 0.70 blue: 0.71 alpha: 1.00];

}

- (BOOL)translucentNavigationBar {

    return YES;

}

@end