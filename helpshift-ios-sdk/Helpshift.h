/*
 *    Helpshift.h
 *    SDK version 4.0.0
 *
 *    Get the documentation at http://www.helpshift.com/docs
 *
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * This document describes the API exposed by the Helpshift SDK (4.x) which the developers can use to integrate Helpshift support into their iOS applications. If you want documentation regarding how to use the various features provided by the Helpshift SDK, please visit the [developer docs](http://developers.helpshift.com/)
 */

typedef NSDictionary * (^metadataBlock)(void);


// A Reserved key (HSTagsKey) constant to be used with metadataBlock (of type NSDictionary) to pass NSArray (of type only NSStrings)
// which get interpreted at server and added as Tags for the issue being reported.
// If an object in NSArray is not of type NSString then the object will be removed from Tags and will not be added for the issue.
//
// Available in SDK version 3.2.0 or later
// Example usage
//    [Helpshift metadataWithBlock:^(void){
//        return [NSDictionary dictionaryWithObjectsAndKeys:[NSArray arrayWithObjects:@"feedback", @"paid user",nil], HSTagsKey, nil];
//    }];
extern NSString *const HSTagsKey;

@protocol HelpshiftDelegate;
@interface Helpshift : NSObject <UIAlertViewDelegate>
{
    id <HelpshiftDelegate> delegate;
}

@property (nonatomic,retain) id<HelpshiftDelegate> delegate;

/** Initialize helpshift support
 *
 * When initializing Helpshift you must pass these three tokens. You initialize Helpshift by adding the following lines in the implementation file for your app delegate, ideally at the top of application:didFinishLaunchingWithOptions. If you use this api to initialize helpshift support, in-app notifications will be enabled by default.
 * In-app notifications are banner like notifications shown by the Helpshift SDK to alert the user of any updates to the reported issues.
 * If you want to disable the in-app notifications please refer to the installForAppID:domainName:apiKey:withOptions: api
 *
 *  @param apiKey This is your developer API Key
 *  @param domainName This is your domain name without any http:// or forward slashes
 *  @param appID This is the unique ID assigned to your app
 *
 *  @available Available in SDK version 4.0.0 or later
 */
+ (void) installForApiKey:(NSString *)apiKey domainName:(NSString *)domainName appID:(NSString *)appID;

/** Initialize helpshift support
 *
 * When initializing Helpshift you must pass these three tokens. You initialize Helpshift by adding the following lines in the implementation file for your app delegate, ideally at the top of application:didFinishLaunchingWithOptions
 *
 * @param apiKey This is your developer API Key
 * @param domainName This is your domain name without any http:// or forward slashes
 * @param appID This is the unique ID assigned to your app
 * @param withOptions This is the dictionary which contains additional configuration options for the HelpshiftSDK. Currently we support the "enableInAppNotification" as the only available option. Possible values are <"YES"/"NO">. If you set the flag to "YES", the helpshift SDK will show notifications similar to the banner notifications supported by Apple Push notifications. These notifications will alert the user of any updates to reported issues. If you set the flag to "NO", the in-app notifications will be disabled.
 *
 * @available Available in SDK version 4.0.0 or later
 */

+ (void) installForApiKey:(NSString *)apiKey domainName:(NSString *)domainName appID:(NSString *)appID withOptions:(NSDictionary *)optionsDictionary;

/** Returns an instance of Helpshift
 *
 * When calling any Helpshift instance method you must use sharedInstance. For example to call showSupport: you must call it like [[Helpshift sharedInstance] showSupport:self];
 *
 * @available Available in SDK version 1.0.0 or later
 */
+ (Helpshift *) sharedInstance;

/** Show the helpshift conversation screen (with Optional Arguments)
 *
 * To show the Helpshift conversation screen with optional arguments you will need to pass the name of the viewcontroller on which the conversation screen will show up and an options dictionary. If you do not want to pass any options then just pass nil which will take on the default options.
 *
 * @param viewController viewController on which the helpshift report issue screen will show up.
 * @param optionsDictionary the dictionary which will contain the arguments passed to the Helpshift conversation session (that will start with this method call).
 *
 * Please check the docs for available options.
 *
 * @available Available in SDK version 4.0.0 or later
 */
- (void) showConversation:(UIViewController *)viewController withOptions:(NSDictionary *)optionsDictionary;

/** Show the support screen with only the faqs (with Optional Arguments)
 *
 * To show the Helpshift screen with only the faq sections with search with optional arguments, you can use this api. This screen will not show the issues reported by the user. If you do not want to pass any options then just pass nil which will take on the default options.
 *
 * @param viewController viewController on which the helpshift faqs screen will show up.
 * @param optionsDictionary the dictionary which will contain the arguments passed to the Helpshift faqs screen session (that will start with this method call).
 *
 * Please check the docs for available options.
 *
 * @available Available in SDK version 2.0.0 or later
 */

- (void) showFAQs:(UIViewController *)viewController withOptions:(NSDictionary *)optionsDictionary;

/** Show the helpshift screen with faqs from a particular section
 *
 * To show the Helpshift screen for showing a particular faq section you need to pass the publish-id of the faq section and the name of the viewcontroller on which the faq section screen will show up. For example from inside a viewcontroller you can call the Helpshift faq section screen by passing the argument “self” for the viewController parameter. If you do not want to pass any options then just pass nil which will take on the default options.
 *
 * @param faqSectionPublishID the publish id associated with the faq section which is shown in the FAQ page on the admin side (__yourcompanyname__.helpshift.com/admin/faq/).
 * @param viewController viewController on which the helpshift faq section screen will show up.
 * @param optionsDictionary the dictionary which will contain the arguments passed to the Helpshift session (that will start with this method call).
 *
 * @available Available in SDK version 2.0.0 or later
 */

- (void) showFAQSection:(NSString *)faqSectionPublishID withController:(UIViewController *)viewController withOptions:(NSDictionary *)optionsDictionary;

/** Show the helpshift screen with a single faq
 *
 * To show the Helpshift screen for showing a single faq you need to pass the publish-id of the faq and the name of the viewcontroller on which the faq screen will show up. For example from inside a viewcontroller you can call the Helpshift faq section screen by passing the argument “self” for the viewController parameter. If you do not want to pass any options then just pass nil which will take on the default options.
 *
 * @param faqPublishID the publish id associated with the faq which is shown when you expand a single FAQ (__yourcompanyname__.helpshift.com/admin/faq/)
 * @param viewController viewController on which the helpshift faq section screen will show up.
 * @param optionsDictionary the dictionary which will contain the arguments passed to the Helpshift session (that will start with this method call).
 *
 * @available Available in SDK version 4.0.0 or later
 */

- (void) showSingleFAQ:(NSString *)faqPublishID withController:(UIViewController *)viewController withOptions:(NSDictionary *)optionsDictionary;

/** Set an user identifier for your users.
 *
 * This is part of additional user configuration. The user identifier will be passed through to the admin dashboard as "User ID" under customer info.
 *  @param userIdentifier A string to identify your users.
 *
 *  @available Available in SDK version 1.0.0 or later
 */

+ (void) setUserIdentifier:(NSString *)userIdentifier;

/** Set the name and email of the application user.
 *
 * This is part of additional user configuration. If this is provided through the api, user will not be prompted to re-enter this information again.
 *
 *   @param name The name of the user.
 *   @param email The email address of the user.
 *
 *   @available Available in SDK version 4.0.0 or later
 */

+ (void) setName:(NSString *)name andEmail:(NSString *)email;

/** Add extra debug information regarding user-actions.
 *
 * You can add additional debugging statements to your code, and see exactly what the user was doing right before they reported the issue.
 *
 *  @param breadCrumbString The string containing any relevant debugging information.
 *
 *  @available Available in SDK version 1.0.0 or later
 */

+ (void) leaveBreadCrumb:(NSString *)breadCrumbString;

/** Provide a block which returns a dictionary for custom meta data to be attached along with reported issues
 *
 * If you want to attach custom data along with any reported issues, use this api to provide a block which accepts zero arguments and returns an NSDictionary containing the meta data key-value pairs. Everytime an issue is reported, the SDK will call this block and attach the returned meta data dictionary along with the reported issue. Ideally this metaDataBlock should be provided before the user can file an issue.
 *
 *  @param metadataBlock a block variable which accepts zero arguments and returns an NSDictionary.
 *
 *  @available Available in SDK version 4.0.0 or later
 */

+ (void) setMetadataBlock:(metadataBlock)metadataBlock;

/** Get the notification count for replies to reported issues.
 *
 *
 * If you want to show your user notifications for replies on the issues posted, you can get the notification count asynchronously by implementing the HelpshiftDelegate in your respective .h and .m files.
 * Use the following method to set the delegate, where self is the object implementing the delegate.
 * [[Helpshift sharedInstance] setDelegate:self];
 * Now you can call the method
 * [[Helpshift sharedInstance] getNotificationCountFromRemote:YES];
 * This will return a notification count in the
 * - (void) didReceiveNotificationCount:(NSInteger)count
 * count delegate method.
 * If you want to retrieve the current notification count synchronously, you can call the same method with the parameter set to false, i.e
 * NSInteger count = [[Helpshift sharedInstance] getNotificationCountFromRemote:NO]
 *
 * @param isRemote Whether the notification count is to be returned asynchronously via delegate mechanism or synchronously as a return val for this api
 *
 * @available Available in SDK version 4.0.0 or later
 */

- (NSInteger) getNotificationCountFromRemote:(BOOL)isRemote;

/** Register the deviceToken to enable push notifications
 *
 *
 * To enable push notifications in the Helpshift iOS SDK, set the Push Notifications’ deviceToken using this method inside your application:didRegisterForRemoteNotificationsWithDeviceToken application delegate.
 *
 *  @param deviceToken The deviceToken received from the push notification servers.
 *
 * Example usage
 *  - (void) application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:
 *              (NSData *)deviceToken
 *  {
 *      [[Helpshift sharedInstance] registerDeviceToken:deviceToken];
 *  }
 *
 *  @available Available in SDK version 1.4.0 or later
 *
 */
- (void) registerDeviceToken:(NSData *)deviceToken;

/** Forward the push notification for the Helpshift lib to handle
 *
 *
 * To show support on Notification opened, call handleRemoteNotification in your application:didReceiveRemoteNotification application delegate.
 * If the value of the “origin” field is “helpshift” call the handleRemoteNotification api
 *
 *  @param notification The dictionary containing the notification information
 *  @param viewController ViewController on which the helpshift support screen will show up.
 *
 * Example usage
 *  - (void) application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
 *  {
 *      if ([[userInfo objectForKey:@"origin"] isEqualToString:@"helpshift"]) {
 *          [[Helpshift sharedInstance] handleRemoteNotification:userInfo withController:self.viewController];
 *      }
 *  }
 *
 *  @available Available in SDK version 4.0.0 or later
 *
 */
- (void) handleRemoteNotification:(NSDictionary *)notification withController:(UIViewController *)viewController;

/** Forward the local notification for the Helpshift lib to handle
 *
 *
 * To show support on Notification opened, call handleLocalNotification in your application:didReceiveLocalNotification application delegate.
 * If the value of the “origin” field is “helpshift” call the handleLocalNotification api
 *
 * @param notification The UILocalNotification object containing the notification information
 * @param viewController ViewController on which the helpshift support screen will show up.
 *
 * Example usage
 *  - (void) application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
 *  {
 *      if ([[notification.userInfo objectForKey:@"origin"] isEqualToString:@"helpshift"])
 *      [[Helpshift sharedInstance] handleLocalNotification:notification withController:self.viewController];
 *  }
 *
 * @available Available in SDK version 2.4.0 or later
 *
 */

- (void) handleLocalNotification:(UILocalNotification *)notification withController:(UIViewController *)viewController;

/** Clears Breadcrumbs list.
 *
 * Breadcrumbs list stores upto 100 latest actions. You'll receive those in every Issue.
 * If for some reason you want to clear previous messages, you can use this method.
 *
 * @available Available in SDK version 2.3.0 or later
 *
 */
- (void) clearBreadCrumbs;

@end

@protocol HelpshiftDelegate <NSObject>

/** Delegate method call that should be implemented if you are calling getNotificationCountFromRemote:YES
 * @param count Returns the number of issues with unread messages.
 *
 * @available Available in SDK version 4.0.0 or later
 */

- (void) didReceiveNotificationCount:(NSInteger)count;

/** Optional delegate method that is called when the Helpshift session ends.
 *
 *
 * Helpshift session is any Helpshift support screen opened via showSupport: or other API calls.
 * Whenever the user closes that support screen and returns back to the app this method is invoked.
 *
 *  @available Available in SDK version 1.4.3 or later
 */
@optional
- (void) helpshiftSessionHasEnded;

@end
