//T.C = O(n)
//S.C = O(n)

class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
            
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
             int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
};
/* 
Brute Force O(n^2)(too slow TLE)
we can compute area of every subarray and return the max of them all.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() ; 
		int max_area = 0 ; 
		for(int i = 0 ; i < n ; i++) {
			int curr_max = 0 ; 
			int min_height = INT_MAX ; 
			for(int j = i ; j < n ; j++) {
				min_height = min(min_height , heights[j]) ; 
				curr_max = max(curr_max , min_height * (j - i + 1)) ; 
			}
			max_area = max(max_area , curr_max) ; 
		}
		return max_area ; 
    }
}; */
/* 
using only one stack O(N)(1 pass)
same as approach 3 but better space complexity (O(N) space)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() , max_area = INT_MIN , i = 0 ; 
        stack<int> s ;
        while(i < n) {
            if(s.empty() || heights[s.top()] <= heights[i]) {
                s.push(i) ; 
                i++ ; 
            } else {
                int prev_top = s.top() ; 
                s.pop() ; 
                max_area = max(max_area , heights[prev_top] * (s.empty() ? i : i - s.top() - 1)) ;
            }
        }
        while(!s.empty()) {
            int prev_top = s.top() ; 
            s.pop() ; 
            max_area = max(max_area , heights[prev_top] * (s.empty() ? i : i - s.top() - 1)) ;
        }  
        return max_area ;
    }
}; */