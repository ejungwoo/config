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
alias vi='vim -p'
alias iv='vi'
alias l='ls -CF'
alias ll='ls -lh'
alias ssh='ssh -Y -A -C'
alias scpl='scp -l 8192'
alias count='ls -afq | wc -l'

# root python
alias roo='root -n'
alias py3='python3'

# git alias gitl='git lg'
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
    #export LILAK_PATH="/home/ejungwoo/llback"
    export KEBIPATH="/home/ejungwoo/kebi"
    export ROOT_LIBRARIES="`root-config --libs` -lMathMore"
    alias root='root --web=off'

    echo "Geant4 installed from the source: /home/ejungwoo/geant4"
    source /home/ejungwoo/geant4/geant4.install/bin/geant4.sh

    #export PKG_CONFIG_PATH=/home/ejungwoo/qt/Qt5.7.0-auto-install/5.7/gcc_64/lib/pkgconfig/
    #export PATH=/home/ejungwoo/qt/Qt5.7.0-auto-install/5.7/gcc_64/bin/:$PATH
}

eroot

echo '* texat           lilak/texat_reco/macros'
function texat() { cd /home/ejungwoo/lilak/texat_reco/macros }

echo '* upscattering    lilak/atomx/macros_proton_upscattering'
function upscattering() { cd /home/ejungwoo/lilak/atomx/macros_proton_upscattering }

echo '* espirit         conda activate spirit'
function espirit() { conda activate spirit }

echo '* deblurring      spirit deblurring'
function deblurring() { cd /home/ejungwoo/spirit/deblurring }

echo '* garfield_texat'
function deblurring() { cd /home/ejungwoo/garfield_texat }

echo '* mfmhs           docker mfmhs'
function mfmhs() { sudo docker exec -it mfmhs /bin/bash }

echo '* atomx'
function atomx() { cd /home/ejungwoo/lilak/atomx/macros }

echo '* lamps'
function lamps() { cd /home/ejungwoo/lilak/lamps/macros }

source /home/ejungwoo/nptool/nptool.sh

#export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print$2}'):0
#export LIBGL_ALWAYS_INDIRECT=0
#export DISPLAY=localhost:0.0

export GARFIELD_HOME=/home/ejungwoo/garfieldpp
source $GARFIELD_HOME/install/share/Garfield/setupGarfield.sh

#####################################################################################################
# set DOCKER_HOST for docker default context
#wsl_ip=$(ip addr show eth0 | grep -oP "(?<=inet\s)\d+(\.\d+){3}")
#export DOCKER_HOST=tcp://$wsl_ip:2375
# start docker daemon automatically when logging in wsl shell
if [ -z "$(ps aux | grep dockerd | grep -v grep)" ] ; then
    wsl_ip=$(ip addr show eth0 | grep -oP "(?<=inet\s)\d+(\.\d+){3}")
    netsh.exe interface portproxy add v4tov4 listenport=2375 connectport=2375 connectaddress=$wsl_ip
    wsl.exe -d Ubuntu -u root -e dockerd -H tcp://$wsl_ip >/dev/null 2>&1 & disown
fi
#####################################################################################################

function vio() {
    # Concatenate all arguments into a single string
    local error_line="$*"
    local file_path="$(echo "$error_line" | cut -d':' -f1)"
    local line_number="$(echo "$error_line" | cut -d':' -f2)"
    local file_extension="${file_path##*.}"
    local complementary_file_path

    # Determine the base name without the file extension
    local base_name="$(basename "$file_path" ."$file_extension")"
    local dir_name="$(dirname "$file_path")"

    # Decide complementary file path based on the current file extension
    if [ "$file_extension" = "h" ]; then
        complementary_file_path="${dir_name}/${base_name}.cpp"
    elif [ "$file_extension" = "cpp" ]; then
        complementary_file_path="${dir_name}/${base_name}.h"
    else
        # If the file is not a recognized C++ file, just open the file at the specified line
        vim "$file_path" +"$line_number"
        return
    fi

    # Check if the complementary file exists and open it alongside the original file
    if [ -f "$complementary_file_path" ]; then
        vim -p "$file_path" +"$line_number" "$complementary_file_path"
    else
        vim "$file_path" +"$line_number"
    fi
}
