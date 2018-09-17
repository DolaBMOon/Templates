set nu
set ts=2
set sw=2
set scrolloff=30
filetype indent on
nmap <F9> :w<cr>:!g++ % -o %.out -Wall -ftrapv -fsanitize=address<cr>
nmap <F8> :!time ./%.out<cr>
nmap <F7> :w<cr>:!g++ % -o %.out<cr>
nmap ` ggvG$"+y
command! UBW normal ~/OI/Header.cpp > %
command! LL normal :%s/%d/%lld/g<cr>:%s/int main/signed main/g<cr>
command! IN normal :%s/%lld/%d/g<cr>:%s/signed main/int main/g<cr>
