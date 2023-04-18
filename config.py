import os
import socket

path_to_home = os.getenv("HOME")
path_to_pwd = os.getenv("PWD")

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

def backup_and_link_file(file_old, file_new, file_backup=""):
    if len(file_backup)==0:
        file_backup = file_new + "_" + str(socket.gethostname()) + "_" + str(os.getenv("USER")) + ".backup"
    if os.path.exists(file_old):
        print(f"copying old file {file_old} to {file_backup}")
        os.system(f"cp {file_old} {file_backup}")
    print(f"configuring {file_old}")
    print(f"rm -f {file_old}")
    print(f"ln -s {file_new} {file_old}")
    os.system(f"rm -f {file_old}")
    os.system(f"ln -s {file_new} {file_old}")

print()
print("*********  set vimrc  *********")
backup_and_link_file(os.path.join(path_to_home,".vimrc"), os.path.join(path_to_pwd,"vimrc"))


print()
print("*********  set vim colors  *********")
path_vim = os.path.join(path_to_home,".vim")
path_vim_colors = os.path.join(path_to_home,".vim","colors")
path_vim_colors_all = os.path.join(path_to_home,".vim","colors","*")
path_vim_colors_ej = os.path.join(path_to_pwd,"vim-colors/")
path_vim_colors_ej_all = os.path.join(path_to_pwd,"vim-colors","*")
if os.path.exists(path_vim)==False:
    os.system(f"mkdir {path_vim}")
if os.path.exists(path_vim_colors):
    print(f"copy {path_vim_colors_all} to {path_vim_colors_ej} and removing directory...")
    os.system(f"cp {path_vim_colors_all} {path_vim_colors_ej}")
    os.system(f"rm -rf {path_vim_colors}")
print(f"linking {path_vim_colors_ej}")
os.system(f"ln -s {path_vim_colors_ej} {path_vim_colors}")

print()
print("*********  set zshrc  *********")
replace_zshrc = input("Replace zshrc? [1/0]: ")
if replace_zshrc=='1':
    backup_and_link_file(os.path.join(path_to_home,".zshrc"), os.path.join(path_to_pwd,"zshrc"))
