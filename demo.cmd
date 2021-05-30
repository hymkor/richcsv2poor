@richcsv2poor demo.csv | gawk "BEGIN{ FS=\"\v\" ; RS=\"\f\" } { printf \"%%d: [%%s]\n\",$2,$1 }"
