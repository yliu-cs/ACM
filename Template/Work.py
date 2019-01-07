# -*- coding:utf-8 -*-

import os
import re
import time

TexHead = r"""\documentclass[a4paper,11pt]{article}
\usepackage{zh_CN-Adobefonts_external}
\usepackage{fancyhdr}
\usepackage{minted}
\usepackage[colorlinks]{hyperref}
\setlength{\headheight}{15pt}

\pagestyle{fancy}
\fancyhf{}
\fancyhead[C]{Algorithm Library by Liu Yang}
\lfoot{}
\cfoot{\thepage}
\rfoot{}

\author{Liu Yang}
\title{Algorithm Library}

\begin{document} 
\maketitle
\newpage
\tableofcontents
\newpage

"""

TexTail = r"""
\end{document}
"""

File = open('Ly-Template.tex', 'w', encoding='utf-8')

def SearchWrite(Address, Cnt):
    Classifies = os.listdir(Address)
    Classifies.sort()
    for Classify in Classifies:
        if Cnt == 0:
            if re.match(r'\d\d\+\+(.+?)', Classify):
                Str = '\\section{' + Classify[4:] + '}\n'
                File.write(Str)
                SearchWrite(Address + '/' + Classify, Cnt + 1)
                Str = '\\newpage\n'
                File.write(Str)
        else:
            if re.match(r'\+.', Classify):
                if re.match(r'(.+?)\.(.+?)', Classify):
                    StrIndex = Classify.find('.')
                    Str = '\\'
                    for i in range(Cnt):
                        Str = Str + 'sub'
                    Str = Str + 'section{' + Classify[1:StrIndex] + '}\n'
                    File.write(Str)
                    Index = Address[39:]
                    print(Index)
                    Str = '\\inputminted[breaklines]{c++}{' + Index  + '/' + Classify + '}\n'
                    File.write(Str)
                else:
                    Str = '\\'
                    for i in range(Cnt):
                        Str = Str + 'sub'
                    Str = Str + 'section{' + Classify[1:] + '}\n'
                    File.write(Str)
                    SearchWrite(Address + '/' + Classify, Cnt + 1)
    File.write('\n')

def Work():
    ClassifyPos = os.getcwd()
    SearchWrite(ClassifyPos, 0)

def main():
    File.write(TexHead)
    Work()
    File.write(TexTail)
    File.close()

if __name__ == '__main__':
    main()

