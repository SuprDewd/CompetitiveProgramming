PDFLATEX=pdflatex

all: comprog.pdf

comprog.pdf: comprog.tex
	$(PDFLATEX) comprog

clean:
	rm comprog.pdf