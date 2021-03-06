/* 
 * Copyright (c) 2009 Keith Lazuka
 * License: http://www.opensource.org/licenses/mit-license.html
 */

#import "KalView.h"       // for the KalViewDelegate protocol
#import "KalDataSource.h" // for the KalDataSourceCallbacks protocol

#define kCalendarWidth 320
#define kCalendarHeight 250//310

@protocol KalCalendarDelegate <NSObject>

- (void)didSelectDate:(NSDate *)date;
@optional
- (void)setCurrentCheckDateType:(NSUInteger)x;

@end


@class KalLogic, KalDate;

/*
 *    KalViewController
 *    ------------------------
 *
 *  KalViewController automatically creates both the calendar view
 *  and the events table view for you. The only thing you need to provide
 *  is a KalDataSource so that the calendar system knows which days to
 *  mark with a dot and which events to list under the calendar when a certain
 *  date is selected (just like in Apple's calendar app).
 *
 */
@interface KalViewController : UIViewController <KalViewDelegate, KalDataSourceCallbacks>
{
    KalLogic *logic;
    UITableView *tableView;
    id <UITableViewDelegate> delegate;
    id <KalDataSource> dataSource;
    id <KalCalendarDelegate> calendarDelegate;
    NSDate *initialSelectedDate;
    NSDate *initialCheckOutDate;
    NSDate *selectedDate;
    BOOL isSingleDate;
}


@property (nonatomic, retain) NSDate *selectedDate;
@property (nonatomic, assign) id <UITableViewDelegate> delegate;
@property (nonatomic, assign) id <KalDataSource> dataSource;
@property (nonatomic, assign) id <KalCalendarDelegate> calendarDelegate;
@property (nonatomic, retain) UITableView *tableView;
@property (nonatomic, assign) BOOL isSingleDate;

- (id)initWithSelectedDate:(NSDate *)date; // designated initializer. When the calendar is first displayed to the user, the month that contains 'selectedDate' will be shown and the corresponding tile for 'selectedDate' will be automatically selected.
- (void)reloadData; // If you change the KalDataSource after the KalViewController has already been displayed to the user, you must call this method in order for the view to reflect the new data.
- (void)showAndSelectDate:(NSDate *)date; // Updates the state of the calendar to display the specified date's month and selects the tile for that date.
- (void)setDateRangeMin:(NSDate *)min Max:(NSDate *)max MaxSelectDays:(NSInteger)days;
- (void)setTimeRange:(NSDate *)min Max:(NSDate *)max;

- (void)getDateSelected:(NSDate **)sDate;  // for single date
- (void)getDateRangeMin:(NSDate **)min Max:(NSDate **)max;

- (id)initWithCheckInDate:(NSDate *)dateIn CheckOutDate:(NSDate *)dateOut;

- (void)setCheckInDate:(NSDate *)dateIn CheckOutDate:(NSDate *)dateOut;
- (void)setInitSelectedDate:(NSDate *)dateSelect;

@end
