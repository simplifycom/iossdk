#import <Simplify/SIMCreditCardToken.h>

@protocol SIMChargeCardViewControllerDelegate

-(void)chargeCardCancelled;
-(void)requestedCreditCardToken:(SIMCreditCardToken *)token withError:(NSError *)error;
-(void)requestedPaymentProcess:(NSString *)paymentID withError:(NSError *)error;

@end

/**
 View Controller that has a SIMChargeCardModel that validates the three fields: credit card number, expiration date, and CVC code
 */
@interface SIMChargeCardViewController : UIViewController

@property (nonatomic, weak) id <SIMChargeCardViewControllerDelegate> delegate; /**< Delegate for SIMChargeCardModelDelegate */

@end
