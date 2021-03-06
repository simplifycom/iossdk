#import <UIKit/UIKit.h>
#import <PassKit/PassKit.h>
#import "SIMCreditCardToken.h"
#import "SIM3DSecureRequestData.h"

/**
 Public Protocol for communicating success or failure of the token generation after the user completes data entry.
 */

@protocol SIMChargeCardViewControllerDelegate

/**
 Token cancel Callback. The User has elected to cancel the token generation workflow.
 */
-(void)chargeCardCancelled;

/**
 Token failure Callback. If token generation fails, this will be called back and an error will be provided with a localizedDescription and code.
 */
-(void)creditCardTokenFailedWithError:(NSError *)error;

/**
 Token success Callback. If token generation succeeds, this will be called back and the fully hydrated credit card token.
 */
-(void)creditCardTokenProcessed:(SIMCreditCardToken *)token;

@end

/**
 This is the turn key solution. Simply create a SIMChargeCardViewController, signup as a SIMChargeCardViewControllerDelegate and implement the callbacks. All card input validation and token creation is handled for you. You simply present the UIViewController subclass and wait for for the token.
 */

@interface SIMChargeCardViewController : UIViewController

-(instancetype)initWithPublicKey:(NSString *)publicKey;
-(instancetype)initWithPublicKey:(NSString *)publicKey primaryColor:(UIColor *)primaryColor;

/**
 See Apple's documentation at: https://developer.apple.com/library/ios/ApplePay_Guide/CreateRequest.html
 for more infromation on creating a PKPaymentRequest
 */

-(instancetype)initWithPublicKey:(NSString *)publicKey paymentRequest:(PKPaymentRequest *)paymentRequest;

/**
 See Apple's documentation at: https://developer.apple.com/library/ios/ApplePay_Guide/CreateRequest.html
 for more infromation on creating a PKPaymentRequest
 */
-(instancetype)initWithPublicKey:(NSString *)publicKey paymentRequest:(PKPaymentRequest *)paymentRequest primaryColor:(UIColor *)primaryColor;

/**
 To use 3DS 1.0 with SIMChargeCardViewController you will need to pass in a SIM3DSecureRequestData
*/
-(instancetype)initWithPublicKey:(NSString *)publicKey threeDSecureRequest:(SIM3DSecureRequestData *)threeDSRequest;
-(instancetype)initWithPublicKey:(NSString *)publicKey threeDSecureRequest:(SIM3DSecureRequestData *)threeDSRequest primaryColor:(UIColor *)primaryColor;

/**
 Delegate for SIMChargeCardModelDelegate
 */
@property (nonatomic, weak) id <SIMChargeCardViewControllerDelegate> delegate;

/**
 Amount to charge
 */
@property (nonatomic, strong) NSDecimalNumber *amount;

/**
 The title for the header
 */
@property (nonatomic, strong) NSString *headerTitle;


/**
 The title color for the header
 */
@property (nonatomic, strong) UIColor *headerTitleColor;

/**
 The color for the header
 */
@property (nonatomic, strong) UIColor *headerViewBackgroundColor;

/**
 Title for the payment button when charging is possible with the entered data
 */
@property (nonatomic, strong) NSString *paymentButtonNormalTitle;

/**
 Title for the payment button when charging is not possible with the entered data
 */
@property (nonatomic, strong) NSString *paymentButtonDisabledTitle;

/**
 Background color for the payment button when charging is possible with the entered data
 */
@property (nonatomic, strong) UIColor *paymentButtonNormalColor;

/**
 Background color for the payment button when charging is not possible with the entered data
 */
@property (nonatomic, strong) UIColor *paymentButtonDisabledColor;

/**
 Title color for the payment button when charging is possible with the entered data
 */
@property (nonatomic, strong) UIColor *paymentButtonNormalTitleColor;

/**
 Title color for the payment button when charging is not possible with the entered data
 */
@property (nonatomic, strong) UIColor *paymentButtonDisabledTitleColor;

@property (nonatomic) BOOL isCVCRequired;   /**< Enable validation on the CVC field */
@property (nonatomic) BOOL isZipRequired;   /**< Enable validation on the Zip field */

@end
