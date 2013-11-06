PDFLATEX=pdflatex -shell-escape

all: comprog.pdf

comprog.pdf: comprog.tex
	$(PDFLATEX) comprog
	$(PDFLATEX) comprog
	rm *.{aux,log,toc}

clean:
	rm comprog.pdf
