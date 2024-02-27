#include <iostream>
#include <vector>
#include <algorithm>

// Define a structure to represent a segment with a start and end point
struct Segment {
    int start, end;

    // Constructor for easy initialization
    Segment(int s, int e) : start(s), end(e) {}

    // Define the '<' operator for sorting, sort by end time
    bool operator<(const Segment& s) const {
        return end < s.end;
    }
};

// Function to find the maximum number of non-overlapping segments
int findMaxNonOverlappingSegments(std::vector<Segment>& segments) {
    // Sort the segments based on their end points
    std::sort(segments.begin(), segments.end());

    // 'last' keeps track of the last selected segment's end time
    // 'count' is the number of non-overlapping segments
    int last = -1, count = 0;

    // Iterate over the segments
    for (const auto& segment : segments) {
        // If the current segment starts after the last selected segment ends
        if (segment.start > last) {
            // Select the current segment and update 'last' and 'count'
            last = segment.end;
            count++;
        }
    }

    // Return the number of non-overlapping segments
    return count;
}

int main() {
    int n; // Number of segments
    std::cin >> n; // Input the number of segments

    std::vector<Segment> segments;

    // Read the segments
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b; // Input the start and end points of each segment
        segments.emplace_back(a, b);
    }

    // Find and output the maximum number of non-overlapping segments
    std::cout << findMaxNonOverlappingSegments(segments) << std::endl;

    return 0;
}
