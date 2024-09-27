class MyCalendarTwo {
public:
    vector<pair<int,int>> doubleOverlab;
    vector<pair<int,int>> overallBookings;
    bool checkOverlab(int start1,int end1,int start2,int end2){
        return max(start1,start2) < min(end1,end2);
    }
    pair<int,int> findoverlab(int start1,int end1,int start2,int end2){
        return {max(start1,start2),min(end1,end2)};
    }
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        // check if tripple booking is being created or not

        for(auto region: doubleOverlab){
            if(checkOverlab(region.first,region.second,start,end)){
                return false;
            }
        }

        // check if it is creating double bookings
        for(auto booking:overallBookings ){
            if(checkOverlab(booking.first,booking.second,start,end)){
                doubleOverlab.push_back(findoverlab(booking.first,booking.second,start,end));
            }
        }
        overallBookings.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
