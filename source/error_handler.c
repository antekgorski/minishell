void panic(char *message)
{
    printf("%s\n", message);
    exit(1);
    //free all and print error and prein new prompt.
}