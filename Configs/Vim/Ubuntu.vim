set si
set number
set scrolloff=30
set ts=2
set sw=2
set mouse=a
syntax on
nmap ` ggvG$"+y

func! CppFunc()
	set cindent
	command! W w
	command! WN %s/%lld/%I64d/g
	command! LN %s/%I64d/%lld/g
	command! LL normal :%s/%d/%lld/g<cr>:%s/int main/signed main/g<cr>
	command! IN normal :%s/%lld/%d/g<cr>:%s/signed main/int main/g<cr>
	command! UBW !cat ~/OI/Templates/Header/Header.cpp >> %
	nmap <F7> :w<cr>:!g++ % -o %.out -O2<cr>
	nmap <F8> :!time ./%.out<cr>
	nmap <F9> :w<cr>:!g++ % -o %.out -O2 -Wall -ftrapv -fsanitize=address<cr>
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
