#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "SIM3DSecureData.h"


@protocol SIM3DSWebViewControllerDelegate

-(void)acsAuthResult:(NSString *)acsResult;

-(void)acsAuthError:(NSError *)error;

-(void)acsAuthCanceled;

@end

@interface SIM3DSWebViewController : UIViewController

/**
 Delegate for SIMThreeDSWebViewControllerDelegate
 */
@property (nonatomic, weak) id <SIM3DSWebViewControllerDelegate> delegate;

-(void)authenticateCardHolderWithSecureData:(SIM3DSecureData *) secureData;

- (instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil;

- (instancetype)initWithCoder:(NSCoder *)coder;

@end

