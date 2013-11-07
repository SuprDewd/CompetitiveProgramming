PDFLATEX=pdflatex -shell-escape

all: comprog.pdf

comprog.pdf: comprog.tex
	python2 preprocess.py
	$(PDFLATEX) comprog
	$(PDFLATEX) comprog
	rm *.{aux,log,toc}
	rm -rf _code/

clean:
	rm comprog.pdf
