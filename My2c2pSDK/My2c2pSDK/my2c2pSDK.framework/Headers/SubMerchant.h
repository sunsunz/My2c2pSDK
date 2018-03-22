//
//  SubMerchant.h
//  my2c2pSDK
//
//  Created by yan feng liu on 9/2/18.
//  Copyright © 2018 2c2p. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - SubMerchant

@interface SubMerchant : NSObject

@property (nonatomic, copy, readonly) NSString *merchantID;
@property (nonatomic, copy, readonly) NSString *uniqueTransactionCode;
@property (nonatomic, copy, readonly) NSString *amount;
@property (nonatomic, assign, readonly) double amountDouble;
@property (nonatomic, copy, readonly) NSString* currencyCode;
@property (nonatomic, copy, readonly) NSString *desc;

@end

#pragma mark - SubMerchantBuilder

@interface SubMerchantBuilder : NSObject {
}

- (SubMerchant *)build;
- (SubMerchantBuilder *)setMerchantID:(NSString *)ID;
- (SubMerchantBuilder *)setUniqueTransactionCode:(NSString *)code;
- (SubMerchantBuilder *)setAmount:(double)amount;
- (SubMerchantBuilder *)setCurrencyCode:(NSString *)currencyCode;
- (SubMerchantBuilder *)setDescription:(NSString *)desc;

@end
