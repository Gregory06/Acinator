//
// Created by Greg Postnikoff on 06.12.17.
//

#ifndef TREE_FUNCS_H
#define TREE_FUNCS_H

Tree * AddNode(Tree * Node, char * Data) {//разделить на 2

    if (!Node) {

        Node = (Tree *) calloc(1, sizeof(Tree));

        Node->Left = NULL;

        Node->Right = NULL;

        strcpy(Node->Data, Data);

        return Node;

    } else

    if (strcmp(Node->Data, Data) < 0)
        Node->Left = AddNode(Node->Left, Data);
    else
        Node->Right = AddNode(Node->Right, Data);

    return Node;

}


int PrintTree( Tree * Node) {

    if (Node) {

        PrintTree(Node->Left);

        printf("%s\n", Node->Data);

        PrintTree(Node->Right);

    }
    return 0;
}


Tree * LoadTree(Tree * Node, FILE * file) {//ренайм

    char str[20] = {};

    if (!feof(file)) {

        fscanf(file, "%s", str);

        if (!strcmp(str, "(")) {

            fscanf(file, "%s", str);

            Node = (Tree *) calloc(1, sizeof(Tree));
            Node->Left = NULL;
            Node->Right = NULL;
            strcpy(Node->Data, str);

            fscanf(file, "%[ ]", str);

            if ( fscanf(file, "%[)]", str) == 0 ) {
                Node->Left = LoadTree(Node->Left, file);
                Node->Right = LoadTree(Node->Right, file);
            }
            fscanf(file, "%[ )\n]", str);


        }
    }
    return Node;

}


int FindChar(Tree * Node) {

    char Answer[20] = {};

    while (Branch(Node)) {

        printf("%s? [y/n]: \n", Node->Data);

        scanf("%s", &Answer);

        if ( strstr(Answer, "yes") )
            Node = Node->Left;
        else
            Node = Node->Right;
    }

    printf("Is it your character?\n %s\n", Node->Data);

    scanf("%s", Answer);

    if ( strstr(Answer, "yes") )
        printf("I've told you\n");
    else
        AddNewCharacter(Node);

    return 0;

}


int Branch(Tree const * Node) {

    return Node->Left && Node->Right;

}


int PrintTreeDot(Tree const * Node) {

    if (Node){
        if (Node->Left) {
            PrintTreeDot(Node->Left);
            printf("\"%s\\n %p\" -> \"%s\\n %p\"\n", Node->Data, Node, Node->Left->Data, Node->Left);
        }
        if (Node->Right) {
            PrintTreeDot(Node->Right);
            printf("\"%s\\n %p\" -> \"%s\\n %p\"\n", Node->Data, Node, Node->Right->Data, Node->Right);
        }
    }
    return 0;
}


int AddNewCharacter( Tree * Node ) {

    printf("(((...\n"
                   "Who is it?\n");
    char NewCharacketr[20] = {};

    scanf("%s", NewCharacketr);

    printf("Whats diff?\n");

    char Diff[20] = {};

    scanf("%s", Diff);

    AddNewBranch(Node, NewCharacketr, Diff);

    return 0;
}


int AddNewBranch( Tree * Node, char * NewCharacketr, char * Diff ) {

    Tree * NewYes = ( Tree * ) calloc(1, sizeof(Tree));

    NewYes->Left = NewYes->Right = NULL;

    strcpy(NewYes->Data, NewCharacketr);

    Tree * OldNo = ( Tree * ) calloc(1, sizeof(Tree));

    OldNo->Left = OldNo->Right = NULL;
    strcpy(OldNo->Data, Node->Data);

    Node->Left = NewYes;
    Node->Right = OldNo;
    strcpy(Node->Data, Diff);

    return 0;
}


int SaveTree( Tree * Node, FILE * file ) {

    fprintf(file, "( ");
    fprintf(file, "%s ", Node->Data);

    if ( Node->Left )
        SaveTree(Node->Left, file);

    if ( Node->Right )
        SaveTree(Node->Right, file);

    fprintf(file, ") ");

    return 0;
}


int PrintDot(const Tree * Node) {

    FILE * file = NULL;

    system("mv /Users/MyMac/CLionProjects/TopProgramming/Difffff/1.gv /Users/MyMac/CLionProjects/TopProgramming/Difffff/123.txt");

    file = fopen("/Users/MyMac/CLionProjects/TopProgramming/Difffff/123.txt", "w");

    fprintf(file, "digraph G {\n");

    PrintTreeDot(Node, file);

    fprintf(file, "}");

    fclose(file);

    system("mv /Users/MyMac/CLionProjects/TopProgramming/Difffff/123.txt /Users/MyMac/CLionProjects/TopProgramming/Difffff/1.gv");

    return 0;

}


int RunDot() {

    system("open /Users/MyMac/CLionProjects/TopProgramming/Difffff/1.gv");

}


int PrintTreeDot(const Tree const * Node, FILE * file) {



    if (Node){
        if (Node->Left) {
            PrintTreeDot(Node->Left, file);
            fprintf(file, "\"%s\\n %p\" -> \"%s\\n %p\"\n", Node->Data, Node, Node->Left->Data, Node->Left);
        }
        if (Node->Right) {
            PrintTreeDot(Node->Right, file);
            fprintf(file, "\"%s\\n %p\" -> \"%s\\n %p\"\n", Node->Data, Node, Node->Right->Data, Node->Right);
        }
    }


    return 0;

}


int Jorney(Tree * Node, char * str) {

    if (Node) {
        Jorn[p++] = 'y';
        Jorney(Node->Left, str);
        Jorn[--p] = '\0';

        if (strcmp(Node->Data, str) == 0)
            strcpy( RJorn, Jorn);

        Jorn[p++] = 'n';
        Jorney(Node->Right, str);
        Jorn[--p] = '\0';
    }

    return 0;
}


int PrintJorn(Tree * Node, FILE * file) {


    if ((RJorn[i] != '\0') && (Node)) {
        if (RJorn[i] == 'y') {
            i++;
            fprintf(file, "%s, ", Node->Data);
            PrintJorn(Node->Left, file);
        } else {
            i++;
            fprintf(file, "not %s, ", Node->Data);
            PrintJorn(Node->Right, file);
        }
    }
    return 0;
}

int FindDiff(Tree * Node) {

    FILE * file = NULL;
    char str[20] = {};
    char str1[20] = {};

    file = fopen("/Users/MyMac/CLionProjects/TopProgramming/Tree/2.txt", "w");
    scanf("%s", str);
    scanf("%s", str1);

    Jorney(Node, str);

    fprintf(file, "%s is - ", str);
    PrintJorn(Node, file);

    p = i = 0;

    Jorney(Node, str1);

    fprintf(file, "and %s is ", str1);
    PrintJorn(Node, file);
    fclose(file);

    return 0;
}

int Say() {

    system("say -f /Users/MyMac/CLionProjects/TopProgramming/Tree/2.txt");

    return 0;
}

#endif //TREE_FUNCS_H
