#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "APSHTTPClient.h"
#import "APSHTTPHelper.h"
#import "APSHTTPPostForm.h"
#import "APSHTTPRequest.h"
#import "APSHTTPResponse.h"

FOUNDATION_EXPORT double APSHTTPClientVersionNumber;
FOUNDATION_EXPORT const unsigned char APSHTTPClientVersionString[];
