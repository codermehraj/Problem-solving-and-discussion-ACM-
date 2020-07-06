/*
    problem link : https://leetcode.com/problems/largest-rectangle-in-histogram/
*/


int largestRectangleArea(vector<int>& heights) {
        
    int MxArea = 0, cur=0, n = heights.size() , top_indx, cur_area, temp;
    stack < int > stuck;
    
    while( cur < n ){
        if( stuck.empty() or heights[stuck.top()] <= heights[cur] ){
        	// Case 1 ~ When stack is empty or new bar is bigger
        	// push the index and do increment
            stuck.push(cur++);
        }
        else {
        	// Case 2 ~ When new bar is smaller than the topmost bar 
            top_indx = stuck.top(); stuck.pop();
            // poping the top value and calculating area for that top
            if(stuck.empty()) cur_area = heights[top_indx] * ( cur - 0 );
            else cur_area = heights[top_indx] * ( cur - (int)stuck.top() - 1 );
            // updating max
            MxArea = max( cur_area , MxArea );
        }
    }
    while ( !stuck.empty() ){
    	// calculating for the remaining ones in the stack untill it is empty
        top_indx = stuck.top(); stuck.pop();
        if(stuck.empty()) cur_area = heights[top_indx] * ( cur - 0 );
        else cur_area = heights[top_indx] * ( cur - (int)stuck.top() - 1 );
        MxArea = max( cur_area , MxArea );
    }
    return MxArea;
}
