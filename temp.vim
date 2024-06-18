" LUA CUSTOMIZED SYNTAX -
"""" https://vim.fandom.com/wiki/Xterm256_color_names_for_console_Vim
"""" https://www.calmar.ws/vim/256-xterm-24bit-rgb-color-chart.html
"""" https://fuchsia.googlesource.com/third_party/vim/+/3f1c15b24a3939d193c80c509132db9ee4d8cceb/runtime/syntax/lua.vim
hi luaComment       ctermfg=71  cterm=italic    " dark sea green 4
hi luaCond          ctermfg=208 cterm=bold      " dark orange
" hi luaIfThen        ctermfg=
" hi luaElseifThen    ctermfg=
" hi luaThenEnd       ctermfg=
hi luaElse          ctermfg=208
hi luaConstant      ctermfg=197                 " deep pink 2          / true, false, nil, ...
hi luaError         ctermfg=196                 " red 1                / organization errors (blocks)
" hi luaParenError    ctermfg=
" hi luaBraceError    ctermfg=
hi luaFor           ctermfg=184                 " yellow 3
hi luaIn            ctermfg=184
hi luaStatement     ctermfg=184 cterm=bold      "                      / if, while, do, end, goto, ...
hi luaRepeat        ctermfg=184 cterm=bold
hi luaString        ctermfg=128 cterm=underline " dark violet
hi luaString2       ctermfg=126 cterm=italic    " medium violet red
hi luaNumber        ctermfg=39                  " dark sky blue 1
hi luaOperator      ctermfg=163 cterm=bold      " magenta 3            / and, or, not, ...
hi luaFunc          ctermfg=34  cterm=underline " green 3              / type, table.insert, ...
hi luaFunction      ctermfg=69  cterm=bold      " corn flower blue
hi luaLabel         ctermfg=99  cterm=bold      " stable blue 1        / `goto` point


" hi luaTable         ctermbg= " table delimiters
" hi luaTodo          ctermfg= " todo comment: `-- TODO: comment`

" hi luaInnerComment  ctermfg=
" hi luaBlock         ctermfg=
" hi luaTableBlock    ctermbg=
" hi luaSpecial       ctermfg=
" hi luaParen         ctermfg=
" hi luaFunctionBlock ctermfg=
" hi luaLoopBlock     ctermfg=
