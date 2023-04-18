import os
import socket

if os.getenv("ZSH") and os.path.exists(os.getenv("ZSH")):
    print()
    print("*********  ZSH exist!  *********")
else:
    print()
    print("*********  installing zsh  *********")
    os.system("sudo apt -y install zsh")
    
    print()
    print("*********  set zsh  *********")
    os.system("chsh -s $(which zsh)")

    print()
    print("*********  set oh-my-zsh  *********")
    os.system('sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"')

print()
print("*********  set vimrc  *********")
path_vimrc_old = os.path.join(os.getenv("HOME"),".vimrc")
path_vimrc_backup = os.path.join(os.getenv("PWD"),"vimrc_" + str(socket.gethostname()) + "_" + str(os.getenv("USER")) + ".backup")
path_vimrc_ej = os.path.join(os.getenv("PWD"),"vimrc")
if os.path.exists(path_vimrc_old):
    print(f"copying old vimrc {path_vimrc_old} to {path_vimrc_backup}")
    os.system(f"cp {path_vimrc_old} {path_vimrc_backup}")
print(f"configuring {path_vimrc_old}")
print(f"rm -f {path_vimrc_old}")
print(f"ln -s {path_vimrc_ej} {path_vimrc_old}")
os.system(f"rm -f {path_vimrc_old}")
os.system(f"ln -s {path_vimrc_ej} {path_vimrc_old}")

print()
print("*********  set vim colors *********")
path_vim = os.path.join(os.getenv("HOME"),".vim")
path_vim_colors = os.path.join(os.getenv("HOME"),".vim","colors")
path_vim_colors_all = os.path.join(os.getenv("HOME"),".vim","colors","*")
path_vim_colors_ej = os.path.join(os.getenv("PWD"),"vim-colors/")
path_vim_colors_ej_all = os.path.join(os.getenv("PWD"),"vim-colors","*")
if os.path.exists(path_vim)==False:
    os.system(f"mkdir {path_vim}")
if os.path.exists(path_vim_colors):
    print(f"copy {path_vim_colors_all} to {path_vim_colors_ej} and removing directory...")
    os.system(f"cp {path_vim_colors_all} {path_vim_colors_ej}")
    os.system(f"rm -rf {path_vim_colors}")
print(f"linking {path_vim_colors_ej}")
os.system(f"ln -s {path_vim_colors_ej} {path_vim_colors}")
