# NemoLibC-Improved

Going to update soon

Installation:

Linux:

1. Copy repository. (Download and unzip)
2. Type in the command "g++ -o out -I . -I ./nauty \*.cpp nauty/\*.c"
3. Type in "./out" or "./out exampleGraph.txt 3 1000 0". Change the last one as needed.

Arguments:

This version can take four different argument. 

The first one will be the file to look at. At default, it will try to scan exampleGraph.txt.

The second argument refers to the motif size. At default it will try to find motifs of size 3.

The third argument is the number of random graphs to generate. At default it will generate 1000.

The last argument is whether the graph is directed or undirected. By default it is undirected.
