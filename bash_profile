########################################################################
export CLICOLOR=1
export LSCOLORS=ExFxCxDxBxegedabagacad
export PS1="@ \h:\W > "
export OPENSSL_ROOT_DIR=/usr/local/opt/openssl/
export PATH=$PATH:/Library/TeX/Distributions/.DefaultTeX/Contents/Programs/texbin

########################################################################
alias rm='rm -i'
alias vi='vim -O'
alias ll='ls -l'
alias count='ls -afq | wc -l'
alias ssh='ssh -Y -A -C'
alias scpl='scp -l 8192'

########################################################################
alias nc='   ssh phyjics@nuclear.korea.ac.kr'
alias rpi='  ssh pi@172.27.224.141'
alias gamow='ssh s017@ribfana02'
alias vme='  ssh 163.152.36.102'
alias ej='   ssh ejungwoo@nuclear.korea.ac.kr'
alias lamps='ssh lamps@nuclear.korea.ac.kr'
alias sp='   ssh s015@ribfana02.riken.jp'
alias spana='ssh -R4445:localhost:22 -t spirit@ribfana02.riken.jp -Y -A ssh -R4445:localhost:4445 spirit@spana01.spnet -Y -A'
alias fl='   ssh -R4446:localhost:22 -t nscl -Y -A ssh -R4446:localhost:4446 flagtail -Y -A'
alias fish=' ssh -R4447:localhost:22 -t nscl -Y -A ssh -R4447:localhost:4447 fishtank -Y -A'
alias gw='   ssh ejungwoo@hokusai.riken.jp'
alias hpcc=' ssh leejun77@hpcc.msu.edu'
alias nscl=' ssh nscl'
alias nw='   ssh -R6666:localhost:22 nw'
alias spnw=' ssh spnw -p2222'
########################################################################
alias tohira='/mnt/spirit/analysis/user/leej/hira/JungWoo'
########################################################################
alias gitl=' git lg'
alias gits=' git status -uno'
alias gitb=' git branch -av'
alias gitut='git clean -fd --dry-run'
alias gitls='git ls-tree -r HEAD --name-only'
alias gitd=' git diff -U0'

########################################################################
echo "==================="
echo "# root6"
function root6() {
  source /Users/ejungwoo/root.v6-12-00.build/bin/thisroot.sh
  alias root='root -l'
  alias ro='root'
  rm -f ~/.rootrc
  ln -s ~/.rootrc.default ~/.rootrc
}
echo "# geant4"
alias geant4='source /Users/ejungwoo/geant4-v10.4.0.build/geant4make.sh'

########################################################################
echo "# kebi"
function kebi() {
  echo "+ kebi"
  export KEBIPATH='/Users/ejungwoo/KEBI'
  root6
  geant4
  rm -f ~/.rootrc
  ln -s ~/.rootrc.kebi ~/.rootrc
  cd $KEBIPATH
}

########################################################################
echo "# e42"
function e42() {
  kebi
  echo "+ e42"
  cd $KEBIPATH/E42/
}

########################################################################
echo "# land"
function land() {
  kebi
  echo "+ land"
  cd $KEBIPATH/NeutronWall/macros
}

########################################################################
echo "# spirit"
function spirit() {
  echo "+ spirit"
  root6
  geant4
  rm -f ~/.rootrc
  ln -s ~/.rootrc.spirit ~/.rootrc
  cd /Users/ejungwoo/spirit/
}
echo "==================="

########################################################################
#echo "# fairsoft"
#function fairsoft() {
#  echo "+ fairsoft"
#  export SIMPATH=/Users/ejungwoo/FairSoft.install
#  export PATH=$PATH:$SIMPATH/bin
#  export MANPATH=$MANPATH:$SIMPATH/share
#  export LD_LIBRARY_PATH=$SIMPATH/lib:$LD_LIBRARY_PATH
#  source $SIMPATH/share/Geant4-10.1.0/geant4make/geant4make.sh
#  source $SIMPATH/bin/thisroot.sh
#  export FAIRROOTPATH=/Users/ejungwoo/FairRoot.install
#  alias spirit='source /Users/ejungwoo/SpiRITROOT/build/config.sh'
#}

########################################################################
alias notebook='jupyter notebook'
alias tf='source ~/tensorflow/bin/activate'
alias dtf='deactivate'
