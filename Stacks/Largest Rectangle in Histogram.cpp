#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int longestRectangleArea(vector<int>& heights) {
    stack<int> st;
    heights.push_back(0);
    int maxArea = 0;

    for (int i = 0; i < heights.size(); i++) {
        if (!st.empty() && heights[i] < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop(); // pop used one
            int width = st.empty()? i : i - st.top() - 1;
            int area = height * width;
            maxArea = max(maxArea, area);
        }
        st.push(i);
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    int result = longestRectangleArea(heights);
    cout << result << endl;
    return 0;
}