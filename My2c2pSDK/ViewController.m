//
//  ViewController.m
//  My2C2PSDK
//
//  Created by Chatchawal Saesee on 5/16/2560 BE.
//  Copyright © 2560 2C2P. All rights reserved.
//

#import "ViewController.h"
#import "PrefixHeader.pch"
#import "My2c2pSDK/My2c2pSDK.h"

#define RAND_FROM_TO(min, max) (min + arc4random_uniform(max - min + 1))

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (NSString *)randomUniqueTransactionCode {
    return [NSString stringWithFormat:@"%@%d",[NSString stringWithFormat:@"%d", (int)roundf([[NSDate date] timeIntervalSince1970])],RAND_FROM_TO(0,9)];
}

- (IBAction)paymentButtonPressed:(id)sender {
    
    My2c2pSDK *my2c2pSDK = [[My2c2pSDK alloc] initWithPrivateKey:PRIVATE_KEY];
    my2c2pSDK.merchantID = @"JT04";
    my2c2pSDK.currencyCode = @"764";
    my2c2pSDK.secretKey = @"QnmrnH6QE23N";
    my2c2pSDK.productionMode = NO;
    my2c2pSDK.uniqueTransactionCode = [self randomUniqueTransactionCode];
    my2c2pSDK.desc = @"example description";
    my2c2pSDK.amount = 199.00;
    
    [my2c2pSDK requestWithTarget:self onResponse:^(NSDictionary *response) {
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
