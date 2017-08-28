set nocscopeverbose
" 状态栏  
 set laststatus=2      " 总是显示状态栏  
 highlight StatusLine cterm=bold ctermfg=yellow ctermbg=blue  
" " 获取当前路径，将$HOME转化为~  
  function! CurDir()  
     let curdir = substitute(getcwd(), $HOME, "~", "g")  
  return curdir  
 endfunction
 set statusline=[%n]\ %f%m%r%h\ \|\ \ pwd:\ %{CurDir()}\ \ \|%=\|\ %l,%c\ %p%%\ \|\ ascii=%b,hex=%b%{((&fenc==\"\")?\"\":\"\ \|\ \".&fenc)}
set number
colo desert
syntax on
syntax enable
set nocompatible
"set foldenable
set ignorecase
autocmd VimEnter * NERDTree
wincmd w
autocmd VimEnter * wincmd w
set tabstop=4
set softtabstop=4
set shiftwidth=4
set encoding=utf-8
" set backspace=indent,eol,start
" set expandtab
set autoindent
set smartindent
set cindent
set omnifunc=phpcomplete
set hidden
set noswapfile
filetype plugin on

imap <C-a> <Esc>:w!<CR>i
:set pastetoggle=<F11>

let g:SuperTabRetainCompletionType=2
let g:AutoPairsFlyMode=1 

let g:DoxygenToolkit_commentType = "php"
let g:DoxygenToolkit_authorName="coolbaby"
let s:licenseTag = "Copyright(C)\<enter>"
let s:licenseTag = s:licenseTag . "For free\<enter>"
let s:licenseTag = s:licenseTag . "All right reserved\<enter>"
let g:DoxygenToolkit_licenseTag = s:licenseTag
let g:doxygen_enhanced_color=1
let g:DoxygenToolkit_paramTag_pre="@params "
let g:DoxygenToolkit_returnTag="@return"
let g:DoxygenToolkit_authorName="Bruce"

set foldmethod=marker


let g:user_emmet_leader_key = '<C-e>'
function CComplier()
	exe ":ccl"
	exe ":update"
	if expand("%:e") == "c"
			let source = expand("%:p")
	endif
	let CurrentFileName=expand("%")
	let FileNameC=substitute(expand("%d"), ".c$", "", "")
	exe 'set makeprg='.'gcc\ -g\ '.CurrentFileName .'\ -o\ '.FileNameC .'.run\ -lapue'
	make
endfunction
map <F9> :call CComplier()<CR>
let g:ctrlp_custom_ignore = '\v[\/]\.(git|hg|svn|pyc)$'
"omni
set completeopt=menu,menuone  
let OmniCpp_MayCompleteDot=1    
let OmniCpp_MayCompleteArrow=1  
let OmniCpp_MayCompleteScope=1  
let OmniCpp_NamespaceSearch=1   
let OmniCpp_GlobalScopeSearch=1  
let OmniCpp_DefaultNamespace=["std"]  
let OmniCpp_ShowPrototypeInAbbr=1 
let OmniCpp_SelectFirstItem = 2
set tags+=/usr/include/tags
imap <C-n> <Esc>:bnext<CR>
imap <C-p> <Esc>:bprev<CR>

inoremap ' ''<ESC>i
inoremap " ""<ESC>i
inoremap ( ()<ESC>i
inoremap [ []<ESC>i
inoremap { {<CR>}<ESC>O
