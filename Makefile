PDFLATEX=pdflatex -shell-escape

all: comprog.pdf


%.pdf: %.tex
	$(PDFLATEX) $<
