//
//  ViewController.m
//  My2C2PSDK
//
//  Created by Chatchawal Saesee on 5/16/2560 BE.
//  Copyright © 2560 2C2P. All rights reserved.
//

#import "ViewController.h"
#import "PrefixHeader.pch"

#define RAND_FROM_TO(min, max) (min + arc4random_uniform(max - min + 1))

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.my2c2pSDK = [[My2c2pSDK alloc] initWithPrivateKey:PRIVATE_KEY];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (NSString *)randomUniqueTransactionCode {
    return [NSString stringWithFormat:@"%@%d",[NSString stringWithFormat:@"%d", (int)roundf([[NSDate date] timeIntervalSince1970])],RAND_FROM_TO(0,9)];
}
- (IBAction)sampleButtonPressed:(id)sender {
    
    self.my2c2pSDK.merchantID = @"JT04";
    self.my2c2pSDK.currencyCode = @"764";
    self.my2c2pSDK.secretKey = @"QnmrnH6QE23N";
    self.my2c2pSDK.productionMode = NO;
    self.my2c2pSDK.uniqueTransactionCode = [self randomUniqueTransactionCode];
    self.my2c2pSDK.desc = @"example description";
    self.my2c2pSDK.paymentUI = true;
    self.my2c2pSDK.amount = 199.00;
    
    [self.my2c2pSDK requestWithTarget:self onResponse:^(NSDictionary *response) {
        if([response[@"respCode"] isEqualToString:@"00"]) {
            NSLog(@"Payment Success");
        } else {
            NSLog(@"Fail reason: %@", response[@"failReason"]);
        }
    } onFail:^(NSError *error) {
        NSLog(@"Error: %@", error.localizedDescription);
    }];
}
- (IBAction)tokenizeButtonPressed:(id)sender {
    
    self.my2c2pSDK.version                      = 9.1;
    self.my2c2pSDK.merchantID                   = @"JT01";
    self.my2c2pSDK.pan                          = @"5105105105105100";
    self.my2c2pSDK.cardExpireMonth              = 12;
    self.my2c2pSDK.cardExpireYear               = 2019;
    self.my2c2pSDK.cardHolderName               = @"Mr.Sample";
    self.my2c2pSDK.panBank                      = @"2c2p Bank";
    self.my2c2pSDK.secretKey                    = @"123456";
    self.my2c2pSDK.tokenizeWithoutAuthorization = NO;
    
    // Optional
    self.my2c2pSDK.paymentUI                    = NO;
    self.my2c2pSDK.cardHolderEmail              = @"user@domain.com";

    [self.my2c2pSDK requestWithTarget:self onResponse:^(NSDictionary *response) {
        if([response[@"respCode"] isEqualToString:@"00"]) {
            NSLog(@"Payment Success");
        } else {
            NSLog(@"Fail reason: %@", response[@"failReason"]);
        }
    } onFail:^(NSError *error) {
        NSLog(@"Error: %@", error.localizedDescription);
    }];
}



@end
