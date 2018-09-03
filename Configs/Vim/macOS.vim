set si
set number
set scrolloff=30
set ts=2
set sw=2
set mouse=a
syntax on
vmap "+y :w !pbcopy<CR><CR>
nmap "+p :r !pbpaste<CR><CR>
nmap ` ggvG$"+y

func! CppFunc()
	set cindent
	command! WN %s/%lld/%I64d/g
	command! LN %s/%I64d/%lld/g
	command! UBW normal :w<cr>:e ~/OI/Templates/Header/Header.cpp<cr>ggvG$"0y:bp<cr>ggvGD"0p
	nmap <F7> :w<cr>:!g++-7 % -o %.out -O2 -std=c++17<cr>
	nmap <F8> :!time ./%.out<cr>
	nmap <F9> :w<cr>:!g++-7 % -o %.out -O2 -std=c++17 -Wall -ftrapv -fsanitize=address<cr>
	endfunc

au filetype cpp call CppFunc()

func! PythonFunc()
	nmap <F7> :w<cr>:!python3 %<cr>
	nmap <F9> :w<cr>:!python3 -i %<cr>
	endfunc

au filetype python call PythonFunc()

func! RubyFunc()
	nmap <F7> :w<cr>:!ruby %<cr>
	nmap <F8> :w<cr>:!ruby -c %<cr>
	nmap <F9> :w<cr>:!irb %<cr>
	endfunc

au filetype ruby call RubyFunc()
