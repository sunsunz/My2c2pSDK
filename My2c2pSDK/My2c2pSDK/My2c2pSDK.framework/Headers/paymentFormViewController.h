//
//  cardInformationViewController.h
//  my2c2pSDK
//
//  Created by 2c2p on 26/11/13.
//  Copyright (c) 2013 2c2p. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PaymentFormViewControllerDelegate <NSObject>

@required
- (void)cardInformationConfirmWithDictionary:(NSDictionary*)dictionary AndViewController:(UIViewController*)controller;
- (void)dismissCardInformationWithController:(UIViewController*)controller;

@end

@protocol PaymentFormViewControllerSourceDelegate <NSObject>

@optional
- (void)paymentFormViewDidLoad;

@end

@interface PaymentFormViewController : UIViewController


@property (nonatomic,strong) id<PaymentFormViewControllerDelegate> delegate;

@property (nonatomic,strong) id<PaymentFormViewControllerSourceDelegate> delegateVC;

@property (nonatomic) BOOL useCustomView;
@property (nonatomic,assign) BOOL productionMode;

@property (nonatomic,strong) UIImage *navBarImage;
@property (nonatomic,strong) UIColor *navBarColor;
@property (nonatomic,strong) UIColor *navButtonTintColor;
@property (nonatomic,strong) UIColor *navTitleColor;

@property (nonatomic,strong) UIImage *navLogo;
@property (nonatomic,strong) NSString *navTitle;


@property (nonatomic,weak) IBOutlet UIButton *confirmbtn;
@property (nonatomic,weak) IBOutlet UIButton *storeCardConfirmbtn;
@property (nonatomic,weak) IBOutlet UIButton *useNewCardBtn;
@property (nonatomic,weak) IBOutlet UIButton *whatIsCvvButton;
@property (nonatomic,weak) IBOutlet UIButton *storeCardWhatIsCvvButton;

- (void) setProductDetails:(NSString *)productDetails;
- (void) setInvoicenumber:(NSString *)invoiecnumber;
- (void) setAmount:(double)amount;
- (void) setEmail:(NSString *)email;
- (void) setName:(NSString *)name;
- (void) setCurrencyCode:(NSString *)currencyCode;

- (void) setAllowStoreCard:(BOOL)allow;
- (void) setStoreCardUniqueId:(NSString*)storeCardUniqueID;
- (void) setMaskedPan:(NSString*)maskedPan;



- (void)showLoadingView;
- (void)hideLoadingView;

- (UINavigationController *)navControllerWithRootViewController:(UIViewController*)vc;

@end
