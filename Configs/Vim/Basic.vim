set nu
filetype indent on
set ts=2
set sw=2
syntax on
nmap ` ggvG$"+y
nmap <F7> :w<cr>:!g++ % -o %.out<cr>
nmap <F8> :w<cr>:!time ./%.out<cr>
nmap <F9> :w<cr>:!g++ % -o %.out -Wall -ftrapv<cr>
command! UBW !cat ~/OI/Header.cpp > %
