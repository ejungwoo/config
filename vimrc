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
colorscheme jellybeans
