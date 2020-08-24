[![Build Status](https://travis-ci.org/appcelerator/APSHTTPClient.svg?branch=master)](https://travis-ci.org/appcelerator/APSHTTPClient)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

## Installation

APSHTTPClient is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'APSHTTPClient'
```

### Requirements
**MobileCoreServices.framework**

### Components
**APSHTTPRequest** - Responsible for the http request  
**NSObject\<APSHTTPRequestDelegate\>** - Responsible for the APSHTTPRequest callbacks  
**APSHTTPPostForm** - Used to build a post form  
**APSHTTPResponse** - Holds all the response information from the request  
**APSHTTPHelper** - Helper class with some handy functions

### GET Request:

```objc
// in header
#import <APSHTTPClient/APSHTTPClient.h>

-(void)sendRequest
{
  APSHTTPRequest *request = [[[APSHTTPRequest alloc] init] autorelease];
  [request setDelegate:self];
  [request setMethod: @"GET"];
  [request setUrl:[NSURL URLWithString: @"http://google.com/"]];
  [request send];
}

- (void)request:(APSHTTPRequest *)request onLoad:(APSHTTPResponse *)response
{
  NSString* responseString = [response responseString];
}

- (void)request:(APSHTTPRequest *)request onError:(APSHTTPResponse *)response
{
  NSString* errorMessage = [[response error] localizedDescription];
}
```

### POST Request:

```objc
// in header
#import <APSHTTPClient/APSHTTPClient.h>

-(void)sendRequest
{
  APSHTTPPostForm *form = [[[APSHTTPPostForm alloc] init] autorelease];
  [form addFormKey:@"first_name" andValue: @"John"];
  [form addFormKey:@"last_name" andValue: @"Smith"];
  [form addFormData: UIImageJPEGRepresentation([[self myImageView] image], 0.7)
           fileName:@"image.jpeg"
	  fieldName:@"photo"];

  APSHTTPRequest *request = [[[APSHTTPRequest alloc] init] autorelease];
  [request setDelegate:self];
  [request setMethod: @"POST"];
  [request setPostForm:form];
  [request setUrl:[NSURL URLWithString: @"http://some_server.com/api/post"]];
  [request send];
}

- (void)request:(APSHTTPRequest *)request onLoad:(APSHTTPResponse *)response
{
  NSString* response = [response responseString];
}

- (void)request:(APSHTTPRequest *)request onError:(APSHTTPResponse *)response
{
  NSString* errorMessage = [[response error] localizedDescription];
}
```
