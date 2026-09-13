CC=gcc
#CC=clang
CODEDIR=.
#INCDIR=
DEPFLAGS= -lncursesw
#DEPFLAGS= -lcurses
CFILES=$(foreach D,$(CODEDIR),$(wildcard $(D)/*.c))
EXE=cube
#EXE=mainosx

all: $(EXE)

$(EXE): $(CFILES)
	$(CC) -o $@ $^ $(DEPFLAGS)
