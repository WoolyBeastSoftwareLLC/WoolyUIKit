//
//  WBTableViewCellHandler.h
//  WoolyTasks
//
//  Created by Scott Chandler on 5/2/09.
//  Copyright 2009 Wooly Beast Software, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol WBTableViewCellHandlerDelegate;

@protocol WBTableViewCellHandler<NSObject>
@required
@property (weak) id<WBTableViewCellHandlerDelegate> delegate;
@property (assign) NSInteger tag;

// configure a cell's content. called once upon creation of the cell.
- (void)configureCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath inTableView:(UITableView *)tableView;

// update a cell's content. can be called many times during lifetime of object.
- (void)updateCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath inTableView:(UITableView *)tableView;

// obtains existing cell if already exists, or calls createCellForRowAtIndexPath:inTableView:
- (UITableViewCell *)cellForRowAtIndexPath:(NSIndexPath *)indexPath inTableView:(UITableView *)tableView;

@optional

- (CGFloat)heightForRowAtIndexPath:(NSIndexPath *)indexPath inTableView:(UITableView *)tableView;

- (void)willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath inTableView:(UITableView *)tableView;

- (NSIndexPath *)willSelectRowAtIndexPath:(NSIndexPath *)indexPath inTableView:(UITableView *)tableView;
- (void)didSelectRowAtIndexPath:(NSIndexPath *)indexPath inTableView:(UITableView *)tableView;

- (NSIndexPath *)willDeselectRowAtIndexPath:(NSIndexPath *)indexPath inTableView:(UITableView *)tableView;
- (void)didDeselectRowAtIndexPath:(NSIndexPath *)indexPath inTableView:(UITableView *)tableView;

- (void)accessoryButtonTappedForRowWithIndexPath:(NSIndexPath *)indexPath inTableView:(UITableView *)tableView;

- (UITableViewCellEditingStyle)editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath inTableView:(UITableView *)tableView;
- (BOOL)shouldIndentWhileEditingRowAtIndexPath:(NSIndexPath *)indexPath inTableView:(UITableView *)tableView;
- (BOOL)canEditRowAtIndexPath:(NSIndexPath *)indexPath inTableView:(UITableView *)tableView;

@end


@protocol WBTableViewCellHandlerDelegate<NSObject>
@optional
- (void)tableViewCellHandler:(id<WBTableViewCellHandler>)controller presentViewController:(UIViewController *)viewController;
- (void)tableViewCellHandler:(id<WBTableViewCellHandler>)controller dismissViewController:(UIViewController *)viewController;
@end


typedef NS_ENUM(NSUInteger,WBTableViewCellEvents) {
	WBTableViewCellEventWillSelect = 1,
	WBTableViewCellEventDidSelect,
	WBTableViewCellEventWillDeselect,
	WBTableViewCellEventDidDeselect,
	WBTableViewCellEventAccessory
};

@interface WBTableViewCellHandler : UIResponder<WBTableViewCellHandler>
{
	UIEdgeInsets						_contentInsets;
	NSString *							_title;
	UIImage *							_image;
	NSString *							_details;
	NSMutableDictionary *				_targetActions;
	id<WBTableViewCellHandlerDelegate>	_delegate;
	NSInteger							_tag;
}

- (void)addTarget:(id)target action:(SEL)action forTableViewCellEvent:(WBTableViewCellEvents)event;
- (void)removeTarget:(id)target action:(SEL)action forTableViewCellEvent:(WBTableViewCellEvents)event;

@property (nonatomic,assign) UIEdgeInsets contentInsets;
@property (strong) NSString *title;
@property (strong) NSString *details;
@property (strong) UIImage *image;
@property (nonatomic,strong,readonly) NSString *tableViewCellReuseIdentifier;
@property (nonatomic,readonly) Class tableViewCellClass;
@property (nonatomic,readonly) UITableViewCellStyle tableViewCellStyle;

- (CGRect)contentBoundsFromCell:(UITableViewCell *)cell;

- (UITableViewCell *)createCellForRowAtIndexPath:(NSIndexPath *)indexPath inTableView:(UITableView *)tableView;

- (void)presentViewController:(UIViewController *)viewControllerToPresent;
- (void)dismissViewController:(UIViewController *)viewControllerToDismiss;
@end

