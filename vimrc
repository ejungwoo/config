syntax enable

set textwidth=100
set ruler
set nu
set smartindent
set hlsearch
set tabstop=4
set sw=4
set formatoptions=croql
set expandtab
set clipboard=unnamed

if has("autocmd")
  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
endif

"colorscheme monokai
"colorscheme thaumaturge
"colorscheme vim-material
"colorscheme soft-era
"colorscheme onehalfdark
"colorscheme onehalflight
"colorscheme jellybeans
"colorscheme artesanal
"colorscheme jellybeans
colorscheme smyck
