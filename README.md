

# Dijkstra's Algorithm in C

This project implements Dijkstra's shortest path algorithm in C for a random undirected graph of 10 nodes.

## Installation and Usage

To run this project, you will need a C compiler installed on your machine. Once you have the compiler installed, navigate to the project directory in your terminal and run the following command:

```
gcc -o dijkstra dijkstra.c
```

This command will compile the C code into an executable file named "dijkstra". To run the executable, use the following command:

```
./dijkstra
```

This will generate a random graph, apply Dijkstra's algorithm to find the shortest paths from a randomly selected node, and print the results to the console.

## Overview

The program creates a random undirected graph of 10 nodes, where each edge has a random weight between 0 and 20. The program then applies Dijkstra's algorithm to find the shortest paths from a randomly selected node to all other nodes in the graph. The algorithm maintains a list of nodes that have already been visited and a list of nodes that have not yet been visited. It repeatedly selects the unvisited node with the smallest distance from the source node and updates the distances of its neighbors. When all nodes have been visited, the algorithm terminates and returns the shortest paths from the source node to all other nodes.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

## Acknowledgements

This project was created as a learning exercise and is based on various resources found online. Special thanks to the creators of the C programming language and the Dijkstra's algorithm.
