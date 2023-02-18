#include "movie_action.h"

int MovieAction::calculate_late_fees(int num_of_days_past_due) {
    //Calculation rules observed:
    //no charge at all if mercy rule (id is a multiple of 13 AND title reads "pulp fiction") applies
    //charges number of days past due times late fee per day
    //doubles charge if number of days past due is 5 or greater

    //fee variable, 0 if mercy fee applies, days x late fee if mercy fee doesn't apply
    int fee = mercy_rule_apply()&&action_movie_mercy_rule_apply() ? 0 : num_of_days_past_due * late_fee_per_day_in_dollar;
    //doubles fee if number of days is 5 or greater
    if(num_of_days_past_due>=5)fee*=2;
    //returns fee variable
    return fee;
}

bool MovieAction::action_movie_mercy_rule_apply() {
    return title.find("pulp fiction") != std::string::npos;
}

bool MovieAction::mercy_rule_apply() {
    return StoreMediaInterface::mercy_rule_apply() && action_movie_mercy_rule_apply();
}