WGraph MST Program

A C++ application that reads a weighted adjacency matrix from a file, constructs a weighted graph, 
and computes a Minimum Spanning Tree (MST) using Kruskal’s Algorithm.

Requirements
1. A C++ compiler (e.g., g++).
2. WGraph.h (included in this project).
3. An input file that:
   - First line: number of vertices (n).
   - Next n lines: each containing n values for the adjacency matrix (0 for no edge, non-zero for edge weight).

Setup Instructions
1. Clone or download this program into a local folder.
2. Compile using a command like:
   g++ *.cpp -o wgraph

How to Run
1. Open a terminal and navigate to the folder containing the compiled program.
2. Run the executable:
       ./wgraph
3. When prompted, enter the name of the input file (e.g., graph_data.txt).
4. The program will:
   - Read n (number of vertices) from the first line.
   - Parse the adjacency matrix and add edges for each non-zero entry (upper triangle).
   - Compute the MST using Kruskal’s Algorithm.
   - Print the MST edges to the console.

Program Features
1. Reads a weighted adjacency matrix to build the graph (0 indicates no edge).
2. Uses Kruskal’s Algorithm to find and print the MST.
3. Automatically skips duplicate edges by only reading the upper part of the matrix.
4. Provides clear console output for debugging or review.

Troubleshooting
- Make sure the input file format is correct:
  - Line 1: number of vertices (n).
  - Next n lines: each line with n values (0 or edge weight).
- Confirm WGraph.h is in the same directory as your .cpp files.
- If you get compilation errors, ensure you’re using a compatible C++ compiler.

License
This project is for demonstration purposes. Feel free to use, modify, or distribute 
with proper attribution or under any additional terms specified in this repository.
