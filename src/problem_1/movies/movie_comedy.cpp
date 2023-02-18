#include "movie_comedy.h"

int MovieComedy::calculate_late_fees(int num_of_days_past_due) {
    //Calculation rules observed:
    //no late fees if 0 days past due (it's not late so no late fees, obviously)
    //if 5 or fewer days past due, charge late fee once
    //if 10 or fewer days past due, charge late fee twice
    //if greater than 10 days past due, charge late fee as many times as days

    //adjustment variable, based on number of days past due
    int adjust=num_of_days_past_due;
    //does nothing if at 0 days
    //note: does not check for negative values, unexpected behavior could theoretically occur
    if (adjust==0);
    //adjusts to single charge at 5 days or less
    else if(adjust<=5)adjust=1;
    //adjusts to double charge at 10 days or less
    else if(adjust<=10)adjust=2;

    //at greater than 10 days, adjustment matches number of days

    //returns modified fee
    return late_fee_per_day_in_dollar * adjust;
}
