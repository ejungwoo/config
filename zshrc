# >>> oh-my-zsh >>>
export ZSH=$HOME/.oh-my-zsh
ZSH_THEME="robbyrussell"
zstyle ':omz:update' mode auto      # update automatically without asking
plugins=(git)
source $ZSH/oh-my-zsh.sh
# <<< conda initialize <<<

# >>> conda initialize >>>
# !! Contents within this block are managed by 'conda init' !!
__conda_setup="$('/home/ejungwoo/anaconda3/bin/conda' 'shell.zsh' 'hook' 2> /dev/null)"
if [ $? -eq 0 ]; then
    eval "$__conda_setup"
else
    if [ -f "/home/ejungwoo/anaconda3/etc/profile.d/conda.sh" ]; then
        . "/home/ejungwoo/anaconda3/etc/profile.d/conda.sh"
    else
        export PATH="/home/ejungwoo/anaconda3/bin:$PATH"
    fi
fi
unset __conda_setup
# <<< conda initialize <<<

# general
alias rm='rm -i'
alias vi='vim -O'
alias iv='vi'
alias l='ls -CF'
alias ll='ls -lh'
alias ssh='ssh -Y -A -C'
alias scpl='scp -l 8192'
alias count='ls -afq | wc -l'

# root python
alias roo='root -n'
alias py3='python3'

# git
alias gitl='git lg'
alias gits='git status -uno'
alias gitb='git branch -av'
alias gitut='git clean -fd --dry-run'
alias gitls='git ls-tree -r HEAD --name-only'
alias gitd='git diff -U0'
alias gitr='git remote -v'
function gitv() {
  GIT_BRANCH_NAME=$(git rev-parse --abbrev-ref HEAD)
  GIT_BRANCH_COUNT=$(git rev-list --count $GIT_BRANCH_NAME)
  GIT_BRANCH_HASH=$(git rev-parse --short $GIT_BRANCH_NAME)
  echo $GIT_BRANCH_NAME.$GIT_BRANCH_COUNT.$GIT_BRANCH_HASH
}

# jupyter
alias jpt=' explorer.exe "C:\Users\ejungwoo\Documents\Hands On Machine Learning (homl).pdf";cd /home/ejungwoo/homl; python3 -m jupyter notebook --no-browser'
alias jpt1='explorer.exe "C:\Users\ejungwoo\Documents\Hands On Machine Learning (homl).pdf";cd /home/ejungwoo/homl; python3 -m jupyter notebook --no-browser --port=8889'
alias jpt2='explorer.exe "C:\Users\ejungwoo\Documents\Hands On Machine Learning (homl).pdf";cd /home/ejungwoo/homl; python3 -m jupyter notebook --no-browser --port=8890'
alias jpt3='explorer.exe "C:\Users\ejungwoo\Documents\Hands On Machine Learning (homl).pdf";cd /home/ejungwoo/homl; python3 -m jupyter notebook --no-browser --port=8891'

function ej() {
  conda activate ej
}

function eroot() {
  conda activate eroot
  echo "ROOT installed from conda"
  export LILAK_PATH="/home/ejungwoo/lilak"
  export PATH="/home/ejungwoo/.local/bin:$PATH"
}

function espirit() {
  conda activate spirit
}
