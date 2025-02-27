/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "SDWebImageCompat.h"
#import "SDWebImageManager.h"

/**
 * Integrates SDWebImage async downloading and caching of remote images with UIImageView.
 *
 * Usage with a UITableViewCell sub-class:
 *
 * 	#import <SDWebImage/UIImageView+WebCache.h>
 * 	
 * 	...
 * 	
 * 	- (UITableViewCell*)tableView:(UITableView*)tableView
 * 	         cellForRowAtIndexPath:(NSIndexPath*)indexPath {
 * 	    static NSString *MyIdentifier = @"MyIdentifier";
 * 	
 * 	    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:MyIdentifier];
 * 	
 * 	    if (cell == nil) {
 * 	        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
 * 	                                       reuseIdentifier:MyIdentifier] autorelease];
 * 	    }
 * 	
 * 	    // Here we use the provided setImageWithURL: method to load the web image
 * 	    // Ensure you use a placeholder image otherwise cells will be initialized with no image
 * 	    [cell.imageView setImageWithURL:[NSURL URLWithString:@"http://example.com/image.jpg"]
 * 	                   placeholderImage:[UIImage imageNamed:@"placeholder"]];
 * 	
 * 	    cell.textLabel.text = @"My Text";
 * 	    return cell;
 * 	}
 * 	
 */
@interface UIImageView (WebCache)

/**
 * Set the imageView `image` with an `url`.
 *
 * The downloand is asynchronous and cached. After the image is downloaded the result image is cropped.
 *
 * @param url The url for the image.
 * @param bounds Bounds of the cropped image.
 * @param size Resize the downloaded image to the specified size
 * @param mode Content mode of the resize strategy. Can be UIViewContentModeScaleAspectFill or UIViewContentModeScaleAspectFit
 */
//- (void)setImageWithURL:(NSURL*)url andResize:(CGSize)size withContentMode:(UIViewContentMode)mode;

/**
 * Set the imageView `image` with an `url`.
 *
 * The downloand is asynchronous and cached.
 *
 * @param url The url for the image.
 */
- (void)setImageWithURL:(NSURL*)url;

/**
 * Set the imageView `image` with an `url` and a placeholder.
 *
 * The downloand is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @see setImageWithURL:placeholderImage:options:
 */
- (void)setImageWithURL:(NSURL*)url placeholderImage:(UIImage*)placeholder;

/**
 * Set the imageView `image` with an `url` a placeholder and resize.
 *
 * The downloand is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param resize Resize the downloaded image to the specified size
 * @see setImageWithURL:placeholderImage:options:
 */
- (void)setImageWithURL:(NSURL*)url placeholderImage:(UIImage*)placeholder andResize:(CGSize)size;

/**
 * Set the imageView `image` with an `url`, placeholder and custom options.
 *
 * The downloand is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options The options to use when downloading the image. @see SDWebImageOptions for the possible values.
 */
- (void)setImageWithURL:(NSURL*)url placeholderImage:(UIImage*)placeholder options:(SDWebImageOptions)options;

/**
 * Set the imageView `image` with an `url`.
 *
 * The downloand is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param completedBlock A block called when operation has been completed. This block as no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrived from the local cache of from the network.
 */
- (void)setImageWithURL:(NSURL*)url completed:(SDWebImageCompletedBlock)completedBlock;

/**
 * Set the imageView `image` with an `url`, placeholder.
 *
 * The downloand is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param resize Resize the downloaded image to the specified size
 * @param completedBlock A block called when operation has been completed. This block as no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrived from the local cache of from the network.
 */
- (void)setImageWithURL:(NSURL*)url placeholderImage:(UIImage*)placeholder andResize:(CGSize)size completed:(SDWebImageCompletedBlock)completedBlock;
/**
 * Set the imageView `image` with an `url`, placeholder.
 *
 * The downloand is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param completedBlock A block called when operation has been completed. This block as no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrived from the local cache of from the network.
 */
- (void)setImageWithURL:(NSURL*)url placeholderImage:(UIImage*)placeholder completed:(SDWebImageCompletedBlock)completedBlock;

/**
 * Set the imageView `image` with an `url`, placeholder and custom options.
 *
 * The downloand is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options The options to use when downloading the image. @see SDWebImageOptions for the possible values.
 * @param completedBlock A block called when operation has been completed. This block as no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrived from the local cache of from the network.
 */
- (void)setImageWithURL:(NSURL*)url placeholderImage:(UIImage*)placeholder options:(SDWebImageOptions)options completed:(SDWebImageCompletedBlock)completedBlock;

/**
 * Set the imageView `image` with an `url`, placeholder and custom options.
 *
 * The downloand is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options The options to use when downloading the image. @see SDWebImageOptions for the possible values.
 * @param progressBlock A block called while image is downloading
 * @param completedBlock A block called when operation has been completed. This block as no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrived from the local cache of from the network.
 */
- (void)setImageWithURL:(NSURL*)url placeholderImage:(UIImage*)placeholder options:(SDWebImageOptions)options andResize:(CGSize)size withBorder:(BOOL)withBorder progress:(SDWebImageDownloaderProgressBlock)progressBlock completed:(SDWebImageCompletedBlock)completedBlock;

/**
 * Cancel the current download
 */
- (void)cancelCurrentImageLoad;

@end
