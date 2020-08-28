#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *ltrim(char *s)
{
    while (isspace(*s))
        s++;
    return s;
}

char *rtrim(char *s)
{
    char *back = s + strlen(s);
    while (isspace(*--back))
        ;
    *(back + 1) = '\0';
    return s;
}

char *trim(char *s)
{
    return rtrim(ltrim(s));
}

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        printf("Usage: ./my_compiler.o sample_ok.c\n");
        return 1;
    }
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(argv[1], "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    int braces = 1;
    int parentheses = 1;
    int brackets = 1;
    int quotesS = 1;
    int quotesD = 1;
    int goodDquotes = 1;
    int goodSquotes = 1;
    while ((read = getline(&line, &len, fp)) != -1)
    {
        char *cleaned = trim(line);
        if (cleaned[0] != '/')
        {
            // printf("%s\n", line);
            size_t length = strlen(cleaned);
            size_t i = 0;
            for (; i < length; i++)
            {

                switch (cleaned[i])
                {
                case '{':
                    braces *= 10;
                    break;
                case '}':
                    braces /= 10;
                    break;

                case '[':
                    brackets *= 10;
                    break;
                case ']':
                    brackets /= 10;
                    break;

                case '(':
                    parentheses *= 10;
                    break;
                case ')':
                    parentheses /= 10;
                    break;

                case '"':
                    goodDquotes *= -1;
                    break;

                case '\'':
                    goodSquotes *= -1;
                    break;

                default:
                    break;
                }
            }
        }
    }
    if (braces > 1)
    {
        printf("Missing } \n");
    }
    else if (braces < 1)
    {
        printf("Missing { \n");
    }
    if (brackets > 1)
    {
        printf("Missing ] \n");
    }
    else if (brackets < 1)
    {
        printf("Missing [ \n");
    }
    if (parentheses > 1)
    {
        printf("Missing ) \n");
    }
    else if (parentheses < 1)
    {
        printf("Missing ( \n");
    }
    if (goodDquotes < 0)
    {
        printf("Missing \" \n");
    }
    if (goodSquotes < 0)
    {
        printf("Missing ' \n");
    }
    // printf("Stack Corchete: %d\n", braces);
    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
