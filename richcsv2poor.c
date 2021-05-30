#include <stdio.h>

void filter(FILE *fp)
{
    int quoted = 0;
    int c;
    while ( (c=getc(fp)) != EOF ){
        if ( c == '"' ) {
            quoted = !quoted;
            continue;
        }
        if ( quoted ) {
            putchar(c);
            continue;
        }
        switch ( c ){
            case ',':
                putchar('\v');
                break;
            case '\r':
                break;
            case '\n':
                putchar('\f');
                break;
            default:
                putchar(c);
                break;
        }
    }
}

int main(int argc,const char **argv)
{
    int i;

    if ( argc <= 1 ) {
        filter( stdin );
        return 0;
    }
    for ( i=1 ; i < argc ; i++ ){
        FILE *fp = fopen(argv[i],"r");
        if ( fp == NULL ) {
            fprintf(stderr,"%s: can not open",argv[i]);
            return 1;
        }
        filter( fp );
        fclose(fp);
    }
    return 0;
}
// vim:set notextmode:
