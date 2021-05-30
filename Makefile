ifeq ($(OS),Windows_NT)
    EXESUFFIX=.exe
    CC=gcc
else
    EXESUFFIX=
endif

richcsv2poor$(EXESUFFIX): richcsv2poor.c
	$(CC) $< -o $@
