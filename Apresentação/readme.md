# APRESENTAÇÃO 

#### Essa apresentação foi criada com [LaTeX](www.latex-project.org).

## Compilação

### Necessário o programa ImageMagik (Linux)!

- Contém arquivo Makefile, basta digitar: `make`.

- Processo manual:
	- `latex main.tex`
	- `bibtex main.aux`
	- 2x `latex main.tex`
	- `dvips main.dvi -o main.ps`
	- `ps2pdf main.ps Metodos_de_ordenacao_Comb_sort.pdf`
