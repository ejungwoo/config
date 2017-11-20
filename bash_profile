export CLICOLOR=1
export LSCOLORS=ExFxCxDxBxegedabagacad
export PS1="@ \h:\W > "

alias rm='rm -i'
alias ssh='ssh -Y -A -C'
alias vi='vim -O'
alias ll='ls -lah'
alias root='root -l'
alias ro='root'

alias nc='ssh phyjics@nuclear.korea.ac.kr'
alias rpi='ssh pi@172.27.224.141'
alias gamow='ssh s017@ribfana02'
alias vme='ssh 163.152.36.102'

alias tensor='ssh tensor@210.119.41.249'
alias ej='ssh ejungwoo@nuclear.korea.ac.kr'
alias lamps='ssh lamps@nuclear.korea.ac.kr'
alias sp='ssh spirit@ribfana02.riken.jp'
alias spana='ssh -R4445:localhost:22 -t spirit@ribfana02.riken.jp -Y -A ssh -R4445:localhost:4445 spirit@spana01.spnet -Y -A'
alias fl='ssh -R4445:localhost:22 -t leej@nsclgw1.nscl.msu.edu -Y -A ssh -R4445:localhost:4445 flagtail -Y -A'
alias gw='ssh ejungwoo@hokusai.riken.jp'
alias hpcc='ssh leejun77@hpcc.msu.edu'
alias nscl='ssh leej@nsclgw1.nscl.msu.edu'

alias gitl='git lg'
alias gits='git status -uno'
alias gitb='git branch -av'
alias gitut='git clean -fd --dry-run'
alias gitls='git ls-tree -r HEAD --name-only'
alias gitd='git diff -U0'

export OPENSSL_ROOT_DIR=/usr/local/opt/openssl/

echo "@@ LAMPS:      'kebi'"
echo "@@ SpiRITROOT: 'spirit'"

function kebi() {
  export KEBIPATH='/Users/ejungwoo/KEBI'
  source /Users/ejungwoo/root.v6-10-08.install/bin/thisroot.sh
  source /Users/ejungwoo/geant4-v10.3.3.build/geant4make.sh
  rm -f ~/.rootrc
  ln -s ~/.rootrc.kebi ~/.rootrc
}

function spirit() {
  source /Users/ejungwoo/root.v6-10-08.install/bin/thisroot.sh
  source /Users/ejungwoo/geant4-v10.3.3.build/geant4make.sh
  rm -f ~/.rootrc
  ln -s ~/.rootrc.spirit ~/.rootrc
}

function fairsoft() {
  export SIMPATH=/Users/ejungwoo/FairSoft.install
  export PATH=$PATH:$SIMPATH/bin
  export MANPATH=$MANPATH:$SIMPATH/share
  export LD_LIBRARY_PATH=$SIMPATH/lib:$LD_LIBRARY_PATH
  source $SIMPATH/share/Geant4-10.1.0/geant4make/geant4make.sh
  source $SIMPATH/bin/thisroot.sh
  export FAIRROOTPATH=/Users/ejungwoo/FairRoot.install
  alias spirit='source /Users/ejungwoo/SpiRITROOT/build/config.sh'
}

export PATH=$PATH:/Library/TeX/Distributions/.DefaultTeX/Contents/Programs/texbin

source ~/.git-completion.bash

alias notebook='jupyter notebook'
alias tf='source ~/tensorflow/bin/activate'
alias dtf='deactivate'

#export PYTHONSTARTUP='/Users/ejungwoo/.pythonstartup.py'
