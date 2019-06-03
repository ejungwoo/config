" call vundle#begin()
" Plugin 'VundleVim/Vundle.vim'
"  Plugin 'git://git.wincent.com/command-t.git'
"  Plugin 'file:///home/gmarik/path/to/plugin'
" call vundle#end()

" autocmd vimenter * NERDTree


" set nocompatible
" filetype off
" 
" set rtp+=~/.vim/bundle/Vundle.vim/
" 
" call vundle#rc()
" Bundle 'gmarik/vundle'
" Bundle 'git://git.wincent.com/command-t.git'
" 
" filetype plugin indent on
" 
" Plugin 'scrooloose/nerdtree'



syntax enable
set textwidth=79
set ruler
set nu
set smartindent
set hlsearch
set tabstop=2
set sw=2
set formatoptions=croql
set expandtab
" set cursorline

if has("autocmd")
  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
endif

" map  :w :!root -l %
" map  :w :!python %
" map  :w :!pdflatex %
" map  :w :!g++ % -o %<
" map  :!./%<

colorscheme monokai
colorscheme thaumaturge
colorscheme vim-material
colorscheme soft-era
colorscheme artesanal

colorscheme onehalfdark
colorscheme jellybeans
colorscheme hybrid
colorscheme onehalflight
