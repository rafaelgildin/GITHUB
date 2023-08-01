/*
- best c tutorial to install c in vscode: https://www.youtube.com/watch?v=77v-Poud_io
- every time for a new project:
    - "open a folder"
    - "save workspace" as the folder before yours.
- when you close it, you can reopen by:
    - "open workspace from file"
    - click in the workspace and tchadaaa here it is :)
*/
#include<stdio.h>

int main(){
    int age;
    printf("Enter yout age:\n");
    scanf("%d",&age);
    printf("age is %d\n", age);
    printf("Press <enter> to quit:");
    printf("%c", getch());
    return 0;
}