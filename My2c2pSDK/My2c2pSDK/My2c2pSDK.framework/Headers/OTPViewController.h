//
//  otpViewController.h
//  2c2pPayment
//
//  Created by 2c2p on 23/1/13.
//  Copyright (c) 2013 comquas. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol OTPViewControllerDelegate <NSObject>
@required
-(void)browserCloseWithURL:(NSString*)urlString RawData:(NSString*)raw AndViewController:(UIViewController*)viewController Error:(NSError *)error;
@end


@class my2c2pLinePay;
@interface OTPViewController : UIViewController <UIWebViewDelegate>
@property (nonatomic,assign) IBOutlet UIWebView* webview;
@property (nonatomic,assign) id<OTPViewControllerDelegate> delegate;
@property (nonatomic,assign) IBOutlet UILabel *loadingLabel;


@property (nonatomic , assign) BOOL masterpass;

@property (nonatomic,strong) UIColor *barButtonTintColor;
@property (nonatomic,strong) UIColor *navTitleColor;

@property (nonatomic, assign) my2c2pLinePay *linepay;

-(id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil AndPrivateKey:(NSString*)filePath Passcode:(NSString*)passcode ProductionMode:(BOOL)mode;
@end
