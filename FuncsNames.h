//
// Created by Greg Postnikoff on 06.12.17.
//

#ifndef TREE_FUNCSNAMES_H
#define TREE_FUNCSNAMES_H


Tree * AddNode(Tree * Node, char * Data);
int PrintTree(Tree * Node);
Tree * LoadTree(Tree * Node, FILE * file);
int FindChar(Tree * Node);
int Branch(Tree const * Node);
int PrintTreeDot(Tree const * Node);
int AddNewCharacter( Tree * Node );
int AddNewBranch( Tree * Node, char * NewCharacketr, char * Diff );
int SaveTree( Tree * Node, FILE * fileS );
int PrintDot(const Tree * Node);
int RunDot();
int PrintTreeDot(const Tree const * Node, FILE * file);
int Jorney(Tree * Node, char * str);
int PrintJorn(Tree * Node, FILE * file);
int FindDiff(Tree * Node);
int Say();


#endif //TREE_FUNCSNAMES_H
