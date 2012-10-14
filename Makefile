PDFLATEX=pdflatex -shell-escape

all: comprog.pdf

comprog.pdf: comprog.tex
	python static_include.py comprog.tex > comprog.static.tex
	$(PDFLATEX) comprog.static -jobname comprog
	mv comprog.static.pdf comprog.pdf

clean:
	rm comprog.pdf