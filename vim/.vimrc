set nocscopeverbose "屏幕cscope警告
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
syntax on "开启代码高亮
syntax enable "同上
autocmd VimEnter * NERDTree
wincmd w
autocmd VimEnter * wincmd w
set nocompatible "不兼容vi
set autoindent "ai.自动缩进，即为新行自动添加与当前行同等的缩进
set cindent "ci.类似c的缩进
set smartindent "si.基于autoindent的改进
set tabstop=4 "ts.一个空格占多少空格
set shiftwidth=4 "sw.使用每层缩进的空格数
set expandtab "et.将tab自动展开成空格
set softtabstop=4 "sts.方便在开启了et后使用退格（backspace）键，每次退格将删除X个空格
set smarttab "sta.开启时，在行首按TAB将加入shiftwidth个空格，否则加入tabstop个空格
set encoding=utf-8
set omnifunc=phpcomplete
set hidden
set noswapfile
" set mouse=a "鼠标支持
set showmatch "显示匹配的括号
set hlsearch "搜索高亮
set ignorecase "搜索忽略大小写
set autoread "外部文件被改变时，vim自动更新
"set cursorline "强调光标所在行
set ruler "光标位置
filetype plugin on
set foldmethod=marker
"set clipboard+=unnamed "和win共用剪切板
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
