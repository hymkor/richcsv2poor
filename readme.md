Rich-CSV to Pool-CSV converter
==============================

This program replaces delimiters:

- Replacing `,` enclosed with double-quotations to `\v` (Vertical Tab)
- Replacing `\n` (Line Feed) enclosed with double-quotations to `\f` (Form Feed)
- Removing double-quotations

Example
-------

demo.csv:

```.csv

"NEWLINE <
> FIELD",1
"COMMA <,>",2
```

```
$ ./richcsv2poor demo.csv | gawk 'BEGIN{ FS="\v" ; RS="\f" } { printf "%d: [%s]\n",$2,$1 }'
1: [NEWLINE <
> FIELD]
2: [COMMA <,>]
```
