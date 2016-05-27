FILE=main
OUT=Metodos_de_ordenacao_Comb_sort

all: $(OUT).pdf move

$(OUT).pdf: gif $(FILE).ps
	ps2pdf $(FILE).ps $(OUT).pdf

$(FILE).ps: $(FILE).dvi
	dvips -G0 $(FILE).dvi -o $(FILE).ps

$(FILE).dvi: bib
	latex $(FILE).tex
	latex $(FILE).tex

bib: compile $(FILE).aux
	bibtex $(FILE).aux

compile: $(FILE).tex
	latex $(FILE).tex

gif: Imagens/*.gif
	for file in Imagens/*.gif; \
	do \
		convert -verbose -antialias "$$file" $$(echo "$$file" | sed 's/gif/eps/'); \
	done; \

# png: Imagens/*.png
# 	for file in Imagens/*.png; \
# 	do \
# 		convert -verbose -antialias "$$file" $$(echo "$$file" | sed 's/png/eps/'); \
# 	done; \

#jpg: Imagens/*.jpg
#	for file in Imagens/*.jpg; \
#	do \
#		convert -verbose -antialias "$$file" $$(echo "$$file" | sed 's/jpg/eps/'); \
#	done; \

move:
	mkdir -p Compilacao
	find . -maxdepth 1 -regextype egrep -iregex \
	'.*\.(nav|snm|aux|bbl|blg|idx|ilg|ind|ifi|log|lof|lot|out|toc|dvi|ps)' \
	-exec mv -f '{}' Compilacao/ \;
