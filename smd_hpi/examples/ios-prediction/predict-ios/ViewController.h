//
//  ViewController.h
//  WhatIsThis
//
//  Created by Haoxiang Li on 1/23/16.
//  Copyright © 2016 Haoxiang Li. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "c_predict_api.h"
#import <vector>
#import <AVFoundation/AVCaptureOutput.h> // Allows us to use AVCaptureVideoDataOutputSampleBufferDelegate

#define kWidth 28
#define kHeight 28

@interface ViewController : UIViewController <AVCaptureVideoDataOutputSampleBufferDelegate>{
    
    PredictorHandle predictor;
    
    NSString *model_symbol;
    NSData *model_params;
    AVCaptureSession *captureSession;
    AVCaptureDevice *videoDevice;
}

@property (weak, nonatomic) IBOutlet UILabel *labelDescription;
@property (weak, nonatomic) IBOutlet UIImageView *imageViewPhoto;
@property (weak, nonatomic) IBOutlet UIButton *detectionButton;
@property (weak, nonatomic) IBOutlet UIImageView *imageViewCrop;
@property (weak, nonatomic) IBOutlet UISlider *exposureSlider;

- (IBAction)startDetectionButtonTapped:(id)sender;
- (IBAction)stopDetectionButtonTapped:(id)sender;
- (AVCaptureSession *)createCaptureSessionFor:(AVCaptureDevice *)device;
- (UIImage *) cropCenterRect:(UIImage *)image toSize:(int)size;

@end
