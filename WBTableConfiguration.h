//
//  WBTableLayout.h
//  WoolyTasks
//
//  Created by Scott Chandler on 7/22/09.
//  Copyright 2009 Wooly Beast Software, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WBTableViewCellController.h"

@interface WBSectionHeaderFooter : NSObject
{
	NSString *_title;
	UIView *_view;
	CGFloat _height;
}

@property(nonatomic,copy) NSString *title;
@property(nonatomic,retain) UIView *view;
@property(nonatomic,assign) CGFloat height;

@end

@interface WBTableSection : NSObject
{
	NSInteger _tag;
	WBSectionHeaderFooter *_header;
	WBSectionHeaderFooter *_footer;
	NSMutableArray *_controllers;
	NSInteger _rowCount;
//	id		_data;
}
@property(nonatomic,retain,readonly) WBSectionHeaderFooter *header;
@property(nonatomic,retain,readonly) WBSectionHeaderFooter *footer;
@property(nonatomic,assign) NSInteger rowCount;
//@property(nonatomic,retain) id	data;
@property(nonatomic,assign) NSInteger tag;

- (id)initWithController:(id<WBTableViewCellController>)controller;
- (id)initWithControllers:(NSArray *)controllers;

- (NSInteger)numberOfRows;

- (void)addController:(id<WBTableViewCellController>)controller;
- (void)removeController:(id<WBTableViewCellController>)controller;
- (id<WBTableViewCellController>)controllerAtIndex:(NSInteger)index;
- (id<WBTableViewCellController>)firstController;
- (id<WBTableViewCellController>)lastController;

- (NSEnumerator *)controllerEnumerator;

- (NSInteger)indexOfController:(id<WBTableViewCellController>)controller;

- (void)makeControllersPerformSelector:(SEL)selector;
- (void)makeControllersPerformSelector:(SEL)selector withObject:(id)object;
@end



@interface WBTableHeaderFooter : NSObject
{
	UIView *_view;
	CGFloat _height;
}

@property(nonatomic,retain) UIView *view;
@property(nonatomic,assign) CGFloat height;

@end




@interface WBTableConfiguration : NSObject
{
	WBTableHeaderFooter *_header;
	NSMutableArray *_sections;
	WBTableHeaderFooter *_footer;
}
@property(nonatomic,retain,readonly) WBTableHeaderFooter *header;
@property(nonatomic,retain,readonly) WBTableHeaderFooter *footer;

- (id)initWithTableSections:(NSArray *)sections;
- (id)initWithTableSection:(WBTableSection *)section;

- (NSInteger)numberOfSections;
- (WBTableSection *)sectionAtIndex:(NSInteger)index;
- (WBTableSection *)sectionWithTag:(NSInteger)tag;
- (WBTableSection *)lastSection;
- (WBTableSection *)firstSection;
- (void)addSection:(WBTableSection *)section;
- (void)insertSection:(WBTableSection *)section atIndex:(NSInteger)index;
- (void)removeSection:(WBTableSection *)section;
- (void)removeSectionAtIndex:(NSInteger)index;

- (NSEnumerator *)sectionEnumerator;

- (NSInteger)indexOfSection:(WBTableSection *)section;

- (id<WBTableViewCellController>)controllerForRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSIndexPath *)indexPathOfController:(id<WBTableViewCellController>)controller;

- (void)makeControllersPerformSelector:(SEL)selector;
- (void)makeControllersPerformSelector:(SEL)selector withObject:(id)object;

@end