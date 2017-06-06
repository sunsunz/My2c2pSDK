//
//  cardInformationViewController.h
//  my2c2pSDK
//
//  Created by Htain Lin Shwe on 26/11/13.
//  Copyright (c) 2013 2c2p. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "My2c2pHeader.h"

@class PKPaymentRequest;

@protocol My2c2pPaymentFormViewControllerDelegate <NSObject>
@optional
- (void)loadChannel:(My2c2pPaymentChannel)channel WithController:(UIViewController *)controller;

///

/**
 Send back payment details

 @param dictionary represent payment infomation
 @param controller self
 */
- (void)cardInformationConfirmWithDictionary:(NSDictionary *)dictionary AndViewController:(UIViewController*)controller;

- (void)dismissCardInformationWithController:(UIViewController *)controller AndError:(NSError *)error;

- (void)dismissCardInformationWithController:(UIViewController *)controller;

- (void)oneTwoThreePaymentDictionary:(NSDictionary *)dictionary AndViewController:(UIViewController *)controller;

- (void)paymentFormDidReceiveMerchantDetail:(NSDictionary *)response;
@end

@protocol My2c2pPaymentFormViewControllerSourceDelegate <NSObject>
@optional
- (void)paymentFormViewDidLoad;
@end

@interface My2c2pPaymentFormViewController : UIViewController
@property (nonatomic,strong) id<My2c2pPaymentFormViewControllerDelegate> delegate;
@property (nonatomic,strong) id<My2c2pPaymentFormViewControllerSourceDelegate> delegateVC;

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

@property (nonatomic, weak) IBOutlet UILabel *labelTitle;
@property (nonatomic, weak) IBOutlet UILabel *labelDetailTitle;
@property (nonatomic, weak) IBOutlet UILabel *labelDetailValue;
@property (nonatomic, weak) IBOutlet UILabel *labelInvoiceTitle;
@property (nonatomic, weak) IBOutlet UILabel *labelInvoiceValue;
@property (nonatomic, weak) IBOutlet UILabel *labelAmountTitle;
@property (nonatomic, weak) IBOutlet UILabel *labelAmountValue;

//@property (nonatomic, assign) BOOL tokenizeWithoutAuthorization;

- (void) setApplePaymentRequest:(PKPaymentRequest *)request;
- (void) setMerchantID:(NSString *)merchantID;
- (void) setAmount:(double)amount;
- (void) setInvoicenumber:(NSString *)invoicenumber;
- (void) setCurrencyCode:(NSString *)currencyCode;
- (void) setInterestType:(NSString *)interestType;
- (void) setPromotion:(NSString *)promotion;
- (void) setAllowIPP:(BOOL)ipp;

- (void) setPaymentOption:(NSString *)paymentOption;
- (void) setRequest3ds:(NSString *)request3ds;
- (void) setStoreCardUniqueId:(NSString *)storeCardUniqueId;
- (void) setRecurring:(BOOL)recurring;
- (void) setInvoicePrefix:(NSString *)invoicePrefix;

- (void) setMWRequest:(id)mwrequest;
- (void) setProductDetails:(NSString *)productDetails;



- (void) setEmail:(NSString *)email;
- (void) setName:(NSString *)name;


- (void) setAllowStoreCard:(BOOL)allow;
- (void) setMaskedPan:(NSString*)maskedPan;

- (void)setTokenizeWithoutAuthorization:(BOOL)tokenizeWithoutAuthorization;

- (void)showLoadingView;
- (void)hideLoadingView;

- (BOOL)isAutoRedirectImmediate;

- (UINavigationController *)navControllerWithRootViewController:(UIViewController*)vc;

@end
