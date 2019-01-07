syntax on
set nu
set tabstop=4
set shiftwidth=4
set cindent
set mouse=a

map <F9> :call Run()<CR>

func! Run()
	exec "w"
	if &filetype == "cpp"
		exec "!g++ -Wall % -o %<"
		exec "! ./%<"
	elseif &filetype == "python"
		exec "!python3 %"
	endif
endfunc
