import os

if len(os.environ["ZSH"])>0 and os.path.exists(os.environ["ZSH"]):
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

name_vimrc = os.path.join(os.environ["HOME"],".vimrc")
#if os.path.exists(name_vimrc)

#os.system("
#file_vimrc = open(os.path.join(os.environ["HOME"],".vimrc"))
#for line in file_vimrc:
#	print(line)
