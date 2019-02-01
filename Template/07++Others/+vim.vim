syntax on
set nu
set tabstop=4
set shiftwidth=4
set cindent
set mouse=a
set expandtab
set backspace=indent,eol,start

map <F2> :call SetTitle()<CR>

func SetTitle()
    let l = 0
    let l = l + 1 | call setline(l, "#include <bits/stdc++.h>")
    let l = l + 1 | call setline(l, "using namespace std;")
    let l = l + 1 | call setline(l, "")
    let l = l + 1 | call setline(l, "int main(int argc, char *argv[]) {")
    let l = l + 1 | call setline(l, "    return 0;")
    let l = l + 1 | call setline(l, "}")
    let l = l + 1 | call setline(l, "")
endfunc

