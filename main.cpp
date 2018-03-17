#include <iostream>

enum {

    DataSize = 20

};



struct Tree {

    Tree * Left = NULL;

    Tree * Right = NULL;

    char Data[DataSize] = {};

};

#include "FuncsNames.h"

char * Jorn = (char *) calloc(100, sizeof(char));
char * RJorn = (char *) calloc(100, sizeof(char));
int p = 0;
int i = 0;


int main() {

    Tree * Node = NULL;
    FILE * file = NULL;

    file = fopen("/Users/MyMac/CLionProjects/TopProgramming/Tree/1.txt", "r");
    Node = LoadTree(Node, file);

    PrintDot(Node);
    RunDot();

    FindChar( Node );

    FindDiff(Node);

    fclose(file);
    file = fopen("/Users/MyMac/CLionProjects/TopProgramming/Tree/1.txt", "w");

    SaveTree( Node, file );

    Say();

    return 0;
}

#include "Funcs.h"
