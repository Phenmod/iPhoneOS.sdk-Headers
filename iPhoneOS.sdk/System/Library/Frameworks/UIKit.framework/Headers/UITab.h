#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UITab.h>)
//
//  UITab.h
//  UIKit
//
//  Copyright © 2024 Apple Inc. All rights reserved.
//

#import <UIKit/UIKitDefines.h>
#import <UIKit/UIViewController.h>
#import <UIKit/UIPopoverPresentationControllerSourceItem.h>
#import <UIKit/UISpringLoadedInteractionSupporting.h>
#import <UIKit/UIAccessibilityIdentification.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

typedef NS_ENUM(NSInteger, UITabPlacement) {
    /// Resolves to `.default` for root-level tabs, and `.optional` for all others.
    UITabPlacementAutomatic     = 0,

    /// The tab can be added or removed from the tab bar, and appears by default.
    UITabPlacementDefault       = 1,
    /// The tab can be added or removed from the tab bar, but does NOT appear by default.
    UITabPlacementOptional      = 2,
    /// The tab cannot be removed from the tab bar, but can be moved within.
    UITabPlacementMovable       = 3,
    /// The tab is always available and visible in the tab bar.
    /// Pinned items are placed at the trailing side of the bar.
    UITabPlacementPinned        = 4,
    /// The tab cannot be moved or removed from the tab bar, and is displayed before
    /// all customizable tabs.
    UITabPlacementFixed         = 5,
    /// The tab cannot be added to the tab bar.
    UITabPlacementSidebarOnly   = 6,
} NS_SWIFT_NAME(UITab.Placement) API_AVAILABLE(ios(18.0), tvos(18.0), visionos(2.0)) API_UNAVAILABLE(watchos);

@class UITab, UITabGroup;
@class UIViewController, UITabBarController;

UIKIT_EXTERN NS_SWIFT_UI_ACTOR
API_AVAILABLE(ios(18.0), tvos(18.0), visionos(2.0)) API_UNAVAILABLE(watchos)
@interface UITab : NSObject

/// The identifier associated with the tab, must be unique across the tab bar controller.
@property (nonatomic, strong, readonly) NSString *identifier;

/// The title of the tab.
@property (nonatomic, copy) NSString *title;

/// The image of the tab. Default is nil.
@property (nonatomic, strong, nullable) UIImage *image;

/// The subtitle of the tab. This is displayed only in certain contexts, like the sidebar. Default is nil.
@property (nonatomic, copy, nullable) NSString *subtitle;

/// The badge value of the tab. Default is nil.
@property (nonatomic, copy, nullable) NSString *badgeValue;

/// The preferred placement for the tab in the contexts that allow for different tab placements.
/// Default is `UITabPlacementAutomatic` which resolves its placement based on context.
@property (nonatomic, assign) UITabPlacement preferredPlacement;

/// A custom object associated with the tab. Default is nil.
@property (nonatomic, strong, nullable) id userInfo;

/// The parent group of the tab. This is only non-nil if the tab is part of a parent group, and returns nil otherwise.
@property (nonatomic, strong, nullable, readonly) UITabGroup *parent;

/// The tab bar controller managing the tab. This is non-nil when the tab
/// or any of its ancestors is added to a UITabBarController; and is nil
/// otherwise.
@property (nonatomic, strong, nullable, readonly) UITabBarController *tabBarController;

/// The view controller owned by the tab. The view controller provider is resolved the first time this is called.
/// For root tabs, the view controller must be non-nil.
@property (nonatomic, strong, nullable, readonly) UIViewController *viewController;

#pragma mark Managed Navigation

/// The managing tab group for the tab. This returns the rootmost `UITabGroup` in the tab's parent hierarchy with an
/// active `managingNavigationController`. This can be different to `parent` if the tab is nested in multiple
/// levels of tab groups. If the tab does not belong to a hierarchy with a managing navigation controller, then this
/// will return nil. Default is nil.
@property (nonatomic, strong, nullable, readonly) UITabGroup *managingTabGroup;

#pragma mark Customization

/// Determines if the tab is currently hidden. Default is NO.
/// Hidden tabs cannot be accessed from the sidebar.
@property (nonatomic, assign, getter=isHidden) BOOL hidden;

/// The default hidden state. When the user resets their customization, `UITab.hidden` will be set to the value
/// of this property. Default is NO.
@property (nonatomic, assign, getter=isHiddenByDefault) BOOL hiddenByDefault;

/// Determines if the tab's visibility can be changed by the user while editing. Default is NO.
@property (nonatomic, assign) BOOL allowsHiding;

/// Creates a tab with the specified identifier, title, image, and view controller provider.
/// The view controller provider will be called once and only once, when the view controller
/// is initially required. For root level tabs on `UITabBarController`, the resolved view
/// controller must be non-nil.
- (instancetype)initWithTitle:(NSString *)title
                        image:(nullable UIImage *)image
                   identifier:(NSString *)identifier
       viewControllerProvider:(UIViewController * (^_Nullable)(__kindof UITab *))viewControllerProvider;


- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

API_AVAILABLE(ios(18.0), visionos(2.0)) API_UNAVAILABLE(tvos, watchos)
@interface UITab (UIPopoverPresentationControllerSourceItem) <UIPopoverPresentationControllerSourceItem>
@end

API_AVAILABLE(ios(18.0), visionos(2.0)) API_UNAVAILABLE(watchos, tvos)
@interface UITab (UISpringLoadedInteractionSupporting) <UISpringLoadedInteractionSupporting>
@end

API_AVAILABLE(ios(18.0), tvos(18.0), visionos(2.0)) API_UNAVAILABLE(watchos)
@interface UITab (UIAccessibility) <UIAccessibilityIdentification>
@end

API_AVAILABLE(ios(18.0), tvos(18.0), visionos(2.0)) API_UNAVAILABLE(watchos)
@interface UIViewController (UITab)

/// The `UITab` instance that was used to create the receiver, and represents the view controller. Default is nil.
@property (nonatomic, weak, nullable, readonly) UITab *tab;

@end

NS_HEADER_AUDIT_END(nullability, sendability)

#else
#import <UIKitCore/UITab.h>
#endif
