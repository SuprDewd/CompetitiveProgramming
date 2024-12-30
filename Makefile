PDFLATEX=pdflatex -shell-escape

all: comprog.pdf

comprog.pdf: comprog.tex
	python3 preprocess.py
	$(PDFLATEX) comprog
	$(PDFLATEX) comprog
	$(PDFLATEX) comprog
	rm -f *.{aux,log,toc,fls,fdb_latexmk}
	rm -rf _code/

clean:
	rm comprog.pdf
