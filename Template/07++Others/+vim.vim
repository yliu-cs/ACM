syntax on
set nu ts=2 sw=2 et mouse=a cindent

"map <F9> :call Run()<CR>
"func! Run()
"    exec "w"
"    exec "!g++ % -o %<"
"    exec "! %<"
"endfunc

"map <F2> :call SetTitle()<CR>
"func SetTitle()
"    let l = 0
"    let l = l + 1 | call setline(l, "#include <bits/stdc++.h>")
"    let l = l + 1 | call setline(l, "")
"    let l = l + 1 | call setline(l, "int main() {")
"    let l = l + 1 | call setline(l, "  return 0;")
"    let l = l + 1 | call setline(l, "}")
"    let l = l + 1 | call setline(l, "")
"endfunc
