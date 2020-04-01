########################################################################
export CLICOLOR=1
export LSCOLORS=ExFxCxDxBxegedabagacad
export PS1="@ \h:\W > "
export OPENSSL_ROOT_DIR=/usr/local/opt/openssl/
export PATH=$PATH:/Library/TeX/Distributions/.DefaultTeX/Contents/Programs/texbin
export BASH_SILENCE_DEPRECATION_WARNING=1 # ignore message ... change to zsh 
########################################################################

########################################################################
alias rm='rm -i'
alias vi='vim -O'
alias iv='vi'
alias ll='ls -lha'
alias ssh='ssh -Y -A -C'
alias scpl='scp -l 8192'
alias count='ls -afq | wc -l'
########################################################################
alias   gamow='ssh s017@ribfana02'
alias      ej='ssh ej'
alias      la='ssh la'
alias    s015='ssh -AY s015@ribfana02.riken.jp'
alias ribfana='ssh spirit@ribfana02.riken.jp'
alias   spana='ssh -R3737:localhost:22 -t spirit@ribfana02.riken.jp -Y -A ssh -R3737:localhost:3737 spirit@spana01.spnet -Y -A'
alias  spanal='ssh -L 3737:spana01.spnet:22 spirit@ribfana02.riken.jp cat -'
alias      fl='ssh -R3737:localhost:22 -t nscl -Y -A ssh -R3737:localhost:4446 flagtail -Y -A'
alias    fish='ssh -R3737:localhost:22 -t nscl -Y -A ssh -R3737:localhost:4447 fishtank -Y -A'
alias      gw='ssh gw'
alias   lee77='ssh leejun77'
alias    nscl='ssh nscl'
alias    spnw='ssh spnw -p2222'
########################################################################
alias tohira='/mnt/spirit/analysis/user/leej/hira/JungWoo'
########################################################################
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
########################################################################

########################################################################
export ROOT_INCLUDE_PATH=/usr/local/Cellar/eigen/3.3.5
function root614() {
  source /Users/ejungwoo/root.v6-14-00.build/bin/thisroot.sh
  alias root='root -l'
  alias ro='root'
}

function scpana() {
  scp -r -P 3737 spirit@127.0.0.1:$1 $2
}

########################################################################
alias geant4='source /Users/ejungwoo/geant4-v10.5.0.build.catalina/geant4make.sh'
########################################################################
function kebi() {
  echo "+ kebi"
  export KEBIPATH='/Users/ejungwoo/kebii'
  root614
  geant4
  rm -f ~/.rootrc
  ln -s ~/.rootrc.kebi ~/.rootrc
}
########################################################################
alias notebook='jupyter notebook'
alias tf='source ~/tensorflow/bin/activate'
alias dtf='deactivate'
########################################################################
export GEOS_DIR=/usr/local/Cellar/geos/3.6.3/
export LDFLAGS='-L/usr/local/opt/zlib/lib'
export CPPFLAGS='-I/usr/local/opt/zlib/include'
export PKG_CONFIG_PATH='/usr/local/opt/zlib/lib/pkgconfig'
########################################################################

########################################################################
kebi
