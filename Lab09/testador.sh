#!/bin/bash
###########################################################
# Created: 16/03/2013
#
# Author: Carla Negri Lintzmayer (carlanl@ic.unicamp.br)
#
# Revision: Zanoni Dias (21/03/2015)
# Revision: Carla Negri (14/03/2016)
###########################################################

# Colors
ESC_SEQ="\x1b["
COL_RESET=$ESC_SEQ"39;49;00m"
COL_RED=$ESC_SEQ"31;01m"
COL_GREEN=$ESC_SEQ"32;01m"
COL_YELLOW=$ESC_SEQ"33;01m"
COL_BLUE=$ESC_SEQ"34;01m"
COL_MAGENTA=$ESC_SEQ"35;01m"
COL_CYAN=$ESC_SEQ"36;01m"
COL_BOLD=$ESC_SEQ";1m"


self="${0##*/}"

if [ $# -lt 2 ]; then
  printf "${COL_BOLD}%-8s${COL_RESET}: ./%s <turma> <laboratorio>\n" "Uso" "$self"
  printf "${COL_BOLD}%-8s${COL_RESET}: ./%s mc102klmn 01\n" "Exemplo" "$self"
  exit 1
fi

class=$1
lab=$2

# Verificando se o comando curl está instalado:

hash curl 2>/dev/null ||
{ echo "Erro: este script necessita do programa curl instalado."; exit 2; }

files=(*.c)
if [ ! -f "$files" ]; then
    echo "Faltando arquivo com extensão .c"
    exit 1;
fi

# Compilando o programa:

echo "Compilando o programa..."

gcc -std=c99 -pedantic -Wall -Werror *.c -o lab${lab} -lm
if [ $? -ne 0 ] ; then
    echo "Erro na compilação. Abortando testes."
    exit
fi

echo "Executando os testes..."
erros=0
SUSY="https://susy.ic.unicamp.br:9999/$class/$lab/dados"
mkdir -p dados$lab
for input in $(curl -ks "$SUSY/testes.html" | sed -n '/Testes abertos/,/Testes fechados/p' | tr \" \\n | grep '^a' | grep '.in'); do
    printf "${COL_BOLD}%-12s${COL_RESET}" "$input"
    res="${input%.in}.res"
    res_file="dados$lab/$res"
    curl -ks "$SUSY/$res" -o "$res_file"
    curl -ks "$SUSY/$input" | ./lab${lab} 2>&1 | diff -q - "$res_file" &>/dev/null
    if [ $? -eq 0 ]; then
        printf "${COL_GREEN}%-12s${COL_RESET}\n" "OK"
    else
        printf "${COL_RED}%-12s${COL_RESET}\n" "Erro"
        echo ">>> Saida esperada (SuSy):"
        cat "$res_file"
        echo ">>> Saida do seu programa:"
        curl -ks "$SUSY/$input" | ./lab${lab} 2>&1
        echo
        erros=$(($erros+1))
    fi
done

echo -e "\nTotal de erros encontrados: $erros"
