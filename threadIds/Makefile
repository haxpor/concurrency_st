OUTDIR := bin-linux

.PHONY: create_dir all

all: create_dir
	g++ -g -O2 -I. main.cpp -o $(OUTDIR)/main.out -pthread -lpthread

create_dir:
	if [ ! -d $(OUTDIR) ]; then		\
		mkdir $(OUTDIR);		\
	fi

clean:
	rm -rf $(OUTDIR)/*
