Readme for Full Support iOS App
===============================

1. Open ***HelpshiftSupportApp.xcodeproj*** in XCode, navigate to ***Full Support*** and click on HSDAppDelegate.m

2. Initialize Helpshift library by calling the method

   ```
      [Helpshift installForApiKey:@"<YOUR_API_KEY>"  domainName:@"<YOUR_COMPANY>.helpshift.com" appID:@"<YOUR_APP_ID>"];
   ```
   inside ***application:didFinishLaunchingWithOptions:*** method (ideally at the top)
   for more information [refer doc](http://developers.helpshift.com/ios/getting-started/#initializing)

3. Refer ***btnSupportClick:*** method in HSDViewController.m to show support screen & decomposed support screen,
   for more information [refer doc](http://developers.helpshift.com/ios/support-tools/#full-support)


![Full Support screenshot](/Screenshot.png)
